/* FUN_a00f16d8 (leon2m 0xa00f16d8-0xa00f176c, 148 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes v to the word register 0xcf000000 + 4 * (DAT_a8026a7a[c] + k); for c = 2 writes it to the registers of
 * entries 0 and 1 instead. Nothing in the image refers to it: no call, branch, sethi/or constant or address word.
 * It lies between FUN_a00f1690 and FUN_a00f176c.
 */
extern unsigned short DAT_a8026a7a[];

void FUN_a00f16d8(unsigned char c, unsigned short k, unsigned char v)
{
    unsigned char i;

    if (c == 2) {
        for (i = 0; i < 2; i++)
            *(volatile unsigned int *)(0xcf000000 | ((DAT_a8026a7a[i] + k) << 2)) = v;
    } else
        *(volatile unsigned int *)(0xcf000000 | ((DAT_a8026a7a[c] + k) << 2)) = v;
}
