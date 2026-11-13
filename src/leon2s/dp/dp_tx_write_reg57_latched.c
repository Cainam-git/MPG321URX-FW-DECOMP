/* dp_tx_write_reg57_latched  (FUN_a008983c)
 *
 * Write a 16-bit value to register 0x57 of a DP output and latch it.
 *   port: DP output
 *   value: 16-bit value
 * Name basis: descriptive - two byte writes then a pulse of register 0x70 bit 4; mailbox command 0x5A
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: value is an int that is read as unsigned short for the high byte; dp_tx_reg_update_bits is
 * declared without a prototype.
 */
extern void dp_tx_reg_write8(unsigned int port, unsigned short reg, unsigned int value);
extern void dp_tx_reg_update_bits();
extern int timer_delay_long_units();

/*
 * Write a 16-bit value to register 0x57 of a DP output, then pulse bit 4 of register 0x70.
 *
 *   port:  DP output 0..4
 *   value: 16-bit value; the low byte is written first, then the high byte, both to register 0x57
 *
 * The pulse is: set bit 4, wait 5 units (timer_delay_long_units), clear bit 4. Called from the mailbox
 * command dispatcher (ipc_dispatch_command).
 */
void dp_tx_write_reg57_latched(unsigned char port, int value)
{
  dp_tx_reg_write8(port,0x57,value & 0xff);
  dp_tx_reg_write8(port,0x57,((unsigned short)value) >> 8);
  dp_tx_reg_update_bits(port,0x70,0x10,1);
  timer_delay_long_units(5);
  dp_tx_reg_update_bits(port,0x70,0x10,0);
}
