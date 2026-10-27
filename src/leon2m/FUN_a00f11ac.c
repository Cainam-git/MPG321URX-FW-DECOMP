/* FUN_a00f11ac (leon2m 0xa00f11ac-0xa00f11f4, 72 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the low byte of the word register at 0xcf000000 | ((DAT_a8026a7e[c] + k) << 2), c above 3 counting as 0
 * (DAT_a8026a7e a halfword table of base indexes, k a halfword). Nothing in the image refers to it: no call,
 * branch, sethi/or constant or address word. It lies between FUN_a00f1150 and FUN_a00f11f4.
 */
extern unsigned short DAT_a8026a7e[];

unsigned char FUN_a00f11ac(unsigned char c, unsigned short k)
{
    if (c > 3)
        c = 0;
    return *(volatile unsigned int *)(0xcf000000 | ((DAT_a8026a7e[c] + k) << 2));
}
