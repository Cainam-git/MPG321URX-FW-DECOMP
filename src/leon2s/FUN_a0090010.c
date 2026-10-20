/* FUN_a0090010 (leon2s, 0xa0090010-0xa0090078, 104 bytes, 26 words).
 * Flags: -mcpu=v8 -Os -g.
 * port = (u8)param_1; v = FUN_a00a6938(port, 0x4e) as u16. When bits 5..7 of FUN_a00a657c(port, 0x144)
 * equal 0x60, or (u8)FUN_a008fff0(port) != 0, the function returns (u16)(v << 1); otherwise (u16)v. Both
 * doubled arms share one call site in the firmware (cross-jump); the 0x60 test's 'be' goes to the sll 0x11
 * block.
 */
extern unsigned int FUN_a00a657c(unsigned int param_1, unsigned short param_2);
extern unsigned char FUN_a008fff0(unsigned char param_1);
extern unsigned int FUN_a00a6938(unsigned int param_1, unsigned short param_2);

unsigned short FUN_a0090010(unsigned int param_1)
{
    param_1 = param_1 & 0xff;
    if ((FUN_a00a657c(param_1, 0x144) & 0xe0) == 0x60)
        return FUN_a00a6938(param_1, 0x4e) << 1;
    if (FUN_a008fff0(param_1) != 0)
        return FUN_a00a6938(param_1, 0x4e) << 1;
    return FUN_a00a6938(param_1, 0x4e);
}
