/* leon2m FUN_a0105a3c @ 0xa0105a3c  MATCH (-mcpu=v8 -O2 -g)
 * Four FUN_a00f2488(port, reg, value) calls on port param_1: reg 0x73 = param_4, 0x75 = param_2, 0x6F = param_5,
 * 0x71 = param_3. param_1 is a byte, params 2..5 are halfwords (the masks and shifts of the firmware).
 */
extern void FUN_a00f2488();

void FUN_a0105a3c(unsigned char param_1, unsigned short param_2, unsigned short param_3, unsigned short param_4, unsigned short param_5)
{
    FUN_a00f2488(param_1, 0x73, param_4);
    FUN_a00f2488(param_1, 0x75, param_2);
    FUN_a00f2488(param_1, 0x6f, param_5);
    FUN_a00f2488(param_1, 0x71, param_3);
}
