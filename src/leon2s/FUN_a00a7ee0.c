/* FUN_a00a7ee0 (leon2s 0xa00a7ee0-0xa00a7f1c, 60 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Register write helper without a port check: writes (v & 0xff) to the word at
 * 0xcf000000 | ((base[port] + reg) * 4), base = the 16-bit table at 0xa00b4d5c (same table as FUN_a00a7f1c).
 * Callers in 0xa00c0000-0xa00df000 reach it through calls linked 0xF10000 above this address (func_0xa0fb7ee0 in
 * their sources). The store is volatile (hardware register); a plain store would be moved into the retl delay slot.
 */
extern unsigned char DAT_a00b4d5c;

void FUN_a00a7ee0(unsigned int port, unsigned short reg, unsigned int v)
{
    *(volatile unsigned int *)(((*(unsigned short *)(&DAT_a00b4d5c + (port & 0xff) * 2) + reg) * 4)
            | 0xcf000000) = v & 0xff;
}
