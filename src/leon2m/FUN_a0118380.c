/* FUN_a0118380 (leon2m 0xa0118380-0xa01183c0, 64 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Sets bit 0 of the word registers 0xcf0129d0, 0xcf012b10 and 0xcf014090 (read-modify-write each). Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a0118324 and
 * FUN_a01183c0.
 */
#define REGA (*(volatile unsigned int *)0xcf0129d0)
#define REGB (*(volatile unsigned int *)0xcf012b10)
#define REGC (*(volatile unsigned int *)0xcf014090)

void FUN_a0118380(void)
{
    REGA |= 1;
    REGB |= 1;
    REGC |= 1;
}
