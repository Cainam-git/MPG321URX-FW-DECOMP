/* FUN_a00fdf44 (leon2m 0xa00fdf44-0xa00fdf74, 48 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes (c << 4) | c (low byte) to the word register 0xcf02010c when the low byte of c is at most 7, otherwise 0.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a00fde94 and FUN_a00fdf74. Source form: an unsigned int parameter; only the compare uses its low byte.
 */
#define REG (*(volatile unsigned int *)0xcf02010c)
void FUN_a00fdf44(unsigned int c)
{
    unsigned char x = 0;
    if ((unsigned char)c <= 7)
        x = (c << 4) | c;
    REG = x;
}
