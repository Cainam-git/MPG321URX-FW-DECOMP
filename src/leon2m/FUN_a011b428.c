/* FUN_a011b428 (leon2m 0xa011b428-0xa011b4b0, 136 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes the low three bytes of v to the word registers 0xcf011784, 0xcf011788, 0xcf00bfcc (c = 0) or 0xcf011798,
 * 0xcf01179c, 0xcf00c3cc (c non-zero), then runs a delay loop of 0xa0 nops. Nothing in the image refers to it: no
 * call, branch, sethi/or constant or address word. It lies between FUN_a011b3e8 and FUN_a011b4b0.
 */
void FUN_a011b428(unsigned char c, unsigned int v)
{
    int i;

    if (c == 0) {
        *(volatile unsigned int *)0xcf011784 = v & 0xff;
        *(volatile unsigned int *)0xcf011788 = (v >> 8) & 0xff;
        *(volatile unsigned int *)0xcf00bfcc = (v >> 16) & 0xff;
    } else {
        *(volatile unsigned int *)0xcf011798 = v & 0xff;
        *(volatile unsigned int *)0xcf01179c = (v >> 8) & 0xff;
        *(volatile unsigned int *)0xcf00c3cc = (v >> 16) & 0xff;
    }
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
}
