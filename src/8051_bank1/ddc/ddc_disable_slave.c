/* ddc_disable_slave  (FUN_CODE_c278)
 *
 * Switch off the DDC/CI slave of the ports chosen by a bit mask.
 *   ports: port bits 0..7
 * Name basis: derived - clears the enable bit 0 of the address registers 0xF040.. set by ddc_enable_slave;
 *   command 0x08 (main side ipc_8051_disable_ddc_slave)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c278, OPTIMIZE(8,SPEED) LARGE. The parameter is copied to R5 and each bit is tested in turn.
 */
extern xdata unsigned char reg_i2c0_address;
extern xdata unsigned char reg_i2c1_address;
extern xdata unsigned char reg_i2c2_address;
extern xdata unsigned char reg_i2c3_address;
extern xdata unsigned char reg_i2c4_address;
extern xdata unsigned char reg_i2c5_address;
extern xdata unsigned char reg_i2c6_address;
extern xdata unsigned char reg_i2c7_address;

/*
 * ddc_disable_slave - clear bit 0 of the address register (XDATA 0xF040, 0xF048, 0xF090, 0xF098, 0xF0A2, 0xF0BF,
 * 0xF147, 0xF01B) of each hardware I2C channel whose bit is set in ports (bit 0..7 = channel 0..7).
 * Command 8 (main side ipc_8051_disable_ddc_slave).
 */
void ddc_disable_slave(unsigned char ports)
{
    if (ports & 0x01)
        reg_i2c0_address &= 0xfe;
    if (ports & 0x02)
        reg_i2c1_address &= 0xfe;
    if (ports & 0x04)
        reg_i2c2_address &= 0xfe;
    if (ports & 0x08)
        reg_i2c3_address &= 0xfe;
    if (ports & 0x10)
        reg_i2c4_address &= 0xfe;
    if (ports & 0x20)
        reg_i2c5_address &= 0xfe;
    if (ports & 0x40)
        reg_i2c6_address &= 0xfe;
    if (ports & 0x80)
        reg_i2c7_address &= 0xfe;
}
