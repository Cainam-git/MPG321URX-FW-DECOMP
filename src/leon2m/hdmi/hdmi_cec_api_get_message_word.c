/* hdmi_cec_api_get_message_word  (FUN_a0147770)
 *
 * Return the four stored CEC message bytes as one word.
 * Returns: word
 * Name basis: descriptive - forwards to the getter of the bytes at 0xA802C978
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147770 @ 0xa0147770, flags -mcpu=v8 -O2 -g (the section default).
 * The call is a tail call: the callee returns straight to this routine's caller, and the last word of the routine
 * is the nop the compiler places behind such a call sequence.
 */
extern unsigned int hdmi_cec_get_message_word(void);

/* Return the word hdmi_cec_get_message_word builds from the kept message of code 0x87. Called by sys_run_app_timer_task. */
unsigned int hdmi_cec_api_get_message_word(void)
{
    return hdmi_cec_get_message_word();
}
