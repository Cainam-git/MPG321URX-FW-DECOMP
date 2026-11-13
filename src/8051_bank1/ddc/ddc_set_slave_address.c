/* ddc_set_slave_address  (FUN_CODE_bde9)
 *
 * Set the DDC/CI slave address of the ports chosen by a bit mask.
 *   ports: port bits 0..7
 *   address: slave address
 * Name basis: proven - command 7 (docs/MAP.md: I2C slave address 0x6E for MSI's tool); address registers
 *   0xF040.. bits 1..7
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_bde9, OPTIMIZE(8,SPEED) LARGE. Keil copies the first parameter with `MOV R4,AR7`, as in the target.
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
 * ddc_set_slave_address - write a slave address into the address registers of the hardware I2C channels chosen by
 * the bit mask ports (bit 0..7 = channel 0..7: XDATA 0xF040, 0xF048, 0xF090, 0xF098, 0xF0A2, 0xF0BF, 0xF147, 0xF01B).
 *   ports: channel bits
 *   address: slave address; bit 0 is dropped, and bit 0 of each register keeps its value
 * Command 7 (IPC_8051_CMD_ENABLE_DDC_SLAVE) uses it (the tool's address is 0x6E, docs/MAP.md).
 */
void ddc_set_slave_address(unsigned char ports, unsigned char address)
{
    address &= 0xfe;
    
    if (ports & 0x01) {
        reg_i2c0_address = (reg_i2c0_address & 0x01) | address;
    }
    if (ports & 0x02) {
        reg_i2c1_address = (reg_i2c1_address & 0x01) | address;
    }
    if (ports & 0x04) {
        reg_i2c2_address = (reg_i2c2_address & 0x01) | address;
    }
    if (ports & 0x08) {
        reg_i2c3_address = (reg_i2c3_address & 0x01) | address;
    }
    if (ports & 0x10) {
        reg_i2c4_address = (reg_i2c4_address & 0x01) | address;
    }
    if (ports & 0x20) {
        reg_i2c5_address = (reg_i2c5_address & 0x01) | address;
    }
    if (ports & 0x40) {
        reg_i2c6_address = (reg_i2c6_address & 0x01) | address;
    }
    if (ports & 0x80) {
        reg_i2c7_address = (reg_i2c7_address & 0x01) | address;
    }
}
