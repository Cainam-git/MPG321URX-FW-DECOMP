/* leon2s FUN_a00a15c8 @ 0xa00a15c8 (-mcpu=v8 -Os -g)
 * This function checks a global flag (`DAT_a807db68`). If it is non-zero, it performs five operations on a per-port register table (`DAT_a807db00`, indexed by `param_1 * 0x34`): calls `FUN_a00a73ac` and `FUN_a00a73d4` with `(8, base+4)` where `base` is the word at the port's offset, calls `FUN_a00b160c(1)`, calls `FUN_a00962ec(param_1 & 0xff, 1)`, and starts a timer with `DRV_HDMI_Start_Timer(0x15)`, then returns 0. If the flag is zero, it skips all work and returns 1. The two loads of `base` are written separately to force the target's re-read from memory. The `param_1` type is `int` to match t
 */
extern unsigned char DAT_a807db00;
extern unsigned char DAT_a807db68;
extern void FUN_a00a73ac(unsigned int, int);
extern void FUN_a00b160c(unsigned int);
extern void FUN_a00a73d4(unsigned int, int);
extern void FUN_a00962ec(unsigned int, unsigned char);
extern void DRV_HDMI_Start_Timer(unsigned int);

int FUN_a00a15c8(int param_1)
{
    if (DAT_a807db68 != 0) {
        FUN_a00a73ac(8, *(unsigned int *)(&DAT_a807db00 + param_1 * 0x34) + 4);
        FUN_a00b160c(1);
        FUN_a00a73d4(8, *(unsigned int *)(&DAT_a807db00 + param_1 * 0x34) + 4);
        FUN_a00962ec(param_1 & 0xff, 1);
        DRV_HDMI_Start_Timer(0x15);
        return 0;
    }
    return 1;
}
