/* FUN_a010b884 (leon2m 0xa010b884-0xa010b8e8, 100 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * For c = 1: clears bit 7 and sets bit 6 of the word register 0xcf00b844 and sets bit 7 of 0xcf00b870; otherwise
 * sets bits 6..7 of 0xcf00b844 and clears bit 7 of 0xcf00b870. Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a010b77c and FUN_a010b8e8.
 */
#define REG44 (*(volatile unsigned int *)0xcf00b844)
#define REG70 (*(volatile unsigned int *)0xcf00b870)

void FUN_a010b884(unsigned char c)
{
    if (c == 1) {
        REG44 &= ~0x80u;
        REG44 |= 0x40;
        REG70 |= 0x80;
    } else {
        REG44 |= 0xc0;
        REG70 &= ~0x80u;
    }
}
