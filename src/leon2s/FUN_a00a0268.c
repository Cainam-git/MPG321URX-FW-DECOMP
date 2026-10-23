/* leon2s FUN_a00a0268 @ 0xa00a0268-0xa00a03c8, -mcpu=v8 -Os -g.
 * (u8 port, u8 *d), returns int. r = the register block pointer at +8 of the 0x34-byte record
 * ARR_a807db00[port]. When the low byte of r[0x80/4] is 0: FUN_a00b15ac(d, 0, 0x22) and return 1.
 * Otherwise the words r[0x80/4] .. r[0x9c/4] are copied to d in little-endian byte order (31 bytes: the last
 * word gives only 3 bytes) and 0 is returned.
 * volatile: the block is a register block (the firmware reads word 0x80 twice).
 */
struct Port34 { unsigned int pad0; unsigned int pad4; volatile unsigned int *regs; unsigned char rest[0x34 - 0xc]; };
extern struct Port34 ARR_a807db00[];
extern void *FUN_a00b15ac(void *, int, unsigned int);

int FUN_a00a0268(unsigned char port, unsigned char *d)
{
    unsigned int w;

    if ((ARR_a807db00[port].regs[0x80 / 4] & 0xff) == 0) {
        FUN_a00b15ac(d, 0, 0x22);
        return 1;
    }
        w = ARR_a807db00[port].regs[0x80 / 4];
        d[0x0] = w;
        d[0x1] = w >> 8;
        d[0x2] = w >> 16;
        d[0x3] = w >> 24;
        w = ARR_a807db00[port].regs[0x84 / 4];
        d[0x4] = w;
        d[0x5] = w >> 8;
        d[0x6] = w >> 16;
        d[0x7] = w >> 24;
        w = ARR_a807db00[port].regs[0x88 / 4];
        d[0x8] = w;
        d[0x9] = w >> 8;
        d[0xa] = w >> 16;
        d[0xb] = w >> 24;
        w = ARR_a807db00[port].regs[0x8c / 4];
        d[0xc] = w;
        d[0xd] = w >> 8;
        d[0xe] = w >> 16;
        d[0xf] = w >> 24;
        w = ARR_a807db00[port].regs[0x90 / 4];
        d[0x10] = w;
        d[0x11] = w >> 8;
        d[0x12] = w >> 16;
        d[0x13] = w >> 24;
        w = ARR_a807db00[port].regs[0x94 / 4];
        d[0x14] = w;
        d[0x15] = w >> 8;
        d[0x16] = w >> 16;
        d[0x17] = w >> 24;
        w = ARR_a807db00[port].regs[0x98 / 4];
        d[0x18] = w;
        d[0x19] = w >> 8;
        d[0x1a] = w >> 16;
        d[0x1b] = w >> 24;
        w = ARR_a807db00[port].regs[0x9c / 4];
        d[0x1c] = w;
        d[0x1d] = w >> 8;
        d[0x1e] = w >> 16;
    return 0;
}
