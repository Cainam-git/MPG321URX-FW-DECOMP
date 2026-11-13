/* hdmi_cec_get_operand  (FUN_a00fca40)
 *
 * Return the stored operand of the last CEC command.
 * Returns: byte
 * Name basis: descriptive - byte at 0xA802C97F; compared with 0x40 for command 5
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fca40 @ 0xa00fca40, flags -mcpu=v8 -O2 -g (the section default). Leaf routine without a register
 * window.
 */
extern unsigned char hdmi_cec_operand;

/*
 * Return the byte that hdmi_cec_receive_and_reply stored from the last received message of code 0x44: the byte
 * after the code. Called by hdmi_cec_api_get_command.
 */
unsigned char hdmi_cec_get_operand(void)
{
    return hdmi_cec_operand;
}
