/* FUN_a00a7acc (leon2s 0xa00a7acc-0xa00a7b64, 152 bytes), flags -mcpu=v8 -Os -g.
 * Reads the low byte of register reg of a hardware block for port (arg & 0xff), ports 0..4 only (other
 * ports return 0). Register address = ((u16 base table 0xa00b4d70[port] + reg) * 4) | 0xcf000000.
 * Before the read, for ports 1..4 and (u16)reg < 0x60, the register at base + 0x60 is rewritten:
 * bits 0..5 kept, bits 6 and up = port - 1.
 * Source forms: the address is built by the inlined helper reg_addr(), so (base + 0x60) * 4 keeps its
 * add before the shift; the read uses a copy r = reg taken right before it, truncated as
 * ((r << 16) >> 16), while the test uses (unsigned short)reg: this keeps the two separate truncations.
 */
extern unsigned char DAT_a00b4d70;

static __inline__ volatile unsigned int *reg_addr(unsigned int a)
{
    return (volatile unsigned int *)((a * 4) | 0xcf000000);
}

unsigned int FUN_a00a7acc(unsigned int port, short reg)
{
    unsigned int v = 0;
    unsigned int r;
    volatile unsigned int *p;

    port &= 0xff;
    if (port < 5) {
        if (port != 0)
            if ((unsigned short)reg < 0x60) {
                p = reg_addr(*(unsigned short *)(&DAT_a00b4d70 + port * 2) + 0x60);
                *p = (*p & 0x3f) | ((port - 1) << 6);
            }
        r = reg;
        v = *reg_addr(*(unsigned short *)(&DAT_a00b4d70 + port * 2) + ((r << 16) >> 16)) & 0xff;
    }
    return v;
}
