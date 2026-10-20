/*
 * FUN_a00a0b98 (leon2s, 0xa00a0b98-0xa00a0bfc, 100 bytes), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/25.
 * Code facts: register word 0x1e (+0x78) of the block at +0 of the 0x34-byte port record
 * ARR_a807db00[port]: on == 1: (w & 0xffffff) | (on << bit); else w & ~(1 << bit) & 0xffffff (bits
 * 24..31 always cleared). void (the fw leaves %i0 = port). Aids: none.
 */
struct Port34 { unsigned int *regs; unsigned char rest[0x30]; };
extern struct Port34 ARR_a807db00[];

void FUN_a00a0b98(unsigned char param_1, unsigned int param_2, unsigned char param_3)
{
    if (param_3 == 1)
        ARR_a807db00[param_1].regs[0x1e] = (ARR_a807db00[param_1].regs[0x1e] & 0xffffff) | (param_3 << param_2);
    else
        ARR_a807db00[param_1].regs[0x1e] = ARR_a807db00[param_1].regs[0x1e] & ~(1 << param_2) & 0xffffff;
}
