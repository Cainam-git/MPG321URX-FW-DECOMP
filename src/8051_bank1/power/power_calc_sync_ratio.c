/* power_calc_sync_ratio  (FUN_CODE_c3e4)
 *
 * Return the ratio of two measured sync meter totals scaled by 256.
 * Returns: ratio
 * Name basis: descriptive - round(reg 0x14 * 256 / (reg 0x12 & 0x1FFF)) from reg_read_sync_meter_word
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c3e4, OPTIMIZE(7,SPEED) LARGE. The result is computed in single-precision float with the Keil float
 * library (256.0 multiply, divide, add 0.5, cast back).
 */
extern unsigned int reg_read_sync_meter_word(unsigned char reg);

/*
 * power_calc_sync_ratio - read two 16-bit values from reg_read_sync_meter_word (register 0x12, masked to 13 bits, and
 * register 0x14) and return second * 256 / first rounded to the nearest integer.
 * Callers: power_check_sync_input and power_check_sync_input_alt; both test the result against 100.
 */
unsigned int power_calc_sync_ratio(void)
{
    unsigned int divisor, dividend;

    divisor = reg_read_sync_meter_word(0x12) & 0x1fff;
    dividend = reg_read_sync_meter_word(0x14);
    return dividend * 256.0 / divisor + 0.5;
}
