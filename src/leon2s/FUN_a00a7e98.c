/* FUN_a00a7e98 (leon2s 0xa00a7e98-0xa00a7ee0, 72 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Register read helper: for port < 4 returns the low byte of the word at 0xcf000000 | ((base[port] + reg) * 4),
 * base = the 16-bit table at 0xa00b4d64; other ports return 0. Callers in 0xa00c0000-0xa00df000 reach it through
 * calls linked 0xF10000 above this address (func_0xa0fb7e98 in their sources).
 */
extern unsigned char DAT_a00b4d64;

unsigned int FUN_a00a7e98(unsigned int port, unsigned short reg)
{
    unsigned int v = 0;

    if ((port & 0xff) < 4)
        v = *(volatile unsigned int *)(((*(unsigned short *)(&DAT_a00b4d64 + (port & 0xff) * 2) + reg) * 4)
                | 0xcf000000) & 0xff;
    return v;
}
