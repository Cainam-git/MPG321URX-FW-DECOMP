/* FUN_a006d568 (leon2s, 0xa006d568-0xa006d5a8, 64 bytes, 16 words).
 * Flags: -mcpu=v8 -Os -g.
 * v = (u8)param_2; when v == 0: func_0x9f1c6694(0); FUN_a008ae18(v); clears bit 6 (0x40) of the u16 at
 * param_1 + 0x12; tail call FUN_a00abb28(v) (firmware: 'orcc %i1,0,%i0' copies v into %i0 = the tail
 * call's %o0 after restore, and tests it). FUN_a00abb28 takes one argument, v; void.
 */
extern int FUN_a008ae18();
extern void FUN_a00abb28(int);
extern int func_0x9f1c6694();

void FUN_a006d568(int param_1, int param_2)
{
    unsigned short *puVar1;
    
    param_2 = param_2 & 0xff;
    if (param_2 == 0) {
        func_0x9f1c6694(0);
    }
    FUN_a008ae18(param_2);
    puVar1 = (unsigned short *)(param_1 + 0x12);
    *puVar1 = *puVar1 & 0xffbf;
    FUN_a00abb28(param_2);
}
