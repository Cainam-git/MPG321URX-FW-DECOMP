/* FUN_a0070434 (leon2s 0xa0070434-0xa0070704, 720 bytes), flags -mcpu=v8 -Os -g.
 * void (struct Sel *s, unsigned char *d). Takes the low byte of s->port (word +4) and collects eight
 * unsigned short values h0..h7 from getters selected by it:
 *   0, 1: h4 = FUN_a0091094(x) + FUN_a0091008(x) - 1, or - 5 when bit 0 of FUN_a00a657c(x, 0x114) is clear;
 *         h5 = FUN_a009105c + FUN_a0091078, h6 = FUN_a0091008, h7 = FUN_a0091078, h0..h3 = FUN_a0090fd0,
 *         FUN_a0091024, FUN_a0090fec, FUN_a0091040 (argument p = the port byte);
 *   2, 3: with p = port - 2: h0..h3 = FUN_a00a2788, FUN_a00a27f8, FUN_a00a27a4, FUN_a00a2814,
 *         h4 = FUN_a00a2868 + FUN_a00a27c0, h5 = FUN_a00a284c + FUN_a00a2830, h6 = FUN_a00a27c0, h7 = FUN_a00a2830;
 *   6..8: between func_0x9f1c65a0(0, 1) and func_0x9f1c65a0(0, 0), FUN_a00acb40 / acb60 / acac0 / acb00(4) and
 *         FUN_a00a6da8(4, 0x94 / 0x96 / 0x98 / 0x9a) (the last two masked to 15 bits);
 *   other: the same getters with p = port - 4, without the func_0x9f1c65a0 calls.
 * Writes h0..h7 to d[0..15] as little-endian halfwords.
 * Source forms: the 0x9100xx getters are declared without a parameter list (the argument is passed as the
 * promoted int; each getter masks it itself) and FUN_a0091094 with an unsigned short result; p = x is
 * assigned at the start of the first branch; h4 is declared before h3.
 */
struct Sel { unsigned int w0; unsigned int port; };
extern unsigned short FUN_a0091094();
extern unsigned short FUN_a0091008();
extern unsigned int FUN_a00a657c(unsigned int, unsigned short);
extern unsigned short FUN_a009105c();
extern unsigned short FUN_a0091078();
extern unsigned short FUN_a0090fd0();
extern unsigned short FUN_a0091024();
extern unsigned short FUN_a0090fec();
extern unsigned short FUN_a0091040();
extern unsigned short FUN_a00a2788(unsigned int);
extern unsigned short FUN_a00a27f8(unsigned int);
extern unsigned short FUN_a00a27a4(unsigned int);
extern unsigned short FUN_a00a2814(unsigned int);
extern unsigned short FUN_a00a2868(unsigned int);
extern unsigned short FUN_a00a27c0(unsigned int);
extern unsigned short FUN_a00a284c(unsigned int);
extern unsigned short FUN_a00a2830(unsigned int);
extern unsigned short FUN_a00acb40(unsigned int);
extern unsigned short FUN_a00acb60(unsigned int);
extern unsigned short FUN_a00acac0(unsigned int);
extern unsigned short FUN_a00acb00(unsigned int);
extern unsigned short FUN_a00a6da8(unsigned int, unsigned short);
extern void func_0x9f1c65a0(unsigned char, unsigned char);

void FUN_a0070434(struct Sel *s, unsigned char *d)
{
    unsigned short h0, h1, h2, h4, h3, h5, h6, h7;
    unsigned short a;
    unsigned int x;
    unsigned char p;

    x = s->port;
    if ((x & 0xff) <= 1) {
        p = x;
        a = FUN_a0091094(x & 0xff) + FUN_a0091008(x & 0xff);
        h4 = a - 1;
        if (!(FUN_a00a657c(x & 0xff, 0x114) & 1))
            h4 = a - 5;
        h5 = FUN_a009105c(p) + FUN_a0091078(p);
        h6 = FUN_a0091008(p);
        h7 = FUN_a0091078(p);
        h0 = FUN_a0090fd0(p);
        h1 = FUN_a0091024(p);
        h2 = FUN_a0090fec(p);
        h3 = FUN_a0091040(p);
    } else if ((x & 0xff) <= 3) {
        p = x - 2;
        h0 = FUN_a00a2788(p);
        h1 = FUN_a00a27f8(p);
        h2 = FUN_a00a27a4(p);
        h3 = FUN_a00a2814(p);
        h4 = FUN_a00a2868(p) + FUN_a00a27c0(p);
        h5 = FUN_a00a284c(p) + FUN_a00a2830(p);
        h6 = FUN_a00a27c0(p);
        h7 = FUN_a00a2830(p);
    } else if ((unsigned char)(x - 6) <= 2) {
        func_0x9f1c65a0(0, 1);
        h0 = FUN_a00acb40(4);
        h1 = FUN_a00acb60(4);
        h2 = FUN_a00acac0(4);
        h3 = FUN_a00acb00(4);
        h4 = FUN_a00a6da8(4, 0x94);
        h5 = FUN_a00a6da8(4, 0x96);
        h6 = FUN_a00a6da8(4, 0x98) & 0x7fff;
        h7 = FUN_a00a6da8(4, 0x9a) & 0x7fff;
        func_0x9f1c65a0(0, 0);
    } else {
        p = x - 4;
        h0 = FUN_a00acb40(p);
        h1 = FUN_a00acb60(p);
        h2 = FUN_a00acac0(p);
        h3 = FUN_a00acb00(p);
        h4 = FUN_a00a6da8(p, 0x94);
        h5 = FUN_a00a6da8(p, 0x96);
        h6 = FUN_a00a6da8(p, 0x98) & 0x7fff;
        h7 = FUN_a00a6da8(p, 0x9a) & 0x7fff;
    }
    d[0] = h0;
    d[0x1] = h0 >> 8;
    d[0x2] = h1;
    d[0x3] = h1 >> 8;
    d[0x4] = h2;
    d[0x5] = h2 >> 8;
    d[0x6] = h3;
    d[0x7] = h3 >> 8;
    d[0x8] = h4;
    d[0x9] = h4 >> 8;
    d[0xa] = h5;
    d[0xb] = h5 >> 8;
    d[0xc] = h6;
    d[0xd] = h6 >> 8;
    d[0xe] = h7;
    d[0xf] = h7 >> 8;
}
