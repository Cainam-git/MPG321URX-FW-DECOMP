/* leon2s FUN_a00b00e0 @ 0xa00b00e0 (-mcpu=v8 -Os -g)
 * p = p1 & 0xff; u = FUN_a00add48(p, func_0x9f1c6624(p) & 0xff); FUN_a00a8400(u & 0xff, 0xb, 3, p2 != 0 ? 1 : 0)
 * (two calls, one per arm). Source form: u holds the FUN_a00add48 result.
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
