/* FUN_a011e5fc (leon2m 0xa011e5fc-0xa011e630, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores bits 8..9 of v into bits 4..5 of the word register 0xcf016184 ((v >> 4) & 0x30, other bits kept) and
 * writes v & 0xff to the word register 0xcf016188. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a011e4c8 and FUN_a011e630.
 */
#define REG184 (*(volatile unsigned int *)0xcf016184)
#define REG188 (*(volatile unsigned int *)0xcf016188)

void FUN_a011e5fc(unsigned int v)
{
    REG184 = (REG184 & ~0x30u) | ((v >> 4) & 0x30);
    REG188 = v & 0xff;
}
