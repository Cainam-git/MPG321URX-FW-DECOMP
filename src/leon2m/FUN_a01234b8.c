/* FUN_a01234b8 (leon2m 0xa01234b8-0xa0123574, 188 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears the word register 0xcf011814, then performs four writes through the FUN_a0122dbc sequence (save
 * 0xcf03d024, select a, write v to register 0x7600 + b, restore): (0xc, 0x11, 1), (0xc, 0x14, 0x55), (0xc, 0x12,
 * 0x51), (0, 3, 0xf7). Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It
 * lies between FUN_a0123384 and FUN_a0123574. Source form: the FUN_a0122dbc body is a static helper inlined four
 * times.
 */
#define REG024 (*(volatile unsigned int *)0xcf03d024)
#define REG858 (*(volatile unsigned int *)0xcf01d858)
#define REG814 (*(volatile unsigned int *)0xcf011814)
static void wr(unsigned char a, unsigned char b, unsigned char v)
{
    unsigned char save = REG024;

    if (a == 0xf) {
        REG024 = 0xc;
        REG858 = 0xff;
    }
    REG024 = a;
    *(volatile unsigned int *)(0xcf000000 | ((b + 0x7600) << 2)) = v;
    REG024 = save;
}
void FUN_a01234b8(void)
{
    REG814 = 0;
    wr(0xc, 0x11, 1);
    wr(0xc, 0x14, 0x55);
    wr(0xc, 0x12, 0x51);
    wr(0, 3, 0xf7);
}
