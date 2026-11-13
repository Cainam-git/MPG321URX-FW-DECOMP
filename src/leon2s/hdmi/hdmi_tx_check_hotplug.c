/* hdmi_tx_check_hotplug  (FUN_a0095d78)
 *
 * Read and parse the sink EDID when an HDMI TX display is plugged in.
 *   port: HDMI TX port 0/1
 * Name basis: derived - on a change of hdmi_tx_is_sink_connected: hdmi_tx_read_sink_edid and the EDID parser,
 *   or DDC reset
 *
 * Matching notes
 * --------------
 * FUN_a0095d78 (leon2s 0xa0095d78-0xa0095e08, 144 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the connected state is read a second time before it is stored; the EDID parser call is a tail call.
 * hdcp_tx_hdmi_set_reg27_bit0 is the ROM routine at 0x9F1B8A1C.
 */
#define HDMI_TX_EDID_BUFFERS 0x9f1b0200 /* EDID buffer of port 0; 0x200 bytes per port */

extern unsigned char hdmi_tx_last_hotplug_states[];
extern unsigned char hdmi_tx_sink_flags[];
extern int hdmi_tx_is_sink_connected(unsigned char);
extern void hdmi_tx_read_sink_edid(unsigned char, unsigned char);
extern void hdmi_tx_parse_hf_vsdb(unsigned char, unsigned int);
extern void hdcp_tx_hdmi_set_reg27_bit0(unsigned char);

/*
 * Follow the hot-plug state of an HDMI TX port. Nothing happens while the connected state equals the one stored
 * at the last check. On a change the new state is stored, and
 *   - display connected: its EDID is read, hdmi_tx_sink_flags[port] is set to 1 and the EDID buffer is parsed
 *     (hdmi_tx_parse_hf_vsdb);
 *   - display gone: hdcp_tx_hdmi_set_reg27_bit0 is called and hdmi_tx_sink_flags[port] is cleared.
 * hdmi_tx_sink_flags is published to the main processor as status bits 3 and 4.
 *   port: HDMI TX port 0/1
 * Called by hdmi_tx_service_port.
 */
void hdmi_tx_check_hotplug(unsigned char port)
{
    unsigned char connected;

    if (hdmi_tx_last_hotplug_states[port] == (unsigned char)hdmi_tx_is_sink_connected(port))
        return;
    connected = hdmi_tx_is_sink_connected(port);
    hdmi_tx_last_hotplug_states[port] = connected;
    if (connected != 0) {
        hdmi_tx_read_sink_edid(port, 0);
        hdmi_tx_sink_flags[port] = 1;
        hdmi_tx_parse_hf_vsdb(port, HDMI_TX_EDID_BUFFERS + port * 0x200);
    } else {
        hdcp_tx_hdmi_set_reg27_bit0(port);
        hdmi_tx_sink_flags[port] = 0;
    }
}
