/* hdcp_tx_hdmi_write_aksv  (FUN_a00c86bc)
 *
 * Send the monitor's own key-selection value to the receiver.
 * Name basis: proven - registers 0x1D..0x21 to DDC device 0x74, offset 0x10, five bytes (Aksv); prints
 *
 * Matching notes
 * --------------
 * FUN_a00c86bc (leon2s 0xa00c86bc-0xa00c8760, 164 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the loop counter is an unsigned char (the firmware clears it on both paths of the first test).
 */
extern int dbg_printf(const char *, ...);
extern unsigned int hdmi_tx_ddc_reset(unsigned char port);
extern int hdmi_tx_ddc_write(unsigned char port, unsigned char *buf, unsigned char device,
                        unsigned char offset, unsigned short count);
extern unsigned char hdmi_tx_reg_read8(unsigned char, int, unsigned short);

#define HDCP_DDC_DEVICE 0x74                    /* device address used for all handshake writes */
#define HDCP_DDC_AKSV   0x10                    /* offset of the 5-byte Aksv */
#define AKSV_LENGTH     5
#define ENGINE_AKSV_REG 0x1d                    /* registers 0x1D..0x21 of the output hold the value */

/*
 * Write the 5-byte Aksv held in registers 0x1D..0x21 of HDMI output `port` to the screen: DDC device 0x74,
 * offset 0x10. The DDC channel is reset first; the firmware prints "DDC_Check_Not_Available" when that reset
 * returns non-zero and "Send AKSV Error index = %02X" (with the result) when the write fails.
 *
 * Called from hdcp_tx_hdmi_state_run_checks.
 */
void hdcp_tx_hdmi_write_aksv(unsigned char port)
{
    unsigned char aksv[AKSV_LENGTH];
    unsigned char i;
    unsigned char result;

    if ((unsigned char)hdmi_tx_ddc_reset(port))
        dbg_printf("\nDDC_Check_Not_Available");
    for (i = 0; i < AKSV_LENGTH; i++)
        aksv[i] = hdmi_tx_reg_read8(port, 0, i + ENGINE_AKSV_REG);
    result = hdmi_tx_ddc_write(port, aksv, HDCP_DDC_DEVICE, HDCP_DDC_AKSV, AKSV_LENGTH);
    if (result)
        dbg_printf("\nSend AKSV Error index = %02X", result);
}
