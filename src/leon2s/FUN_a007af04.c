/* leon2s FUN_a007af04 @ 0xa007af04-0xa007af6c (26 words), flags -mcpu=v8 -Os -g.
 * p (u8). If FUN_a0073520(p) != 0 (one argument; returns 1 for p == 2 or 3): i = (p != 2); returns
 * FUN_a00a7408(8, word +0xc of the 0x34-byte record ARR_a807db00[i] + 0x60) != 0. Else returns
 * FUN_a00a657c(p, 0x2e1) & 1.
 * Source form: the record index is a separate local 'i = p != 2' (firmware: xor, addx, smul 0x34; an inline
 * index lets gcc rewrite it as 0x34 - (p == 2) * 0x34).
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
