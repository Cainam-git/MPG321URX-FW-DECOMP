/* leon2m FUN_a0104f48 @ 0xa0104f48-0xa0105150 (130 words), flags -mcpu=v8 -O3 -g.
 * When a is 0, clears bit 0 of the word registers 0xcf012890 and 0xcf012990. Otherwise mode != 0 runs
 * FUN_a0104d18(a, b) and mode 0 runs FUN_a0104eb0(a) (bits 1..4, then 5..7 of the byte a merged into 0xcf012890,
 * each result also written to 0xcf012990, then bit 0 of both set or cleared from bit 26 of *DAT_a802d6a4).
 * Source form: FUN_a0104d18, FUN_a0104eb0 and the three routines FUN_a0104eb0 calls (FUN_a0104e50, FUN_a0104e80,
 * FUN_a0104cb0) are the matched same-file functions, defined here and inlined by GCC.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define REG90 (*(volatile unsigned int *)0xcf012890)
#define REG190 (*(volatile unsigned int *)0xcf012990)
extern unsigned int *DAT_a802d6a4;

void FUN_a0104d18(unsigned short a, unsigned short b)
{
    unsigned char d, v;

    if (!(a >= 25 && a <= 500))
        a = 100;
    if (!(b >= 5 && b <= 5000))
        b = 150;
    d = 1500 / a;
    v = ((unsigned int)(b * a) << 15) / 15000000;
    R(0xcf012898) = d;
    R(0xcf01289c) = v;
    R(0xcf012898) |= 0x80;
    R(0xcf012998) = d;
    R(0xcf01299c) = v;
    R(0xcf012998) |= 0x80;
    if (*DAT_a802d6a4 & 0x4000000) {
        R(0xcf012890) |= 1;
        R(0xcf012990) |= 1;
    } else {
        R(0xcf012890) &= ~1;
        R(0xcf012990) &= ~1;
    }
}

void FUN_a0104cb0(void)
{
    if (*DAT_a802d6a4 & 0x4000000) {
        REG90 |= 1;
        REG190 |= 1;
    } else {
        REG90 &= ~1u;
        REG190 &= ~1u;
    }
}

void FUN_a0104e50(unsigned int v)
{
    unsigned char x = (REG90 & ~0x1eu) | (v & 0x1e);

    REG90 = x;
    REG190 = x;
}

void FUN_a0104e80(unsigned int v)
{
    unsigned char x = (REG90 & 0x1f) | (v & ~0x1fu);

    REG90 = x;
    REG190 = x;
}

void FUN_a0104eb0(unsigned char v)
{
    FUN_a0104e50(v);
    FUN_a0104e80(v);
    FUN_a0104cb0();
}

void FUN_a0104f48(unsigned char mode, unsigned short a, unsigned short b)
{
    if (a != 0) {
        if (mode)
            FUN_a0104d18(a, b);
        else
            FUN_a0104eb0(a);
    } else {
        R(0xcf012890) &= ~1;
        R(0xcf012990) &= ~1;
    }
}
