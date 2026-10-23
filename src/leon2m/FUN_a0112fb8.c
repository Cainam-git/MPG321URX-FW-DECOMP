/* FUN_a0112fb8 (leon2m 0xa0112fb8-0xa0112fcc, 20 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the low byte of the word register 0xcf011a00. Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a0112db0 and FUN_a0112fcc. Source form: a volatile word
 * read returned as unsigned char (the and 0xff sits in the retl delay slot).
 */
#define R (*(volatile unsigned int *)0xcf011a00)

unsigned char FUN_a0112fb8(void)
{
    return R;
}
