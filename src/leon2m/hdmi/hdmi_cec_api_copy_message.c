/* hdmi_cec_api_copy_message  (FUN_a0147780)
 *
 * Copy the five stored CEC message bytes to a buffer.
 * Name basis: descriptive - forwards to the copy of the bytes at 0xA802C968
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147780 @ 0xa0147780, flags -mcpu=v8 -O2 -g (the section default).
 * The call is a tail call: the callee returns straight to this routine's caller, and the last word of the routine
 * is the nop the compiler places behind such a call sequence.
 */
extern void hdmi_cec_copy_message(unsigned char *);

/* Copy the kept message of code 0x47 to `dest` through hdmi_cec_copy_message (five bytes). Called by sys_run_app_timer_task. */
void hdmi_cec_api_copy_message(unsigned char *dest)
{
    hdmi_cec_copy_message(dest);
}
