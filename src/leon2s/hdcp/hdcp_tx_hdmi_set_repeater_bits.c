/* hdcp_tx_hdmi_set_repeater_bits  (FUN_a00c8444)
 *
 * Set or clear two control bits of an HDMI output by a flag of its record.
 * Name basis: descriptive - bit 4 of register 0x0F and bit 3 of register 0xCC by record bit 28
 *
 * Matching notes
 * --------------
 * FUN_a00c8444 (leon2s 0xa00c8444-0xa00c850c, 200 bytes), flags -mcpu=v8 -Os -g.
 * Source form: word 0 of the 24-byte output record is a big-endian bit-field struct (first field = most
 * significant bit); the register helpers are called with the read inside the write's argument list.
 */
/* Output record of hdcp_tx_records (24 bytes). Word 0 bit-fields, most significant bit first; only the
   repeater flag is used here. */
struct hdcp_tx_record {
    unsigned int bits_29_31 : 3;
    unsigned int repeater : 1;                  /* bit 28: set by hdcp_tx_hdmi_read_bcaps */
    unsigned int tries_left : 4;                /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bits_18_22 : 5;
    unsigned int step_result : 2;               /* bits 16..17 */
    unsigned int state : 8;                     /* byte +2 */
    unsigned char device_count;                 /* +3 */
    unsigned char level;                        /* +4 */
    unsigned char count_overflow;               /* +5 */
    unsigned char level_overflow;               /* +6 */
    unsigned char pad[17];
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned int hdmi_tx_reg_read8(unsigned char, int, unsigned short);
extern void hdmi_tx_reg_write8(unsigned char, int, unsigned short, unsigned char);

/*
 * Copy the repeater flag of the output record (bit 28 of word 0) into two bits of HDMI output `port`: when it is
 * set, bit 4 of register 0x0F and bit 3 of register 0xCC are set; when it is clear, both are cleared.
 *
 * Called from hdcp_tx_hdmi_state_run_checks.
 */
void hdcp_tx_hdmi_set_repeater_bits(unsigned char port)
{
    if (hdcp_tx_records[port].repeater) {
        hdmi_tx_reg_write8(port, 0, 0xf, hdmi_tx_reg_read8(port, 0, 0xf) | 0x10);
        hdmi_tx_reg_write8(port, 0, 0xcc, hdmi_tx_reg_read8(port, 0, 0xcc) | 8);
    } else {
        hdmi_tx_reg_write8(port, 0, 0xf, hdmi_tx_reg_read8(port, 0, 0xf) & 0xef);
        hdmi_tx_reg_write8(port, 0, 0xcc, hdmi_tx_reg_read8(port, 0, 0xcc) & 0xf7);
    }
}
