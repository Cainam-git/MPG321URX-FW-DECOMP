/* FUN_a00ad6ec (leon2s, 0xa00ad6ec-0xa00ad734, 72 bytes, 18 words).
 * Flags: -mcpu=v8 -Os -g. Judge: jf 100.00 match=True, rawcmp_l2s 0/18 mismatches.
 * Code facts: port = (u8)param_1; FUN_a00a6c00(port, 0x70, 0); FUN_a00a6c00(port, 0x73, 8);
 * returns 1 when bit 4 (0x10) of FUN_a00a6bb8(port, 0x7a) is CLEAR, else 0
 * (fw: and 0x10, cmp %g0,%o0, subx %g0,-1 = (x == 0)).
 * Draft behaviour bug fixed: the draft returned (bit != 0). Aids: none.
 */
extern unsigned int FUN_a00a6bb8(unsigned int param_1, unsigned short param_2);
extern void FUN_a00a6c00(unsigned int param_1, unsigned short param_2, unsigned int param_3);

int FUN_a00ad6ec(unsigned int param_1)
{
    unsigned int result;
    param_1 &= 0xff;
    FUN_a00a6c00(param_1, 0x70, 0);
    FUN_a00a6c00(param_1, 0x73, 8);
    result = FUN_a00a6bb8(param_1, 0x7a) & 0x10;
    return (result == 0) ? 1 : 0;
}
