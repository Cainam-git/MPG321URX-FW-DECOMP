/* leon2s FUN_a009fcb8 @ 0xa009fcb8-0xa009fe2c, -mcpu=v8 -Os -g.
 * (u8 port, struct Out *d), returns int. r = the register block pointer at +4 of the 0x34-byte record
 * ARR_a807db00[port]; v = r[0x60/4]. When the low byte of v is 0x83, byte 2 of v is not 0 and the low 24 bits
 * of r[0x64/4] are not 0x1a: d->b[0] = byte 1 of v and, when that byte is 1, the words r[0x64/4] ..
 * r[0x78/4] are copied little-endian into d->b[1..0x18] and d->w1c = low byte of r[0x7c/4]; returns 0.
 * Otherwise FUN_a00b15ac(d, 0, 0x24) and returns 1. Companion of FUN_a00a0268 (same block form).
 * volatile: register block (the firmware reads every word at its use).
 */
struct Port34 { unsigned int pad0; volatile unsigned int *regs; unsigned char rest[0x34 - 8]; };
struct Out { unsigned char b[0x1c]; unsigned int w1c; unsigned char rest[4]; };
extern struct Port34 ARR_a807db00[];
extern void *FUN_a00b15ac(void *, int, unsigned int);

int FUN_a009fcb8(unsigned char port, struct Out *d)
{
    unsigned int v, w;

    v = ARR_a807db00[port].regs[0x60 / 4];
    if ((v & 0xff) == 0x83 && ((v >> 16) & 0xff) != 0 && (ARR_a807db00[port].regs[0x64 / 4] & 0xffffff) != 0x1a) {
        d->b[0] = v >> 8;
        if (((v >> 8) & 0xff) == 1) {
            w = ARR_a807db00[port].regs[0x64 / 4];
            d->b[0x1] = w;
            d->b[0x2] = w >> 8;
            d->b[0x3] = w >> 16;
            d->b[0x4] = w >> 24;
            w = ARR_a807db00[port].regs[0x68 / 4];
            d->b[0x5] = w;
            d->b[0x6] = w >> 8;
            d->b[0x7] = w >> 16;
            d->b[0x8] = w >> 24;
            w = ARR_a807db00[port].regs[0x6c / 4];
            d->b[0x9] = w;
            d->b[0xa] = w >> 8;
            d->b[0xb] = w >> 16;
            d->b[0xc] = w >> 24;
            w = ARR_a807db00[port].regs[0x70 / 4];
            d->b[0xd] = w;
            d->b[0xe] = w >> 8;
            d->b[0xf] = w >> 16;
            d->b[0x10] = w >> 24;
            w = ARR_a807db00[port].regs[0x74 / 4];
            d->b[0x11] = w;
            d->b[0x12] = w >> 8;
            d->b[0x13] = w >> 16;
            d->b[0x14] = w >> 24;
            w = ARR_a807db00[port].regs[0x78 / 4];
            d->b[0x15] = w;
            d->b[0x16] = w >> 8;
            d->b[0x17] = w >> 16;
            d->b[0x18] = w >> 24;
            d->w1c = ARR_a807db00[port].regs[0x7c / 4] & 0xff;
        }
    } else {
        FUN_a00b15ac(d, 0, 0x24);
        return 1;
    }
    return 0;
}
