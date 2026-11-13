/* hdcp_rx_set_port_option  (FUN_a00c19b8)
 *
 * Write an option of an input's protection block; set by a command from the main processor.
 * Name basis: descriptive - two arms: ports 0 and 1 write register 0x301 of the HDMI 2.0 receiver, ports 2 and
 *   up use the index registers of HDMI 2.1 receiver (port - 2)
 *
 * Matching notes
 * --------------
 * FUN_a00c19b8 (leon2s 0xa00c19b8-0xa00c1ac0, 264 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the full call sequence in each arm of the port test, long arm first ('port > 1'), (u8)(port - 2)
 * written at each use (as in dp_toggle_status_bit): -Os pre-sets the hdmi_rx21_reg_update_bits args above the test.
 * A local for the receiver number gives different code.
 */
extern int hdmi_reg_write8(unsigned int, unsigned int, unsigned int);
extern void hdmi_rx21_reg_write8(unsigned int, unsigned int, unsigned int);
extern int hdmi_rx21_reg_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);

/*
 * Set an option of the protection block of input `port`, on the command 0x14 (ipc_set_hdcp_rx_port_option) of
 * the main processor (high byte of the command word = mode, low byte = port).
 *
 * Mode 1 writes the value 4, any other mode the value 0:
 *   port 0 and 1 (HDMI 2.0): the value to register 0x301 of that receiver;
 *   port 2 and up: through the index registers of HDMI 2.1 receiver (port - 2): select 0, index 0, value to
 *                  register 0xA7, then bit 5 of register 0xA4 is set.
 */
int hdcp_rx_set_port_option(unsigned char mode, unsigned char port)
{
    if (mode == 1) {
        if (port > 1) {
            hdmi_rx21_reg_write8((unsigned char)(port - 2), 0xa6, 0);
            hdmi_rx21_reg_write8((unsigned char)(port - 2), 0xa5, 0);
            hdmi_rx21_reg_write8((unsigned char)(port - 2), 0xa4, 0);
            hdmi_rx21_reg_write8((unsigned char)(port - 2), 0xa7, 4);
            return hdmi_rx21_reg_update_bits((unsigned char)(port - 2), 0xa4, 0x20, 1);
        } else {
            return hdmi_reg_write8(port, 0x301, 4);
        }
    } else {
        if (port > 1) {
            hdmi_rx21_reg_write8((unsigned char)(port - 2), 0xa6, 0);
            hdmi_rx21_reg_write8((unsigned char)(port - 2), 0xa5, 0);
            hdmi_rx21_reg_write8((unsigned char)(port - 2), 0xa4, 0);
            hdmi_rx21_reg_write8((unsigned char)(port - 2), 0xa7, 0);
            return hdmi_rx21_reg_update_bits((unsigned char)(port - 2), 0xa4, 0x20, 1);
        } else {
            return hdmi_reg_write8(port, 0x301, 0);
        }
    }
}
