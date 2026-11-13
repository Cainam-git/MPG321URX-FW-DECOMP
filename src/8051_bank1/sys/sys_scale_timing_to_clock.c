/* sys_scale_timing_to_clock  (FUN_CODE_d8a6)
 *
 * Set two timing registers in proportion to the current clock divider.
 * Note: Runs in register bank 3 (interrupt context).
 * Name basis: descriptive - r from the clock divider reg 0xD929; regs 0xDCB1 = r * 9, 0xDCB2 = r * 15; step of
 *   sys_step_clock_switch
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d8a6 @ 0xd8a6  Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 * Source form: 'using 3'; the two results are bytes 0 and 1 of one array.
 */
#define TIMING_FACTOR_A 9
#define TIMING_FACTOR_B 15

extern unsigned char xdata DAT_EXTMEM_d929;
extern unsigned char xdata reg_clock_timing_factors[];
unsigned char sys_lookup_clock_factor(unsigned char a);

/*
 * Look up the factor for the divider bits (low nibble) of XDATA 0xD929 and store factor * 9 and factor * 15 in
 * the registers at XDATA 0xDCB1 and 0xDCB2. Runs in register bank 3. The use of the two registers is not shown.
 */
void sys_scale_timing_to_clock(void) using 3
{
    unsigned char clock_factor;

    clock_factor = sys_lookup_clock_factor(DAT_EXTMEM_d929 & 0x0f);
    reg_clock_timing_factors[0] = clock_factor * TIMING_FACTOR_A;
    reg_clock_timing_factors[1] = clock_factor * TIMING_FACTOR_B;
}
