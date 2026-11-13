/* dp_reset_receiver_flags  (FUN_a00d649c)
 *
 * Clear the receiver's status flags and pulse two reset bits.
 * Name basis: descriptive - 0xFF to 0xCF01301C, pulses on 0xCF013008 and 0xCF013020
 *
 * Matching notes
 * --------------
 * FUN_a00d649c (leon2s 0xa00d649c-0xa00d64ec, 80 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Hardware registers: volatile.
 */
#define R1C (*(volatile unsigned int *)0xcf01301c)
#define R08 (*(volatile unsigned int *)0xcf013008)
#define R20 (*(volatile unsigned int *)0xcf013020)

/* Write 0xff to register 0xcf01301c, then set and clear bits 0xc0 of 0xcf013008 and bit 1 (value 2) of
 * 0xcf013020 in turn. */
void dp_reset_receiver_flags(void)
{
    R1C = 0xff;
    R08 |= 0xc0;
    R08 &= ~0xc0;
    R20 |= 2;
    R20 &= ~2;
}
