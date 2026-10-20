/* leon2m FUN_a00d472c @ 0xa00d472c-0xa00d477c (20 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/20 mismatches. Leaf frame, sibcall (mov %o7 form).
 * Code facts: a = byte DAT_a802d290+0xd, b = byte +0xe, each clamped to 100 (cmp 0x64; bleu, the
 * clamp value built as sethi 0x640000 / srl 16 = u16 arithmetic), then tail call
 * FUN_a0146518(a, b, 0). The callee's asm takes (u16, u16, u8): sll/srl 16 on %o0/%o1, and 0xff on %o2.
 * Required forms: the real base DAT_a802d290 as a struct (not the
 * mid-record names d29d/d29e), u16 clamp variables (the a00d4780 lever) and the callee's real
 * (u16, u16, u8) prototype. Aids: none.
 */
struct R290 { unsigned char pad[0xd]; unsigned char b0d; unsigned char b0e; };
extern struct R290 DAT_a802d290;
extern void FUN_a0146518(unsigned short, unsigned short, unsigned char);

void FUN_a00d472c(void)
{
    struct R290 *p = &DAT_a802d290;
    unsigned short a = p->b0d;
    unsigned short b = p->b0e;

    if (a > 100)
        a = 100;
    if (b > 100)
        b = 100;
    FUN_a0146518(a, b, 0);
}
