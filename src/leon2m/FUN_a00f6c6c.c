/* FUN_a00f6c6c (leon2m 0xa00f6c6c-0xa00f6c88, 28 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Clears bit 0 of the word register 0xcf00e984 (read-modify-write). Called by FUN_a012d554. It lies between
 * FUN_a00f6c38 and FUN_a00f6c88.
 */
#define REG (*(volatile unsigned int *)0xcf00e984)

void FUN_a00f6c6c(void)
{
    REG &= ~1u;
}
