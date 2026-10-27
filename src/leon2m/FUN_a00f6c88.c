/* FUN_a00f6c88 (leon2m 0xa00f6c88-0xa00f6ca4, 28 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Sets bit 0 of the word register 0xcf00e984 (read-modify-write). Nothing in the image refers to it: no call,
 * branch, sethi/or constant or address word. It lies between FUN_a00f6c6c and FUN_a00f6ca4.
 */
#define REG (*(volatile unsigned int *)0xcf00e984)

void FUN_a00f6c88(void)
{
    REG |= 1;
}
