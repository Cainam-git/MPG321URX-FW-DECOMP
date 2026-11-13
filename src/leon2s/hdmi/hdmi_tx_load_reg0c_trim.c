/* hdmi_tx_load_reg0c_trim  (FUN_a008e004)
 *
 * Load HDMI TX register 0x0C from the calibration record, default 0x0C.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - bytes 3 / 9 of record 0xA807D3C1 when its header is 0xA0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008e004 @ 0xa008e004-0xa008e054, flags -mcpu=v8 -Os -g (leaf apart from the tail call).
 */
extern unsigned char hdmi_tx_reg0c_trims[];
extern void hdmi_tx_write_reg0c(unsigned char, unsigned char);

#define REG0C_DEFAULT 0xc

/*
 * Write HDMI TX register 0x0C. The value is 0x0C unless byte 0 of hdmi_tx_reg0c_trims is 0xA0; then it is byte 3
 * of the table for port 0 and byte 9 for port 1.
 *   port: HDMI TX port 0/1.  Called by hdmi_tx_phy_enable_outputs.
 */
void hdmi_tx_load_reg0c_trim(unsigned char port)
{
    unsigned char value = REG0C_DEFAULT;

    if (hdmi_tx_reg0c_trims[0] == 0xa0) {
        if (port == 0)
            value = hdmi_tx_reg0c_trims[3];
        else if (port == 1)
            value = hdmi_tx_reg0c_trims[9];
    }
    hdmi_tx_write_reg0c(port, value);
}
