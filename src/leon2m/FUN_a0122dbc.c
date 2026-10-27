/* FUN_a0122dbc (leon2m 0xa0122dbc-0xa0122e24, 104 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Saves the low byte of the word register 0xcf03d024; when a is 0xf writes 0xc to it and 0xff to 0xcf01d858; then
 * writes a to 0xcf03d024, v to the register 0xcf000000 + 4 * (b + 0x7600) and restores 0xcf03d024. Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a0122d5c and
 * FUN_a0122e24.
 */
#define REG024 (*(volatile unsigned int *)0xcf03d024)
#define REG858 (*(volatile unsigned int *)0xcf01d858)

void FUN_a0122dbc(unsigned char a, unsigned char b, unsigned char v)
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
