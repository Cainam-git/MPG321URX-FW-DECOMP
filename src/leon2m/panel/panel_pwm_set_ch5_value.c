/* panel_pwm_set_ch5_value  (FUN_a011e5fc)
 *
 * Write a 10-bit value to the register pair +4 / +8 of PWM channel 5.
 * Note: Bits 8..9 go to bits 4..5 of 0xCF016184, bits 0..7 to 0xCF016188. Nothing calls it.
 * Name basis: descriptive - 0xCF016184 / 0xCF016188 = +4 / +8 of the block at 0xCF016180 that the PWM routines
 *   use for channel 5
 *
 * Matching notes
 * --------------
 * FUN_a011e5fc (leon2m 0xa011e5fc-0xa011e630, 52 bytes, leaf), flags -mcpu=v8 -O2 -g.
 */
#define HIGH_BITS_REGISTER (*(volatile unsigned int *)0xcf016184)
#define LOW_BYTE_REGISTER  (*(volatile unsigned int *)0xcf016188)

/*
 * Write a 10-bit value across two registers: bits 8..9 go to bits 4..5 of 0xCF016184 (its other bits are kept),
 * bits 0..7 to 0xCF016188. panel_pwm_get_ch5_value reads the value back. No routine in the image calls it.
 */
void panel_pwm_set_ch5_value(unsigned int value)
{
    HIGH_BITS_REGISTER = (HIGH_BITS_REGISTER & ~0x30u) | ((value >> 4) & 0x30);
    LOW_BYTE_REGISTER = value & 0xff;
}
