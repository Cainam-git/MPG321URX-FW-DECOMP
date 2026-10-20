/* FUN_a00a7bf8 (leon2s 0xa00a7bf8-0xa00a7cc0, 200 bytes), flags -mcpu=v8 -Os -g.
 * Read-modify-write of the low byte of register reg of a hardware block for port 0..4 (other ports: no
 * access). Register address = ((u16 base table 0xa00b4d70[port] + reg) * 4) | 0xcf000000. For ports 1..4
 * and (u16)reg < 0x60 the register at base + 0x60 is first rewritten: bits 0..5 kept, bits 6 and up =
 * port - 1 (the same step as in the read function FUN_a00a7acc). Then the register is read into a byte,
 * mode == 1 sets the bits of mask, any other mode clears them, and the byte is written back.
 * Source forms: the inlined helper reg_addr() keeps (base + 0x60) * 4 as add + shift; the read address
 * uses a copy addr = reg truncated as ((addr << 16) >> 16), the store (unsigned short)reg, which keeps
 * the separate truncations and register copies of the firmware (as in FUN_a00a7940); mask is a byte.
 */
extern unsigned char DAT_a00b4d70;

static __inline__ volatile unsigned int *reg_addr(unsigned int a)
{
    return (volatile unsigned int *)((a * 4) | 0xcf000000);
}

void FUN_a00a7bf8(unsigned char port, short reg, unsigned char mask, unsigned char mode)
{
    unsigned int addr;
    unsigned char v;
    volatile unsigned int *p;

    if (port < 5) {
        if (port != 0)
            if ((unsigned short)reg < 0x60) {
                p = reg_addr(*(unsigned short *)(&DAT_a00b4d70 + port * 2) + 0x60);
                *p = (*p & 0x3f) | ((port - 1) << 6);
            }
        addr = reg;
        addr = ((*(unsigned short *)(&DAT_a00b4d70 + port * 2) + ((addr << 16) >> 16)) * 4) | 0xcf000000;
        v = *(volatile unsigned int *)addr;
        if (mode == 1)
            v |= mask;
        else
            v &= ~mask;
        *reg_addr(*(unsigned short *)(&DAT_a00b4d70 + port * 2) + (unsigned short)reg) = v & 0xff;
    }
}
