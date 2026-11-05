/* FUN_a009faf0 (leon2s 0xa009faf0-0xa009fcb8, 456 bytes), flags -mcpu=v8 -Os -g.
 * unsigned char (u8 port, d): fills the 0x30-byte block d from the register block ARR_a807db00[port].regs (word
 * pointer at +4 of the 0x34-byte record). Word 0x80: bytes raw +0x1c / +0x1e (bits 0..7 / 16..23). Unless
 * bits 0..7 are 0x84 and bits 16..23 are nonzero, the block is cleared with FUN_a00b15ac(d, 0, 0x30) and 1 is
 * returned. Otherwise bits 24..31 go to +0x1f, word 0x84 to bytes +0x20..+0x23, word 0x80 bits 8..15 to +0x1d
 * and +0; fields of word 0x84 (bits 4..7, 0..2, 10..12, 8..9), each limited to a maximum index, select the
 * words of the 8-byte entry tables DAT_a00b4750 (+4), DAT_a00b4708 (+8), DAT_a00b46c0 (+0xc) and DAT_a00b4698
 * (+0x10). Byte +0x14 = word 0x84 bits 24..31; word 0x88 goes to bytes +0x24..+0x27, its bits 3..6 to +0x15
 * and bit 7 selects DAT_a00b4680 (+0x18); word 0x8c bits 0..15 go to bytes +0x28 / +0x29; returns 0.
 * Source form: the 0x84 and 0x88 reads go through the record pointer pr assigned after the 0x80 read, the 0x80
 * and 0x8c reads index ARR_a807db00[port] directly; byte +0x14 is written '(w & 0xff000000) >> 24'; the
 * DAT_a00b4698 word is read into t after the 0x8c read; the stores are in the order of this file.
 */
struct Port34 { unsigned int pad0; volatile unsigned int *regs; unsigned char rest[0x34 - 8]; };
struct Ent { unsigned int v; unsigned int s; };
struct AudInfo {
    unsigned char b0;
    unsigned char _1[3];
    unsigned int w4;
    unsigned int w8;
    unsigned int wc;
    unsigned int w10;
    unsigned char b14;
    unsigned char b15;
    unsigned char _16[2];
    unsigned int w18;
    unsigned char raw[14];
};
extern struct Port34 ARR_a807db00[];
extern const struct Ent DAT_a00b4680[];
extern const struct Ent DAT_a00b4698[];
extern const struct Ent DAT_a00b46c0[];
extern const struct Ent DAT_a00b4708[];
extern const struct Ent DAT_a00b4750[];
extern void *FUN_a00b15ac(void *, int, unsigned int);

unsigned char FUN_a009faf0(unsigned char port, struct AudInfo *d)
{
    unsigned int v, w, x, t;
    unsigned char i1, i2, i3, i4, i5;
    struct Port34 *pr;

    v = ARR_a807db00[port].regs[0x80 / 4];
    pr = &ARR_a807db00[port];
    d->raw[0] = v;
    d->raw[2] = v >> 16;
    if ((v & 0xff) == 0x84 && ((v >> 16) & 0xff) != 0) {
        d->raw[3] = v >> 24;
        w = pr->regs[0x84 / 4];
        i1 = (w & 0xf0) >> 4;
        d->raw[4] = w;
        d->b0 = v >> 8;
        d->raw[5] = w >> 8;
        d->raw[6] = w >> 16;
        d->raw[7] = w >> 24;
        d->raw[1] = v >> 8;
        if (i1 > 14)
            i1 = 15;
        d->w4 = DAT_a00b4750[i1].v;
        i2 = w & 7;
        if (i2 > 7)
            i2 = 8;
        d->w8 = DAT_a00b4708[i2].v;
        i3 = (w >> 10) & 7;
        if (i3 > 7)
            i3 = 8;
        d->wc = DAT_a00b46c0[i3].v;
        i4 = (w & 0x300) >> 8;
        if (i4 > 3)
            i4 = 4;
    } else {
        FUN_a00b15ac(d, 0, 0x30);
        return 1;
    }
    d->b14 = (w & 0xff000000) >> 24;
    w = pr->regs[0x88 / 4];
    d->raw[8] = w;
    d->raw[9] = w >> 8;
    d->raw[10] = w >> 16;
    d->raw[11] = w >> 24;
    x = w & 0x80;
    d->b15 = (w & 0x78) >> 3;
    i5 = x >> 7;
    w = ARR_a807db00[port].regs[0x8c / 4];
    t = DAT_a00b4698[i4].v;
    if (i5 > 1)
        i5 = 2;
    d->w10 = t;
    d->raw[12] = w;
    d->w18 = DAT_a00b4680[i5].v;
    d->raw[13] = w >> 8;
    return 0;
}
