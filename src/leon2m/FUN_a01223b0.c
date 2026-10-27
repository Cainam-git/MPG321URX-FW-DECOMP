/* FUN_a01223b0 (leon2m 0xa01223b0-0xa0122480, 208 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes a fixed sequence of 22 constants (0, 0x80, 0xff, 0x82, 0x70, 0x22) to word registers in the
 * 0xcf01cc58..0xcf01cf9c block, in the order of the source statements. Called by FUN_a01413d0. It lies between
 * FUN_a01222c8 and FUN_a0122480. Source form: one volatile word store per statement.
 */
#define REG(a) (*(volatile unsigned int *)(a))

void FUN_a01223b0(void)
{
    REG(0xcf01cd10) = 0;
    REG(0xcf01cd9c) = 0;
    REG(0xcf01ce28) = 0;
    REG(0xcf01ceb4) = 0;
    REG(0xcf01cd18) = 0;
    REG(0xcf01cda4) = 0;
    REG(0xcf01ce30) = 0;
    REG(0xcf01cebc) = 0;
    REG(0xcf01ccec) = 0x80;
    REG(0xcf01cd78) = 0x80;
    REG(0xcf01ce04) = 0x80;
    REG(0xcf01ce90) = 0x80;
    REG(0xcf01cd28) = 0xff;
    REG(0xcf01cdb4) = 0xff;
    REG(0xcf01ce40) = 0xff;
    REG(0xcf01cecc) = 0xff;
    REG(0xcf01cf94) = 0x82;
    REG(0xcf01cf9c) = 0x70;
    REG(0xcf01cc6c) = 0x22;
    REG(0xcf01cc70) = 0x22;
    REG(0xcf01cc68) = 0x22;
    REG(0xcf01cc58) = 0;
}
