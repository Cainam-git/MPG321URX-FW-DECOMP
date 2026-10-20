/* leon2s FUN_a00ad7c8 @ 0xa00ad7c8-0xa00ad828 (24 words), flags -mcpu=v8 -Os -g.
 * Code facts: ch (u8). r = 0; if FUN_a00ad784(ch) != 0: FUN_a00a6c00(ch, 0x70, 0);
 * FUN_a00a6c00(ch, 0x73, 8); r = (FUN_a00a6bb8(ch, 0x7a) & 8) != 0 (and 8; cmp %g0; addx).
 * Returns r.
 * Required forms: the bit-3 test is on FUN_a00a6bb8's RESULT. The mask is a local 'm = 8': with a
 * literal 8 the single-bit test is folded to 'srl 3; and 1' (do_store_flag); the fw keeps the
 * and/sne form, which only appears when the constant reaches the test at RTL level (same as
 * FUN_a00aaf48's bound). Aids: none (code-free local constant).
 */
extern unsigned int FUN_a00a6bb8(unsigned char, unsigned short);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned char);
extern unsigned char FUN_a00ad784(unsigned char);

unsigned int FUN_a00ad7c8(unsigned char ch)
{
    unsigned int r = 0;
    unsigned int m = 8;

    if (FUN_a00ad784(ch) != 0) {
        FUN_a00a6c00(ch, 0x70, 0);
        FUN_a00a6c00(ch, 0x73, 8);
        r = (FUN_a00a6bb8(ch, 0x7a) & m) != 0;
    }
    return r;
}
