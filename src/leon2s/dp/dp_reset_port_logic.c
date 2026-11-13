/* dp_reset_port_logic  (FUN_a00aba5c)
 *
 * Pulse the reset and option bits of a DP receiver (registers 0x3E, 0xF7, 0x20).
 *   p1: DP receiver
 *   p2: option
 *   p3: option
 * Name basis: descriptive - caller dp_reset_port
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00aba5c @ 0xa00aba5c, flags -mcpu=v8 -Os -g.
 * Source form: the routine has six parameters; the last write (register 0xF4) is passed param_4, param_5 and
 * param_6 after its value, the way the firmware calls it. The register routines are declared without prototypes.
 */
extern void dp_reg_write8();
extern void dp_reg_update_bits();
extern void dp_status_reg_update_bits();

/*
 * Run the reset sequence of a DP receiver: write the register values below in this order.
 *   0x3E (status): bit 0 set;  0xF7: 7, then 5;  0x20: bit 0 set, then cleared;
 *   0xF7: bit 6 = bit6, bit 4 = bit4, bit 5 = bit5 (low byte of the fourth parameter), bit 7 set;
 *   0xF4: 0xA0.
 * dp_reset_port calls it with (port, 1, 1, 0) when byte 0x11F of the port's record is 1.
 *   port: DP receiver
 *   bit6: value of bit 6 of register 0xF7
 *   bit4: value of bit 4 of register 0xF7
 *   bit5: value of bit 5 of register 0xF7 (low byte used)
 *   param_5, param_6: only passed on to the last write
 */
void dp_reset_port_logic(unsigned char port, unsigned char bit6, unsigned char bit4, unsigned int bit5,
                 unsigned int param_5, unsigned int param_6)

{
  dp_status_reg_update_bits(port,0x3e,1,1);
  dp_reg_write8(port,0xf7,7);
  dp_reg_write8(port,0xf7,5);
  dp_reg_update_bits(port,0x20,1,1);
  dp_reg_update_bits(port,0x20,1,0);
  dp_reg_update_bits(port,0xf7,0x40,bit6);
  dp_reg_update_bits(port,0xf7,0x10,bit4);
  dp_reg_update_bits(port,0xf7,0x20,bit5 & 0xff);
  dp_reg_update_bits(port,0xf7,0x80,1);
  dp_reg_write8(port,0xf4,0xa0,bit5,param_5,param_6);
  return;
}
