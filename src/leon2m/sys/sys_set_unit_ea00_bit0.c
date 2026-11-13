/* sys_set_unit_ea00_bit0  (FUN_a01075a8)
 *
 * Clear bit 4 of 0xCF00EAC8 and write bit 0 of 0xCF00EA00.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01075a8 @ 0xa01075a8, flags -mcpu=v8 -O3 -g.
 */
#define REG_cf00eac8 (*(volatile unsigned int *)0xcf00eac8)
#define REG_cf00ea00 (*(volatile unsigned int *)0xcf00ea00)

/*
 * Clear bit 4 of register 0xCF00EAC8, then set (on == 1) or clear bit 0 of register 0xCF00EA00.
 * Nothing in the image calls it.
 */
void sys_set_unit_ea00_bit0(unsigned char on)
{
    REG_cf00eac8 &= ~0x10u;
    if (on == 1)
        REG_cf00ea00 |= 1;
    else
        REG_cf00ea00 &= ~1u;
}
