/* input_read_port_timing  (FUN_a0070434)
 *
 * Collect the eight timing values of a port into a reply buffer.
 *   request: request (port)
 *   reply: reply buffer
 * Note: Reply order: htotal, vtotal, hactive, vactive, hback+hsync, vback+vsync, hsync width, vsync width,
 *   each low byte first.
 * Name basis: derived - per port type the HDMI 2.0 / HDMI 2.1 / DP timing getters, written little-endian;
 *   caller ipc_dispatch_command (command 0x71)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0070434 @ 0xa0070434-0xa0070704 (720 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the 0x9100xx getters are declared without a parameter list (the argument is passed as the
 * promoted int; each getter masks it itself) and hdmi_get_saved_hback_porch returns an unsigned short;
 * unit = port_word is assigned at the start of the first branch; hback_plus_hsync is declared before vactive.
 */
/* Request record of mailbox command 0x71 (the dispatcher's command record); only the port word is read. */
struct timing_request { unsigned int word_0; unsigned int port; };
extern unsigned short hdmi_get_saved_hback_porch();
extern unsigned short hdmi_get_saved_hsync_width();
extern unsigned int hdmi_reg_read8(unsigned int, unsigned short);
extern unsigned short hdmi_get_saved_vback_porch();
extern unsigned short hdmi_get_saved_vsync_width();
extern unsigned short hdmi_get_saved_htotal();
extern unsigned short hdmi_get_saved_vtotal();
extern unsigned short hdmi_get_saved_hactive();
extern unsigned short hdmi_get_saved_vactive();
extern unsigned short hdmi_rx21_get_htotal(unsigned int);
extern unsigned short hdmi_rx21_get_vtotal(unsigned int);
extern unsigned short hdmi_rx21_get_hactive(unsigned int);
extern unsigned short hdmi_rx21_get_vactive(unsigned int);
extern unsigned short hdmi_rx21_get_hback_porch(unsigned int);
extern unsigned short hdmi_rx21_get_hsync_width(unsigned int);
extern unsigned short hdmi_rx21_get_vback_porch(unsigned int);
extern unsigned short hdmi_rx21_get_vsync_width(unsigned int);
extern unsigned short dp_read_reg90_word(unsigned int);
extern unsigned short dp_read_reg92_word(unsigned int);
extern unsigned short dp_get_hactive(unsigned int);
extern unsigned short dp_get_vactive(unsigned int);
extern unsigned short dp_reg_read16(unsigned int, unsigned short);
extern void dp_set_reg9f_field(unsigned char, unsigned char);

/*
 * Mailbox command 0x71: write eight timing values of one input port into a 16-byte reply buffer, each as a
 * little-endian 16-bit value. The port is the low byte of request->port; reply receives the bytes.
 * Reply words in order: total line length, total lines, active width, active lines, back porch + sync width
 * (horizontal), back porch + sync width (vertical), horizontal sync width, vertical sync width; the HDMI
 * paths read exactly these. The DisplayPort paths fill the same eight slots from registers 0x90, 0x92 and
 * 0x94..0x9A and from dp_get_hactive and dp_get_vactive, in this slot order.
 * Port 0..1: HDMI 2.0 receivers, from the saved timing getters. Port 2..3: HDMI 2.1 receivers (unit = port - 2).
 * Port 6..8: always DP unit 4, read between dp_set_reg9f_field(0, 1) and (0, 0); registers 0x98 and 0x9A are
 * masked to 15 bits. Any other port (4, 5 and above 8): DP unit = port - 4.
 * Only for HDMI 2.0 the horizontal back porch + sync width is reduced by 1 when bit 0 of register 0x114
 * is set and by 5 when it is clear.
 */
void input_read_port_timing(struct timing_request *request, unsigned char *reply)
{
    unsigned short htotal, vtotal, hactive, hback_plus_hsync, vactive, vback_plus_vsync, hsync_width, vsync_width;
    unsigned short hback_plus_hsync_raw;
    unsigned int port_word;
    unsigned char unit;

    port_word = request->port;
    if ((port_word & 0xff) <= 1) {
        unit = port_word;
        hback_plus_hsync_raw = hdmi_get_saved_hback_porch(port_word & 0xff) + hdmi_get_saved_hsync_width(port_word & 0xff);
        hback_plus_hsync = hback_plus_hsync_raw - 1;
        if (!(hdmi_reg_read8(port_word & 0xff, 0x114) & 1))
            hback_plus_hsync = hback_plus_hsync_raw - 5;
        vback_plus_vsync = hdmi_get_saved_vback_porch(unit) + hdmi_get_saved_vsync_width(unit);
        hsync_width = hdmi_get_saved_hsync_width(unit);
        vsync_width = hdmi_get_saved_vsync_width(unit);
        htotal = hdmi_get_saved_htotal(unit);
        vtotal = hdmi_get_saved_vtotal(unit);
        hactive = hdmi_get_saved_hactive(unit);
        vactive = hdmi_get_saved_vactive(unit);
    } else if ((port_word & 0xff) <= 3) {
        unit = port_word - 2;
        htotal = hdmi_rx21_get_htotal(unit);
        vtotal = hdmi_rx21_get_vtotal(unit);
        hactive = hdmi_rx21_get_hactive(unit);
        vactive = hdmi_rx21_get_vactive(unit);
        hback_plus_hsync = hdmi_rx21_get_hback_porch(unit) + hdmi_rx21_get_hsync_width(unit);
        vback_plus_vsync = hdmi_rx21_get_vback_porch(unit) + hdmi_rx21_get_vsync_width(unit);
        hsync_width = hdmi_rx21_get_hsync_width(unit);
        vsync_width = hdmi_rx21_get_vsync_width(unit);
    } else if ((unsigned char)(port_word - 6) <= 2) {
        dp_set_reg9f_field(0, 1);
        htotal = dp_read_reg90_word(4);
        vtotal = dp_read_reg92_word(4);
        hactive = dp_get_hactive(4);
        vactive = dp_get_vactive(4);
        hback_plus_hsync = dp_reg_read16(4, 0x94);
        vback_plus_vsync = dp_reg_read16(4, 0x96);
        hsync_width = dp_reg_read16(4, 0x98) & 0x7fff;
        vsync_width = dp_reg_read16(4, 0x9a) & 0x7fff;
        dp_set_reg9f_field(0, 0);
    } else {
        unit = port_word - 4;
        htotal = dp_read_reg90_word(unit);
        vtotal = dp_read_reg92_word(unit);
        hactive = dp_get_hactive(unit);
        vactive = dp_get_vactive(unit);
        hback_plus_hsync = dp_reg_read16(unit, 0x94);
        vback_plus_vsync = dp_reg_read16(unit, 0x96);
        hsync_width = dp_reg_read16(unit, 0x98) & 0x7fff;
        vsync_width = dp_reg_read16(unit, 0x9a) & 0x7fff;
    }
    reply[0x0] = htotal;
    reply[0x1] = htotal >> 8;
    reply[0x2] = vtotal;
    reply[0x3] = vtotal >> 8;
    reply[0x4] = hactive;
    reply[0x5] = hactive >> 8;
    reply[0x6] = vactive;
    reply[0x7] = vactive >> 8;
    reply[0x8] = hback_plus_hsync;
    reply[0x9] = hback_plus_hsync >> 8;
    reply[0xa] = vback_plus_vsync;
    reply[0xb] = vback_plus_vsync >> 8;
    reply[0xc] = hsync_width;
    reply[0xd] = hsync_width >> 8;
    reply[0xe] = vsync_width;
    reply[0xf] = vsync_width >> 8;
}
