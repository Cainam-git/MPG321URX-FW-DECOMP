/* dp_tx_init_port_extra_regs  (FUN_a0085b14)
 *
 * Write the remaining fixed start-up registers of a DP output.
 *   p1: output
 * Name basis: descriptive - five fixed register writes (0x21..0x24, 0x07); caller dp_tx_init_ports
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0085b14 @ 0xa0085b14 (-mcpu=v8 -Os -g)
 * Source form: the last write also passes the unused parameters 4..6 on.
 */
extern void dp_tx_reg_write8();
extern void dp_tx_reg_update_bits();

/*
 * Set up five more registers of a link output: clear bit 3 of register 0x28, then write 0x31 to register
 * 0x21, 0x30 to 0x07, 0x04 to 0x22, 0x32 to 0x23 and 0x96 to 0x24.
 *   output: link output
 * Called by dp_tx_init_ports.
 */
void dp_tx_init_port_extra_regs(unsigned char output,unsigned int unused_2,unsigned int unused_3,unsigned int unused_4,
                 unsigned int unused_5,unsigned int unused_6)
{
  dp_tx_reg_update_bits(output,0x28,8,0);
  dp_tx_reg_write8(output,0x21,0x31);
  dp_tx_reg_write8(output,7,0x30);
  dp_tx_reg_write8(output,0x22,4);
  dp_tx_reg_write8(output,0x23,0x32);
  dp_tx_reg_write8(output,0x24,0x96,unused_4,unused_5,unused_6);
  return;
}
