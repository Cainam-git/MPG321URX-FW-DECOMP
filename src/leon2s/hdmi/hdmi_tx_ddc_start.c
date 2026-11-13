/* hdmi_tx_ddc_start  (FUN_a00c8048)
 *
 * Program the DDC master with a device address, an offset and a byte count.
 * Returns: 1 when the count is 0
 * Name basis: proven - header registers 0xED..0xF3
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c8048, flags -mcpu=v8 -Os -g.
 * Source form: the result is an unsigned char set in both arms and returned as ok & 1. The register writes
 * are the same as at the start of hdmi_tx_ddc_write.
 */
extern void hdmi_tx_reg_write8(unsigned char, int, int, unsigned char);

#define HDMI_TX_BANK_CORE 0             /* bank 0 of an HDMI transmitter's registers */
#define DDC_DEVICE_REG 0xed             /* DDC master: device address */
#define DDC_OFFSET_REG 0xef             /* DDC master: offset in the device */
#define DDC_COUNT_LOW_REG 0xf0          /* DDC master: byte count, low byte */
#define DDC_COUNT_HIGH_REG 0xf1         /* DDC master: byte count, high byte */
#define DDC_CONTROL_REG 0xf3            /* DDC master: control */
#define DDC_CONTROL_START 2             /* control value written by hdmi_tx_ddc_start */

/*
 * Program the DDC master of an HDMI output with a device address, an offset and a byte count, and write 2 to
 * the control register 0xF3 (hdmi_tx_ddc_write writes 7 there instead). Register 0xEE is set to 0.
 * Returns 1 without any access when the count is 0, else 0.
 *   port:   HDMI TX port
 *   device: written to register 0xED
 *   offset: written to register 0xEF
 *   count:  number of bytes; low byte to 0xF0, high byte to 0xF1
 */
unsigned char hdmi_tx_ddc_start(unsigned char port, unsigned char device, unsigned char offset, unsigned short count)
{
    unsigned char ok = 0;

    if (count == 0) {
        ok = 1;
    } else {
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_CORE, DDC_DEVICE_REG, device);
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_CORE, 0xee, 0);
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_CORE, DDC_OFFSET_REG, offset);
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_CORE, DDC_COUNT_LOW_REG, count);
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_CORE, DDC_COUNT_HIGH_REG, count >> 8);
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_CORE, DDC_CONTROL_REG, DDC_CONTROL_START);
    }
    return ok & 1;
}
