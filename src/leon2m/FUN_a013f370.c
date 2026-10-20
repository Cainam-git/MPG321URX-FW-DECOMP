/* leon2m FUN_a013f370 @ 0xa013f370  per-port mode match; publishes the line-rate switch into 0xA802CBD4 (hand;
 * BYTE-EXACT at -mcpu=v8 -O3 -g -msoft-float).
 *
 * t = FUN_a013cd4c(port) (pointer to the port's timing record).
 * Port status P = 0xA802E224 + 42*port:
 *   P.h0 bit 0x400 set -> 0xA802CBD4 |= 1 << port, else 0xA802CBD4 &= ~(1 << port)   (read back by FUN_a0148540 /
 *   FUN_a0121258 = 'bit port of 0xA802CBD4', i.e. the line-rate switch read by the row picker FUN_a00dac38);
 *   P.h0 bit 0x80 -> 0xA802CBD3 bit port the same way.
 * Then FUN_a01215e8(port) and, by FUN_a0142e8c(port):
 *   != 5: best match over the mode table 0x1A5A16 (36-byte rows, ends at row.w2 == 0xFFFF): rows whose +0x22 id is in the
 *     0x1A59E2 list (13 x {id 0x0C, value}) are skipped, row +0x22 bit 0 must equal FUN_a0121258(port); tolerance checks on
 *     t+6 / t+8 against row +2 / +4 (limits row +0x1E / +0x1F), FUN_a0142e8c(port) == 2 also needs t+0xA & row+6;
 *     t+0x10 (doubled when FUN_a0121258(port) == 1) must exceed row +0x10; score = (|d6| + |d8| + 4*|d10|) * 100 + |t+0xC
 *     - row+8|; the minimum wins, else the row nearest in t+0x10. The row is copied into a second FUN_a013cd4c(port)
 *     record (apply_mode, scaled by row+0 when non-zero); then FUN_a01541ec(&t+6) and, if it returns 0, FUN_a01542c4(&t+6).
 *   == 5: timing taken from P+0x16 / P+0x18 (P+0x18 doubled when FUN_a0121258(port), i.e. when the 0xA802CBD4 bit is set),
 *     defaults stored in t, then the first table row within +-5 / +-6 / +-9 / +-9 sets t+0x12, +0x14, +0x3C.
 * Callers: FUN_a013dc6c (call at 0xA013E8A4, the only call site).
 * BYTE-EXACT keys: -msoft-float; 'if (type != 5) {search} else {type-5}' (pre-layout block order drives -frename-registers);
 *   'if (found == 1)' (gcc predicts == const false, so the not-found arm falls through) with the final FUN_a01541ec check
 *   written in BOTH arms; P bits as bitfields (lets gcc reorder the 0xA802CBD4 store after the next load); table rows read
 *   as DAT_001a5a16[i].x in the search loop; abs() builtin; local declaration order matters (register spill of 'best').
 */
struct Tim {
    unsigned char pad0[6];
    unsigned short w6, w8;      /* +6, +8 */
    unsigned char b0a, pad0b;   /* +0xa */
    unsigned char b0c, pad0d;   /* +0xc */
    unsigned short we, w10, w12, w14, w16, w18, w1a, w1c, w1e, w20;   /* +0xe..+0x21 */
    unsigned char pad22[4];
    unsigned char b26, pad27;   /* +0x26 */
    unsigned short w28, w2a, w2c;   /* +0x28.. */
    unsigned char pad2e[12];
    unsigned char b3a, pad3b;   /* +0x3a */
    unsigned short w3c;         /* +0x3c */
};
struct Mode {
    unsigned char mul, pad1;    /* +0 */
    unsigned short w2, w4;      /* +2, +4 */
    unsigned char b6, pad7, b8, pad9;
    unsigned short wa, wc, we, w10, w12, w14, w16, w18, w1a, w1c;   /* +0xa..+0x1d */
    unsigned char b1e, b1f;     /* +0x1e, +0x1f */
    unsigned short w20, w22;    /* +0x20, +0x22 */
};
struct Excl { unsigned char id, pad; unsigned short val; };
struct Port {
    unsigned short p15:1, p14:1, p13:1, p12:1, p11:1, p10:1, p9:1, p8:1, p7:1, p6:1, p5:1, plo:5;
    unsigned char pad2[0x14];
    unsigned short w16, w18;
    unsigned char pad1a[0x10];
};
extern struct Port DAT_a802e224[];
extern struct Mode DAT_001a5a16[];
extern struct Excl DAT_001a59e2[];
extern unsigned char DAT_a802cbd3, DAT_a802cbd4;
extern struct Tim *FUN_a013cd4c(unsigned char);
extern void FUN_a01215e8(unsigned char);
extern unsigned char FUN_a0142e8c(unsigned int);
extern unsigned char FUN_a0121258(unsigned char);
extern unsigned char FUN_a01541ec(void *);
extern void FUN_a01542c4(void *);

static unsigned char excluded(unsigned short v)
{
    unsigned char j;
    for (j = 0; j < 13; j++)
        if (DAT_001a59e2[j].id == 12 && DAT_001a59e2[j].val == v)
            return 1;
    return 0;
}

extern int abs(int);
#define ABS(x) abs(x)

static void apply_mode(unsigned char port, unsigned char k)
{
    struct Tim *t2;

    t2 = FUN_a013cd4c(port);
    t2->w12 = DAT_001a5a16[k].we;
    t2->w14 = DAT_001a5a16[k].w10;
    t2->w16 = DAT_001a5a16[k].w12;
    t2->w18 = DAT_001a5a16[k].w14;
    t2->we = DAT_001a5a16[k].wa;
    t2->w1e = DAT_001a5a16[k].w1a;
    t2->w20 = DAT_001a5a16[k].w1c;
    t2->w1a = DAT_001a5a16[k].w16;
    t2->w1c = DAT_001a5a16[k].w18;
    t2->w28 = DAT_001a5a16[k].wa;
    t2->w2a = DAT_001a5a16[k].w16;
    t2->w2c = DAT_001a5a16[k].w18;
    t2->b26 = 0x20;
    t2->b3a = 0;
    t2->w3c = DAT_001a5a16[k].w22;
    if (DAT_001a5a16[k].mul) {
        t2->w16 = t2->w16 * DAT_001a5a16[k].mul;
        t2->we = t2->we * DAT_001a5a16[k].mul;
        t2->w1e = t2->w1e * DAT_001a5a16[k].mul;
        t2->w28 = t2->w28 * DAT_001a5a16[k].mul;
        t2->w2a = t2->w2a * DAT_001a5a16[k].mul;
    }
}

void FUN_a013f370(unsigned char port)
{
    struct Mode *m;
    unsigned short v;
    unsigned short w;
    unsigned char i;
    unsigned char bi3;
    unsigned char bi2;
    unsigned short mind;
    struct Tim *t;
    unsigned char found;
    unsigned char b5;
    int d;
    unsigned int best;
    unsigned short h;
    unsigned int score;

    t = FUN_a013cd4c(port);
    if (DAT_a802e224[port].p10)
        DAT_a802cbd4 |= 1 << port;
    else
        DAT_a802cbd4 &= ~(1 << port);
    if (DAT_a802e224[port].p7)
        DAT_a802cbd3 |= 1 << port;
    else
        DAT_a802cbd3 &= ~(1 << port);
    FUN_a01215e8(port);
    if (FUN_a0142e8c(port) != 5) {
        best = 0xffffffff;
        bi3 = 0;
        bi2 = 0;
        mind = 0xffff;
        b5 = t->b0c;
        found = 0;
        for (i = 0; DAT_001a5a16[i].w2 != 0xffff; i++) {
            if (excluded(DAT_001a5a16[i].w22))
                continue;
            if (FUN_a0121258(port) != (DAT_001a5a16[i].w22 & 1))
                continue;
            if (t->w10 > DAT_001a5a16[i].w10) {
                d = t->w10 - DAT_001a5a16[i].wc;
                if (ABS(d) < mind) {
                    mind = ABS(d);
                    bi3 = i;
                }
            }
            d = t->w6 - DAT_001a5a16[i].w2;
            if (ABS(d) > DAT_001a5a16[i].b1e)
                continue;
            d = t->w8 - DAT_001a5a16[i].w4;
            if (ABS(d) > DAT_001a5a16[i].b1f)
                continue;
            if (FUN_a0142e8c(port) == 2 && !(t->b0a & DAT_001a5a16[i].b6))
                continue;
            w = t->w10;
            if (FUN_a0121258(port) == 1)
                w += w;
            if (DAT_001a5a16[i].w10 >= w)
                continue;
            score = (ABS(t->w6 - DAT_001a5a16[i].w2) + ABS(t->w8 - DAT_001a5a16[i].w4) + ABS(t->w10 - DAT_001a5a16[i].wc) * 4) * 100 + ABS(b5 - DAT_001a5a16[i].b8);
            found = 1;
            if (score < best) {
                best = score;
                bi2 = i;
            }
        }
        if (found == 1) {
            apply_mode(port, bi2);
            if (!FUN_a01541ec(&t->w6))
                FUN_a01542c4(&t->w6);
        } else {
            apply_mode(port, bi3);
            t->w3c = (t->w3c >> 8) | 0xff00;
            if (!FUN_a01541ec(&t->w6))
                FUN_a01542c4(&t->w6);
        }
    } else {
        h = DAT_a802e224[port].w18;
        if (FUN_a0121258(port))
            h *= 2;
        v = DAT_a802e224[port].w16;
        t->w1c = 0x1e0;
        t->w20 = 0x1e0;
        t->w3c = 0xff00;
        t->w16 = v;
        t->w14 = h;
        t->w12 = v;
        t->w18 = h;
        t->w1a = 0;
        t->w1e = 0;
        t->w2a = 0;
        t->w2c = 0x1e0;
        for (i = 0; DAT_001a5a16[i].w2 != 0xffff; i++) {
            m = &DAT_001a5a16[i];
            if ((unsigned int)(v - m->w12 + 5) <= 10 && (unsigned int)(h - m->w14 + 6) <= 12 &&
                (unsigned int)(t->w6 - m->w2 + 9) <= 18 && (unsigned int)(t->w8 - m->w4 + 9) <= 18) {
                t->w12 = m->we;
                t->w14 = m->w10;
                t->w3c = m->w22;
                return;
            }
        }
    }
}
