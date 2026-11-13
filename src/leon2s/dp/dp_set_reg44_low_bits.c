/* dp_set_reg44_low_bits  (FUN_a00ad09c)
 *
 * Set the low two bits of register 0x44 of a port.
 * Name basis: descriptive - read, OR 3, write
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad09c @ 0xa00ad09c, flags -mcpu=v8 -Os -g.
 * Source form: the routine has six parameters and the register write is passed the last three after its value, the
 * way the firmware calls it (one caller, dp_set_reg40_bits_6_7, passes all six). The register routines are declared
 * without prototypes.
 */
extern int dp_reg_read8();
extern int dp_reg_write8();

/*
 * Set bits 0 and 1 of receiver register 0x44 (read, OR 3, write back).
 *   port: DP receiver
 *   param_2 .. param_6: only param_4 .. param_6 are used, passed on to the register write
 */
void dp_set_reg44_low_bits(unsigned int port,unsigned int param_2,unsigned int param_3,unsigned int param_4,
                 unsigned int param_5,unsigned int param_6)

{
  unsigned char value;

  port = port & 0xff;
  value = dp_reg_read8(port,0x44);
  dp_reg_write8(port,0x44,value & 0xff | 3,param_4,param_5,param_6);
  return;
}
