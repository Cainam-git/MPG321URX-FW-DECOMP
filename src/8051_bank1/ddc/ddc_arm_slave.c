/* ddc_arm_slave  (FUN_CODE_c2d3)
 *
 * Arm the DDC/CI slave of the ports chosen by a bit mask for the next request.
 *   ports: port bits 0..7
 * Name basis: derived - sets bit 6 of the channel control registers 0xF039.. (same write as the interrupt's
 *   re-arm); last step of command 7
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c2d3, OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned char xdata reg_i2c0_ctrl;
extern unsigned char xdata reg_i2c1_ctrl;
extern unsigned char xdata reg_i2c2_ctrl;
extern unsigned char xdata reg_i2c3_ctrl;
extern unsigned char xdata reg_i2c4_ctrl;
extern unsigned char xdata reg_i2c5_ctrl;
extern unsigned char xdata reg_i2c6_ctrl;
extern unsigned char xdata reg_i2c7_ctrl;

/*
 * ddc_arm_slave - set bit 6 of the control register (XDATA 0xF039, 0xF041, 0xF089, 0xF091, 0xF09B, 0xF0B8, 0xF140,
 * 0xF014) of each hardware I2C channel whose bit is set in ports (bit 0..7 = channel 0..7). Last step of command 7.
 */
void ddc_arm_slave(unsigned char ports)
{
    unsigned char mask;
    
    mask = ports;
    if (mask & 0x01) {
        reg_i2c0_ctrl |= 0x40;
    }
    if (mask & 0x02) {
        reg_i2c1_ctrl |= 0x40;
    }
    if (mask & 0x04) {
        reg_i2c2_ctrl |= 0x40;
    }
    if (mask & 0x08) {
        reg_i2c3_ctrl |= 0x40;
    }
    if (mask & 0x10) {
        reg_i2c4_ctrl |= 0x40;
    }
    if (mask & 0x20) {
        reg_i2c5_ctrl |= 0x40;
    }
    if (mask & 0x40) {
        reg_i2c6_ctrl |= 0x40;
    }
    if (mask & 0x80) {
        reg_i2c7_ctrl |= 0x40;
    }
}
