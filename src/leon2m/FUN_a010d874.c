/* FUN_a010d874 (leon2m 0xa010d874-0xa010d89c, 40 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Sets bit 0 of the word registers 0xd0032000 and 0xd003a000 (read-modify-write each). Nothing in the image refers
 * to it: no call, branch, sethi/or constant or address word. It lies between FUN_a010d838 and FUN_a010d89c.
 */
#define REGA (*(volatile unsigned int *)0xd0032000)
#define REGB (*(volatile unsigned int *)0xd003a000)

void FUN_a010d874(void)
{
    REGA |= 1;
    REGB |= 1;
}
