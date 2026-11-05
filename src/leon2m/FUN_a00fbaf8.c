/* leon2m FUN_a00fbaf8 @ 0xa00fbaf8-0xa00fbc80 (98 words), flags -mcpu=v8 -O3 -g. Called from FUN_a00fbc80.
 * Returns 0 when p > 1 or m > 4. Otherwise stores m to byte 0xa802b7fc, halfword 0xa8026a8a = 0x100 (m <= 1) or
 * 0x80, t = (halfword 0xa802b7fa * halfword 0xa8026a8a) >> 8, w = 1000 - t (0 when t > 1000) to halfword
 * 0xa8026a88, and calls FUN_a00fb434(8, &w, halfword 0xa802d67a, halfword 0xa802d678). For m == 4 and p == 0:
 * w = halfword 0xa8026a86; w2 = 0x80 above 0xbb7, 0 up to 0x1f3, else (w * 0x34 - 0x6590) >> 10;
 * FUN_a00fb434(0xb, &w2, ...same halfwords). Then bit 31 of register 0xd0040000 = (byte 0xa802b7fc != 0), bits
 * 0..3 of register 0xd00400d8 = the byte, and returns 1.
 * Source form: the 0xa8026a8a store as one '?:' assignment (the store goes through the full address register);
 * w and w2 are stack words whose addresses are passed; the register words are read-modify-written, bit 31 with a
 * mask local; the halfword at 0xa802d678 is declared as s_a802d678 (the symbol name sets the global-alloc order
 * of the two address registers that live across the calls).
 */
#define REG(a) (*(volatile unsigned int *)(a))

extern unsigned char DAT_a802b7fc;
extern unsigned short DAT_a802b7fa;
extern unsigned short DAT_a8026a86;
extern unsigned short DAT_a8026a88;
extern unsigned short DAT_a8026a8a;
extern unsigned short s_a802d678;
extern unsigned short DAT_a802d67a;
extern int FUN_a00fb434(unsigned int, unsigned int *, unsigned int, unsigned int);

int FUN_a00fbaf8(unsigned char p, unsigned int m)
{
    unsigned int w = 0, w2 = 0;
    unsigned char f;
    unsigned int mask;

    if (p > 1 || m > 4)
        return 0;
    DAT_a802b7fc = m;
    DAT_a8026a8a = (m <= 1) ? 0x100 : 0x80;
    w = (int)(DAT_a802b7fa * DAT_a8026a8a) >> 8;
    w = (w > 1000) ? 0 : 1000 - w;
    DAT_a8026a88 = w;
    FUN_a00fb434(8, &w, DAT_a802d67a, s_a802d678);
    if (m == 4) {
        if (p == 0) {
            w = DAT_a8026a86;
            if (w > 0xbb7)
                w2 = 0x80;
            else if (w <= 0x1f3)
                w2 = 0;
            else
                w2 = (w * 0x34 - 0x6590) >> 10;
            FUN_a00fb434(0xb, &w2, DAT_a802d67a, s_a802d678);
        }
    }
    f = DAT_a802b7fc != 0;
    mask = 0x80000000;
    REG(0xd0040000) = (REG(0xd0040000) & ~mask) | ((f << 31) & mask);
    REG(0xd00400d8) = (REG(0xd00400d8) & ~0xf) | (DAT_a802b7fc & 0xf);
    return 1;
}
