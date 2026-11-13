/* sys_restore_crystal_timing  (FUN_CODE_de7c)
 *
 * Set the two clock-scaled timing registers to their crystal values.
 * Name basis: descriptive - regs 0xDCB1 = 9, 0xDCB2 = 15 (sys_scale_timing_to_clock with factor 1); after the
 *   crystal clock switch
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_de7c @ 0xde7c  OPTIMIZE(7,SPEED)
 * Source form: one pointer to 0xDCB1, stepped on to 0xDCB2 (INC DPTR).
 */
#define TIMING_DCB1_FACTOR_1 0x09   /* = 1 * 9, as sys_scale_timing_to_clock stores for factor 1 */
#define TIMING_DCB2_FACTOR_1 0x0f   /* = 1 * 15 */

extern xdata unsigned char reg_clock_timing_factors;
extern xdata unsigned char DAT_EXTMEM_dcb2;

/*
 * Write 9 and 15 to the two timing registers at XDATA 0xDCB1 and 0xDCB2. sys_scale_timing_to_clock sets the
 * same registers to factor * 9 and factor * 15 for the current clock divider, so these are its values for a
 * factor of 1. Only caller: power_watch_dp_activity, right after sys_switch_to_crystal_clock. The use of the two
 * registers is not shown.
 */
void sys_restore_crystal_timing(void)
{
    unsigned char xdata *timing_reg = &reg_clock_timing_factors;
    *timing_reg = TIMING_DCB1_FACTOR_1;
    timing_reg++;
    *timing_reg = TIMING_DCB2_FACTOR_1;
}
