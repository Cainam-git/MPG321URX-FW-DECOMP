/* leon2s FUN_a00b00e0 @ 0xa00b00e0  MATCH (-mcpu=v8 -Os -g)
 * The function masks the first parameter to a byte, calls a hardware function, then a second function with the masked result, and finally calls a third function with either 1 or 0 as the last argument depending on whether the original second parameter was non-zero. The key fix is capturing the result of `FUN_a00add48` (Ghidra dropped it) and using an if/else with separate calls instead of passing a boolean expression directly, matching the `btst`/`bne` branch pattern in the assembly.
 */
extern int func_0x9f1c6624(unsigned int param_1);
extern unsigned int FUN_a00add48(unsigned int param_1, unsigned int param_2);
extern void FUN_a00a8400(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4);

void FUN_a00b00e0(unsigned int param_1, unsigned char param_2)
{
    unsigned int uVar1;
    
    param_1 = param_1 & 0xff;
    uVar1 = func_0x9f1c6624(param_1);
    uVar1 = FUN_a00add48(param_1, uVar1 & 0xff);
    if (param_2 != 0) {
        FUN_a00a8400(uVar1 & 0xff, 0xb, 3, 1);
    } else {
        FUN_a00a8400(uVar1 & 0xff, 0xb, 3, 0);
    }
    return;
}
