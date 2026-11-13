/* dp_tx_write_regs_69_6a  (FUN_a0087d8c)
 *
 * Write registers 0x69 and 0x6A of a DP output.
 *   p1: output
 *   p2: value 0x69
 *   p3: value 0x6A
 * Name basis: descriptive - two byte writes; caller dp_tx_set_video_timing
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0087d8c @ 0xa0087d8c (-mcpu=v8 -Os -g)
 * Source form: the second write also passes the unused parameters 4..6 on.
 */
extern int dp_tx_reg_write8();

/*
 * Write registers 0x69 and 0x6a of a link output.
 *   port:    link output
 *   value_69: byte for register 0x69
 *   value_6a: byte for register 0x6a
 * Called by dp_tx_set_video_timing.
 */
void dp_tx_write_regs_69_6a(unsigned char port,unsigned char value_69,unsigned char value_6a,unsigned int unused_4,
                 unsigned int unused_5,unsigned int unused_6)
{
  dp_tx_reg_write8(port,0x69,value_69);
  dp_tx_reg_write8(port,0x6a,value_6a,unused_4,unused_5,unused_6);
  return;
}
