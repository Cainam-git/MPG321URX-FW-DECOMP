/* dp_write_low_reg  (FUN_a00ac550)
 *
 * Write a DP receiver register below 0x200.
 *   port: DP receiver
 *   reg: register
 *   val: value
 * Name basis: derived - mailbox command 0xF6 (debug)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ac550 @ 0xa00ac550, flags -mcpu=v8 -Os -g. The register routine is declared without a prototype.
 */
extern int dp_reg_write8();

/*
 * Write one receiver register, only when its number is below 0x200 (registers from 0x200 up are written by
 * dp_write_dpcd_reg). Mailbox command 0xF6 (debug).
 *   port: DP receiver
 *   reg: register number
 *   val: value
 */
void dp_write_low_reg(unsigned char port, unsigned short reg, unsigned char val)

{
  if (reg < 0x200) {
    dp_reg_write8(port,reg,val);
    return;
  }
  return;
}
