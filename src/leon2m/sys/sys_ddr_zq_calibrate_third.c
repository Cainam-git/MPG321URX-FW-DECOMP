/* sys_ddr_zq_calibrate_third  (FUN_a00e3880)
 *
 * Run the register sequence and the setting search of the third calibration unit.
 * Name basis: descriptive - registers 0x216 / 0x237 and following
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g.
 * Source form: the four repeated hook stores are a static helper set_hooks() that the compiler inlines; its
 * source order (0xa802d660, 668, 664, 65c) gives the firmware's store order (664, 65c, 660, 668). The hook
 * values are link-time symbol addresses (the firmware has a separate 'sethi %hi(0x82800)' for 0x82bcc and
 * 0x829a4); 0xa802d668 is stored as a word. The routine has three parameters and ends with a tail call of five
 * arguments.
 */
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

extern char sys_ddr_unit3_idle_wait_entry, sys_ddr_unit3_measure_entry, sys_ddr_unit3_n_values_entry, sys_ddr_unit3_adj_fields_entry;

/* Control register of this unit; the first and second units use 0x1c0 and 0x1e1. */
#define CAL_CTRL 0x215

/* Point the search routine at this unit's four routines (see sys_ddr_search_cal_setting). */
static void set_hooks(void)
{
  sys_ddr_set_n_adj_det_hook = (unsigned int)&sys_ddr_unit3_n_values_entry;
  sys_ddr_set_adj_fields_hook = (unsigned int)&sys_ddr_unit3_adj_fields_entry;
  sys_ddr_wait_cal_idle_hook = (unsigned int)&sys_ddr_unit3_idle_wait_entry;
  sys_ddr_run_cal_hook = (unsigned int)&sys_ddr_unit3_measure_entry;
}

/*
 * Calibration unit 3 of memory interface phy, used for duty_idx 2 of sys_ddr_calibrate_drivers (its only
 * caller). version and generation are the values sys_ddr_check_arguments checks. It has the same steps as unit 2
 * (sys_ddr_zq_calibrate_second) on its own registers (0x215..0x237); it also uses registers 0x1f0 and 0x1df
 * with the other units and bit 0x40 of 0x1f1 with unit 2.
 *
 * Order:
 *  1. Only when version is 0 and generation is 3: set three fields of registers 0x216 and 0x237 to fixed values.
 *  2. Pulse bits in 0x1f0 (0x80) and 0x1df (8) off and on, set bits 8, 2 and 4 of the control register, wait one
 *     short delay, clear bit 8, then set bits 0x20 and 0x10 of 0x23a.
 *  3. Run four searches with index 4, 5, 7, 6 (sys_ddr_search_cal_setting takes the same index twice and mode
 *     0). Before every search the four routine pointers are set to this unit's routines.
 *  4. Read 0x231 and 0x232 and copy them into 0x21a and 0x21b; the control register's field 0xf0 is set to 0x20
 *     and 0x30 for those copies.
 *  5. Set bit 0x40 of 0x1f1, run the searches with index 1 and 0, clear bit 0x40 again.
 *  6. Read 0x228 and 0x229 and copy them into 0x223 and 0x224, with field 0xf0 of the control register set to
 *     0x80 and 0x90.
 *  7. Set bit 2 of the control register and clear its field 0xf0.
 */
void sys_ddr_zq_calibrate_third(unsigned int phy, int version, unsigned int generation)
{
  int result;

  if (version == 0 && generation == 3) {
    sys_ddr_phy_write_field(phy, 0x216, 6, 1, 1);
    sys_ddr_phy_write_field(phy, 0x216, 0xf0, 4, 1);
    sys_ddr_phy_write_field(phy, 0x237, 0xc0, 6, 1);
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
  sys_ddr_phy_set_bits(phy, 0x23a, 0x20);
  sys_ddr_phy_set_bits(phy, 0x23a, 0x10);
  set_hooks();
  sys_ddr_search_cal_setting(phy, 4, 4, 0);
  set_hooks();
  sys_ddr_search_cal_setting(phy, 5, 5, 0);
  set_hooks();
  sys_ddr_search_cal_setting(phy, 7, 7, 0);
  set_hooks();
  sys_ddr_search_cal_setting(phy, 6, 6, 0);
  result = sys_ddr_phy_read(phy, 0x231);
  sys_ddr_phy_update_bits(phy, CAL_CTRL, 0xf0, 0x20);
  sys_ddr_phy_update_bits(phy, 0x21a, 0xff, result);
  result = sys_ddr_phy_read(phy, 0x232);
  sys_ddr_phy_update_bits(phy, CAL_CTRL, 0xf0, 0x30);
  sys_ddr_phy_update_bits(phy, 0x21b, 0xff, result);
  sys_ddr_phy_update_bits(phy, 0x1f1, 0x40, 0x40);
  set_hooks();
  sys_ddr_search_cal_setting(phy, 1, 1, 0);
  set_hooks();
  sys_ddr_search_cal_setting(phy, 0, 0, 0);
  sys_ddr_phy_update_bits(phy, 0x1f1, 0x40, 0);
  result = sys_ddr_phy_read(phy, 0x228);
  sys_ddr_phy_update_bits(phy, CAL_CTRL, 0xf0, 0x80);
  sys_ddr_phy_update_bits(phy, 0x223, 0xff, result);
  result = sys_ddr_phy_read(phy, 0x229);
  sys_ddr_phy_update_bits(phy, CAL_CTRL, 0xf0, 0x90);
  sys_ddr_phy_update_bits(phy, 0x224, 0xff, result);
  sys_ddr_phy_set_bits(phy, CAL_CTRL, 2);
  sys_ddr_phy_write_field(phy, CAL_CTRL, 0xf0, 4, 0);
}
