/* leon2s FUN_a0092944 @ 0xa0092944-0xa0092cec (936 bytes, 234 words)
 * Flags: -mcpu=v8 -Os -g.
 * (u8 port, u8 *p), void. Writes a 0xa1-byte block p[0..0xa0] into registers 3..0xa3 of page 2 through
 * FUN_a00a8054(u8 port, u8 page, u16 reg, u8 val): reg = offset + 3. It does so in runs: eleven u8-counter
 * loops (lengths 3, 7, 0x15, 3, 0x1c, 3, 0x1c, 3, 0x1c, 3, 0x17), five single writes 0x99..0x9d, one loop
 * of 3 (0x9e..0xa0), and three single writes 0xa1..0xa3. The last one is a sibcall.
 * One counter variable i serves all loops (the firmware re-uses %i3). No volatile.
 * Source form: the run at reg 0x63 (p + 0x60) is the only one whose firmware address add is 'add i, p' (the
 * others are 'add p, i'): it is written in the integer address form (u32)i + (u32)p + 0x60 that Ghidra also
 * showed. &p[i + 0x60] gives 'add p, i' there.
 */
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);

void FUN_a0092944(unsigned char port, unsigned char *p)
{
    unsigned char i;

    for (i = 0; i < 3; i++)
        FUN_a00a8054(port, 2, i + 0x3, p[i]);
    for (i = 0; i < 7; i++)
        FUN_a00a8054(port, 2, i + 0x6, p[i + 0x3]);
    for (i = 0; i < 21; i++)
        FUN_a00a8054(port, 2, i + 0xd, p[i + 0xa]);
    for (i = 0; i < 3; i++)
        FUN_a00a8054(port, 2, i + 0x22, p[i + 0x1f]);
    for (i = 0; i < 28; i++)
        FUN_a00a8054(port, 2, i + 0x25, p[i + 0x22]);
    for (i = 0; i < 3; i++)
        FUN_a00a8054(port, 2, i + 0x41, p[i + 0x3e]);
    for (i = 0; i < 28; i++)
        FUN_a00a8054(port, 2, i + 0x44, p[i + 0x41]);
    for (i = 0; i < 3; i++)
        FUN_a00a8054(port, 2, i + 0x60, p[i + 0x5d]);
    for (i = 0; i < 28; i++)
        FUN_a00a8054(port, 2, i + 0x63, *(unsigned char *)((unsigned int)i + (unsigned int)p + 0x60));
    for (i = 0; i < 3; i++)
        FUN_a00a8054(port, 2, i + 0x7f, p[i + 0x7c]);
    for (i = 0; i < 23; i++)
        FUN_a00a8054(port, 2, i + 0x82, p[i + 0x7f]);
    FUN_a00a8054(port, 2, 0x99, p[0x96]);
    FUN_a00a8054(port, 2, 0x9a, p[0x97]);
    FUN_a00a8054(port, 2, 0x9b, p[0x98]);
    FUN_a00a8054(port, 2, 0x9c, p[0x99]);
    FUN_a00a8054(port, 2, 0x9d, p[0x9a]);
    for (i = 0; i < 3; i++)
        FUN_a00a8054(port, 2, i + 0x9e, p[i + 0x9b]);
    FUN_a00a8054(port, 2, 0xa1, p[0x9e]);
    FUN_a00a8054(port, 2, 0xa2, p[0x9f]);
    FUN_a00a8054(port, 2, 0xa3, p[0xa0]);
}
