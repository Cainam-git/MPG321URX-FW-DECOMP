/* dp_clear_start_bits  (FUN_a00abb30)
 *
 * Clear the start-up bits of a DP receiver around register 0xC0 bit 4.
 *   port: DP receiver 0/1
 * Name basis: descriptive - registers 0xCF01143C / 0xCF011674 / 0xCF01147C; caller dp_start_port
 *
 * Matching notes
 * --------------
 * FUN_a00abb30 (leon2s), flags -mcpu=v8 -Os -g.
 * Source form: the four bits of register 0xCF01147C are cleared by four separate read-modify-writes.
 */
#define REG(addr) (*(volatile unsigned int *)(addr))
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned int, unsigned int);

/*
 * Clear bits 0..2 of register 0xCF01143C and bit 7 of 0xCF011674, clear bit 4 of receiver register 0xC0, then
 * clear bits 4, 1, 2 and 3 of register 0xCF01147C, one bit at a time. Counterpart of dp_set_reg1143c_bits for
 * the first of them. dp_start_port calls it.
 *   port: DP receiver 0 or 1
 */
void dp_clear_start_bits(unsigned char port)
{
    REG(0xcf01143c) &= ~7;
    REG(0xcf011674) &= ~0x80;
    dp_reg_update_bits(port, 0xc0, 0x10, 0);
    REG(0xcf01147c) &= ~0x10;
    REG(0xcf01147c) &= ~2;
    REG(0xcf01147c) &= ~4;
    REG(0xcf01147c) &= ~8;
}
