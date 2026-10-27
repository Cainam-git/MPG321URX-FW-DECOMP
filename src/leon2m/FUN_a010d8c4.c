/* FUN_a010d8c4 (leon2m 0xa010d8c4-0xa010d914, 80 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes 0x40020000 (c = 1) or 0x40000000 (other c) to the word registers 0xd003210c and 0xd003a10c. Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a010d89c and
 * FUN_a010d914.
 */
#define REGA (*(volatile unsigned int *)0xd003210c)
#define REGB (*(volatile unsigned int *)0xd003a10c)

void FUN_a010d8c4(unsigned char c)
{
    if (c == 1) {
        REGA = 0x40020000;
        REGB = 0x40020000;
    } else {
        REGA = 0x40000000;
        REGB = 0x40000000;
    }
}
