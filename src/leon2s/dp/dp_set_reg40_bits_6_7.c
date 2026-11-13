/* dp_set_reg40_bits_6_7  (FUN_a00ae344)
 *
 * Set bits 6 and 7 of register 0x40 of a port and the low bits of register 0x44.
 * Name basis: descriptive - set by a command from the main processor
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ae344 @ 0xa00ae344, flags -mcpu=v8 -Os -g.
 * Source form: the routine has six parameters, all passed on to dp_set_reg44_low_bits, the way the firmware calls
 * it; the mask is written as 0xffffffc0 and cut to a byte. The called routines are declared without prototypes.
 */
extern int dp_reg_read8();
extern int dp_reg_write8();
extern int dp_set_reg44_low_bits();

/*
 * Set bits 6 and 7 of receiver register 0x40, then call dp_set_reg44_low_bits (sets bits 0 and 1 of register
 * 0x44). Mailbox command from ipc_dispatch_command.
 *   port: DP receiver
 *   param_2 .. param_6: passed on unchanged
 */
void dp_set_reg40_bits_6_7(unsigned int port,unsigned int param_2,unsigned int param_3,unsigned int param_4,
                 unsigned int param_5,unsigned int param_6)

{
  unsigned char value;

  port = port & 0xff;
  value = dp_reg_read8(port,0x40);
  dp_reg_write8(port,0x40,(value | 0xffffffc0) & 0xff);
  dp_set_reg44_low_bits(port,param_2,param_3,param_4,param_5,param_6);
  return;
}
