/* FUN_a0123654 (leon2m 0xa0123654-0xa012367c, 40 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Sets bit 0 of the word register 0xcf03c780, then clears bit 1 of it (two read-modify-writes). Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a0123648 and
 * FUN_a012367c.
 */
#define REG (*(volatile unsigned int *)0xcf03c780)

void FUN_a0123654(void)
{
    REG |= 1;
    REG &= ~2u;
}
