/* leon2s FUN_a00af320 @ 0xa00af320-0xa00af464 (81 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 * Code facts: port = arg & 0xff; FUN_a00a6bb8(port, 0x8f) bit 0x40 clear -> return 0. Else four
 * indexed reads: FUN_a00a6c00(port, 0x70, 0); FUN_a00a6c00(port, 0x73, idx); FUN_a00a6bb8(port, 0x7a)
 * for idx 0xc, 0xd, 0x10, 0x11. num = (b0c << 8) + b0d, div = (b10 << 8) + b11 (both u16, sll/srl 16);
 * return (div ? (num / div) : 0) & 0xff != 0 (udiv, cmp/addx).
 * Fix vs the autoc draft (97.53): the bytes are combined with '+' (fw add), the draft used '|' (or).
 * Draft junk ('uVar3 = uVar3', 'result = result') removed. Aids: none.
 */
extern unsigned int FUN_a00a6bb8(unsigned int, unsigned short);
extern void FUN_a00a6c00(unsigned int, unsigned short, unsigned int);

int FUN_a00af320(char param_1)
{
    unsigned short num;
    unsigned short div;
    unsigned int r0, r1, r2, r3;
    unsigned int result;

    if ((FUN_a00a6bb8(param_1 & 0xff, 0x8f) & 0x40) == 0) {
        return 0;
    }

    FUN_a00a6c00(param_1 & 0xff, 0x70, 0);
    FUN_a00a6c00(param_1 & 0xff, 0x73, 0xc);
    r0 = FUN_a00a6bb8(param_1 & 0xff, 0x7a);
    FUN_a00a6c00(param_1 & 0xff, 0x70, 0);
    FUN_a00a6c00(param_1 & 0xff, 0x73, 0xd);
    r1 = FUN_a00a6bb8(param_1 & 0xff, 0x7a);
    FUN_a00a6c00(param_1 & 0xff, 0x70, 0);
    FUN_a00a6c00(param_1 & 0xff, 0x73, 0x10);
    r2 = FUN_a00a6bb8(param_1 & 0xff, 0x7a);
    FUN_a00a6c00(param_1 & 0xff, 0x70, 0);
    FUN_a00a6c00(param_1 & 0xff, 0x73, 0x11);
    r3 = FUN_a00a6bb8(param_1 & 0xff, 0x7a);

    div = ((r2 & 0xff) << 8) + (r3 & 0xff);
    num = ((r0 & 0xff) << 8) + (r1 & 0xff);

    result = 0;
    if (div != 0) {
        result = num / div;
    }
    return (result & 0xff) != 0;
}
