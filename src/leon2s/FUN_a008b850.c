/* leon2s FUN_a008b850 @ 0xa008b850  MATCH (-mcpu=v8 -Os -g)
 * 
 */
extern unsigned int FUN_a00a6bb8(unsigned int param_1, unsigned short param_2);

unsigned int FUN_a008b850(unsigned int param_1)
{
    unsigned int uVar1;
    unsigned int uVar2;

    param_1 = param_1 & 0xff;
    uVar2 = FUN_a00a6bb8(param_1, 0x68) & 0xff;
    uVar2 = (uVar2 << 8) | (FUN_a00a6bb8(param_1, 0x67) & 0xff);
    uVar2 = (uVar2 << 8) | (FUN_a00a6bb8(param_1, 0x66) & 0xff);
    if (uVar2 == 0)
        uVar2 = 1;
    return uVar2;
}
