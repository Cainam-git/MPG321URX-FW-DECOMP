/* hdmi_tx_is_sink_connected  (FUN_a0095d34)
 *
 * Return whether a display is plugged into an HDMI TX port.
 *   port: HDMI TX port 0/1
 * Returns: 1 when connected
 * Name basis: derived - hot-plug lines 5 / 6 through dp_tx_hpd_is_low
 *
 * Matching notes
 * --------------
 * FUN_a0095d34 (leon2s 0xa0095d34-0xa0095d78, 68 bytes), flags -mcpu=v8 -Os -g.
 * Source form: same as dp_tx_is_connected (if/else chain on the port, a byte result local starting at 0, returned as
 * result & 1).
 */
#define HPD_LINE_PORT_0 5               /* hot-plug line number of HDMI TX port 0 (dp_tx_hpd_is_low argument) */
#define HPD_LINE_PORT_1 6               /* hot-plug line number of HDMI TX port 1 */

extern int dp_tx_hpd_is_low(int param_1);

/*
 * Tell whether a display is connected to an HDMI TX port, from its hot-plug line (low means no display).
 *   port: HDMI TX port 0/1; any other value gives 0 without a look at a line
 * Returns 1 when the line is not low.
 * Called by hdmi_tx_check_hotplug.
 */
int hdmi_tx_is_sink_connected(unsigned char port)
{
    unsigned char connected;

    port = port & 0xff;
    connected = 0;
    if (port == 0) {
        if (dp_tx_hpd_is_low(HPD_LINE_PORT_0) == 0) {
            connected = 1;
        }
    } else if (port == 1) {
        if (dp_tx_hpd_is_low(HPD_LINE_PORT_1) == 0) {
            connected = 1;
        }
    }
    return connected & 1;
}
