/* leon2m FUN_a0150b8c @ 0xa0150b8c-0xa0150da4 (134 words), -mcpu=v8 -O3 -g. Called by FUN_a01471a0.
 * Builds five tables of 12 halfwords on the stack (m0 = 0x100, 0, 0, 0x80, 0, 0x100, 0, 0x80, 0, 0, 0x100, 0x80;
 * m1..m4 as listed below) and a table of pointers to them. sel <= 4 calls FUN_a00f6fe4(1, 2, table sel, 0xff),
 * any other value FUN_a00f6fe4(1, 2, 0, 0xff).
 * Source form: each table is a const local union of 12 halfwords and 6 words, initialised through the halfword
 * array; GCC clears such a union first (three std of zero) and then stores the non-zero halfwords, table by table.
 */
extern void FUN_a00f6fe4(unsigned char, unsigned char, const unsigned short *, int);

union Tab { unsigned short h[12]; unsigned int w[6]; };

void FUN_a0150b8c(unsigned int sel)
{
    const union Tab m0 = { {0x100, 0, 0, 0x80, 0, 0x100, 0, 0x80, 0, 0, 0x100, 0x80} };
    const union Tab m1 = { {0x131, 0x447, 0x16, 0x80, 0x40b, 0x117, 0x40c, 0x80, 0x413, 0xe, 0x105, 0x80} };
    const union Tab m2 = { {0x162, 0x48e, 0x2c, 0x80, 0x416, 0x12e, 0x418, 0x80, 0x427, 0x1c, 0x10b, 0x80} };
    const union Tab m3 = { {0x176, 0x4ab, 0x35, 0x80, 0x41d, 0x13c, 0x41f, 0x80, 0x436, 0x15, 0x121, 0x80} };
    const union Tab m4 = { {0x18b, 0x4c9, 0x3e, 0x80, 0x424, 0x149, 0x426, 0x80, 0x445, 0xe, 0x137, 0x80} };
    const unsigned short *tab[5] = {m0.h, m1.h, m2.h, m3.h, m4.h};

    if (sel <= 4)
        FUN_a00f6fe4(1, 2, tab[sel], 0xff);
    else
        FUN_a00f6fe4(1, 2, 0, 0xff);
}
