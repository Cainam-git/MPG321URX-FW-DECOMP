/* sys_set_reg1360_bit  (FUN_a0101e24)
 *
 * Set or clear one bit of register 0xCF011360.
 * Name basis: descriptive - used by SYSAPI_ConfigSystemPIPMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101e24 @ 0xa0101e24, flags -mcpu=v8 -O3 -g.
 * Source form: one read-modify-write through a volatile pointer in either case; a leaf routine without a register
 * window.
 */
#define REG_CF011360 (*(volatile unsigned int *)0xcf011360)

/*
 * Set (on != 0) or clear bit `bit` of the word register at 0xCF011360.
 *
 * Called by SYSAPI_ConfigSystemPIPMode once for each of the four channel records, with bits 12..15 of the record's
 * cfg word as the bit number.
 */
void sys_set_reg1360_bit(unsigned char bit, unsigned char on)
{
    if (on)
        REG_CF011360 |= 1 << bit;
    else
        REG_CF011360 &= ~(1 << bit);
}
