/* hdmi_rx21_get_color_depth  (FUN_a00a26fc)
 *
 * Return the colour depth (bits per colour) of an HDMI 2.1 input.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: bits per colour
 * Name basis: proven - record byte +0x19 = 'Color Depth' of the mode info print (8/10/12/16)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a26fc, flags -mcpu=v8 -Os -g (section default).
 */
#define RX21_COLOR_DEPTH 0x19           /* offset in the 400-byte receiver record */

extern unsigned char hdmi_rx21_input_records[];

/*
 * Return the byte at record offset 0x19 of receiver `port`: the 'Color Depth' value printed by
 * DRV_HDMI_ModeDetect_FSM_Complete (8, 10, 12 or 16 bits per colour). Called by CONV2HDMITX_UpdateInterface.
 *   port  HDMI 2.1 receiver 0/1
 */
unsigned char hdmi_rx21_get_color_depth(unsigned int port)
{
    return hdmi_rx21_input_records[(port & 0xff) * 400 + RX21_COLOR_DEPTH];
}
