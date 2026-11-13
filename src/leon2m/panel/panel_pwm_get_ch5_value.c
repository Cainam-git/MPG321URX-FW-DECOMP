/* panel_pwm_get_ch5_value  (FUN_a011e630)
 *
 * Return the 10-bit value of the register pair +4 / +8 of PWM channel 5.
 * Returns: value
 * Note: Nothing calls it.
 * Name basis: descriptive - 0xCF016184 / 0xCF016188 = +4 / +8 of the block at 0xCF016180 that the PWM routines
 *   use for channel 5
 *
 * Matching notes
 * --------------
 * FUN_a011e630 (leon2m 0xa011e630-0xa011e65c, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 */
#define HIGH_BITS_REGISTER (*(volatile unsigned int *)0xcf016184)
#define LOW_BYTE_REGISTER  (*(volatile unsigned int *)0xcf016188)

/*
 * Return the 10-bit value that panel_pwm_set_ch5_value writes: bits 4..5 of 0xCF016184 as bits 8..9, plus the
 * register 0xCF016188 as bits 0..7. No routine in the image calls it.
 */
unsigned short panel_pwm_get_ch5_value(void)
{
    return ((HIGH_BITS_REGISTER & 0x30) << 4) + LOW_BYTE_REGISTER;
}
