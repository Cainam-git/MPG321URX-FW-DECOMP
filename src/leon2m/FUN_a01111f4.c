/* FUN_a01111f4 (leon2m 0xa01111f4-0xa01112c0, 204 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes a fixed sequence of 22 constants (0, 0xff, 0x82, 0x70, 0x22) to word registers in the
 * 0xcf01cc58..0xcf01cfac block, in the order of the source statements. Called by FUN_a01413d0. It lies between
 * FUN_a01111e4 and FUN_a01112c0. Source form: one volatile word store per statement.
 */
#define REG(a) (*(volatile unsigned int *)(a))

void FUN_a01111f4(void)
{
    REG(0xcf01cd10) = 0;
    REG(0xcf01cd9c) = 0;
    REG(0xcf01ce28) = 0;
    REG(0xcf01ceb4) = 0;
    REG(0xcf01ccf8) = 0;
    REG(0xcf01cd84) = 0;
    REG(0xcf01ce10) = 0;
    REG(0xcf01ce9c) = 0;
    REG(0xcf01cd28) = 0xff;
    REG(0xcf01cdb4) = 0xff;
    REG(0xcf01ce40) = 0xff;
    REG(0xcf01cecc) = 0xff;
    REG(0xcf01ccc0) = 0;
    REG(0xcf01cfac) = 0;
    REG(0xcf01cf94) = 0x82;
    REG(0xcf01cf08) = 0x82;
    REG(0xcf01cf9c) = 0x70;
    REG(0xcf01cf10) = 0x70;
    REG(0xcf01cc6c) = 0x22;
    REG(0xcf01cc70) = 0x22;
    REG(0xcf01cc68) = 0x22;
    REG(0xcf01cc58) = 0;
}
