/* leon2s FUN_a00d6dac @ 0xa00d6dac (-mcpu=v8 -Os -g)
 * h = (src[0] >> 4) - 1; k = h / 2, plus 1 when h is odd; dst[0] = (dst[0] & 0x80) | (src[k + 3] & 0x7f). Same offset
 * rule as FUN_a00d6e94.
 */
void FUN_a00d6dac(unsigned char *param_1, unsigned char *param_2)
{
    unsigned int uVar1;
    unsigned char uVar2;
    unsigned char a, b;

    uVar1 = (*param_2 >> 4) - 1;
    uVar2 = (int)uVar1 / 2;
    if ((uVar1 & 1) != 0) {
        uVar2 = uVar2 + 1;
    }
    b = param_2[(uVar2 & 0xff) + 3];
    a = *param_1;
    b = b & 0x7f;
    a = a & -128;
    a = a | b;
    *param_1 = a;
}
