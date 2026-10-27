/* FUN_a0101e70 (leon2m 0xa0101e70-0xa0101e9c, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears bit 0 of the word registers 0xcf012890 and 0xcf012990 (read-modify-write each). Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a0101e68 and FUN_a0101e9c.
 */
#define REGA (*(volatile unsigned int *)0xcf012890)
#define REGB (*(volatile unsigned int *)0xcf012990)

void FUN_a0101e70(void)
{
    REGA &= ~1u;
    REGB &= ~1u;
}
