/* ddc_enable_slave  (FUN_CODE_9f04)
 *
 * Switch on the DDC/CI slave of the ports chosen by a bit mask.
 *   port_mask: port bits 0..7
 * Name basis: proven - sets the slave enable bit and 0xF8 mode per port; prints 'Enable I2C 7' for port 7;
 *   command 7 after ddc_set_slave_address
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_9f04 @ 0x9f04, OPTIMIZE(8,SPEED) LARGE.
 * Source form: the text is passed as one generic pointer (0xffdd52), which gives the firmware's
 * MOV R3,#0xff / MOV R2,#0xdd / MOV R1,#0x52 before the LCALL. The parameter is copied into the local 'ports'.
 */
extern unsigned char xdata reg_i2c0_address _at_ 0xf040;
extern unsigned char xdata reg_i2c0_event_ack _at_ 0xf03d;
extern unsigned char xdata reg_i2c0_mode _at_ 0xf03b;
extern unsigned char xdata reg_i2c1_address _at_ 0xf048;
extern unsigned char xdata reg_i2c1_event_ack _at_ 0xf045;
extern unsigned char xdata reg_i2c1_mode _at_ 0xf043;
extern unsigned char xdata reg_i2c2_address _at_ 0xf090;
extern unsigned char xdata reg_i2c2_event_ack _at_ 0xf08d;
extern unsigned char xdata reg_i2c2_mode _at_ 0xf08b;
extern unsigned char xdata reg_i2c3_address _at_ 0xf098;
extern unsigned char xdata reg_i2c3_event_ack _at_ 0xf095;
extern unsigned char xdata reg_i2c3_mode _at_ 0xf093;
extern unsigned char xdata reg_i2c4_address _at_ 0xf0a2;
extern unsigned char xdata reg_i2c4_event_ack _at_ 0xf09f;
extern unsigned char xdata reg_i2c4_mode _at_ 0xf09d;
extern unsigned char xdata reg_i2c5_address _at_ 0xf0bf;
extern unsigned char xdata reg_i2c5_event_ack _at_ 0xf0bc;
extern unsigned char xdata reg_i2c5_mode _at_ 0xf0ba;
extern unsigned char xdata reg_i2c6_address _at_ 0xf147;
extern unsigned char xdata reg_i2c6_event_ack _at_ 0xf144;
extern unsigned char xdata reg_i2c6_mode _at_ 0xf142;
extern unsigned char xdata reg_i2c7_address _at_ 0xf01b;
extern unsigned char xdata reg_i2c7_event_ack _at_ 0xf018;
extern unsigned char xdata reg_i2c7_mode _at_ 0xf016;

extern void lib_printf517(void *fmt, ...) large;

#define I2C_ADDRESS_ON         0x01  /* reg_i2c<N>_address bit 0: slave enable (ddc_disable_slave clears it) */
#define I2C_ACK_ALL_EVENTS     0xff  /* written to reg_i2c<N>_event_ack: acknowledge every pending event */
#define I2C_MODE_SLAVE_ENABLE  0xf8  /* reg_i2c<N>_mode value written when the slave is switched on */

/*
 * ddc_enable_slave - switch on the DDC/CI slave of every I2C unit whose bit is set in port_mask.
 *   port_mask  bit N = I2C unit N (0..7); units whose bit is clear are left as they are
 * For each chosen unit, in the order 0..7: set the enable bit 0 of its address register (the address in bits
 * 7..1 is kept), acknowledge all pending events and write the slave mode value 0xF8. Unit 7 also prints
 * "Enable I2C 7" first.
 * Only caller: mailbox command IPC_8051_CMD_ENABLE_DDC_SLAVE (7) in ipc_run_command, between
 * ddc_set_slave_address (which stores the addresses) and ddc_arm_slave, all three with the same port mask.
 */
void ddc_enable_slave(unsigned char port_mask) 
{
    unsigned char ports = port_mask;
    
    if (ports & 0x01) {
        reg_i2c0_address |= I2C_ADDRESS_ON;
        reg_i2c0_event_ack = I2C_ACK_ALL_EVENTS;
        reg_i2c0_mode = I2C_MODE_SLAVE_ENABLE;
    }
    if (ports & 0x02) {
        reg_i2c1_address |= I2C_ADDRESS_ON;
        reg_i2c1_event_ack = I2C_ACK_ALL_EVENTS;
        reg_i2c1_mode = I2C_MODE_SLAVE_ENABLE;
    }
    if (ports & 0x04) {
        reg_i2c2_address |= I2C_ADDRESS_ON;
        reg_i2c2_event_ack = I2C_ACK_ALL_EVENTS;
        reg_i2c2_mode = I2C_MODE_SLAVE_ENABLE;
    }
    if (ports & 0x08) {
        reg_i2c3_address |= I2C_ADDRESS_ON;
        reg_i2c3_event_ack = I2C_ACK_ALL_EVENTS;
        reg_i2c3_mode = I2C_MODE_SLAVE_ENABLE;
    }
    if (ports & 0x10) {
        reg_i2c4_address |= I2C_ADDRESS_ON;
        reg_i2c4_event_ack = I2C_ACK_ALL_EVENTS;
        reg_i2c4_mode = I2C_MODE_SLAVE_ENABLE;
    }
    if (ports & 0x20) {
        reg_i2c5_address |= I2C_ADDRESS_ON;
        reg_i2c5_event_ack = I2C_ACK_ALL_EVENTS;
        reg_i2c5_mode = I2C_MODE_SLAVE_ENABLE;
    }
    if (ports & 0x40) {
        reg_i2c6_address |= I2C_ADDRESS_ON;
        reg_i2c6_event_ack = I2C_ACK_ALL_EVENTS;
        reg_i2c6_mode = I2C_MODE_SLAVE_ENABLE;
    }
    if (ports & 0x80) {
        lib_printf517((void code *)0xffdd52 /* "Enable I2C 7\r\n" */);
        reg_i2c7_address |= I2C_ADDRESS_ON;
        reg_i2c7_event_ack = I2C_ACK_ALL_EVENTS;
        reg_i2c7_mode = I2C_MODE_SLAVE_ENABLE;
    }
}
