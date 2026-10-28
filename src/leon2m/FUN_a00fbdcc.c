/* leon2m FUN_a00fbdcc @ 0xa00fbdcc-0xa00fbf54 (98 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00fbfd4 and
 * FUN_a00fc044 with three arguments (p, sel, 0); the third one is not read.
 * sel 1: the body of FUN_a00fb9ec (FUN_a00f9a00(), FUN_a00f9bbc(), then FUN_a00fb434(id, &value, DAT_a802d67a,
 * DAT_a802d678) for ids 0xc..0x11 with the stack values 0, 1, 0, 0x80, 0x80, 0x100), result 1; sel 2: the body of
 * FUN_a00fbaa4(DAT_a802b7ef) (bit 31 of the word register 0xd0040000 saved to DAT_a802b7e8 and cleared, or written
 * back from it), result 1; sel 3: FUN_a00fbaf8(p, DAT_a802b7ec); sel 4: FUN_a00fbc80(p, DAT_a802b7eb); other
 * values: 0. Returns the result as an unsigned char value.
 * Source form: FUN_a00fb9ec and FUN_a00fbaa4 are the matched same-file functions, defined here and inlined by GCC;
 * FUN_a00fb9ec is declared inline (GCC 3.4 at -O3 does not inline it otherwise; as a non-static inline function it
 * also keeps its own copy in the image, as the firmware has at 0xa00fb9ec).
 */
#define REG0 (*(volatile unsigned int *)0xd0040000)
extern void FUN_a00f9a00(void);
extern void FUN_a00f9bbc(void);
extern int FUN_a00fb434(unsigned int id, unsigned int *v, unsigned int w, unsigned int h);
extern int FUN_a00fbaf8(unsigned char, unsigned int);
extern int FUN_a00fbc80(unsigned char, unsigned char);
extern unsigned short DAT_a802d678;
extern unsigned short DAT_a802d67a;
extern unsigned char DAT_a802b7e8;
extern unsigned char DAT_a802b7eb;
extern unsigned short DAT_a802b7ec;
extern unsigned char DAT_a802b7ef;

__inline__ int FUN_a00fb9ec(void)
{
    unsigned int v11, v10, vf, ve, vd, vc;
    vf = 0x80;
    vd = 1;
    v10 = 0x80;
    v11 = 0x100;
    vc = 0;
    ve = 0;

    FUN_a00f9a00();
    FUN_a00f9bbc();
    FUN_a00fb434(0xc, &vc, DAT_a802d67a, DAT_a802d678);
    FUN_a00fb434(0xd, &vd, DAT_a802d67a, DAT_a802d678);
    FUN_a00fb434(0xe, &ve, DAT_a802d67a, DAT_a802d678);
    FUN_a00fb434(0xf, &vf, DAT_a802d67a, DAT_a802d678);
    FUN_a00fb434(0x10, &v10, DAT_a802d67a, DAT_a802d678);
    FUN_a00fb434(0x11, &v11, DAT_a802d67a, DAT_a802d678);
    return 1;
}

static void wr(volatile unsigned int *r, unsigned int mask, unsigned int shift, unsigned int val)
{
    *r = (*r & ~mask) | ((val << shift) & mask);
}
int FUN_a00fbaa4(unsigned char c)
{
    if (c) {
        unsigned int v = REG0;
        DAT_a802b7e8 = v >> 31;
        REG0 = v & ~0x80000000u;
    } else
        wr(&REG0, 0x80000000, 31, DAT_a802b7e8);
    return 1;
}

int FUN_a00fbdcc(unsigned int p, unsigned int sel, unsigned int unused)
{
    unsigned char r = 0;

    switch (sel) {
    case 1:
        r = FUN_a00fb9ec();
        break;
    case 2:
        r = FUN_a00fbaa4(DAT_a802b7ef);
        break;
    case 3:
        r = FUN_a00fbaf8(p, DAT_a802b7ec);
        break;
    case 4:
        r = FUN_a00fbc80(p, DAT_a802b7eb);
        break;
    }
    return r;
}
