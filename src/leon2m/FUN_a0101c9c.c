/* FUN_a0101c9c (leon2m 0xa0101c9c-0xa0101cb4, 24 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes its byte argument to the word register 0xcf0160c8. Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a0101c64 and FUN_a0101cb4. Source form: a volatile
 * register store of an unsigned char parameter (and 0xff; the store stays before retl).
 */
#define R (*(volatile unsigned int *)0xcf0160c8)

void FUN_a0101c9c(unsigned char v)
{
    R = v;
}
