/* fwupd_svc_read_register  (FUN_CODE_e105)
 *
 * Read one register of the main chip through the service link.
 * Returns: register value
 * Name basis: derived - service packet 03 87 <register> to I2C address 0x6E
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e105 @ 0xe105, OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned char xdata fwupd_svc_packet[];
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char i2c_read_packet(unsigned char addr, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);
void fwupd_svc_read_reply_entry(void);
void fwupd_svc_read_reply(unsigned char *buf);
void timer_delay_units(unsigned char t);
unsigned char fwupd_svc_write_register(unsigned int reg, unsigned char val);

#define SVC_ADDRESS         0x6e    /* I2C slave address of every service packet */
#define SVC_CMD_READ_REG    0x87    /* 03 87 <reg high byte> <reg byte> */
#define SVC_WAIT_SHORT      100     /* fwupd_wait_ready_line limit */
#define REPLY_VALUE         2       /* reply byte that holds the register value */

/* Send the packet 03 87 <reg high byte> <reg byte>, wait on the ready line, read the reply packet into
 * fwupd_svc_packet and return its byte 2.
 * Unlike fwupd_svc_read_reply (wait of 2 units) this reads the reply itself and waits 5 delay units after it.
 * Callers: flash_identify_chip (id bytes), fwupd_svc_spi_transfer (the SPI window), fwupd_svc_claim_link and
 * fwupd_svc_set_control_bit (read, change, write back), fwupd_run_isp_write (keeps register 0xF1E0),
 * fwupd_svc_read_flash_status (register 0xF880). */
unsigned char fwupd_svc_read_register(unsigned int reg)
{
    fwupd_svc_packet[0] = 3;
    fwupd_svc_packet[1] = SVC_CMD_READ_REG;
    fwupd_svc_packet[2] = reg >> 8;
    fwupd_svc_packet[3] = reg;
    i2c_write_packet(SVC_ADDRESS, 4, fwupd_svc_packet);
    fwupd_wait_ready_line(SVC_WAIT_SHORT);
    i2c_read_packet(SVC_ADDRESS, fwupd_svc_packet);
    timer_delay_units(5);
    return fwupd_svc_packet[REPLY_VALUE];
}
