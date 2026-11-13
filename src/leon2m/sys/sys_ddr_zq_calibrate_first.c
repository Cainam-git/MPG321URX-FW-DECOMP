/* sys_ddr_zq_calibrate_first  (FUN_a00e321c)
 *
 * Run the register sequence and the setting search of the first calibration unit.
 * Name basis: descriptive - step of the impedance calibration
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g.
 * Source form: c = (version == 0 && generation == 3) is a variable (compare and subtract-with-carry pair, kept in
 * a saved register). HOOKS() is a do/while(0) macro for the four repeated stores; the hook values are link-time
 * symbol addresses (the firmware has a separate 'sethi %hi(0x82400)' for 0x82588 and 0x82714). The routine has
 * three parameters (phy passed unextended) and ends with a tail call of five arguments.
 */
extern unsigned int sys_ddr_cal_compare_mode;
extern unsigned int sys_ddr_run_cal_hook;
extern unsigned int sys_ddr_set_n_adj_det_hook;
extern unsigned int sys_ddr_wait_cal_idle_hook;
extern unsigned int sys_ddr_set_adj_fields_hook;
extern void sys_ddr_delay_short(int);
extern int sys_ddr_phy_read(unsigned int, unsigned int);
extern void sys_ddr_phy_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_set_bits(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_search_cal_setting(unsigned int, unsigned int, unsigned int, unsigned int);

extern char sys_ddr_unit1_n_values_entry, sys_ddr_unit1_adj_fields_entry, sys_ddr_unit1_idle_wait_entry, sys_ddr_unit1_measure_entry;

/* Control register of this unit; the second and third units use 0x1e1 and 0x215. */
#define CAL_CTRL 0x1c0

/* Point the search routine at this unit's four routines (see sys_ddr_search_cal_setting). */
#define HOOKS() do { \
  sys_ddr_set_n_adj_det_hook = (unsigned int)&sys_ddr_unit1_n_values_entry; \
  sys_ddr_set_adj_fields_hook = (unsigned int)&sys_ddr_unit1_adj_fields_entry; \
  sys_ddr_wait_cal_idle_hook = (unsigned int)&sys_ddr_unit1_idle_wait_entry; \
  sys_ddr_run_cal_hook = (unsigned int)&sys_ddr_unit1_measure_entry; } while (0)

/*
 * Calibration unit 1 of memory interface phy, used for duty_idx 0 of sys_ddr_calibrate_drivers (its only
 * caller). Units 2 and 3 have their own routines.
 * version and generation are the values sys_ddr_check_arguments checks.
 *
 * Order:
 *  1. Only when version is 0 and generation is 3: set three fields of registers 0x1c1 and 0x1dc to fixed values.
 *  2. Pulse bits in the shared registers 0x1f0 (0x80) and 0x1df (8) off and on, set bits 8, 2 and 4 of the
 *     control register, wait one short delay, clear bit 8, then set bits 0x80 and 0x40 of 0x1df.
 *  3. Run five searches (sys_ddr_search_cal_setting with index 0, 8, 1, 7, 6; the same index is passed twice);
 *     before each one the four routine pointers are set to this unit's routines. During the searches for index 0
 *     and 1 the comparison mode of the search is 1 when step 1 applied (version 0, generation 3), otherwise 0.
 *  4. After the searches for index 8, 1 and 6, read 0x1d0, 0x1d1 and 0x1d0 and copy each value into 0x1cc, 0x1c8
 *     and 0x1c7; the control register's field 0xf0 is set to 0x90, 0x50 and 0x40 for those copies.
 *  5. Set bit 2 of the control register and clear its field 0xf0.
 */
void sys_ddr_zq_calibrate_first(unsigned int phy, int version, unsigned int generation)
{
  int result;
  int special = version == 0 && generation == 3;

  if (special) {
    sys_ddr_phy_write_field(phy, 0x1c1, 6, 1, 1);
    sys_ddr_phy_write_field(phy, 0x1c1, 0xf0, 4, 1);
    sys_ddr_phy_write_field(phy, 0x1dc, 0xc0, 6, 1);
  }
  sys_ddr_phy_update_bits(phy, 0x1f0, 0x80, 0);
  sys_ddr_phy_update_bits(phy, 0x1df, 8, 0);
  sys_ddr_phy_set_bits(phy, 0x1f0, 0x80);
  sys_ddr_phy_set_bits(phy, 0x1df, 8);
  sys_ddr_phy_set_bits(phy, CAL_CTRL, 8);
  sys_ddr_phy_set_bits(phy, CAL_CTRL, 2);
  sys_ddr_phy_set_bits(phy, CAL_CTRL, 4);
  sys_ddr_delay_short(1);
  sys_ddr_phy_update_bits(phy, CAL_CTRL, 8, 0);
  sys_ddr_phy_set_bits(phy, 0x1df, 0x80);
  sys_ddr_phy_set_bits(phy, 0x1df, 0x40);
  if (special)
    sys_ddr_cal_compare_mode = 1;
  HOOKS();
  sys_ddr_search_cal_setting(phy, 0, 0, 0);
  sys_ddr_cal_compare_mode = 0;
  HOOKS();
  sys_ddr_search_cal_setting(phy, 8, 8, 0);
  result = sys_ddr_phy_read(phy, 0x1d0);
  sys_ddr_phy_update_bits(phy, CAL_CTRL, 0xf0, 0x90);
  sys_ddr_phy_update_bits(phy, 0x1cc, 0xff, result);
  if (special)
    sys_ddr_cal_compare_mode = 1;
  HOOKS();
  sys_ddr_search_cal_setting(phy, 1, 1, 0);
  sys_ddr_cal_compare_mode = 0;
  result = sys_ddr_phy_read(phy, 0x1d1);
  sys_ddr_phy_update_bits(phy, CAL_CTRL, 0xf0, 0x50);
  sys_ddr_phy_update_bits(phy, 0x1c8, 0xff, result);
  HOOKS();
  sys_ddr_search_cal_setting(phy, 7, 7, 0);
  HOOKS();
  sys_ddr_search_cal_setting(phy, 6, 6, 0);
  result = sys_ddr_phy_read(phy, 0x1d0);
  sys_ddr_phy_update_bits(phy, CAL_CTRL, 0xf0, 0x40);
  sys_ddr_phy_update_bits(phy, 0x1c7, 0xff, result);
  sys_ddr_phy_set_bits(phy, CAL_CTRL, 2);
  sys_ddr_phy_write_field(phy, CAL_CTRL, 0xf0, 4, 0);
}
