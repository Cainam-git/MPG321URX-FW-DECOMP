/* FUN_a002c22c (leon2m 0xa002c22c-0xa002c250, 36 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears bit 'bit' of the word register 0xcf03c894 (read-modify-write). Nothing in the image refers to it: no call,
 * branch, sethi/or constant or address word. It lies between FUN_a002c218 and FUN_a002c250.
 */
#define REG (*(volatile unsigned int *)0xcf03c894)

void FUN_a002c22c(unsigned int bit)
{
    REG &= ~(1 << bit);
}
