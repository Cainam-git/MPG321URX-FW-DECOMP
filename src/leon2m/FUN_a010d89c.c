/* FUN_a010d89c (leon2m 0xa010d89c-0xa010d8c4, 40 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears bit 0 of the word registers 0xd0032000 and 0xd003a000 (read-modify-write each). Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a010d874 and FUN_a010d8c4.
 */
#define REGA (*(volatile unsigned int *)0xd0032000)
#define REGB (*(volatile unsigned int *)0xd003a000)

void FUN_a010d89c(void)
{
    REGA &= ~1u;
    REGB &= ~1u;
}
