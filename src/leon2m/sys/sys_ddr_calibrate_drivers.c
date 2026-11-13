/* sys_ddr_calibrate_drivers  (FUN_a00e3bdc)
 *
 * Run training step 3 (DUTY): the calibration unit duty_idx selects, then update three registers.
 * Returns: 0 or -1
 * Note: duty_idx 0, 1, 2 = first, second, third unit; above 2 prints "duty_idx %d out of range."; registers
 *   0x1c0, 0x1e1, 0x215.
 * Name basis: derived - sys_ddr_set_step(3); prints 'duty_idx %d out of range.'; one script command per unit
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O2 (no -g). The error path is an early return of -1. The extern declarations are old-style
 * (no parameter list). The extra pair of braces around the body and the 'else if ((int)duty_idx < 2)' chain are
 * the form the build needs.
 */
extern int dbg_printf();
extern int sys_ddr_print_step();
extern int sys_ddr_check_arguments();
extern void sys_ddr_set_step();
extern void sys_ddr_phy_update_bits();
extern int sys_ddr_print_error_prefix();
extern int sys_ddr_zq_calibrate_first();
extern int sys_ddr_zq_calibrate_second();
extern int sys_ddr_zq_calibrate_third();

/* Training step number printed as "DUTY" (see sys_ddr_print_step). */
#define DDR_STEP_DUTY 3

/*
 * Training step 3 (DUTY) for one calibration unit of memory interface phy. Returns 0, or -1 when duty_idx is
 * out of range. The script runner calls it with duty_idx 0, 1 and 2 (script commands 45, 46, 47).
 *
 * phy, version and generation are passed on to sys_ddr_check_arguments and to the unit routine. duty_idx
 * (0..2) selects the unit routine: 0 sys_ddr_zq_calibrate_first, 1 _second, 2 _third. A larger duty_idx prints
 * "duty_idx %d out of range." and returns -1 before anything else is done.
 *
 * After the unit routine, the control registers that the three unit routines use (0x1c0, 0x1e1, 0x215) are each
 * updated under mask 0xf2 with a fixed list of values that ends in 0 (10 values for 0x1c0, 13 for each of the
 * other two). This happens for every duty_idx, whichever unit routine ran.
 */
int sys_ddr_calibrate_drivers(unsigned int phy, unsigned int version, unsigned int generation,
                              unsigned int duty_idx)

{
  sys_ddr_set_step(DDR_STEP_DUTY,phy,duty_idx);
  sys_ddr_check_arguments(phy,version,generation);
  if (2 < duty_idx) {
    sys_ddr_print_step();
    sys_ddr_print_error_prefix();
    dbg_printf("duty_idx %d out of range.\n",duty_idx);
    return -1;
  }
  {
    if (duty_idx == 1) {
      sys_ddr_zq_calibrate_second(phy,version,generation);
    }
    else if ((int)duty_idx < 2) {
      if (duty_idx == 0) {
        sys_ddr_zq_calibrate_first(phy,version,generation);
      }
    }
    else if (duty_idx == 2) {
      sys_ddr_zq_calibrate_third(phy,version,generation);
    }
    sys_ddr_phy_update_bits(phy,0x1c0,0xf2,2);
    sys_ddr_phy_update_bits(phy,0x1c0,0xf2,0x82);
    sys_ddr_phy_update_bits(phy,0x1c0,0xf2,0x92);
    sys_ddr_phy_update_bits(phy,0x1c0,0xf2,0x12);
    sys_ddr_phy_update_bits(phy,0x1c0,0xf2,0x52);
    sys_ddr_phy_update_bits(phy,0x1c0,0xf2,0x72);
    sys_ddr_phy_update_bits(phy,0x1c0,0xf2,0x62);
    sys_ddr_phy_update_bits(phy,0x1c0,0xf2,0x42);
    sys_ddr_phy_update_bits(phy,0x1c0,0xf2,2);
    sys_ddr_phy_update_bits(phy,0x1c0,0xf2,0);
    sys_ddr_phy_update_bits(phy,0x1e1,0xf2,2);
    sys_ddr_phy_update_bits(phy,0x1e1,0xf2,0x42);
    sys_ddr_phy_update_bits(phy,0x1e1,0xf2,0x52);
    sys_ddr_phy_update_bits(phy,0x1e1,0xf2,0x72);
    sys_ddr_phy_update_bits(phy,0x1e1,0xf2,0x62);
    sys_ddr_phy_update_bits(phy,0x1e1,0xf2,0x22);
    sys_ddr_phy_update_bits(phy,0x1e1,0xf2,0x32);
    sys_ddr_phy_update_bits(phy,0x1e1,0xf2,0x12);
    sys_ddr_phy_update_bits(phy,0x1e1,0xf2,2);
    sys_ddr_phy_update_bits(phy,0x1e1,0xf2,0x82);
    sys_ddr_phy_update_bits(phy,0x1e1,0xf2,0x92);
    sys_ddr_phy_update_bits(phy,0x1e1,0xf2,2);
    sys_ddr_phy_update_bits(phy,0x1e1,0xf2,0);
    sys_ddr_phy_update_bits(phy,0x215,0xf2,2);
    sys_ddr_phy_update_bits(phy,0x215,0xf2,0x42);
    sys_ddr_phy_update_bits(phy,0x215,0xf2,0x52);
    sys_ddr_phy_update_bits(phy,0x215,0xf2,0x72);
    sys_ddr_phy_update_bits(phy,0x215,0xf2,0x62);
    sys_ddr_phy_update_bits(phy,0x215,0xf2,0x22);
    sys_ddr_phy_update_bits(phy,0x215,0xf2,0x32);
    sys_ddr_phy_update_bits(phy,0x215,0xf2,0x12);
    sys_ddr_phy_update_bits(phy,0x215,0xf2,2);
    sys_ddr_phy_update_bits(phy,0x215,0xf2,0x82);
    sys_ddr_phy_update_bits(phy,0x215,0xf2,0x92);
    sys_ddr_phy_update_bits(phy,0x215,0xf2,2);
    sys_ddr_phy_update_bits(phy,0x215,0xf2,0);
  }
  return 0;
}