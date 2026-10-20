/* FUN_a01211d4 (leon2m, 0xa01211d4-0xa0121258, 33 words). Flags -mcpu=v8 -O3 -g.
 * Code facts: u8 param. t = FUN_a00f1a90(param, 4). (t & 3) == 3: x = FUN_a00f1690(FUN_a00f1a90(param, 3) & 1, 0x8f)
 * & 4. Else: if bit 5 of FUN_a00f1a90(param, 3) return 0; x = FUN_a00f1f9c(param, 0x11) & 4. Returns x != 0 (fw cmp
 * %g0 / addx after the join).
 * Source form: the '& 4' is in each arm (both fw arms end in 'and %o0,4,%o0' before the shared cmp/addx); a '(x & 4)
 * != 0' after the join becomes srl/and. Callees return u8 (their retl does 'and %o0,0xff'). Compiler aids: none.
 */
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern unsigned char FUN_a00f1f9c(unsigned char a, unsigned char b);
extern unsigned char FUN_a00f1690(unsigned char a, unsigned char b);

unsigned int FUN_a01211d4(unsigned char param)
{
    unsigned char t = FUN_a00f1a90(param, 4);
    unsigned int x;
    
    if ((t & 3) == 3) {
        unsigned char v = FUN_a00f1a90(param, 3);
        x = FUN_a00f1690(v & 1, 0x8f) & 4;
    } else {
        unsigned char r2 = FUN_a00f1a90(param, 3);
        if (r2 & 0x20)
            return 0;
        x = FUN_a00f1f9c(param, 0x11) & 4;
    }
    return x != 0;
}
