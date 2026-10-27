/* FUN_a01075a8 (leon2m 0xa01075a8-0xa01075f8, 80 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears bit 4 of the word register 0xcf00eac8, then sets (c = 1) or clears bit 0 of the word register 0xcf00ea00.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a0107554 and FUN_a01075f8.
 */
#define REGC8 (*(volatile unsigned int *)0xcf00eac8)
#define REG00 (*(volatile unsigned int *)0xcf00ea00)

void FUN_a01075a8(unsigned char c)
{
    REGC8 &= ~0x10u;
    if (c == 1)
        REG00 |= 1;
    else
        REG00 &= ~1u;
}
