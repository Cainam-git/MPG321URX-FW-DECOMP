/* FUN_a00a7fa0 (leon2s 0xa00a7fa0-0xa00a7fd8, 56 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Register read helper without a port check: returns the low byte of the word at
 * 0xcf000000 | ((base[port] + reg) * 4), base = the 16-bit table at 0xa00b4d5c. Callers in 0xa00c0000-0xa00df000
 * reach it through calls linked 0xF10000 above this address (func_0xa0fb7fa0 in their sources).
 */
extern unsigned char DAT_a00b4d5c;

unsigned int FUN_a00a7fa0(unsigned int port, unsigned short reg)
{
    return *(volatile unsigned int *)(((*(unsigned short *)(&DAT_a00b4d5c + (port & 0xff) * 2) + reg) * 4)
            | 0xcf000000) & 0xff;
}
