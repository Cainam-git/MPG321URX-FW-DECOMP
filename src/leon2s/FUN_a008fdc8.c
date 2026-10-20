/* leon2s FUN_a008fdc8 @ 0xa008fdc8 (-mcpu=v8 -Os -g)
 * Calls FUN_a008fb5c(param_1 & 0xFF), then FUN_a00a67b8(param_1 & 0xFF, 0x48, 2, flag) with flag = 1 when the low
 * byte of the first result equals 1, else 0. The if/else with the call in both arms gives the firmware's two
 * separate call sequences after the comparison. param_2 is not used.
 */
extern unsigned int FUN_a008fb5c(unsigned int param_1);
extern void FUN_a00a67b8(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4);

void FUN_a008fdc8(unsigned int param_1, unsigned int param_2)
{
    unsigned int uVar1;
    unsigned int uVar2;
    
    uVar1 = param_1 & 0xff;
    uVar2 = FUN_a008fb5c(uVar1);
    if ((uVar2 & 0xff) == 1) {
        FUN_a00a67b8(uVar1, 0x48, 2, 1);
    } else {
        FUN_a00a67b8(uVar1, 0x48, 2, 0);
    }
    return;
}
