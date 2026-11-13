/* hdmi_cec_api_get_sender  (FUN_a0147814)
 *
 * Return the stored byte that accompanies the last CEC command.
 * Returns: byte
 * Name basis: descriptive - forwards to the getter of the byte at 0xA802C97E
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147814 @ 0xa0147814, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the declaration keeps two unused word parameters and the result is built with CONCAT44, as the
 * decompiler printed it (only the low word, the byte, is returned).
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern unsigned char hdmi_cec_get_sender(void);

/*
 * Return the stored sender byte (hdmi_cec_get_sender). The two parameters are not used. Called by
 * sys_run_app_timer_task, which reads the byte as the source of an input request (0x10 to 0x40).
 */
int hdmi_cec_api_get_sender(unsigned int unused1, unsigned int unused2)
{
  unsigned char sender;

  sender = hdmi_cec_get_sender();
  return CONCAT44(unused2, (unsigned int)sender);
}
