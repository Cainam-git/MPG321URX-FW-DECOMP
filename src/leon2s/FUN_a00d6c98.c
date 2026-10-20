/* leon2s FUN_a00d6c98 @ 0xa00d6c98 (-mcpu=v8 -Os -g)
 * Computes k = u / 2 + (u & 1) with u = (param_2[0] >> 4) - 1, then merges
 * param_1[0] = (param_1[0] & 0x80) | (param_2[k + 3] & 0x7F) and
 * param_1[1] = (param_1[1] & 0x0F) | (param_2[k + 4] & 0xF0).
 * Holding the second masked byte in the unsigned int temporary b makes GCC emit and %o5, 0xf0 instead of the
 * sign-extended and %o5, -16.
 */
void FUN_a00d6c98(unsigned char *param_1, unsigned char *param_2)
{
    unsigned int uVar1;
    unsigned char uVar2;
    unsigned int b;

    uVar1 = (*param_2 >> 4) - 1;
    uVar2 = (int)uVar1 / 2;
    if ((uVar1 & 1) != 0) {
        uVar2 = uVar2 + 1;
    }

    *param_1 = *param_1 & 0x80 | param_2[(uVar2 & 0xff) + 3] & 0x7f;

    b = param_2[(uVar2 & 0xff) + 4] & 0xf0;
    param_1[1] = (param_1[1] & 0xf) | b;
}
