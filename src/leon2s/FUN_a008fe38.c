/* leon2s FUN_a008fe38 @ 0xa008fe38 (-mcpu=v8 -Os -g)
 * FUN_a00a65c4(p1, 0x135, 6) when p2 != 0, else FUN_a00a65c4(p1, 0x135, 9) (the firmware loads 0x135 in both arms).
 */
extern void FUN_a00a65c4(unsigned int param_1, unsigned short param_2, unsigned int param_3);

void FUN_a008fe38(unsigned char param_1, unsigned char param_2)
{
    if (param_2 != 0)
        FUN_a00a65c4(param_1, 0x135, 6);
    else
        FUN_a00a65c4(param_1, 0x135, 9);
}
