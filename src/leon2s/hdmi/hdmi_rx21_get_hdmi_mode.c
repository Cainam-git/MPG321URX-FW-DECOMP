/* hdmi_rx21_get_hdmi_mode  (FUN_a00a26e0)
 *
 * Return the HDMI (not DVI) mode flag of an HDMI 2.1 input.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: 1 for HDMI
 * Name basis: proven - record byte +0x18 = 'HDMI Mode' of the mode info print; caller
 *   CONV2HDMITX_UpdateInterface
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a26e0, flags -mcpu=v8 -Os -g (section default; own cflags entry, same flags). Same code as
 * hdmi_rx21_get_color_depth with another offset.
 */
#define RX21_HDMI_MODE 0x18             /* offset in the 400-byte receiver record */

extern unsigned char hdmi_rx21_input_records[];

/*
 * Return the byte at record offset 0x18 of receiver `port`: the 'HDMI Mode' value printed by
 * DRV_HDMI_ModeDetect_FSM_Complete (1 for HDMI). Called by CONV2HDMITX_UpdateInterface.
 *   port  HDMI 2.1 receiver 0/1
 */
unsigned char hdmi_rx21_get_hdmi_mode(unsigned int port)
{
    return hdmi_rx21_input_records[(port & 0xff) * 400 + RX21_HDMI_MODE];
}
