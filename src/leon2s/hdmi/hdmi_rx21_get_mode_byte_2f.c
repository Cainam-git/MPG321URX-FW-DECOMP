/* hdmi_rx21_get_mode_byte_2f  (FUN_a00a2718)
 *
 * Return the mode info byte +0x2F of an HDMI 2.1 input.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: byte
 * Name basis: descriptive - record byte +0x2F; caller CONV2HDMITX_UpdateInterface (same place as
 *   hdmi_get_saved_reg55_bit0)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2718, flags -mcpu=v8 -Os -g (section default; own cflags entry, same flags). Same code as
 * hdmi_rx21_get_color_depth with another offset.
 */
#define RX21_BYTE_0x2F 0x2f             /* offset in the 400-byte receiver record */

extern unsigned char hdmi_rx21_input_records[];

/*
 * Return the byte at record offset 0x2F of receiver `port`. Called by CONV2HDMITX_UpdateInterface.
 *   port  HDMI 2.1 receiver 0/1
 */
unsigned char hdmi_rx21_get_mode_byte_2f(unsigned int port)
{
    return hdmi_rx21_input_records[(port & 0xff) * 400 + RX21_BYTE_0x2F];
}
