/* leon2s FUN_a00b06e0 @ 0xa00b06e0 (-mcpu=v8 -Os -g)
 * Calls FUN_a00a6c98(param_1 & 0xFF, 0x46, 8, flag) with flag = 1 when the low byte of FUN_a00ad320(param_1 &
 * 0xFF) is non-zero and 0 otherwise. FUN_a00ad320 takes one argument (only %o0 is set before the call); param_2 is
 * not used.
 */
extern int FUN_a00ad320(unsigned int param_1);
extern void FUN_a00a6c98(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4);

void FUN_a00b06e0(unsigned int param_1, unsigned int param_2)
{
    unsigned int uVar1;
    
    uVar1 = FUN_a00ad320(param_1 & 0xff);
    if ((uVar1 & 0xff) != 0) {
        FUN_a00a6c98(param_1 & 0xff, 0x46, 8, 1);
    } else {
        FUN_a00a6c98(param_1 & 0xff, 0x46, 8, 0);
    }
    return;
}
