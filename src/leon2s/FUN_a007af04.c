/* leon2s FUN_a007af04 @ 0xa007af04-0xa007af6c (26 words), flags -mcpu=v8 -Os -g.
 * Code facts: p (u8). If FUN_a0073520(p) (1 arg: returns 1 for p == 2 or 3) != 0: i = (p != 2);
 * return FUN_a00a7408(8, word +0xc of the 0x34-byte record ARR_a807db00[i] + 0x60) != 0. Else
 * return FUN_a00a657c(p, 0x2e1) & 1.
 * Fixes vs the autoc draft (84.62): FUN_a0073520 takes 1 arg (the draft passed param_2); real base
 * ARR_a807db00 (draft used db0c) as a 0x34-byte record with the word at +0xc; the record index is a
 * separate local 'i = p != 2' (fw: xor, addx, smul 0x34; the inline index lets gcc rewrite it as
 * 0x34 - (p == 2) * 0x34: 88.46). Aids: none.
 */
struct Port34 { unsigned char pad[0xc]; unsigned int base; unsigned char rest[0x34 - 0x10]; };
extern struct Port34 ARR_a807db00[];
extern unsigned char FUN_a0073520(unsigned char);
extern unsigned int FUN_a00a657c(unsigned char, unsigned short);
extern unsigned int FUN_a00a7408(unsigned int, unsigned int);

unsigned int FUN_a007af04(unsigned char p)
{
    if (FUN_a0073520(p) != 0)
    {
        unsigned int i = p != 2;
        return FUN_a00a7408(8, ARR_a807db00[i].base + 0x60) != 0;
    }
    return FUN_a00a657c(p, 0x2e1) & 1;
}
