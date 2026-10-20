/* leon2m FUN_a00e2588 @ 0xa00e2588-0xa00e260c (33 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 33 words.
 * Code facts: DDR setter (a, x = N_adj, y = N_det): x > 9 -> FUN_a00df80c(), FUN_a00e0bc0() (prints
 * "ddr_err: "), tail print s_00199788 "error: N_adj=%d, should be 0~9." with x; else y > 9 -> the same with
 * s_00199768 "error: N_det=%d, should be 0~9." and y; else FUN_a00e0774(a, 0x1c0, 0xf0, 4, x); tail FUN_a00e0774(a, 0x1f0, 0x0f, 0, y)
 * (FUN_a00e0774 = field write (a, reg, mask, shift, value); its asm shifts %o4 by %o3). Twin of FUN_a00e260c.
 * Fix vs the autoc draft (77.78): BEHAVIOUR - the first FUN_a00e0774 call has a 5th argument (x, fw %o4 = %i1
 * set at entry) and the second is (a, reg, mask, shift, y); each print takes ONE value; FUN_a00df80c and
 * FUN_a00e0bc0 take no arguments (their asm never reads %o0); 3 params. Aids: none.
 */
extern const char s_00199788[], s_00199768[];
extern int FUN_a00df170();
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

void FUN_a00e2588(unsigned int a, unsigned int x, unsigned int y)
{
    if (x > 9) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170(s_00199788, x);
        return;
    }
    if (y > 9) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170(s_00199768, y);
        return;
    }
    FUN_a00e0774(a, 0x1c0, 0xf0, 4, x);
    FUN_a00e0774(a, 0x1f0, 0x0f, 0, y);
}
