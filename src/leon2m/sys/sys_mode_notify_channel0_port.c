/* sys_mode_notify_channel0_port  (FUN_a01517f4)
 *
 * Pass the port number of channel 0 to sys_map_port_signal_code, with selector 0.
 * Name basis: descriptive - sys_map_port_signal_code(0, bits 12-15 of the word at 0xA802DF30)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01517f4 @ 0xa01517f4 (-mcpu=v8 -O3 -g).
 * Source form: the decompiler's type names are kept; channel_records is declared as the first word only.
 */
extern unsigned int channel_records;            /* word 0 of channel record 0 */
extern int sys_map_port_signal_code();

/*
 * Pass the port number of channel 0 (bits 12..15 of its first word) to sys_map_port_signal_code, with selector 0.
 *
 * Called by GlobalModeHandler (GlobalModeHandler) when any channel enters state 0xC and no other channel is above
 * state 0xB; it always uses channel record 0, whichever channel entered.
 */
void sys_mode_notify_channel0_port(void)

{
  sys_map_port_signal_code(0,channel_records >> 12 & 0xf);
  return;
}
