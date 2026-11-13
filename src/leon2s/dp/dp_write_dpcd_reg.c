/* dp_write_dpcd_reg  (FUN_a00ac4ec)
 *
 * Write a DP receiver register at 0x200 or above with write access opened.
 *   port: DP receiver
 *   reg: register
 *   val: value
 * Name basis: derived - bit 7 of register 0x30 set around the write; mailbox command 0x23
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ac4ec @ 0xa00ac4ec, flags -mcpu=v8 -Os -g. The routine ends in a merged unreachable return tail
 * (FUN_a00ac548). The register routines take a 16-bit register number.
 */
extern void dp_reg_write8(unsigned int, unsigned short, unsigned int);
extern void dp_reg_update_bits(unsigned int, unsigned short, unsigned int, unsigned int);

/*
 * Write one receiver register of number 0x200 or above. Bit 7 of register 0x30 is set around the write and
 * cleared after it. Below 0x200 nothing is written. ipc_dispatch_command calls it.
 *   port: DP receiver
 *   reg: register number
 *   val: value
 */
void dp_write_dpcd_reg(unsigned char port, unsigned short reg, unsigned char val)
{
  if (reg < 0x200)
    return;
  dp_reg_update_bits(port, 0x30, 0x80, 1);
  dp_reg_write8(port, reg, val);
  dp_reg_update_bits(port, 0x30, 0x80, 0);
}
