/* leon2s FUN_a008d800 @ 0xa008d800-0xa008d8d8 (54 words), flags -mcpu=v8 -Os -g.
 * Code facts: returns a u8 mode code from two hardware words: word 0xcf011444 (re-read for each test) and
 * word 0xcf011440 == 1 (full 'ld', so u32): 0x16 -> (byte 0x9f1b0606 == 1 ? 0x81 : 0x80), 0x1e -> 0x82,
 * 0x1f -> 0x83, 0x17 -> 0x84; anything else 0x84 (preset). Callers test the result (FUN_a00a0b10, FUN_a00af764).
 * Fixes vs the autoc draft (81.82): 0xcf011440 is a WORD (draft: byte), 0x9f1b0606 is a symbol (simm13 ldub
 * form; the constant cast gives or + ldub [reg]), and the 0x81/0x80 pick is a ?: on '== 1' (the draft's
 * '-0x7f - (b != 1)' folds to (b == 1) - 128 = subx %g0,-1 + add -128; the ?: keeps the fw mov -127 + subx).
 * volatile only on the hardware registers 0xcf0114xx / 0x9f1b0606. Aids: none.
 */
#define REG_CF011444 (*(volatile unsigned int *)0xcf011444)
#define REG_CF011440 (*(volatile unsigned int *)0xcf011440)
extern volatile unsigned char DAT_9f1b0606;   /* hw byte, symbol form (simm13 ldub) */

unsigned char FUN_a008d800(void)
{
    unsigned char r;

    r = 0x84;
    if (REG_CF011444 == 0x16 && REG_CF011440 == 1) {
        r = (DAT_9f1b0606 == 1) ? 0x81 : 0x80;
    } else if (REG_CF011444 == 0x1e && REG_CF011440 == 1) {
        r = 0x82;
    } else if (REG_CF011444 == 0x1f && REG_CF011440 == 1) {
        r = 0x83;
    } else if (REG_CF011444 == 0x17 && REG_CF011440 == 1) {
        r = 0x84;
    }
    return r;
}
