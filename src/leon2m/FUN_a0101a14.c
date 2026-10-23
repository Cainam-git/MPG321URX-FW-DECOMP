/* FUN_a0101a14 (leon2m 0xa0101a14-0xa0101a28, 20 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the low byte of the word register 0xcf0160e4. Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a0101a00 and FUN_a0101a28. Source form: a volatile word
 * read returned as unsigned char (the and 0xff sits in the retl delay slot).
 */
#define R (*(volatile unsigned int *)0xcf0160e4)

unsigned char FUN_a0101a14(void)
{
    return R;
}
