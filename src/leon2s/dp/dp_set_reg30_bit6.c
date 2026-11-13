/* dp_set_reg30_bit6  (FUN_a00ae1c0)
 *
 * Set bit 6 of register 0x30 of a port while bit 5 of register 0 is cleared, then restore register 0.
 * Name basis: descriptive - register 0 saved, bit 5 cleared, bit 6 of 0x30 set, 35000 loop passes, register 0
 *   written back
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ae1c0 @ 0xa00ae1c0, flags -mcpu=v8 -Os -g.
 * Source form: the wait is a loop of 35000 explicit nop instructions counted in an unsigned short.
 * The register routines are declared without prototypes.
 */
extern int dp_reg_read8();
extern int dp_reg_write8();
extern void dp_reg_update_bits();

/*
 * Save receiver register 0, clear its bit 5, set bit 6 of register 0x30, wait 35000 loop passes, then write the
 * saved value back to register 0. Bit 6 of register 0x30 is not cleared here.
 * Callers: ipc_dispatch_command, dp_handle_block_event, dp_mst_send_down_reply_step, dp_mst_send_up_message_step.
 *   port: DP receiver
 */
void dp_set_reg30_bit6(unsigned int port)

{
  unsigned char saved_reg0;
  unsigned short wait;

  port = port & 0xff;
  saved_reg0 = dp_reg_read8(port,0);
  dp_reg_update_bits(port,0,0x20,0);
  dp_reg_update_bits(port,0x30,0x40,1);
  for (wait = 0; wait < 35000; wait++) __asm__("nop");
  dp_reg_write8(port,0,saved_reg0 & 0xff);
  return;
}
