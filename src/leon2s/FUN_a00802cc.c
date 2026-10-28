/* leon2s FUN_a00802cc @ 0xa00802cc-0xa0080494, flags -mcpu=v8 -Os -g.
 * For port p (low byte 2 -> k = 0, 3 -> k = 1, else return) and lane mask m (0 -> return), two passes over
 * i < ARR_a807d680[k][0] for each set bit i <= 3 of m:
 *   first pass: a = DAT_a00b3b70[i]; FUN_a00a7424(0, 0x10, p, a), FUN_a00a7424(1, 4, p, DAT_a00b3b10[i]),
 *   FUN_a00a7424(0, 0, p, a), FUN_a00a7424(1, 0x11, p, a), FUN_a00a7488(p, DAT_a00b3b18[i], 0xff0000f0,
 *   (b[i] & 0xf) | (c[i] << 8)). Then FUN_a007f900(p, m); second pass: FUN_a00a7424(1, 0, p, DAT_a00b3b70[i]),
 *   FUN_a00a7424(0, 4, p, DAT_a00b3b10[i]).
 * Source form: unsigned int parameter p; the port test and the calls of one pass take the low byte of p in
 *   different spellings (p & 0xff, (char)p & 0xff, (unsigned short)p & 0xff, (unsigned char)p,
 *   (p << 24) >> 24, p - p / 256 * 256); equal spellings are merged into one register by GCC, the firmware
 *   masks %i0 again for every use.
 */
extern unsigned char ARR_a807d680[][0xb0];
extern unsigned short DAT_a00b3b10[4];
extern unsigned short DAT_a00b3b18[4];
extern unsigned short DAT_a00b3b70[4];
extern void FUN_a00a7424(int mode, unsigned int bit, unsigned int reg, unsigned short val);
extern void FUN_a00a7488(unsigned int param_1, unsigned short param_2, unsigned int param_3, unsigned int param_4);
extern void FUN_a007f900(unsigned char, unsigned char);

void FUN_a00802cc(unsigned int p, unsigned char mask, unsigned char *b, unsigned short *c)
{
    unsigned char k;
    unsigned char i;
    unsigned short a;

    if ((p & 0xff) == 2)
        k = 0;
    else if ((p & 0xff) == 3)
        k = 1;
    else
        return;
    if (mask == 0)
        return;
    for (i = 0; i < ARR_a807d680[k][0]; i++) {
        if ((mask >> i) & 1)
        if (i <= 3) {
            a = DAT_a00b3b70[i];
            FUN_a00a7424(0, 0x10, (char)p & 0xff, a);
            FUN_a00a7424(1, 4, (unsigned short)p & 0xff, DAT_a00b3b10[i]);
            FUN_a00a7424(0, 0, (unsigned char)p, a);
            FUN_a00a7424(1, 0x11, (p << 24) >> 24, a);
            FUN_a00a7488(p - p / 256 * 256, DAT_a00b3b18[i], 0xff0000f0, (b[i] & 0xf) | (c[i] << 8));
        }
    }
    FUN_a007f900((char)p & 0xff, mask);
    for (i = 0; i < ARR_a807d680[k][0]; i++) {
        if ((mask >> i) & 1)
        if (i <= 3) {
            FUN_a00a7424(1, 0, (char)p & 0xff, DAT_a00b3b70[i]);
            FUN_a00a7424(0, 4, (unsigned short)p & 0xff, DAT_a00b3b10[i]);
        }
    }
}
