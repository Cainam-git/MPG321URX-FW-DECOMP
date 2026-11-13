/* sys_dsc_dec_is_hdmi21_mode_lost  (FUN_a00a621c)
 *
 * Return whether byte +1 of the record of the decoder's HDMI 2.1 input is 0.
 *   input_code: input code 0x51/0x61/0x71/0x81
 * Returns: 1 when 0
 * Name basis: descriptive - input code 0x51 / 0x61 -> the byte at +1 of the HDMI 2.1 input record 0 / 1
 *   (0xA807D7E1 / 0xA807D971) is 0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a621c @ 0xa00a621c (-mcpu=v8 -Os -g)
 * Other codes use the constant 1 (result 0).
 */
extern unsigned char hdmi_rx21_input_record0_mode_detected;
extern unsigned char hdmi_rx21_input_record1_mode_detected;

/* Return 1 when the mode-detected byte of the HDMI 2.1 input named by the input code is 0: record 0 for code
 * 0x51 ('Q'), record 1 for code 0x61 ('a'). Any other code gives 0.
 *   input_code: 0x51 or 0x61 for the HDMI 2.1 inputs
 */
unsigned int sys_dsc_dec_is_hdmi21_mode_lost(unsigned char input_code)

{
  int mode_detected;
  unsigned char lost;
  
  lost = 0;
  if (input_code == 'Q') {
    mode_detected = hdmi_rx21_input_record0_mode_detected;
  } else {
    if (input_code == 'a') {
      mode_detected = hdmi_rx21_input_record1_mode_detected;
    } else {
      mode_detected = 1;
    }
  }
  if (mode_detected == 0) {
    lost = 1;
  }
  return lost;
}
