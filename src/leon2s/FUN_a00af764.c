/* FUN_a00af764 (leon2s, 0xa00af764-0xa00af858, 61 words). Flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 Code facts: void (u8 port). r = FUN_a00add48(port, func_0x9f1c6624(port)) (u8 returns); mask = -1, r 0..1 -> 1, 2..3 -> 2, 4..5 -> 4, 6..7 -> 8.
 If (u8)FUN_a008d800() <= 0x81 and port == 0 and func_0x9f1c6624(0) == 0: FUN_a008ae18(1). m = (u8)mask; if m != 0xff: pulse bits m of the
 hardware register 0xcf0124b8 (|= m, FUN_a00b1794(1), &= ~m).
 Fixes vs draft: BEHAVIOUR the <= 0x81 test is on d800()'s u8 return (the draft tested r); u8 prototypes. void: the only caller
 (DP_GetClrSpace 0xa006f160) overwrites %o0 right after the call; a u8 'return m' version is byte-identical too. Aids: none.
 */
// FUN_a00af764 at 0xa00af764
extern unsigned char FUN_a008d800(void);
extern unsigned char FUN_a00add48(unsigned char, unsigned char);
extern void FUN_a008ae18(unsigned int);
extern void FUN_a00b1794(unsigned int);
extern unsigned char func_0x9f1c6624(unsigned char);

#define REG_CF0124B8 (*(volatile unsigned int *)0xcf0124b8)

void FUN_a00af764(unsigned char port)
{
    unsigned char r;
    unsigned int mask;
    unsigned char m;

    r = FUN_a00add48(port, func_0x9f1c6624(port));
    mask = 0xffffffff;
    if (r < 2) {
        mask = 1;
    } else if ((unsigned char)(r - 2) < 2) {
        mask = 2;
    } else if ((unsigned char)(r - 4) < 2) {
        mask = 4;
    } else if ((unsigned char)(r - 6) < 2) {
        mask = 8;
    }
    if (FUN_a008d800() <= 0x81 && port == 0 && func_0x9f1c6624(0) == 0)
        FUN_a008ae18(1);
    m = mask;
    if (m != 0xff) {
        REG_CF0124B8 = REG_CF0124B8 | m;
        FUN_a00b1794(1);
        REG_CF0124B8 = REG_CF0124B8 & ~m;
    }
}
