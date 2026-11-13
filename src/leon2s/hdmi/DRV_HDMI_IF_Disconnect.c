/* DRV_HDMI_IF_Disconnect  (DRV_HDMI_IF_Disconnect)
 *
 * Mark an HDMI receiver port disconnected and update the connect state.
 *   port: receiver
 * Returns: 0, or 0x16 for port 2
 * Name basis: proven - original name printed ('[VERBOSE]: %s: Port%c')
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_IF_Disconnect @ 0xa00a1b08, flags -mcpu=v8 -Os -g.
 * Same source form as DRV_HDMI_IF_Enable_RxPort: the function-name string is a separate read-only object.
 */
#define RX21_RECORD_SIZE 0x190      /* bytes per entry of hdmi_rx21_input_records */
#define RX21_RECORD_BYTE_3 3        /* set to 1 by hdmi_rx21_set_connected, cleared here */

extern unsigned char hdmi_rx21_input_records[];
extern int dbg_printf(const char *, ...);
extern void hdmi_rx21_update_connect_state(void);
static const char fn_[] = "DRV_HDMI_IF_Disconnect";

/* Clears byte +3 of the receiver's record and updates the connect state. Port 2 is refused: it
 * prints "[VERBOSE]: DRV_HDMI_IF_Disconnect: PortC" and returns 0x16.
 *   port: receiver
 * Returns 0, or 0x16 for port 2. */
unsigned int DRV_HDMI_IF_Disconnect(unsigned int port)
{
    if (port == 2) {
        dbg_printf("[VERBOSE]: %s: Port%c \n", fn_, 0x43);
        return 0x16;
    } else {
        hdmi_rx21_input_records[port * RX21_RECORD_SIZE + RX21_RECORD_BYTE_3] = 0;
        hdmi_rx21_update_connect_state();
        return 0;
    }
}
