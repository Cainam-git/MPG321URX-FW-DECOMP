/* leon2m FUN_a00f2708 @ 0xa00f2708  stable 16-bit register read (hand; byte-exact at -O3 -g)
 *
 * Reads a 16-bit value from a register block of the 0x19A2EC table (block base + reg; block 6/7 remap of 0xA0 -> +0x60
 * and 0xBE -> +0x5D), exactly as FUN_a00f25f8, which the original has in the same file and inlines here three times.
 * It reads the value a, then reads it again and compares; while the two reads differ and fewer than 5 retries were
 * made, it reads a again. It returns the last a. So a live counter that changes between its low-byte and high-byte
 * reads is read until two consecutive reads agree (at most 6 compare reads); after 5 retries the last a is returned
 * even when it still differs.
 * Callers: the display timing code FUN_a01038c0 (many times).
 * Idioms found: the counter is set to 0 in its declaration, BEFORE the first read, and the loop is
 *   for (; a != read() && n < 5; n++) a = read();  (the compare read comes first, then the counter test).
 *   Setting n = 0 after the first read changes the register choice (86.6 %); a separate b temporary or two
 *   if-breaks give 49 %.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))   /* register at 0xCF000000 + 4 * a */
extern unsigned short DAT_0019a2ec[8];     /* block bases, see above */
unsigned short FUN_a00f25f8(unsigned char blk, unsigned char reg)
{
    unsigned short v; unsigned int a, lo, hi;
    if (blk > 7) blk = 0;
    if (blk <= 5) { a = DAT_0019a2ec[blk] + reg; lo = R(a); hi = R(a + 1); v = (hi << 8) | (lo & 0xff); }
    else if (reg == 0xa0) v = R(DAT_0019a2ec[blk] + 0x60);
    else if (reg == 0xbe) v = R(DAT_0019a2ec[blk] + 0x5d);
    else { a = DAT_0019a2ec[blk] + reg; lo = R(a); hi = R(a + 1); v = (hi << 8) | (lo & 0xff); }
    return v;
}
unsigned short FUN_a00f2708(unsigned char blk, unsigned char reg)
{
    unsigned short a;
    unsigned char n = 0;
    a = FUN_a00f25f8(blk, reg);
    for (; a != FUN_a00f25f8(blk, reg) && n < 5; n++)
        a = FUN_a00f25f8(blk, reg);
    return a;
}
