/* FUN_a010ec70 (leon2m 0xa010ec70-0xa010eca8, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Replaces bits 16..18 of the word register 0xd003002c with c << 16 and writes the result to 0xd003002c and
 * 0xd003802c. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies
 * between FUN_a010ebd0 and FUN_a010eca8.
 */
#define REGA (*(volatile unsigned int *)0xd003002c)
#define REGB (*(volatile unsigned int *)0xd003802c)

void FUN_a010ec70(unsigned char c)
{
    unsigned int x = (REGA & ~0x70000u) | (c << 16);

    REGA = x;
    REGB = x;
}
