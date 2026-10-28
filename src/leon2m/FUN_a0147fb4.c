/* leon2m FUN_a0147fb4 @ 0xa0147fb4-0xa0148120 (91 words), flags -mcpu=v8 -O3 -g.
 * Scans the byte string s for at most 45 positions; last = the position of the terminating 0, otherwise the
 * position 0x2c when it is reached. ch = FUN_a0124168(), FUN_a0124174() is called; while register 0xcf000000 +
 * 4 * (2 * ch + 0xf190) reads 0x96: FUN_a01238e8(), func_0x4008ced8() and FUN_a0123c80(s, last); when that returns
 * 1, 0x46 is written to register 2 * ch + 0xf191, the function calls func_0x4008ced8() until that register no
 * longer reads 0x46, then returns 3 when register 2 * ch + 0xf190 reads 0x9c, else FUN_a0147d70(). Returns 4 when
 * the first register stops reading 0x96. Variant of the next function, FUN_a0148120. No direct callers were found.
 * Source form: as in FUN_a0148120, last is copied through an unsigned int into the dead loop index
 * (n = last; i = n;) before the calls.
 */
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

extern unsigned char FUN_a0124168(void);
extern unsigned char *FUN_a0124174(void);
extern void FUN_a01238e8(void);
extern void func_0x4008ced8(void);
extern unsigned char FUN_a0123c80(const unsigned char *s, unsigned char n);
extern int FUN_a0147d70(void);

unsigned char FUN_a0147fb4(const unsigned char *s)
{
    unsigned char i, last = 0, ch;
    unsigned int n;

    for (i = 0; i <= 0x2c; i++) {
        if (s[i] == 0) {
            last = i;
            break;
        }
        if (i == ',')
            last = i;
    }
    n = last;
    i = n;
    ch = FUN_a0124168();
    FUN_a0124174();
    if (RB(ch * 2 + 0xf190) == 0x96) {
        do {
            FUN_a01238e8();
            func_0x4008ced8();
            if (FUN_a0123c80(s, i) == 1) {
                RB(ch * 2 + 0xf191) = 0x46;
                while (RB(ch * 2 + 0xf191) == 0x46)
                    func_0x4008ced8();
                if (RB(ch * 2 + 0xf190) == 0x9c)
                    return 3;
                return FUN_a0147d70();
            }
        } while (RB(ch * 2 + 0xf190) == 0x96);
    }
    return 4;
}
