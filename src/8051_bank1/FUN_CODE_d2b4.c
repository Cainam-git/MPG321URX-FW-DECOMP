/* 8051_bank1 FUN_CODE_d2b4 @ 0xd2b4
 * b = b * 8 (MUL AB, b kept in R6: needs REGFILE, dd74 / dcd3 leave R6 alone); reg 0x29 = (dd74(0x29) & 0x13) |
 * (b & 0xE0) | 0x04 via FUN_CODE_dcd3; then tail dcd3(0x1B, (a << 5) | (b & 0x1E)); a is the LARGE parameter slot
 * XDATA 0xA475. Only caller 0x8866. Byte-exact with OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC) ONLY (without REGFILE b goes to XDATA).
 */
unsigned char FUN_CODE_dd74(unsigned char reg);
void FUN_CODE_dcd3(unsigned char reg, unsigned char val);
void FUN_CODE_d2b4(unsigned char a, unsigned char b)
{
    b = b * 8;
    FUN_CODE_dcd3(0x29, (FUN_CODE_dd74(0x29) & 0x13) | (b & 0xe0) | 0x04);
    FUN_CODE_dcd3(0x1b, (a << 5) | (b & 0x1e));
}
