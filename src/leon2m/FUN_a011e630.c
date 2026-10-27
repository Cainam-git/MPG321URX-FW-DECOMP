/* FUN_a011e630 (leon2m 0xa011e630-0xa011e65c, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the halfword ((register 0xcf016184 & 0x30) << 4) + register 0xcf016188. Nothing in the image refers to
 * it: no call, branch, sethi/or constant or address word. It lies between FUN_a011e5fc and FUN_a011e65c.
 */
#define REG184 (*(volatile unsigned int *)0xcf016184)
#define REG188 (*(volatile unsigned int *)0xcf016188)

unsigned short FUN_a011e630(void)
{
    return ((REG184 & 0x30) << 4) + REG188;
}
