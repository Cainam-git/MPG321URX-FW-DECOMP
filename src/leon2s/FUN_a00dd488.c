/*
 * FUN_a00dd488 (leon2s 0xa00dd488-0xa00de8a8, 5152 bytes), flags -mcpu=v8 -Os -g.
 * void (void). Called by FUN_a00de8ac. Reads the record DAT_a8079538 (format byte +7: 0 DSC_RGB, 3 DSC_YUV444,
 * 4 DSC_YUV422_SIMPLE, 1 DSC_YUV422, 2 DSC_YUV420; +0x1a divisor of the bits per pixel; +4 bit depth 8/10/12;
 * halfwords +0xa (w) and +0x12 (h) printed as DSC_ENC_Timing_%dx%d; +0x19 slice count s, printed as SLICE),
 * prints the names, computes sw = ceil(w / s), bpp (24, 16 or 12 / divisor, doubled for formats 1 and 2, printed
 * as BPP), chunk = ceil(bpp * sw' / 8) and (sw' + 2) / 3 (sw' = sw, halved for formats 1 and 2), h / 10, the
 * values 0x800..0x1800 chosen by bpp, (0x2000 / bpp + 1) >> 1, 0x10000 / (0x2000 - value), and the further
 * words below from them; packs them into the 27 words DAT_a807955c[0..26] (words 11..14 hold the fixed values
 * 0x0e1c2a38, 0x46546269, 0x7077797b, 0x7d7e0000; words 14..21 add the 15 range entries (min << 11) +
 * (max << 6) + offset from the 15-byte rows of the tables at 0x9f1cea6f..0x9f1cec08, row by bit depth, or for
 * format 1 by temp_idx / Ofs_422_idx, printed), copies words 0..23 to 0xc0110000.., 24 and 25 to 0xc0110060 /
 * 0xc0110064 (bit 9 set when func_0xa0f9d800() > 0x83), 26 to 0xc011009c, and prints all 27 words as %08lX.
 * Source form: slice width ceil as 'sw = W / slices; if (W % slices) sw++;'; the doubling of bpp and the halving
 * of the width go through int temporaries; fl = f17 is assigned right before the rate computation.
 * Source form: each print call is shared by its arms (the flags are set before the call); the format 2 branch
 * adds the two 16-bit range entries of a word without the << 16 of the upper one; upper halves are unsigned
 * terms, lower halves int terms.
 * Source form: the copy loop (k, fw %o3 at 0xa00de7d4..) and the print loop (j, fw %l4 at 0xa00de850..) use two
 * counters; j is initialised in its declaration ('j = 0', overwritten by its loop before any read), which keeps
 * the arm stores of the format flags (fw 0xa00dd530, 0xa00dd538, 0xa00dd5a0, 0xa00dd5e0). rgb and s422 are also
 * initialised in their declarations; the explicit stores then give the fw copies 'mov %l4,%i2' (0xa00dd4dc) and
 * 'stb %l4,[%fp-61]' (0xa00dd4fc).
 * Source form: groups_per_line is computed before the chunk size, as in the reference model ('groups = (sw2 + 2)
 * / 3; bits = bpp * sw2; chunk = bits / 8; if (bits & 7) chunk++;'; fw sw2 %o3 / chunk quotient %o2 at
 * 0xa00dd6c4..).
 * Source form: x accumulates the rbsMin terms one statement each ('x = scale * bpp; gf = groups * fl; x += gf; m
 * = 0x2000 - u23; x += m;', fw adds at 0xa00dd930 / 0xa00dd934); m is its own signed local, so fs = 0x10000 / m
 * after the nfl ceil is a signed sdiv by the kept register (0xa00dd9b8); the slice offset recomputes 'x2 =
 * 0x2000 - u23; x2 += ofs2;' (0xa00dda78).
 * Source form: reference-model names and ceils: 'hrd = x / bpp; if (x % bpp) hrd++; sdi = hrd - scale;' (fw addx
 * before the sub at 0xa00dd984 / 0xa00dd9bc), 'gt = groups * sh;' before the mux-bit chain (fw smul in the delay
 * slot at 0xa00dd9e0); the final offset shift is unsigned (fw srl at 0xa00ddab8) and the offset is added in its
 * own statement ('fo = 0x2000 - tmp; fo += ofs2;', fw sub then add at 0xa00ddabc).
 * Source form: one unsigned int temporary tmp holds the shifted numerators of both offset ceils ('tmp = fl <<
 * 11; idi = tmp / (sh - 1); if (tmp % (sh - 1)) idi++;', 'tmp = x2 << 11;' for iofs), the final-offset product
 * ('tmp = bpp << 4; tmp = (scale * tmp) >> 4;') and the word 5 divisor (fw %i5 at 0xa00dd960, 0xa00dda80,
 * 0xa00ddab0 / 0xa00ddab8, 0xa00ddb08).
 * Source form: the two RC intervals are their own values in the reference-model order right after the word 5
 * divisor ('sdec = groups / (fs - 8);' scale_decrement_interval, 'sinc = (fofs << 11) / tmp;'
 * scale_increment_interval); word 5 = '(fs << 16) + sinc', word 6 = '(sdec << 16) + fl'.
 * Source form: the range tables are block-scope static const arrays in the ROM order (ofs_444, the three 422
 * offset rows, ofs_420, then the max / min qp tables for 444, 422, 420); the fw never addresses 0x9f1cea60 /
 * 0x9f1ceaa0 (only ea6f, eaaf, eadc, eb45, eb72, eb9f, ec08): these two offset tables are read with constant
 * indexes and become immediates. Word 10 is built in a temporary ('w10 = q3 << 16; w10 += 0x6000000; w10 += q4
 * << 8; w10 += 0x33;', fw 0xa00ddb24 / 0xa00ddc30).
 * Source form: the words are stored in index order 0..14 except that word 7 (nfl_bpg_offset, slice_bpg_offset)
 * is written before word 5, whose divisor uses both, and the word 11 constant before the w10 temporary block;
 * the emitted store sequence equals the fw (7, 11, 12 hoisted from 0xa00ddbf0, word 0 at 0xa00ddc40, then 1..6,
 * 8..14).
 * Source form: the slice bits 'a * 8' are written at each use in both word 26 ceils ('cc = a * 8 / 192 + (a * 8
 * % 192 != 0); mm = a * 8 / mux + (a * 8 % mux != 0);'; fw a / 24 by one smul at 0xa00de740).
 * Source form: words 22, 23, 24 are written in index order like words 0..14 (the scheduler still issues word 24
 * first, fw 0xa00de6a0).
 * Source form: values shifted into the top bits are cast to unsigned int first (same code).
 * Source form: 'nsl = slices == 16 ? 15 : slices;' (the ?: join ends the cse path: fw rebuilds the DAT_a807955c
 * low part for words 25 / 26 at 0xa00de7c0); word 26 adds the shifted term first (fw add order at 0xa00de7bc).
 */
struct G {
    unsigned int f;
    unsigned char b4, b5, b6, b7;
    unsigned short h[8];
    unsigned char b18, b19, b1a, b1b;
    unsigned int w1c;
    unsigned int w20;
};
extern struct G DAT_a8079538;
extern unsigned int DAT_a807955c[27];
extern const char s_9f1cca78[];
extern const char s_9f1ced30[];
extern const char s_9f1ced48[];
extern const char s_9f1ced60[];
extern const char s_9f1ced80[];
extern const char s_9f1ced98[];
extern const char s_9f1cedb0[];
extern const char s_9f1cedd8[];
extern const char s_9f1cedf0[];
extern const char s_9f1cee08[];
extern const char s_9f1cee20[];
extern const char s_9f1cee40[];
extern const char s_9f1cee60[];
extern const char s_9f1cee88[];
extern const char s_9f1cee90[];
extern const char s_9f1cee98[];
extern int func_0xa0f83044(const char *, ...);
extern int func_0xa0f834c4(const char *);
extern unsigned char func_0xa0f9d800(void);


#define REG(o) (*(volatile unsigned int *)(0xc0110000 | (o)))

void FUN_a00dd488(void)
{
    static const signed char ofs_444[15] = { 2, 0, 0, -2, -4, -6, -8, -8, -8, -10, -10, -10, -12, -12, -12 };
    static const signed char DAT_9f1cea6f[3][15] = {
        { 2, 0, 0, -2, -4, -6, -8, -8, -8, -10, -10, -10, -12, -12, -12 },
        { 6, 4, 3, 1, -1, -3, -5, -6, -7, -9, -10, -10, -12, -12, -12 },
        { 10, 8, 6, 4, 2, 0, -2, -4, -6, -8, -10, -10, -12, -12, -12 }
    };
    static const signed char ofs_420[15] = { 2, 0, 0, -2, -4, -6, -8, -8, -8, -10, -10, -10, -12, -12, -12 };
    static const unsigned char DAT_9f1ceaaf[3][15] = {
        { 2, 3, 4, 5, 6, 6, 7, 8, 8, 9, 9, 9, 9, 10, 11 },
        { 4, 6, 8, 9, 10, 10, 11, 12, 12, 13, 13, 13, 13, 14, 15 },
        { 11, 12, 13, 14, 15, 15, 15, 16, 17, 17, 18, 18, 19, 19, 21 }
    };
    static const unsigned char DAT_9f1ceadc[7][15] = {
        { 2, 4, 5, 6, 7, 7, 7, 8, 8, 9, 9, 9, 9, 10, 11 },
        { 1, 2, 3, 4, 5, 5, 5, 6, 6, 7, 7, 8, 8, 9, 10 },
        { 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7 },
        { 4, 6, 7, 9, 10, 11, 11, 12, 12, 13, 13, 13, 13, 14, 15 },
        { 3, 4, 5, 7, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 14 },
        { 2, 3, 3, 5, 5, 5, 7, 7, 8, 8, 9, 9, 10, 10, 11 },
        { 6, 9, 10, 12, 14, 15, 15, 16, 16, 17, 17, 17, 17, 18, 19 }
    };
    static const unsigned char DAT_9f1ceb45[3][15] = {
        { 2, 4, 5, 6, 7, 7, 7, 8, 8, 9, 9, 9, 9, 10, 11 },
        { 4, 6, 8, 9, 10, 10, 11, 12, 12, 13, 13, 13, 13, 14, 15 },
        { 6, 9, 11, 12, 13, 14, 15, 16, 16, 17, 17, 17, 17, 18, 19 }
    };
    static const unsigned char DAT_9f1ceb72[3][15] = {
        { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 10 },
        { 0, 2, 4, 4, 6, 6, 7, 7, 7, 7, 9, 9, 9, 11, 14 },
        { 0, 4, 8, 9, 11, 11, 11, 11, 11, 11, 13, 13, 13, 15, 20 }
    };
    static const unsigned char DAT_9f1ceb9f[7][15] = {
        { 0, 0, 1, 2, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 10 },
        { 0, 0, 0, 1, 2, 2, 2, 2, 2, 3, 4, 5, 5, 7, 9 },
        { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 4, 5, 5, 6 },
        { 0, 2, 3, 5, 5, 6, 6, 7, 7, 7, 8, 8, 9, 11, 14 },
        { 0, 2, 3, 4, 5, 5, 5, 6, 6, 7, 8, 8, 9, 11, 13 },
        { 0, 2, 2, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 9, 10 },
        { 0, 4, 7, 8, 10, 11, 11, 11, 11, 11, 13, 13, 13, 15, 18 }
    };
    static const unsigned char DAT_9f1cec08[3][15] = {
        { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 10 },
        { 0, 2, 3, 4, 6, 7, 7, 7, 7, 7, 9, 9, 9, 11, 14 },
        { 0, 4, 7, 8, 10, 11, 11, 11, 11, 11, 13, 13, 13, 15, 18 }
    };
    unsigned short bpp16;
    unsigned short sw2;
    unsigned int rem;
    unsigned char f25;
    unsigned char q1;
    unsigned char fs;
    unsigned char q2;
    unsigned short q5;
    unsigned int sdi;
    unsigned short scale;
    unsigned short sh;
    unsigned char mux;
    unsigned int ofs;
    unsigned int ofs2;
    unsigned int iofs;
    unsigned char s422 = 0;
    unsigned int groups;
    int a;
    unsigned char d;
    unsigned char nsl;
    unsigned char o;
    unsigned short g3;
    unsigned short bpp;
    unsigned short W;
    unsigned short u23;
    int mm;
    unsigned char k;
    unsigned char j = 0;
    unsigned char r3;
    int bits;
    unsigned char t;
    unsigned char ratio;
    unsigned char fmt;
    unsigned int idi;
    int cc;
    int b;
    unsigned int x25;
    unsigned char slices;
    unsigned int fl;
    unsigned char f17;
    unsigned char n420;
    unsigned char c;
    unsigned short H;
    unsigned short sw;
    unsigned short fofs;
    unsigned short chunk;
    unsigned char q3;
    unsigned char q4;
    unsigned char n422;
    unsigned char rgb = 0;
    unsigned int fo;
    unsigned char depth;
    unsigned int x;
    unsigned int gf;
    unsigned int gt;
    unsigned int hrd;
    unsigned int x2;
    int m;
    unsigned int sdec;
    unsigned int sinc;
    unsigned int w10;
    unsigned int tmp;

    fmt = DAT_a8079538.b7;
    depth = DAT_a8079538.b4;
    H = DAT_a8079538.h[5];
    W = DAT_a8079538.h[1];
    slices = DAT_a8079538.b19;
    ratio = DAT_a8079538.b1a;
    func_0xa0f834c4(s_9f1cca78);
    n420 = 0;
    rgb = 0;
    bpp = 0;
    u23 = 0;
    n422 = 0;
    o = 0;
    t = 0;
    s422 = 0;
    if (fmt == 0 || fmt == 3 || fmt == 4) {
        bpp = 24 / ratio;
        n420 = 0;
        n422 = 0;
        if (fmt == 0) {
            rgb = 1;
            func_0xa0f83044(s_9f1ced30);
        } else if (fmt == 3) {
            func_0xa0f83044(s_9f1ced48);
        } else {
            s422 = 1;
            func_0xa0f83044(s_9f1ced60);
        }
    } else if (fmt == 1) {
        bpp = 16 / ratio;
        n420 = 0;
        n422 = 1;
        func_0xa0f83044(s_9f1ced80);
    } else if (fmt == 2) {
        bpp = 12 / ratio;
        n420 = 1;
        n422 = 0;
        func_0xa0f83044(s_9f1ced98);
    }
    func_0xa0f83044(s_9f1cedb0, W, H);
    func_0xa0f83044(s_9f1cedd8, slices);
    sw = W / slices;
    if (W % slices)
        sw++;
    sh = H / 10;
    c = n420 | n422;
    {
        int b2 = bpp;
        if (c)
            b2 += b2;
        bpp = b2;
    }
    bpp16 = bpp << 4;
    func_0xa0f83044(s_9f1cedf0, bpp);
    {
        int s2 = sw;
        if (c)
            s2 >>= 1;
        sw2 = s2;
    }
    groups = (sw2 + 2) / 3;
    bits = bpp * sw2;
    chunk = bits / 8;
    if (bits & 7)
        chunk++;
    if (sh > 7) {
        f25 = fmt == 2 ? 12 : 0;
        f17 = 15;
    } else {
        f17 = 0;
        f25 = 0;
    }
    if (depth == 8) {
        q1 = 3; q2 = 12; q5 = 2; q3 = 11; q4 = 11; mux = 0x30; d = 0;
        func_0xa0f83044(s_9f1cee08);
    } else if (depth == 10) {
        q1 = 7; q2 = 16; q5 = 8; q3 = 15; q4 = 15; mux = 0x30; d = 1;
        func_0xa0f83044(s_9f1cee20);
    } else if (depth == 12) {
        q1 = 11; q2 = 20; q5 = 0x20; q3 = 19; q4 = 19; mux = 0x40; d = 2;
        func_0xa0f83044(s_9f1cee40);
    } else {
        q1 = 3; q2 = 12; q5 = 2; q3 = 11; q4 = 11; mux = 0x30; d = 0;
    }
    if (n422) {
        if (bpp > 15)
            u23 = 0x800;
        else if (bpp > 13)
            u23 = 5632 - (bpp - 14) * 1792;
        else if (bpp > 11)
            u23 = 0x1600;
    } else {
        if (bpp > 11)
            u23 = 0x800;
        else if (bpp > 9)
            u23 = 5632 - (bpp - 10) * 1792;
        else if (bpp > 7)
            u23 = 6144 - (bpp - 8) * 256;
        else if (bpp > 5)
            u23 = 0x1800;
    }
    fl = f17;
    scale = (unsigned int)(0x2000 / bpp + 1) >> 1;
    x = scale * bpp;
    gf = groups * fl;
    x += gf;
    m = 0x2000 - u23;
    x += m;
    hrd = x / bpp;
    if (x % bpp)
        hrd++;
    sdi = hrd - scale;
    b = chunk * sh * 8;
    gt = groups * sh;
    tmp = fl << 11;
    idi = tmp / (sh - 1);
    if (tmp % (sh - 1))
        idi++;
    fs = 0x10000 / m;
    if (rgb)
        ofs = 3 * (mux + (4 * depth + 4) - 2);
    else if (!n422)
        ofs = 3 * mux + (4 * depth + 4) + 2 * (4 * depth) - 2;
    else
        ofs = 4 * mux + (4 * depth + 4) + 3 * (4 * depth) - 2;
    rem = (b - ofs) % mux;
    ofs2 = ofs - (mux - rem);
    x2 = 0x2000 - u23;
    x2 += ofs2;
    tmp = x2 << 11;
    iofs = tmp / gt;
    if (tmp % gt)
        iofs++;
    tmp = bpp << 4;
    tmp = (scale * tmp) >> 4;
    fo = 0x2000 - tmp;
    fo += ofs2;
    fofs = fo;
    tmp = (0x10000 / (0x2000 - fo) - 9) * (idi + iofs);
    sdec = groups / (fs - 8);
    sinc = (fofs << 11) / tmp;
    DAT_a807955c[0] = depth * 17 + 0x12000001;
    DAT_a807955c[1] = ((unsigned int)rgb << 28) + ((unsigned int)s422 << 27) + ((unsigned int)bpp16 << 16) + H + 0x20000000;
    DAT_a807955c[2] = ((unsigned int)W << 16) + sh;
    DAT_a807955c[3] = ((unsigned int)sw << 16) + chunk;
    DAT_a807955c[4] = ((unsigned int)scale << 16) + sdi;
    DAT_a807955c[7] = (idi << 16) + iofs;
    DAT_a807955c[5] = (fs << 16) + sinc;
    DAT_a807955c[6] = (sdec << 16) + fl;
    DAT_a807955c[8] = ((unsigned int)u23 << 16) + fofs;
    DAT_a807955c[9] = ((unsigned int)q1 << 24) + (q2 << 16) + 0x2000;
    DAT_a807955c[11] = 0x0e1c2a38;
    w10 = q3 << 16;
    w10 += 0x6000000;
    w10 += q4 << 8;
    w10 += 0x33;
    DAT_a807955c[10] = w10;
    DAT_a807955c[12] = 0x46546269;
    DAT_a807955c[13] = 0x7077797b;
    DAT_a807955c[14] = 0x7d7e0000;
    if (fmt == 2) {
        DAT_a807955c[14] += ((DAT_9f1cec08[d][0] << 11) + (DAT_9f1ceb45[d][0] << 6) + (ofs_420[0] & 0x3f));
        DAT_a807955c[15] = ((DAT_9f1cec08[d][1] << 11) + (DAT_9f1ceb45[d][1] << 6) + (ofs_420[1] & 0x3f))
                         + ((DAT_9f1cec08[d][2] << 11) + (DAT_9f1ceb45[d][2] << 6) + (ofs_420[2] & 0x3f));
        DAT_a807955c[16] = ((DAT_9f1cec08[d][3] << 11) + (DAT_9f1ceb45[d][3] << 6) + (ofs_420[3] & 0x3f))
                         + ((DAT_9f1cec08[d][4] << 11) + (DAT_9f1ceb45[d][4] << 6) + (ofs_420[4] & 0x3f));
        DAT_a807955c[17] = ((DAT_9f1cec08[d][5] << 11) + (DAT_9f1ceb45[d][5] << 6) + (ofs_420[5] & 0x3f))
                         + ((DAT_9f1cec08[d][6] << 11) + (DAT_9f1ceb45[d][6] << 6) + (ofs_420[6] & 0x3f));
        DAT_a807955c[18] = ((DAT_9f1cec08[d][7] << 11) + (DAT_9f1ceb45[d][7] << 6) + (ofs_420[7] & 0x3f))
                         + ((DAT_9f1cec08[d][8] << 11) + (DAT_9f1ceb45[d][8] << 6) + (ofs_420[8] & 0x3f));
        DAT_a807955c[19] = ((DAT_9f1cec08[d][9] << 11) + (DAT_9f1ceb45[d][9] << 6) + (ofs_420[9] & 0x3f))
                         + ((DAT_9f1cec08[d][10] << 11) + (DAT_9f1ceb45[d][10] << 6) + (ofs_420[10] & 0x3f));
        DAT_a807955c[20] = ((DAT_9f1cec08[d][11] << 11) + (DAT_9f1ceb45[d][11] << 6) + (ofs_420[11] & 0x3f))
                         + ((DAT_9f1cec08[d][12] << 11) + (DAT_9f1ceb45[d][12] << 6) + (ofs_420[12] & 0x3f));
        DAT_a807955c[21] = ((DAT_9f1cec08[d][13] << 11) + (DAT_9f1ceb45[d][13] << 6) + (ofs_420[13] & 0x3f))
                         + ((DAT_9f1cec08[d][14] << 11) + (DAT_9f1ceb45[d][14] << 6) + (ofs_420[14] & 0x3f));
        n420 = 1;
        n422 = 0;
    } else if (fmt == 1) {
        if (d == 0) {
            t = 0; o = 0;
            if (bpp != 8) {
                t = 1; o = 1;
                if (bpp != 9) {
                    t = 2; o = 2;
                }
            }
        } else if (d == 1) {
            t = 3; o = 0;
            if (bpp != 8) {
                t = 4; o = 1;
                if (bpp != 9) {
                    t = 5; o = 2;
                }
            }
        } else if (d == 2) {
            t = 6; o = 0;
        }
        func_0xa0f83044(s_9f1cee60, t, o);
        DAT_a807955c[14] += ((DAT_9f1ceb9f[t][0] << 11) + (DAT_9f1ceadc[t][0] << 6) + (DAT_9f1cea6f[o][0] & 0x3f));
        DAT_a807955c[15] = (((unsigned int)DAT_9f1ceb9f[t][1] << 27) + ((unsigned int)DAT_9f1ceadc[t][1] << 22) + ((unsigned int)(DAT_9f1cea6f[o][1] & 0x3f) << 16))
                         + ((DAT_9f1ceb9f[t][2] << 11) + (DAT_9f1ceadc[t][2] << 6) + (DAT_9f1cea6f[o][2] & 0x3f));
        DAT_a807955c[16] = (((unsigned int)DAT_9f1ceb9f[t][3] << 27) + ((unsigned int)DAT_9f1ceadc[t][3] << 22) + ((unsigned int)(DAT_9f1cea6f[o][3] & 0x3f) << 16))
                         + ((DAT_9f1ceb9f[t][4] << 11) + (DAT_9f1ceadc[t][4] << 6) + (DAT_9f1cea6f[o][4] & 0x3f));
        DAT_a807955c[17] = (((unsigned int)DAT_9f1ceb9f[t][5] << 27) + ((unsigned int)DAT_9f1ceadc[t][5] << 22) + ((unsigned int)(DAT_9f1cea6f[o][5] & 0x3f) << 16))
                         + ((DAT_9f1ceb9f[t][6] << 11) + (DAT_9f1ceadc[t][6] << 6) + (DAT_9f1cea6f[o][6] & 0x3f));
        DAT_a807955c[18] = (((unsigned int)DAT_9f1ceb9f[t][7] << 27) + ((unsigned int)DAT_9f1ceadc[t][7] << 22) + ((unsigned int)(DAT_9f1cea6f[o][7] & 0x3f) << 16))
                         + ((DAT_9f1ceb9f[t][8] << 11) + (DAT_9f1ceadc[t][8] << 6) + (DAT_9f1cea6f[o][8] & 0x3f));
        DAT_a807955c[19] = (((unsigned int)DAT_9f1ceb9f[t][9] << 27) + ((unsigned int)DAT_9f1ceadc[t][9] << 22) + ((unsigned int)(DAT_9f1cea6f[o][9] & 0x3f) << 16))
                         + ((DAT_9f1ceb9f[t][10] << 11) + (DAT_9f1ceadc[t][10] << 6) + (DAT_9f1cea6f[o][10] & 0x3f));
        DAT_a807955c[20] = (((unsigned int)DAT_9f1ceb9f[t][11] << 27) + ((unsigned int)DAT_9f1ceadc[t][11] << 22) + ((unsigned int)(DAT_9f1cea6f[o][11] & 0x3f) << 16))
                         + ((DAT_9f1ceb9f[t][12] << 11) + (DAT_9f1ceadc[t][12] << 6) + (DAT_9f1cea6f[o][12] & 0x3f));
        DAT_a807955c[21] = (((unsigned int)DAT_9f1ceb9f[t][13] << 27) + ((unsigned int)DAT_9f1ceadc[t][13] << 22) + ((unsigned int)(DAT_9f1cea6f[o][13] & 0x3f) << 16))
                         + ((DAT_9f1ceb9f[t][14] << 11) + (DAT_9f1ceadc[t][14] << 6) + (DAT_9f1cea6f[o][14] & 0x3f));
        n420 = 0;
        n422 = 1;
    } else {
        DAT_a807955c[14] += ((DAT_9f1ceb72[d][0] << 11) + (DAT_9f1ceaaf[d][0] << 6) + (ofs_444[0] & 0x3f));
        DAT_a807955c[15] = (((unsigned int)DAT_9f1ceb72[d][1] << 27) + ((unsigned int)DAT_9f1ceaaf[d][1] << 22) + ((unsigned int)(ofs_444[1] & 0x3f) << 16))
                         + ((DAT_9f1ceb72[d][2] << 11) + (DAT_9f1ceaaf[d][2] << 6) + (ofs_444[2] & 0x3f));
        DAT_a807955c[16] = (((unsigned int)DAT_9f1ceb72[d][3] << 27) + ((unsigned int)DAT_9f1ceaaf[d][3] << 22) + ((unsigned int)(ofs_444[3] & 0x3f) << 16))
                         + ((DAT_9f1ceb72[d][4] << 11) + (DAT_9f1ceaaf[d][4] << 6) + (ofs_444[4] & 0x3f));
        DAT_a807955c[17] = (((unsigned int)DAT_9f1ceb72[d][5] << 27) + ((unsigned int)DAT_9f1ceaaf[d][5] << 22) + ((unsigned int)(ofs_444[5] & 0x3f) << 16))
                         + ((DAT_9f1ceb72[d][6] << 11) + (DAT_9f1ceaaf[d][6] << 6) + (ofs_444[6] & 0x3f));
        DAT_a807955c[18] = (((unsigned int)DAT_9f1ceb72[d][7] << 27) + ((unsigned int)DAT_9f1ceaaf[d][7] << 22) + ((unsigned int)(ofs_444[7] & 0x3f) << 16))
                         + ((DAT_9f1ceb72[d][8] << 11) + (DAT_9f1ceaaf[d][8] << 6) + (ofs_444[8] & 0x3f));
        DAT_a807955c[19] = (((unsigned int)DAT_9f1ceb72[d][9] << 27) + ((unsigned int)DAT_9f1ceaaf[d][9] << 22) + ((unsigned int)(ofs_444[9] & 0x3f) << 16))
                         + ((DAT_9f1ceb72[d][10] << 11) + (DAT_9f1ceaaf[d][10] << 6) + (ofs_444[10] & 0x3f));
        DAT_a807955c[20] = (((unsigned int)DAT_9f1ceb72[d][11] << 27) + ((unsigned int)DAT_9f1ceaaf[d][11] << 22) + ((unsigned int)(ofs_444[11] & 0x3f) << 16))
                         + ((DAT_9f1ceb72[d][12] << 11) + (DAT_9f1ceaaf[d][12] << 6) + (ofs_444[12] & 0x3f));
        DAT_a807955c[21] = (((unsigned int)DAT_9f1ceb72[d][13] << 27) + ((unsigned int)DAT_9f1ceaaf[d][13] << 22) + ((unsigned int)(ofs_444[13] & 0x3f) << 16))
                         + ((DAT_9f1ceb72[d][14] << 11) + (DAT_9f1ceaaf[d][14] << 6) + (ofs_444[14] & 0x3f));
        n420 = 0;
        n422 = 0;
    }
    DAT_a807955c[22] = ((unsigned int)n420 << 25) + ((unsigned int)n422 << 24) + (f25 << 16);
    DAT_a807955c[23] = 0;
    DAT_a807955c[24] = q5 + 0x800;
    nsl = slices == 16 ? 15 : slices;
    g3 = sw2 / 3;
    r3 = sw2 % 3;
    if (r3)
        g3++;
    a = chunk * sh;
    x25 = ((r3 & 3) << 28) + 0x40000000;
    DAT_a807955c[25] = x25 + ((g3 & 0x7ff) << 16) + (nsl & 0xf);
    cc = a * 8 / 192 + (a * 8 % 192 != 0);
    mm = a * 8 / mux + (a * 8 % mux != 0);
    DAT_a807955c[26] = ((unsigned int)(cc * 4 - mm) << 29) + (cc & 0x1fffffff);
    for (k = 0; k < 24; k++)
        REG(k << 2) = DAT_a807955c[k];
    REG(0x60) = DAT_a807955c[24];
    REG(0x64) = DAT_a807955c[25];
    if (func_0xa0f9d800() > 0x83)
        REG(0x64) |= 0x200;
    REG(0x9c) = DAT_a807955c[26];
    for (j = 0; j < 27; j++) {
        if ((j & 3) == 0)
            func_0xa0f83044(s_9f1cee88);
        func_0xa0f83044(s_9f1cee90, DAT_a807955c[j]);
    }
    func_0xa0f83044(s_9f1cee98);
}
