/* leon2m FUN_a0134428 @ 0xa0134428 (-mcpu=v8 -O2 -g)
 * Two calls to func_0x4008f3f4: the first passes 0x14, the low byte of param_2, bits 8-15 of param_1 (left-then-right
 * shift), the low byte of param_1 and 1; the second passes 0x11 with all-zero data fields and 2. The parameters are
 * unsigned int (the assembly works on full 32-bit registers with explicit masks); the two-step shift `(x<<16)>>24`
 * gives the target's `sll` + `srl` pair instead of a single `srl`.
 */
extern int func_0x4008f3f4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int); /* 0x4008f3f4 */

void FUN_a0134428(unsigned int param_1, unsigned int param_2)
{
    func_0x4008f3f4(0x14, param_2 & 0xff, (param_1 << 16) >> 24, param_1 & 0xff, 1);
    func_0x4008f3f4(0x11, 0, 0, 0, 2);
}
