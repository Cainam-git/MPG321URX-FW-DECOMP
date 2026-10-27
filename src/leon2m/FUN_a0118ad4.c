/* FUN_a0118ad4 (leon2m 0xa0118ad4-0xa0118af0, 28 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears bit 7 (0x80) of the word register 0xcf012ff0 (read-modify-write). Nothing in the image refers to it: no
 * call, branch, sethi/or constant or address word. It lies between FUN_a0118a80 and FUN_a0118af0.
 */
#define REG (*(volatile unsigned int *)0xcf012ff0)

void FUN_a0118ad4(void)
{
    REG &= ~0x80u;
}
