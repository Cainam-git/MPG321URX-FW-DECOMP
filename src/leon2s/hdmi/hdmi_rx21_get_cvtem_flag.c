/* hdmi_rx21_get_cvtem_flag  (FUN_a00a26c4)
 *
 * Return the second CVTEM field of an HDMI 2.1 input.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: flag
 * Name basis: descriptive - record byte +0x185 from hdmi_rx21_read_cvtem (bit 27); mailbox command 0xA0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a26c4, flags -mcpu=v8 -Os -g (section default; own cflags entry, same flags). Same code as
 * hdmi_rx21_get_color_depth with another offset.
 */
#define RX21_CVTEM_FLAG 0x185           /* offset in the 400-byte receiver record; out[1] of hdmi_rx21_read_cvtem */

extern unsigned char hdmi_rx21_input_records[];

/*
 * Return the byte at record offset 0x185 of receiver `port`: the second CVTEM field (bit 27 of the packet
 * word) as stored by DRV_HDMI_ModeDetect_FSM_Complete from hdmi_rx21_read_cvtem. Called by
 * ipc_dispatch_command (mailbox command 0xA0).
 *   port  HDMI 2.1 receiver 0/1
 */
unsigned char hdmi_rx21_get_cvtem_flag(unsigned int port)
{
    return hdmi_rx21_input_records[(port & 0xff) * 400 + RX21_CVTEM_FLAG];
}
