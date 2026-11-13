/* dp_write_port_reg_wrapper  (FUN_a00ac584)
 *
 * Write a paged DP receiver register.
 *   port: DP receiver
 *   reg: register
 *   val: value
 * Name basis: proven - forwards to dp_write_port_reg; mailbox command 0xF5 (debug)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ac584 @ 0xa00ac584, flags -mcpu=v8 -Os -g. The register routine is declared without a prototype.
 */
extern int dp_write_port_reg();

/*
 * Pass the three arguments on to dp_write_port_reg. Mailbox command 0xF5 (debug).
 *   port: DP receiver
 *   reg: register number
 *   val: value
 */
void dp_write_port_reg_wrapper(unsigned char port, unsigned short reg, unsigned char val)

{
  dp_write_port_reg(port,reg,val);
  return;
}
