/* hdcp_rx_is_port_authenticated  (FUN_a00c30e4)
 *
 * Return a 0/1 status of an input's protection block.
 * Returns: 0 or 1
 * Name basis: descriptive - one register read for inputs 0 and 1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c30e4 @ 0xa00c30e4, flags -mcpu=v8 -Os -g.
 * Source form: the tests are in this order: port <= 1 (read and bit test), else port > 3 (then port <= 5), else
 * the result 1.
 */
extern int hdmi_reg_read8();

/*
 * Status of input `port` (0..5) for hdcp_rx_update_port_status. For the HDMI 2.0 inputs 0 and 1 it is bit 4 of
 * register 0x319 of that receiver. For the inputs 2 to 5 (HDMI 2.1 and DisplayPort) it is always 1; for a port
 * above 5 it is 0.
 */
int hdcp_rx_is_port_authenticated(unsigned int port)
{
    unsigned char result = 0;
    
    port = port & 0xff;
    if (port <= 1) {
        if ((hdmi_reg_read8(port, 0x319) & 0x10) != 0) {
            result = 1;
        }
    } else if (port > 3) {
        if (port <= 5) {
            result = 1;
        }
    } else {
        result = 1;
    }
    return result;
}
