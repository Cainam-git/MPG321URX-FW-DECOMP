/* reg_write_sync_meter_mode  (FUN_CODE_d2b4)
 *
 * Set two mode fields of the sync measurement block.
 *   a: field written to reg 0x1B bits 5..7
 *   b: field value
 * Name basis: descriptive - writes regs 0x29 and 0x1B of the block read by the standby signal checks
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d2b4 @ 0xd2b4  Byte-exact with OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC) only.
 * Source form: 'b' is multiplied by 8 in place (MUL AB) and kept in R6; that needs REGFILE (without it b goes
 * to XDATA). The two callee routines leave R6 alone. 'a' is the LARGE parameter slot XDATA 0xA475. The build was not
 * exact when the parameters were renamed.
 */
unsigned char reg_read_sync_meter_byte(unsigned char reg);
void reg_write_sync_meter_byte(unsigned char reg, unsigned char val);

/*
 * Set two fields of the sync measurement block. b is multiplied by 8
 * first. Register 0x29 = (register 0x29 & 0x13) | (b & 0xE0) | 0x04;
 * register 0x1B = (a << 5) | (b & 0x1E). Only caller: the code at 0x8866.
 */
void reg_write_sync_meter_mode(unsigned char a, unsigned char b)
{
    b = b * 8;
    reg_write_sync_meter_byte(0x29, (reg_read_sync_meter_byte(0x29) & 0x13) | (b & 0xe0) | 0x04);
    reg_write_sync_meter_byte(0x1b, (a << 5) | (b & 0x1e));
}
