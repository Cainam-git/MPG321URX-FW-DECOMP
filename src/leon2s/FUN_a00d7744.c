/* leon2s FUN_a00d7744 @ 0xa00d7744 (-mcpu=v8 -Os -g)
 * Copies a message: dst[0] = src[0] & 0x7f, dst[1] = src[1] & 0xf, dst[2] = n = src[2], then dst[3 + i] = src[3 + i] for
 * i < n with an unsigned char counter (n re-read each round).
 */
extern void *memcpy(void *dest, const void *src, unsigned int n); // not used, but for reference

void FUN_a00d7744(unsigned char *param_1, unsigned char *param_2)
{
    unsigned char bVar2;
    unsigned char uVar1;

    *param_2 = *param_1 & 0x7f;
    param_2[1] = param_1[1] & 0xf;
    param_2[2] = param_1[2];

    if (param_1[2] != 0) {
        bVar2 = 0;
        do {
            param_2[(unsigned char)bVar2 + 3] = param_1[(unsigned char)bVar2 + 3];
            bVar2 = bVar2 + 1;
            uVar1 = (unsigned short)bVar2;
        } while ((unsigned char)uVar1 < param_1[2]);
    }
}
