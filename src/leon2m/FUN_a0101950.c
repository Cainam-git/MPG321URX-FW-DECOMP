/* leon2m FUN_a0101950 @ 0xa0101950-0xa0101984 (13 words).
 * Keeps bits 0..3 of the register at 0xcf0160c0 and sets bits 4..7 to bits 0..3 of a, then sets bit 3 in a second
 * read-modify-write. A leaf routine
 * without a register window; the register is read and written through a volatile pointer.
 */
#define REG (*(volatile unsigned int *)0xcf0160c0)

void FUN_a0101950(unsigned int a)
{
    REG = (REG & 0xf) | (a & 0xf) << 4;
    REG |= 8;
}
