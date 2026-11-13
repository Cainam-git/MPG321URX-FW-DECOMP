/* sys_ddr_send_mode_register  (FUN_a00e406c)
 *
 * Send a mode register command to the memory chips.
 * Name basis: derived - field writes, then the start bit; used by the levelling and reference voltage steps
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e406c @ 0xa00e406c, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the callees are declared without parameter lists, so the last call passes its fifth and sixth
 * arguments.
 */
extern void sys_ddr_phy_update_bits();
extern void sys_ddr_phy_write_field();
extern int sys_ddr_set_mode_register_fields();

/*
 * Send one mode register command to memory interface `unit`.
 *
 *   mode_register, field_b, payload   the command, see sys_ddr_set_mode_register_fields
 *   tail_a, tail_b                    passed as the fifth and sixth argument of the second
 *                                     sys_ddr_set_mode_register_fields call
 *
 * Steps: set bits 5 and 6 of register 0x2c; write the command fields; set bit 7 of register 0x2c and clear it
 * again; clear bit 6 of register 0x2c; clear the command fields (mode register, field_b and payload all 0).
 *
 * Called by the write levelling, the gate training and the reference voltage code.
 */
void sys_ddr_send_mode_register(unsigned int unit, unsigned int mode_register, unsigned int field_b,
                                unsigned int payload, unsigned int tail_a, unsigned int tail_b)
{
  sys_ddr_phy_update_bits(unit,0x2c,0x60,0x60);
  sys_ddr_set_mode_register_fields(unit,mode_register,field_b,payload);
  sys_ddr_phy_write_field(unit,0x2c,0x80,7,1);
  sys_ddr_phy_write_field(unit,0x2c,0x80,7,0);
  sys_ddr_phy_write_field(unit,0x2c,0x40,6,0);
  sys_ddr_set_mode_register_fields(unit,0,0,0,tail_a,tail_b);
}
