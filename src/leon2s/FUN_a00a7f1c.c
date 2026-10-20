/* FUN_a00a7f1c (leon2s 0xa00a7f1c-0xa00a7fa0, 132 bytes), flags -mcpu=v8 -Os -g.
 * Read-modify-write of one 8-bit register of a hardware block: port = arg & 0xff, ports 0..3 only.
 * Address = ((u16 base table 0xa00b4d5c[port] + (u16)reg) * 4) | 0xcf000000. The word is read,
 * mode (arg4 & 0xff) == 1 sets the bits of mask, any other mode clears them (andn); the store
 * re-reads the table entry, recomputes the address and writes (v & 0xff).
 * Same code shape as FUN_a00a7d04 (table 0xa00b4d6c, 2 ports). Source forms: the load address uses
 * ((u32)reg << 16) >> 16 and the store address (unsigned short)reg, which keeps two separate
 * truncations; the value is held in an unsigned char.
 */
extern unsigned char DAT_a00b4d5c;

void FUN_a00a7f1c(unsigned int port, short reg, unsigned int mask, unsigned int mode)
{
    unsigned int addr;
    unsigned char v;

    if ((port & 0xff) < 4) {
        addr = reg;
        addr = ((*(unsigned short *)(&DAT_a00b4d5c + (port & 0xff) * 2) + ((addr << 16) >> 16)) * 4) | 0xcf000000;
        v = *(unsigned int *)addr;
        if ((mode & 0xff) == 1)
            v |= mask;
        else
            v &= ~mask;
        *(unsigned int *)(((*(unsigned short *)(&DAT_a00b4d5c + (port & 0xff) * 2) + (unsigned short)reg) * 4)
                          | 0xcf000000) = v & 0xff;
    }
}
