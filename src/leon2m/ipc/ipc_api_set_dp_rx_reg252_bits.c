/* ipc_api_set_dp_rx_reg252_bits  (FUN_a012b8a8)
 *
 * Ask the input processor to write bits 5-7 of DisplayPort receiver register 0x252.
 * Name basis: derived - forwards; mailbox command 0x86, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b8a8 @ 0xa012b8a8, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype and both arguments are passed unchanged.
 */
extern int ipc_set_dp_rx_reg252_bits();

/*
 * Forward the receiver number and a value to ipc_set_dp_rx_reg252_bits, which sends them as mailbox command 0x86
 * to the input processor.
 *   receiver: DisplayPort receiver number
 *   value:    option bit 20 (sys_config.option_bit_20), as passed by the caller
 * Caller: input_api_set_port_option_bit20.
 */
void ipc_api_set_dp_rx_reg252_bits(unsigned char receiver, unsigned char value)
{
  ipc_set_dp_rx_reg252_bits(receiver, value);
}
