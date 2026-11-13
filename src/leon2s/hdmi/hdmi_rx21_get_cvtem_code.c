/* hdmi_rx21_get_cvtem_code  (FUN_a00a26a8)
 *
 * Return the first CVTEM field of an HDMI 2.1 input.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: value
 * Name basis: descriptive - record byte +0x184 from hdmi_rx21_read_cvtem (bits 20..23, default 0x10); mailbox
 *   command 0xA1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a26a8, flags -mcpu=v8 -Os -g (section default; own cflags entry, same flags). Same code as
 * hdmi_rx21_get_color_depth with another offset.
 */
#define RX21_CVTEM_CODE 0x184           /* offset in the 400-byte receiver record; out[0] of hdmi_rx21_read_cvtem */

extern unsigned char hdmi_rx21_input_records[];

/*
 * Return the byte at record offset 0x184 of receiver `port`: the first CVTEM field (bits 20..23 of the packet
 * word, or 0x10 when they are 0) as stored by DRV_HDMI_ModeDetect_FSM_Complete from hdmi_rx21_read_cvtem.
 * Called by ipc_dispatch_command (mailbox command 0xA1).
 *   port  HDMI 2.1 receiver 0/1
 */
unsigned char hdmi_rx21_get_cvtem_code(unsigned int port)
{
    return hdmi_rx21_input_records[(port & 0xff) * 400 + RX21_CVTEM_CODE];
}
