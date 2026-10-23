/* leon2m FUN_a0106920 @ 0xa0106920-0xa0106b08 (122 words), flags -mcpu=v8 -O3 -g.
 * What it does: switches an output-path mode of block 0 on or off (FUN_a0106b08 calls it with
 * (blk, 1) at the start of the rate set-up). blk != 0 -> nothing. Then by the code
 * c = FUN_a011cf88() (see FUN_a011cf88.c):
 *   c > 0x81 (chips 0x82..0x84): only register 0x86 of block 0 (0xcf009a18, accessor FUN_a00f232c):
 *     on  -> set bit 3, wait func_0x4008d1a0(0x50), set bit 4;   off -> clear bit 3, clear bit 4.
 *   c <= 0x81 (chips 0x80/0x81):
 *     on:  c == 0x81 -> 0xcf00f1c0 |= 1; reg 0x86 = (v & ~0x0c) | 0x18, then & ~0x04 (bits 4,3 set,
 *          bit 2 clear); stop if FUN_a010a864() (bit 0 of 0xcf011800) or if reg 0x7d bit 5 is
 *          already set; else set reg 0x7d bit 5, clear 0xcf00ed58 bit 4 and 0xcf00ed84 bit 0.
 *     off: c == 0x81 -> 0xcf00f1c0 &= ~1; reg 0x86 = (v & ~0x0c) | 0x10, then & ~0x0c; stop if reg 0x7d
 *          bit 5 is clear; else clear it, set 0xcf00ed58 bit 4 and 0xcf00ed84 bit 0.
 *   (c is read again for the 0x80 test: the fw calls FUN_a011cf88 twice.)
 * The path taken depends only on FUN_a011cf88() and 'on', never on the input rate.
 * Source form: the c <= 0x81 part is the then-arm (firmware fall-through); the reg 0x86 value is two statements (one
 * combined expression lets fold drop the third and).
 * volatile only on the 0xcf00.... hardware registers. Compiler aids: none.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned char FUN_a011cf88(void);
extern unsigned char FUN_a00f2254(unsigned char blk, unsigned char reg);
extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f232c(unsigned char port, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned char FUN_a010a864(void);
extern void func_0x4008d1a0(int ms);

void FUN_a0106920(unsigned char blk, unsigned char on)
{
    unsigned char v;

    if (blk != 0)
        return;
    if (FUN_a011cf88() <= 0x81) {
        if (on) {
            if (FUN_a011cf88() > 0x80)
                R(0xcf00f1c0) |= 1;
            v = FUN_a00f2254(0, 0x86);
            v = (v & ~0x0c) | 0x18;
            FUN_a00f2298(0, 0x86, v & ~0x04);
            if (FUN_a010a864())
                return;
            if (FUN_a00f2254(0, 0x7d) & 0x20)
                return;
            FUN_a00f232c(0, 0x7d, 0x20, 1);
            R(0xcf00ed58) &= ~0x10;
            R(0xcf00ed84) &= ~1;
        } else {
            if (FUN_a011cf88() > 0x80)
                R(0xcf00f1c0) &= ~1;
            v = FUN_a00f2254(0, 0x86);
            v = (v & ~0x0c) | 0x10;
            FUN_a00f2298(0, 0x86, v & ~0x0c);
            if (!(FUN_a00f2254(0, 0x7d) & 0x20))
                return;
            FUN_a00f232c(0, 0x7d, 0x20, 0);
            R(0xcf00ed58) |= 0x10;
            R(0xcf00ed84) |= 1;
        }
    } else {
        if (on) {
            FUN_a00f232c(0, 0x86, 8, 1);
            func_0x4008d1a0(0x50);
            FUN_a00f232c(0, 0x86, 0x10, 1);
        } else {
            FUN_a00f232c(0, 0x86, 8, 0);
            FUN_a00f232c(0, 0x86, 0x10, 0);
        }
    }
}
