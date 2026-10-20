/* leon2m FUN_a00b7d14 @ 0xa00b7d14-0xa00b7e68 (85 words), flags -mcpu=v8 -O3 -g.
 * Code facts: twin of FUN_a00b7e68. n = byte DAT_a802d290[0x1df] * 17 (sll 4 + add),
 * n = 100 if that byte > 5; FUN_a00ab5f0(0x2c, 6, (u8)n, 6, p & 0xff); p & 0xff != 0: v = 0x742,
 * FUN_a00a9468(1, 3); else v = 0x792, FUN_a00a9468(1, 2) (u16 v; the fw keeps 'and v, 0x7d2' =
 * nonzero bits of both constants). FUN_a0146a80(0x28/0x2b/0x32, 6, 3/1/1, v, 0) with
 * FUN_a0146b20(0, 0x2b/0x32, 6, 1, 0x3f/0x40, 0) after the 2nd and 3rd; FUN_a0146b50(0xe6, 0);
 * FUN_a01577f4(buf[8] at %fp-16, 0x1981d0, (u8)(DAT_a802d290[0x1df] + 1)); buf[0] = 3;
 * FUN_a0146b6c(2, 0); FUN_a00a31a4(0, 0x28, 6, 2, buf, 0). void, one param.
 * Required forms: real base DAT_a802d290[0x1df]; v is assigned in BOTH arms
 * with the '!= 0' arm first (a default 'v = 0x742' moves the mov into the bleu delay slot: 97.65);
 * the twin's prototypes. Aids: none.
 */
extern unsigned char DAT_a802d290[];
extern void FUN_a0146b50(unsigned int, unsigned char);
extern void FUN_a00ab5f0(unsigned int, unsigned int, unsigned char, unsigned int, unsigned int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a0146a80(unsigned int, unsigned int, unsigned char, unsigned int, unsigned char);
extern void FUN_a0146b20(unsigned int, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);
extern void FUN_a01577f4(unsigned char *, unsigned int, unsigned char);
extern void FUN_a0146b6c(unsigned int, unsigned int);
extern void FUN_a00a31a4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *, unsigned int);

void FUN_a00b7d14(unsigned int p)
{
    unsigned short v;
    unsigned int n;
    unsigned char buf[8];

    n = DAT_a802d290[0x1df] * 17;
    if (DAT_a802d290[0x1df] > 5)
        n = 100;
    FUN_a00ab5f0(0x2c, 6, n, 6, p & 0xff);
    if ((p & 0xff) != 0) {
        v = 0x742;
        FUN_a00a9468(1, 3);
    } else {
        v = 0x792;
        FUN_a00a9468(1, 2);
    }
    FUN_a0146a80(0x28, 6, 3, v, 0);
    FUN_a0146a80(0x2b, 6, 1, v, 0);
    FUN_a0146b20(0, 0x2b, 6, 1, 0x3f, 0);
    FUN_a0146a80(0x32, 6, 1, v, 0);
    FUN_a0146b20(0, 0x32, 6, 1, 0x40, 0);
    FUN_a0146b50(0xe6, 0);
    FUN_a01577f4(buf, 0x1981d0, DAT_a802d290[0x1df] + 1);
    buf[0] = 3;
    FUN_a0146b6c(2, 0);
    FUN_a00a31a4(0, 0x28, 6, 2, buf, 0);
}
