/* hdmi_tx_ddc_write  (FUN_a00c80f0)
 *
 * Write a block of bytes to a device on the HDMI output's DDC channel.
 * Name basis: proven - header registers, then the data register 0xF4 with a wait per byte
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c80f0, flags -mcpu=v8 -Os -g.
 * Source form: the count is copied to an unsigned short and tested; the port is masked to a byte again inside
 * the loop; the declared-but-unused local `unused` is kept because it affects the register allocation.
 */
extern int hdmi_tx_reg_read8();
extern void hdmi_tx_reg_write8();
extern int timer_delay_long_units();

#define HDMI_TX_BANK_CORE 0             /* bank 0 of an HDMI transmitter's registers */
#define DDC_DEVICE_REG 0xed             /* DDC master: device address */
#define DDC_OFFSET_REG 0xef             /* DDC master: offset in the device */
#define DDC_COUNT_LOW_REG 0xf0          /* DDC master: byte count, low byte */
#define DDC_COUNT_HIGH_REG 0xf1         /* DDC master: byte count, high byte */
#define DDC_STATUS_REG 0xf2             /* DDC master: status */
#define DDC_CONTROL_REG 0xf3            /* DDC master: control */
#define DDC_DATA_REG 0xf4               /* DDC master: data */
#define DDC_CONTROL_WRITE 7             /* control value written by hdmi_tx_ddc_write */
#define DDC_STATUS_WAIT_BIT 8           /* bit 3 of the status register: set until the byte is taken */

/*
 * Write `length` bytes to a device on the DDC channel of an HDMI output. The header registers are set like
 * hdmi_tx_ddc_start does but with 7 in the control register; then each byte goes to the data register 0xF4 and
 * the routine waits (without a limit) until bit 3 of status register 0xF2 is 0. After the last byte it waits
 * timer_delay_long_units(2).
 * Returns 1 without any access when length is 0, else 0.
 *   port:   HDMI TX port
 *   data:   the bytes to write
 *   device: written to register 0xED
 *   offset: written to register 0xEF
 *   length: number of bytes; low byte to 0xF0, high byte to 0xF1
 */
int hdmi_tx_ddc_write(unsigned char port, unsigned char *data,
                 unsigned char device, unsigned char offset, unsigned short length)
{
    unsigned int unused;
    unsigned short count;
    unsigned char port_byte;
    unsigned int status;
    unsigned short i;

    count = (unsigned short)length;
    if (count != 0) {
        port_byte = port & 0xff;
        hdmi_tx_reg_write8(port_byte, HDMI_TX_BANK_CORE, DDC_DEVICE_REG, device);
        hdmi_tx_reg_write8(port_byte, HDMI_TX_BANK_CORE, 0xee, 0);
        hdmi_tx_reg_write8(port_byte, HDMI_TX_BANK_CORE, DDC_OFFSET_REG, offset);
        hdmi_tx_reg_write8(port_byte, HDMI_TX_BANK_CORE, DDC_COUNT_LOW_REG, (unsigned char)length);
        hdmi_tx_reg_write8(port_byte, HDMI_TX_BANK_CORE, DDC_COUNT_HIGH_REG, (unsigned char)(length >> 8));
        hdmi_tx_reg_write8(port_byte, HDMI_TX_BANK_CORE, DDC_CONTROL_REG, DDC_CONTROL_WRITE);

        for (i = 0; i < count; i++) {
            port_byte = port & 0xff;
            hdmi_tx_reg_write8(port_byte, HDMI_TX_BANK_CORE, DDC_DATA_REG, *data);
            data++;
            do {
                status = hdmi_tx_reg_read8(port_byte, HDMI_TX_BANK_CORE, DDC_STATUS_REG);
            } while ((status & DDC_STATUS_WAIT_BIT) != 0);
        }
        timer_delay_long_units(2);
        return 0;
    }
    return 1;
}
