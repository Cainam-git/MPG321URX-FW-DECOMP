/* FUN_a011e65c (leon2m 0xa011e65c-0xa011e690, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores bits 8..9 of v into bits 4..5 of the word register 0xcf016404 ((v >> 4) & 0x30, other bits kept) and
 * writes v & 0xff to the word register 0xcf016408. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a011e630 and FUN_a011e690.
 */
#define REG404 (*(volatile unsigned int *)0xcf016404)
#define REG408 (*(volatile unsigned int *)0xcf016408)

void FUN_a011e65c(unsigned int v)
{
    REG404 = (REG404 & ~0x30u) | ((v >> 4) & 0x30);
    REG408 = v & 0xff;
}
