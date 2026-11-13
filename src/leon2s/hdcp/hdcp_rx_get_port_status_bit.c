/* hdcp_rx_get_port_status_bit  (FUN_a00c0a04)
 *
 * Return a status bit for the first input record that has a given flag bit set.
 * Returns: 0 or 1
 * Name basis: descriptive - six 16-byte records at 0xA807D5C8
 *
 * Matching notes
 * --------------
 * FUN_a00c0a04 (leon2s 0xa00c0a04-0xa00c0a88, 132 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the bit-5 test is an if with two returns (a "!= 0" expression folds into a shift).
 */
/* One 16-byte record per input (hdcp_rx_record_hdmi20, then _hdmi21, then _dp: inputs 0..5). */
struct hdcp_rx_record { unsigned char byte_0x0[4]; unsigned char output_bits; unsigned char rest[11]; };
extern struct hdcp_rx_record hdcp_rx_record_hdmi20[];
extern unsigned char hdmi_port_reg_read8(unsigned char, unsigned int);
extern unsigned char dp_reg_read8(unsigned char, unsigned int);

/*
 * Find the first input that is shown on video output `output` (bit `output` of its output_bits) and return one
 * status bit of that input's receiver: bit 5 of register 0x2E for the HDMI inputs 0..3, bit 0 of register 0x2A9
 * of the DisplayPort receiver (input - 4) for inputs 4 and 5. Returns 0 when no input is shown on that output.
 *
 * Called with the output number from hdcp_tx_hdmi_state_read_repeater_info, hdcp_tx_hdmi_update_record and
 * hdcp_tx_dp_state_read_receiver_ids.
 */
unsigned char hdcp_rx_get_port_status_bit(int output)
{
    unsigned char i;

    for (i = 0; i <= 5; i++) {
        if ((hdcp_rx_record_hdmi20[i].output_bits >> output) & 1) {
            if (i <= 3)
                {
                    if (hdmi_port_reg_read8(i, 0x2e) & 0x20)
                        return 1;
                    return 0;
                }
            return dp_reg_read8(i - 4, 0x2a9) & 1;
        }
    }
    return 0;
}
