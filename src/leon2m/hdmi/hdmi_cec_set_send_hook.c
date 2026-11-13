/* hdmi_cec_set_send_hook  (FUN_a00fc30c)
 *
 * Store the hook that is called when a CEC message is sent.
 * Name basis: descriptive - word at 0xA802C970; called from System_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fc30c @ 0xa00fc30c, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the hook is declared as an unsigned int; the callers pass a function address.
 */
extern unsigned int hdmi_cec_send_hook;

/*
 * Store the send hook. Once it is set, the CEC send routines call it with the destination address and the
 * message length instead of writing the destination and length registers of the CEC block themselves.
 * System_Initialize calls this with ipc_8051_cec_registers_entry.
 */
void hdmi_cec_set_send_hook(unsigned int hook)
{
  hdmi_cec_send_hook = hook;
}
