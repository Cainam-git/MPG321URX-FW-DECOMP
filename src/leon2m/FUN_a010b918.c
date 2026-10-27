/* FUN_a010b918 (leon2m 0xa010b918-0xa010b948, 48 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears bit 0 of the word registers 0xd0030004 and 0xd0038004 (read-modify-write each). Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a010b8e8 and FUN_a010b948.
 */
#define REGA (*(volatile unsigned int *)0xd0030004)
#define REGB (*(volatile unsigned int *)0xd0038004)

void FUN_a010b918(void)
{
    REGA &= ~1u;
    REGB &= ~1u;
}
