/* hdmi_cec_get_sender  (FUN_a00fca34)
 *
 * Return the stored byte that accompanies the last CEC command.
 * Returns: byte
 * Name basis: descriptive - byte at 0xA802C97E
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fca34 @ 0xa00fca34, flags -mcpu=v8 -O2 -g (the section default). Leaf routine without a register
 * window.
 */
extern unsigned char hdmi_cec_sender;

/*
 * Return the byte that hdmi_cec_receive_and_reply stored from the last received message of code 0x82, 0x84 or
 * 0x9D: the byte after the code. Called only by hdmi_cec_api_get_sender.
 */
unsigned char hdmi_cec_get_sender(void)
{
  return hdmi_cec_sender;
}
