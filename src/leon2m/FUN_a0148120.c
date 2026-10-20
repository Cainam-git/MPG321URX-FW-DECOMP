/* FUN_a0148120: scans the byte string s for at most 45 positions; last = the position of the terminating 0,
 * otherwise the position 0x2c when it is reached (the loop compares the index, not the character, with 0x2c).
 * ch = FUN_a0124168() (byte DAT_a802d87e), FUN_a0124174() is called; while register 0xcf000000 + 4 * (2 * ch +
 * 0xf190) reads 0x96: FUN_a01238e8() and FUN_a0123c80(s, last); when that returns 1, 0x48 is written to register
 * 2 * ch + 0xf191, the function waits until it no longer reads 0x48 and returns 2. Otherwise returns 4.
 * No direct callers were found. Exact form: last is copied through an unsigned int into the dead loop index
 * (n = last; i = n;) before the calls; that keeps it in a call-saved register as in the firmware.
 */
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

extern unsigned char FUN_a0124168(void);
extern unsigned char *FUN_a0124174(void);
extern void FUN_a01238e8(void);
extern unsigned char FUN_a0123c80(const unsigned char *s, unsigned char n);

int FUN_a0148120(const unsigned char *s)
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
            if (FUN_a0123c80(s, i) == 1) {
                RB(ch * 2 + 0xf191) = 0x48;
                while (RB(ch * 2 + 0xf191) == 0x48)
                    ;
                return 2;
            }
        } while (RB(ch * 2 + 0xf190) == 0x96);
    }
    return 4;
}
