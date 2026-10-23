/* FUN_a00a7dd0 (leon2s 0xa00a7dd0-0xa00a7e14, 68 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Register write helper of one hardware block: for port < 4 writes (v & 0xff) to the word at
 * 0xcf000000 | ((base[port] + reg) * 4), base = the 16-bit table at 0xa00b4d64; other ports do nothing.
 * Write counterpart of FUN_a00a7e98, same table as FUN_a00a7e14. Callers in 0xa00c0000-0xa00df000 reach it through
 * calls linked 0xF10000 above this address (func_0xa0fb7dd0 in their sources). Hardware register: volatile.
 */
extern unsigned char DAT_a00b4d64;

void FUN_a00a7dd0(unsigned int port, unsigned short reg, unsigned int v)
{
    if ((port & 0xff) < 4)
        *(volatile unsigned int *)(((*(unsigned short *)(&DAT_a00b4d64 + (port & 0xff) * 2) + reg) * 4)
                | 0xcf000000) = v & 0xff;
}
