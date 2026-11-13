/* ipc_api_set_dp_rx_reg44_bits  (FUN_a012b86c)
 *
 * Ask the input processor to write DisplayPort receiver register bits from a value.
 * Name basis: derived - forwards; unused; mailbox command 0x2C, whose handler in the input program shows the
 *   meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b86c @ 0xa012b86c, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the callee is declared without a prototype and both arguments are masked with 0xFF at the call.
 */
extern int ipc_set_dp_rx_reg44_bits();

/*
 * Forward two bytes to ipc_set_dp_rx_reg44_bits, which sends them as mailbox command 0x2C to the input processor.
 *   byte0, byte1: the first two bytes of the command; only their low bytes are used.
 * Nothing calls this routine.
 */
void ipc_api_set_dp_rx_reg44_bits(unsigned int byte0, unsigned int byte1)
{
  ipc_set_dp_rx_reg44_bits(byte0 & 0xff, byte1 & 0xff);
}
