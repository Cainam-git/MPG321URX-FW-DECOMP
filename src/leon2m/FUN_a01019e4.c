/* FUN_a01019e4 (leon2m 0xa01019e4-0xa0101a00, 28 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears bit 3 (0x8) of the word register 0xcf0160c0 (read-modify-write). Nothing in the image refers to it: no
 * call, branch, sethi/or constant or address word. It lies between FUN_a01019b4 and FUN_a0101a00.
 */
#define REG (*(volatile unsigned int *)0xcf0160c0)

void FUN_a01019e4(void)
{
    REG &= ~8u;
}
