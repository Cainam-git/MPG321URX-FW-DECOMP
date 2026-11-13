/* input_port_write_event_byte  (FUN_a00c5da8)
 *
 * Write an event byte to an input's register and clear its buffer.
 * Name basis: descriptive - register routine chosen by the input number
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c5da8 @ 0xa00c5da8-0xa00c5f18 (368 bytes), flags -mcpu=v8 -Os -g.
 * Source form: port, the record pointer, value and dp_unit are locals set at the top; byte +0xd is
 * cleared before byte +0xc.
 */
struct hdcp_rx_record {
    unsigned char _0[0xc];
    unsigned char byte_0xc;
    unsigned char byte_0xd;
    unsigned char _e[2];
};
extern struct hdcp_rx_record hdcp_rx_record_hdmi20[];
extern unsigned int hdcp_repeater_counters[];
extern void hdmi_port_reg_write8(unsigned char, unsigned short, unsigned char);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern void timer_delay_units(unsigned int);

/*
 * Send the 8-bit value value_arg to an input and reset that input's bookkeeping. Called by
 * input_port_raise_event when the restart bit of the input changes. Parameter port_arg: the input, 0..3 are
 * the HDMI receivers, above 3 the DisplayPort units (unit = port - 4).
 * The value is written through a fixed register sequence that depends on the input:
 *   - port 0..1: registers 0x310 = 0xAD, 0x311 = 8, 0x312 = value, 0x310 = 0;
 *   - port 2..3: registers 0xA6 = 10, 0xA5 = 0x12, 0xA4 = 2, 0xA7 = value;
 *   - above 3 (DP): registers 0x408 = 1, 0x404 = 7, a one-unit wait, 0x404 = 1, 0x400 = 3, 0x403 = 10,
 *     0x402 = 0x40, 0x401 = value + 2, 0x402 = 0x80.
 * Afterwards the repeater counter of the port (hdcp_repeater_counters) and bytes +0xD and +0xC of the port's
 * 16-byte copy-protection input record (hdcp_rx_record_hdmi20) are set to 0.
 * The meaning of the registers is not shown in the firmware.
 */
void input_port_write_event_byte(unsigned int port_arg, unsigned int value_arg)
{
    unsigned char port = port_arg;
    struct hdcp_rx_record *record = &hdcp_rx_record_hdmi20[port];
    unsigned char value = value_arg;
    unsigned int dp_unit = port_arg - 4;

    if (port < 2) {
        hdmi_port_reg_write8(port, 0x310, 0xad);
        hdmi_port_reg_write8(port, 0x311, 8);
        hdmi_port_reg_write8(port, 0x312, value);
        hdmi_port_reg_write8(port, 0x310, 0);
    } else if (port < 4) {
        hdmi_port_reg_write8(port, 0xa6, 10);
        hdmi_port_reg_write8(port, 0xa5, 0x12);
        hdmi_port_reg_write8(port, 0xa4, 2);
        hdmi_port_reg_write8(port, 0xa7, value);
    } else {
        dp_reg_write8(dp_unit, 0x408, 1);
        dp_reg_write8(dp_unit, 0x404, 7);
        timer_delay_units(1);
        dp_reg_write8(dp_unit, 0x404, 1);
        dp_reg_write8(dp_unit, 0x400, 3);
        dp_reg_write8(dp_unit, 0x403, 10);
        dp_reg_write8(dp_unit, 0x402, 0x40);
        dp_reg_write8(dp_unit, 0x401, value + 2);
        dp_reg_write8(dp_unit, 0x402, 0x80);
    }
    hdcp_repeater_counters[port] = 0;
    record->byte_0xd = 0;
    record->byte_0xc = 0;
}
