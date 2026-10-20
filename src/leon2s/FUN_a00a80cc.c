/* FUN_a00a80cc (leon2s 0xa00a80cc-0xa00a8184, 184 bytes), flags -mcpu=v8 -Os -g.
 * Read-modify-write of the low byte of register reg in register block (port, sub): port (arg & 0xff)
 * 0..1 and sub (arg & 0xff) 0..5 select the u16 base DAT_a00b4d44[port * 6 + sub]; other values do
 * nothing. Register address = ((base + reg) * 4) | 0xcf000000. mode (arg & 0xff) == 1 sets the bits of
 * mask, any other mode clears them; the byte is written back.
 * Source forms: the range test uses two flag variables as in FUN_a00a8054; the load address uses a copy
 * addr = reg truncated as ((addr << 16) >> 16) and the store (unsigned short)reg, and both addresses
 * repeat the full table index expression (FUN_a00a7940 form), which gives the firmware's register copies.
 */
extern unsigned char DAT_a00b4d44;

void FUN_a00a80cc(unsigned int port, unsigned int sub, short reg, unsigned int mask, unsigned int mode)
{
    unsigned int cond1;
    unsigned int cond2;
    unsigned int addr;
    unsigned char v;

    cond1 = (port & 0xff) > 1;
    cond2 = (sub & 0xff) > 5;
    if (cond1 || cond2)
        return;
    addr = reg;
    addr = ((*(unsigned short *)(&DAT_a00b4d44 + ((port & 0xff) * 6 + (sub & 0xff)) * 2) + ((addr << 16) >> 16))
            * 4) | 0xcf000000;
    v = *(volatile unsigned int *)addr;
    if ((mode & 0xff) == 1)
        v |= mask;
    else
        v &= ~mask;
    *(volatile unsigned int *)(((*(unsigned short *)(&DAT_a00b4d44 + ((port & 0xff) * 6 + (sub & 0xff)) * 2)
                                 + (unsigned short)reg) * 4) | 0xcf000000) = v & 0xff;
}
