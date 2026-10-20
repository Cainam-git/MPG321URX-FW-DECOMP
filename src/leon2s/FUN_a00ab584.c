/* leon2s FUN_a00ab584 @ 0xa00ab584-0xa00ab674 (60 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/60 mismatches.
 * Code facts: leaf. If byte DAT_a807d289[0] == 0xa0: v = hw word 0xcf013280 & ~0x1f (read once); for the
 * five select bits 1, 2, 4, 8, 0x10: 0xcf013280 = (u8)(v | bit), then 0xcf013284 = (0xcf013284 & 0x1f) |
 * byte DAT_a807d289[3 + n] (n = 0..4). Else: 0xcf013280 |= 0x1f; 0xcf013284 = (0xcf013284 & 0x1f) | 0x80.
 * void. Fixes vs the autoc draft (78.46): one base symbol DAT_a807d289 for the flag and the 5 data bytes
 * (the draft used 6 mid-record names: fw [%o1 + 3..7] off one base); the select write is a u8 cast.
 * volatile only on the two 0xcf0132xx hardware registers. Aids: none.
 */
#define REG_CF013280 (*(volatile unsigned int *)0xcf013280)
#define REG_CF013284 (*(volatile unsigned int *)0xcf013284)
extern unsigned char DAT_a807d289[];

void FUN_a00ab584(void)
{
    unsigned int v;

    if (DAT_a807d289[0] == 0xa0) {
        v = REG_CF013280 & ~0x1f;
        REG_CF013280 = (unsigned char)(v | 1);
        REG_CF013284 = (REG_CF013284 & 0x1f) | DAT_a807d289[3];
        REG_CF013280 = (unsigned char)(v | 2);
        REG_CF013284 = (REG_CF013284 & 0x1f) | DAT_a807d289[4];
        REG_CF013280 = (unsigned char)(v | 4);
        REG_CF013284 = (REG_CF013284 & 0x1f) | DAT_a807d289[5];
        REG_CF013280 = (unsigned char)(v | 8);
        REG_CF013284 = (REG_CF013284 & 0x1f) | DAT_a807d289[6];
        REG_CF013280 = (unsigned char)(v | 0x10);
        REG_CF013284 = (REG_CF013284 & 0x1f) | DAT_a807d289[7];
    } else {
        REG_CF013280 |= 0x1f;
        REG_CF013284 = (REG_CF013284 & 0x1f) | 0x80;
    }
}
