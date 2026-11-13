/* hdmi_rx21_is_format_420  (FUN_a00a2080)
 *
 * Return 1 when the colour format of an HDMI 2.1 input is 4:2:0 (format code 3), else 0.
 *   port: receiver
 * Returns: 1 = 4:2:0, 0 = any other format
 * Name basis: derived - record word +0x50 compared with 3; FSM_Complete prints that word as 'Color format = %d
 *   (0: RGB, 1: 422, 2: 444, 3:420)'; the callers double the horizontal values on 1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2080, flags -mcpu=v8 -Os -g (section default).
 */
#define RX21_COLOR_FORMAT    0x50       /* word of the 400-byte receiver record (AVI colour format) */
#define COLOR_FORMAT_YCBCR420 3         /* 0: RGB, 1: 422, 2: 444, 3: 420 (text printed by FSM_Complete) */

extern unsigned char hdmi_rx21_input_records[];

/*
 * Return 1 when the colour format word of receiver `port` (record offset 0x50) is 3 (4:2:0), otherwise 0.
 * Called by hdmi_rx21_copy_link_timing and hdmi_rx21_run_link_state.
 *   port  HDMI 2.1 receiver 0/1
 */
int hdmi_rx21_is_format_420(unsigned int port)
{
  unsigned char *record = hdmi_rx21_input_records + (port & 0xff) * 400;
  return *(unsigned int *)(record + RX21_COLOR_FORMAT) == COLOR_FORMAT_YCBCR420;
}
