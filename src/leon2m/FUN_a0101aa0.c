/* FUN_a0101aa0 (leon2m 0xa0101aa0-0xa0101abc, 28 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears bit 0 of the word register 0xcf01610c (read-modify-write). Nothing in the image refers to it: no call,
 * branch, sethi/or constant or address word. It lies between FUN_a0101a70 and FUN_a0101abc.
 */
#define REG (*(volatile unsigned int *)0xcf01610c)

void FUN_a0101aa0(void)
{
    REG &= ~1u;
}
