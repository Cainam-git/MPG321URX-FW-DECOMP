/* FUN_a0119578 (leon2m 0xa0119578-0xa01195ac, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Keeps only bits 0..6 (and 0x7f) of the word register at 0xcf000000 | (DAT_a8027aa8[i] << 2), DAT_a8027aa8 a
 * halfword array of register indexes. Nothing in the image refers to it: no call, branch, sethi/or constant or
 * address word. It lies between FUN_a011932c and FUN_a01195ac.
 */
extern unsigned short DAT_a8027aa8[];

void FUN_a0119578(unsigned char i)
{
    volatile unsigned int *p = (volatile unsigned int *)(0xcf000000 | (DAT_a8027aa8[i] << 2));

    *p &= 0x7f;
}
