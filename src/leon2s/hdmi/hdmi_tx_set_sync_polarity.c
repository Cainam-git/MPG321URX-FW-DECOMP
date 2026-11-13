/* hdmi_tx_set_sync_polarity  (FUN_a00945f0)
 *
 * Set the horizontal and vertical sync polarity of an HDMI TX port.
 *   port: HDMI TX port 0/1
 * Name basis: proven - prints 'Desired H Polarity +/-' and 'Desired V Polarity +/-'
 *
 * Matching notes
 * --------------
 * FUN_a00945f0 (leon2s 0xa00945f0-0xa0094798, 424 bytes), flags -mcpu=v8 -Os -g.
 * Source form: bit 30 of record word 0 is a 1-bit bit-field; the polarity getters' results are tested as bytes.
 */
/* First word of the 0x1c-byte channel record of an HDMI TX port (hdmi_tx_output_records); only word 0 is used here. */
struct hdmi_tx_channel_record {
    unsigned int ctrl_bit31 : 1, ctrl_bit30 : 1, : 30;
    unsigned int rest[6];
};
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern unsigned int dbg_print_string(const char *);
extern void hdmi_tx_reg_update_bits(unsigned int port, unsigned int sub, short reg, unsigned int mask, unsigned int mode);
extern short hdmi_tx_reg_read8(unsigned int, unsigned short, unsigned short);
extern void hdmi_tx_reg_write8(unsigned int, unsigned int, unsigned short, unsigned int);
extern unsigned int hdmi_tx_get_hsync_polarity(unsigned int);
extern unsigned int hdmi_tx_get_vsync_polarity(unsigned int);

/*
 * Set the sync polarity registers of the transmitter to the polarity the channel wants. Bits 0..1 of register
 * 0xBA of bank 0 are cleared first.
 *   - channel record word 0 bit 30 set: register 0x33 of bank 0 takes bits 0..1 of register 0x3F (shifted to
 *     bits 4..5), nothing else is touched;
 *   - otherwise register 0x33 bits 4..5 are cleared and each polarity is set from hdmi_tx_get_hsync_polarity /
 *     hdmi_tx_get_vsync_polarity: positive clears the polarity bit in register 0x35 of bank 1 (bit 1 for H,
 *     bit 0 for V); negative sets that bit, sets the matching bit of register 0xBA (bit 1 / bit 0) and the matching
 *     bit of register 0x33 (bit 4 for H, bit 5 for V). Each choice is printed ('Desired H Polarity +/-').
 * Called by hdmi_tx_run_step in the two packet set-up steps.
 */
void hdmi_tx_set_sync_polarity(unsigned char port)
{
    hdmi_tx_reg_update_bits(port, 0, 0xba, 3, 0);
    if (hdmi_tx_output_records[port].ctrl_bit30) {
        hdmi_tx_reg_write8(port, 0, 0x33, (hdmi_tx_reg_read8(port, 0, 0x3f) & 3) << 4);
        return;
    }
    hdmi_tx_reg_update_bits(port, 0, 0x33, 0x30, 0);
    if ((unsigned char)hdmi_tx_get_hsync_polarity(port) == 1) {
        dbg_print_string("\x1b[0m\t\t - Desired H Polarity + \n");
        hdmi_tx_reg_update_bits(port, 1, 0x35, 2, 0);
    } else {
        dbg_print_string("\x1b[0m\t\t - Desired H Polarity - \n");
        hdmi_tx_reg_update_bits(port, 1, 0x35, 2, 1);
        hdmi_tx_reg_update_bits(port, 0, 0xba, 2, 1);
        hdmi_tx_reg_update_bits(port, 0, 0x33, 0x10, 1);
    }
    if ((unsigned char)hdmi_tx_get_vsync_polarity(port) == 1) {
        dbg_print_string("\x1b[0m\t\t - Desired V Polarity + \n");
        hdmi_tx_reg_update_bits(port, 1, 0x35, 1, 0);
    } else {
        dbg_print_string("\x1b[0m\t\t - Desired V Polarity - \n");
        hdmi_tx_reg_update_bits(port, 1, 0x35, 1, 1);
        hdmi_tx_reg_update_bits(port, 0, 0xba, 1, 1);
        hdmi_tx_reg_update_bits(port, 0, 0x33, 0x20, 1);
    }
}
