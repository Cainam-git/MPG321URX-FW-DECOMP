/* FUN_a010d838 (leon2m 0xa010d838-0xa010d874, 60 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Replaces bits 0 and 16..18 of the word register 0xd003002c (mask 0xfff8fffe) with c << 16 and writes the result
 * to 0xd003002c and 0xd003802c. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a010d530 and FUN_a010d874.
 */
#define REGA (*(volatile unsigned int *)0xd003002c)
#define REGB (*(volatile unsigned int *)0xd003802c)

void FUN_a010d838(unsigned char c)
{
    unsigned int x = (REGA & 0xfff8fffe) | (c << 16);

    REGA = x;
    REGB = x;
}
