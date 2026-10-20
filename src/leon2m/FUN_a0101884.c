/* leon2m FUN_a0101884 @ 0xa0101884-0xa01018b0 (11 words).
 * Writes (a & 0xf) << 4 to the register at 0xcf0160c4, then reads it back and ORs in b & 0xf. A leaf routine without
 * a register window; the register is accessed through a volatile pointer.
 */
#define REG (*(volatile unsigned int *)0xcf0160c4)

void FUN_a0101884(unsigned int a, unsigned int b)
{
    REG = (a & 0xf) << 4;
    REG |= b & 0xf;
}
