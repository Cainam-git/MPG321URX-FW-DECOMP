/* ipc_api_set_dp_rx_setting_11f  (FUN_a012b884)
 *
 * Ask the input processor to store a DisplayPort receiver setting byte and set the port up again.
 * Name basis: derived - forwards with the saved bit; mailbox command 0x80, whose handler in the input program
 *   shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b884 @ 0xa012b884, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype; the second argument is bit 27 of the first word of the
 * device settings record.
 */
#define DEVICE_SETTINGS_FLAG_SHIFT 0x1b         /* bit 27 of the first word; not named in docs/RECORDS.md */

extern unsigned int device_settings;
extern int ipc_set_dp_rx_setting_11f();

/*
 * Forward the receiver number and bit 27 of the device settings record to ipc_set_dp_rx_setting_11f, which sends
 * them as mailbox command 0x80 to the input processor.
 *   receiver: DisplayPort receiver number
 * Caller: input_api_power_on_dp_port.
 */
void ipc_api_set_dp_rx_setting_11f(unsigned char receiver)
{
  ipc_set_dp_rx_setting_11f(receiver, device_settings >> DEVICE_SETTINGS_FLAG_SHIFT & 1);
}
