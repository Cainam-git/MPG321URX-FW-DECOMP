/* FUN_a00f6f7c (leon2m 0xa00f6f7c-0xa00f6f94, 24 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes its byte argument to the word register 0xcf00ef20. Called by FUN_a01471a0. It lies between FUN_a00f6f54
 * and FUN_a00f6f94. Source form: a volatile register store of an unsigned char parameter (and 0xff; the store stays
 * before retl).
 */
#define R (*(volatile unsigned int *)0xcf00ef20)

void FUN_a00f6f7c(unsigned char v)
{
    R = v;
}
