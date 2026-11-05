/* FUN_a009f738 (leon2s 0xa009f738-0xa009facc, 916 bytes), flags -mcpu=v8 -Os -g.
 * unsigned char (u8 port, d): fills the 0x58-byte block d from the register block ARR_a807db00[port].regs (word pointer
 * at +4 of the 0x34-byte record). Word 0x40: bytes +0x42 / +0x44 (bits 0..7 / 16..23). Unless bits 0..7 are
 * 0x82 and bits 16..23 are nonzero, the block is cleared with FUN_a00b15ac(d, 0, 0x58) and 1 is returned.
 * Otherwise word 0x44 goes to bytes +0x46..+0x49, word 0x40 bits 8..15 to +0x43 and +0, bits 24..31 to +0x45;
 * fields of word 0x44, each limited to a maximum index, select the words of the 8-byte entry tables
 * DAT_a00b49d8, DAT_a00b49c0, DAT_a00b4998, DAT_a00b4970, DAT_a00b4948, DAT_a00b4920 (+4..+0x18),
 * DAT_a00b48a0 (+0x1c, only when +8 is 1, else 0) and DAT_a00b4878 (+0x2c). When byte +0 is 2: DAT_a00b4860
 * (+0x20), DAT_a00b4820 (+0x24, only when +0x14 is 3), DAT_a00b47f8 (+0x28), byte +0x30 = bits 24..30; word
 * 0x48 bits 6..7 select DAT_a00b47d0 (+0x34) and bits 0..3 give byte +0x38. Finally words 0x48, 0x4c
 * and 0x50 go to bytes +0x4a..+0x53 and the halfwords +0x3a (0x48 bits 8..23), +0x3c (0x48 bits 24..31 |
 * 0x4c bits 0..7 << 8), +0x3e (0x4c bits 8..23) and +0x40 (0x4c bits 24..31 | 0x50 bits 0..7 << 8); returns 0.
 * Source form: K&R definition; the high bytes of the +0x3c / +0x40 halfwords are written '(w & 0xff000000) >> 24'
 * (the byte stores use 'w >> 24'); the byte stores and field reads are in the order of this file.
 */
struct Port34 { unsigned int pad0; volatile unsigned int *regs; unsigned char rest[0x34 - 8]; };
struct Ent { unsigned int v; unsigned int s; };
struct Avi {
    unsigned char b0;
    unsigned char _1[3];
    unsigned int w4, w8, wc, w10, w14, w18, w1c, w20, w24, w28, w2c;
    unsigned char b30;
    unsigned char _31[3];
    unsigned int w34;
    unsigned char b38;
    unsigned char _39;
    unsigned short h3a, h3c, h3e, h40;
    unsigned char b42, b43, b44, b45, b46, b47, b48, b49, b4a, b4b, b4c, b4d, b4e, b4f, b50, b51, b52, b53;
    unsigned char _54[4];
};
extern struct Port34 ARR_a807db00[];
extern const struct Ent DAT_a00b49d8[], DAT_a00b49c0[], DAT_a00b4998[], DAT_a00b4970[], DAT_a00b4948[];
extern const struct Ent DAT_a00b4920[], DAT_a00b48a0[], DAT_a00b4878[], DAT_a00b4860[], DAT_a00b4820[];
extern const struct Ent DAT_a00b47f8[], DAT_a00b47d0[];
extern void *FUN_a00b15ac(void *, int, unsigned int);

unsigned char FUN_a009f738(port, d)
    unsigned char port;
    struct Avi *d;
{
    unsigned int v, w;
    unsigned char i;

    v = ARR_a807db00[port].regs[0x40 / 4];
    d->b42 = v;
    d->b44 = v >> 16;
    if ((v & 0xff) == 0x82 && ((v >> 16) & 0xff) != 0) {
    unsigned char i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;
    w = ARR_a807db00[port].regs[0x44 / 4];
    d->b46 = w;
    d->b0 = v >> 8;
    d->b47 = w >> 8;
    d->b48 = w >> 16;
    d->b49 = w >> 24;
    d->b43 = v >> 8;
    d->b45 = v >> 24;
    i1 = (w & 0x60) >> 5;
    if (i1 > 3)
        i1 = 4;
    d->w4 = DAT_a00b49d8[i1].v;
    i2 = (w & 0x10) >> 4;
    if (i2 > 1)
        i2 = 2;
    d->w8 = DAT_a00b49c0[i2].v;
    i3 = (w & 0xc) >> 2;
    if (i3 > 3)
        i3 = 4;
    d->wc = DAT_a00b4998[i3].v;
    i4 = w & 3;
    if (i4 > 3)
        i4 = 4;
    d->w10 = DAT_a00b4970[i4].v;
    i5 = (w >> 14) & 3;
    if (i5 > 3)
        i5 = 4;
    d->w14 = DAT_a00b4948[i5].v;
    i6 = (w >> 12) & 3;
    if (i6 > 3)
        i6 = 4;
    d->w18 = DAT_a00b4920[i6].v;
    if (d->w8 == 1)
        d->w1c = DAT_a00b48a0[(w & 0xf00) >> 8].v;
    else
        d->w1c = 0;
    i7 = (w & 0x30000) >> 16;
    if (i7 > 3)
        i7 = 4;
    d->w2c = DAT_a00b4878[i7].v;
    if (d->b0 == 2) {
        i8 = (w >> 23) & 1;
        if (i8 > 1)
            i8 = 2;
        d->w20 = DAT_a00b4860[i8].v;
        if (d->w14 == 3) {
            i9 = (w >> 20) & 7;
            if (i9 > 6)
                i9 = 7;
            d->w24 = DAT_a00b4820[i9].v;
        }
        i10 = (w >> 18) & 3;
        if (i10 > 3)
            i10 = 4;
        d->b30 = (w & 0x7f000000) >> 24;
        w = ARR_a807db00[port].regs[0x48 / 4];
        d->w28 = DAT_a00b47f8[i10].v;
        i = (w & 0xc0) >> 6;
        if (i > 3)
            i = 4;
        d->w34 = DAT_a00b47d0[i].v;
        d->b38 = w & 0xf;
    }
    } else {
        FUN_a00b15ac(d, 0, 0x58);
        return 1;
    }
    {
    unsigned int a3a;
    unsigned int a3c;
    unsigned int a3e;
    unsigned int a40;
    w = ARR_a807db00[port].regs[0x48 / 4];
    a3a = (w & 0xffff00) >> 8;
    d->b4b = w >> 8;
    d->b4c = w >> 16;
    d->b4d = w >> 24;
    d->b4a = w;
    a3c = (w & 0xff000000) >> 24;
    w = ARR_a807db00[port].regs[0x4c / 4];
    d->b4f = w >> 8;
    d->b50 = w >> 16;
    d->b51 = w >> 24;
    d->b4e = w;
    a3c |= (w & 0xff) << 8;
    a3e = (w & 0xffff00) >> 8;
    a40 = (w & 0xff000000) >> 24;
    w = ARR_a807db00[port].regs[0x50 / 4];
    a40 |= (w & 0xff) << 8;
    d->h3a = a3a;
    d->h3c = a3c;
    d->h3e = a3e;
    d->b53 = w >> 8;
    d->b52 = w;
    d->h40 = a40;
    }
    return 0;
}
