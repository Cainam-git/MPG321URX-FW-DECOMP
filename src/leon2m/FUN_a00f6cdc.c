/* FUN_a00f6cdc (leon2m 0xa00f6cdc-0xa00f6cf4, 24 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes its byte argument to the word register 0xcf00eed8. Called by FUN_a012d554. It lies between FUN_a00f6cc0
 * and FUN_a00f6cf4. Source form: a volatile register store of an unsigned char parameter (and 0xff; the store stays
 * before retl).
 */
#define R (*(volatile unsigned int *)0xcf00eed8)

void FUN_a00f6cdc(unsigned char v)
{
    R = v;
}
