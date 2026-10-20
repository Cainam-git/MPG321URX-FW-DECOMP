/* leon2s FUN_a0094a50 @ 0xa0094a50  MATCH (-mcpu=v8 -Os -g)
 * void(u8 param_1, u8 param_2). Calls FUN_a00a80cc(param_1, 0, 0xFD, 0x60, param_2) (param_2 is set in the call's
 * delay slot), FUN_a00a8260(param_1, 0x81, 0x30, param_2), then FUN_a00a8184(param_1, 1, 0x80, 0x0C, 8) for
 * param_2 == 1, else FUN_a00a8184(param_1, 1, 0x80, 0x0C, 4) (cmp / be).
 */
extern void FUN_a00a80cc();
extern int FUN_a00a8184();
extern int FUN_a00a8260();

void FUN_a0094a50(unsigned char param_1, unsigned char param_2)
{
    unsigned char uVar1;
    
    FUN_a00a80cc(param_1, 0, 0xfd, 0x60, param_2);
    FUN_a00a8260(param_1, 0x81, 0x30, param_2);
    
    if (param_2 == 1) {
        FUN_a00a8184(param_1, 1, 0x80, 0xc, 8);
    } else {
        FUN_a00a8184(param_1, 1, 0x80, 0xc, 4);
    }
    return;
}
