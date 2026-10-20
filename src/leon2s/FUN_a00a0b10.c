/* FUN_a00a0b10 (leon2s, 0xa00a0b10-0xa00a0b98, 136 bytes, 34 words; includes the merged
 * unreachable ret/restore tail FUN_a00a0b90). Flags: -mcpu=v8 -Os -g.
 * Code facts: port = (u8)param_1, v = (u8)param_2; FUN_a00a0930(port, reg, v) for reg 0x16, 0xe,
 * 0x1c, 0xb, 8; then if (u8)FUN_a008d800() > 0x82, tail call FUN_a00a0930(port, 0xc, v).
 * Fix vs draft: FUN_a008d800 takes NO argument (fw sets no %o0 before it; the 'mov 0xc,%i1' in its
 * delay slot belongs to the tail call). Aids: none.
 */
extern int FUN_a008d800();
extern void FUN_a00a0930();

void FUN_a00a0b10(unsigned char param_1, unsigned char param_2)
{
    unsigned char uVar1;
    
    param_1 = param_1 & 0xff;
    FUN_a00a0930(param_1, 0x16, param_2);
    FUN_a00a0930(param_1, 0xe, param_2);
    FUN_a00a0930(param_1, 0x1c, param_2);
    FUN_a00a0930(param_1, 0xb, param_2);
    FUN_a00a0930(param_1, 8, param_2);
    uVar1 = FUN_a008d800() & 0xff;
    if (uVar1 <= 0x82) {
        return;
    }
    FUN_a00a0930(param_1, 0xc, param_2);
}
