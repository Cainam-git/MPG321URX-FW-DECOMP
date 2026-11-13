/* panel_pwm_set_group_value  (FUN_a011e65c)
 *
 * Write a 10-bit value to the register pair 0xCF016404/0xCF016408.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * FUN_a011e65c (leon2m 0xa011e65c-0xa011e690, 52 bytes, leaf), flags -mcpu=v8 -O2 -g.
 */
#define HIGH_BITS_REGISTER (*(volatile unsigned int *)0xcf016404)
#define LOW_BYTE_REGISTER  (*(volatile unsigned int *)0xcf016408)

/*
 * Write a 10-bit value across two registers: bits 8..9 go to bits 4..5 of 0xCF016404 (its other bits are kept),
 * bits 0..7 to 0xCF016408. Same split as panel_pwm_set_ch5_value, on the registers of the group.
 * No routine in the image calls it.
 */
void panel_pwm_set_group_value(unsigned int value)
{
    HIGH_BITS_REGISTER = (HIGH_BITS_REGISTER & ~0x30u) | ((value >> 4) & 0x30);
    LOW_BYTE_REGISTER = value & 0xff;
}
