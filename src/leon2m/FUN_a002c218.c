/* FUN_a002c218 (leon2m 0xa002c218-0xa002c22c, 20 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the low byte of the word register 0xcf03c894. Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a002c204 and FUN_a002c22c. Source form: a volatile word
 * read returned as unsigned char (the and 0xff sits in the retl delay slot).
 */
#define R (*(volatile unsigned int *)0xcf03c894)

unsigned char FUN_a002c218(void)
{
    return R;
}
