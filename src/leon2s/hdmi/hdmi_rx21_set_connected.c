/* hdmi_rx21_set_connected  (FUN_a00a1b58)
 *
 * Mark an HDMI 2.1 receiver port connected and update the connect state.
 *   port: receiver
 * Returns: 0
 * Name basis: derived - record byte +3 = 1 (cleared by DRV_HDMI_IF_Disconnect), then
 *   hdmi_rx21_update_connect_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a1b58, flags -mcpu=v8 -Os -g (section default). The base is a flat unsigned char array; the
 * index is port * 400 (smul by 0x190). The call takes no arguments; the return value is 0.
 */
#define RX21_CONNECTED 3                /* byte of the 400-byte receiver record */

extern int hdmi_rx21_update_connect_state();
extern unsigned char hdmi_rx21_input_records[];

/*
 * Mark HDMI 2.1 receiver `port` as connected and run hdmi_rx21_update_connect_state. Returns 0. Called by
 * DRV_HDMI21_RX_Init. DRV_HDMI_IF_Disconnect clears the same byte.
 *   port  HDMI 2.1 receiver 0/1
 */
unsigned int hdmi_rx21_set_connected(int port)
{
    hdmi_rx21_input_records[port * 400 + RX21_CONNECTED] = 1;
    hdmi_rx21_update_connect_state();
    return 0;
}
