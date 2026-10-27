/* FUN_a009fed0 (leon2s 0xa009fed0-0xa00a0268, 920 bytes), flags -mcpu=v8 -Os -g.
 * int (u8 port, record d). Reads the registers r = ARR_a807db00[port].regs (pointer at +0x14 of the 0x34-byte entry,
 * volatile words). Unless byte 0 of r[0] is 0x87 and byte 1 is 1, d is cleared (0x48 bytes) and 1 returned.
 * Otherwise: d->w4 = DAT_a00b4568[min(r[1] & 7, 4)].v, d->w8 = DAT_a00b4558[bits 8..10 of r[1] != 0].v (8-byte
 * entries); x[0..2] = high halves of r[1..3], y[0..2] = low halves of r[2..4]; g = index of the largest x, k = the
 * second index chosen by the y comparisons, and the third is 3 - g - k; d's halfwords +0xc..+0x16 = (x, y) of g, k
 * and the third; +0x18..+0x22 = halves of r[4..7]; d's bytes +0x24 = 0x87, +0x25..+0x27 = bytes 1..3 of r[0],
 * +0x28..+0x42 = the bytes of r[1..7] (the last word without its top byte); d->b0 = 1; returns 0.
 * Source forms the exact build depends on: K&R definition (u8 port); w4/w8 declared unsigned long (their own alias
 * set, so the stores move past the volatile reads as in the firmware); the failure arm as the else of the success
 * test with the stores after it; k given its default before the x2 test; per-word byte store orders as found by a
 * permutation search.
 */
struct PortX { unsigned char pad[0x14]; volatile unsigned int *regs; unsigned char rest[0x34 - 0x18]; };
struct Ent { unsigned int v; unsigned int s; };
struct Drm {
    unsigned char b0;
    unsigned char _1[3];
    unsigned long w4, w8;
    unsigned short h0c, h0e, h10, h12, h14, h16, h18, h1a, h1c, h1e, h20, h22;
    unsigned char b[0x24];
};
extern struct PortX ARR_a807db00[];
extern const struct Ent DAT_a00b4568[], DAT_a00b4558[];
extern void *FUN_a00b15ac(void *, int, unsigned int);

int FUN_a009fed0(port, d)
    unsigned char port;
    struct Drm *d;
{
    volatile unsigned int *r;
    unsigned short x[3];
    unsigned short y[3];
    unsigned char i, j, g, k;
    unsigned short t18, t1a, t1c, t1e, t20, t22;
    unsigned int w;

    r = ARR_a807db00[port].regs;
    if ((r[0] & 0xff) == 0x87 && ((r[0] >> 8) & 0xff) == 1) {
        i = r[1] & 7;
        if (i > 3)
            i = 4;
        j = (r[1] >> 8) & 7;
        d->w4 = DAT_a00b4568[i].v;
        if (j != 0)
            j = 1;
        x[0] = r[1] >> 16;
        x[1] = r[2] >> 16;
        x[2] = r[3] >> 16;
        y[0] = r[2];
        y[1] = r[3];
        y[2] = r[4];
        d->w8 = DAT_a00b4558[j].v;
        if (x[0] >= x[1] && x[0] >= x[2]) {
            g = 0;
            if (y[1] < y[0] || y[1] < y[2])
                k = 2;
            else
                k = 1;
        } else if (x[1] >= x[0] && x[1] >= x[2]) {
            g = 1;
            if (y[0] < y[1] || y[0] < y[2])
                k = 2;
            else
                k = 0;
        } else {
            g = 2;
            k = 0;
            if (y[0] < y[1] || y[0] < y[2])
                k = 1;
        }
        t18 = ARR_a807db00[port].regs[4] >> 16;
        t1a = ARR_a807db00[port].regs[5];
        t1c = ARR_a807db00[port].regs[5] >> 16;
        t1e = ARR_a807db00[port].regs[6];
        t20 = ARR_a807db00[port].regs[6] >> 16;
        t22 = ARR_a807db00[port].regs[7];
    } else {
        FUN_a00b15ac(d, 0, 0x48);
        return 1;
    }
    d->b0 = 1;
    d->b[0] = 0x87;
    d->b[1] = ARR_a807db00[port].regs[0] >> 8;
    d->b[2] = ARR_a807db00[port].regs[0] >> 16;
    d->h0c = x[g];
    d->h0e = y[g];
    d->h10 = x[k];
    d->h12 = y[k];
    d->h14 = x[3 - g - k];
    d->h16 = y[3 - g - k];
    d->h18 = t18;
    d->h1a = t1a;
    d->h1c = t1c;
    d->h1e = t1e;
    d->h20 = t20;
    d->h22 = t22;
    d->b[3] = ARR_a807db00[port].regs[0] >> 24;
    w = ARR_a807db00[port].regs[1];
    d->b[5] = w >> 8;
    d->b[4] = w;
    d->b[6] = w >> 16;
    d->b[7] = w >> 24;
    w = ARR_a807db00[port].regs[2];
    d->b[9] = w >> 8;
    d->b[10] = w >> 16;
    d->b[8] = w;
    d->b[11] = w >> 24;
    w = ARR_a807db00[port].regs[3];
    d->b[13] = w >> 8;
    d->b[14] = w >> 16;
    d->b[12] = w;
    d->b[15] = w >> 24;
    w = ARR_a807db00[port].regs[4];
    d->b[17] = w >> 8;
    d->b[18] = w >> 16;
    d->b[16] = w;
    d->b[19] = w >> 24;
    w = ARR_a807db00[port].regs[5];
    d->b[21] = w >> 8;
    d->b[22] = w >> 16;
    d->b[23] = w >> 24;
    d->b[20] = w;
    w = ARR_a807db00[port].regs[6];
    d->b[24] = w;
    d->b[25] = w >> 8;
    d->b[26] = w >> 16;
    d->b[27] = w >> 24;
    w = ARR_a807db00[port].regs[7];
    d->b[28] = w;
    d->b[29] = w >> 8;
    d->b[30] = w >> 16;
    return 0;
}
