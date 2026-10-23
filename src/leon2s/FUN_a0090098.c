/* leon2s FUN_a0090098 @ 0xa0090098 (-mcpu=v8 -Os -g)
 * k = p1 & 0xff; v = FUN_a00a6938(k, 0x3a). Returns v << 1 (16 bits) when (FUN_a00a657c(k, 0x144) & 0xE0) == 0x60
 * or FUN_a008fff0(k) is nonzero, otherwise v. Same code as FUN_a0090010 with other constants.
 * See FUN_a0090010 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned int FUN_a00a657c(unsigned int param_1, unsigned short param_2);
extern unsigned char FUN_a008fff0(unsigned char param_1);
extern unsigned int FUN_a00a6938(unsigned int param_1, unsigned short param_2);

unsigned short FUN_a0090098(unsigned int param_1)
{
    param_1 = param_1 & 0xff;
    if ((FUN_a00a657c(param_1, 0x144) & 0xe0) == 0x60)
        return FUN_a00a6938(param_1, 0x3a) << 1;
    if (FUN_a008fff0(param_1) != 0)
        return FUN_a00a6938(param_1, 0x3a) << 1;
    return FUN_a00a6938(param_1, 0x3a);
}
