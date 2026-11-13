/* sys_ddr_set_mode_register_fields  (FUN_a00e3f6c)
 *
 * Write the fields of a mode register command.
 * Name basis: descriptive - registers 0x2C, 0x2B, 0x2A and 0x29
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e3f6c @ 0xa00e3f6c, flags -mcpu=v8 -O3 -g.
 * Source form: sys_ddr_phy_write_field is declared without a parameter list, so the sixth argument of the last call
 * is passed on.
 */
extern void sys_ddr_phy_write_field();

/*
 * Write the four register fields that make up a mode register command of memory interface `unit`.
 *
 *   mode_register  callers pass 5, 6 or 0xb: bit 0 goes to bit 7 of register 0x2b, bits 1..4 to register 0x2c
 *   field_b        its low 4 bits go to bits 3..6 of register 0x2b
 *   payload        bits 0..7 go to register 0x29, bits 8..15 to register 0x2a, bits 16..18 to bits 0..2 of
 *                  register 0x2b
 *   unused         not used
 *   extra          handed on as a sixth argument to sys_ddr_phy_write_field, which does not read it
 *
 * Called by sys_ddr_send_mode_register, which sets the command and then clears it again.
 */
void sys_ddr_set_mode_register_fields(unsigned int unit, unsigned int mode_register, unsigned int field_b,
                                      unsigned int payload, unsigned int unused, unsigned int extra)
{
  sys_ddr_phy_write_field(unit,0x2c,0xf,0,mode_register >> 1 & 0xf);
  sys_ddr_phy_write_field(unit,0x2b,0xff,0,(mode_register & 1) << 7 | (field_b & 0xf) << 3 | payload >> 0x10 & 7);
  sys_ddr_phy_write_field(unit,0x2a,0xff,0,payload >> 8 & 0xff);
  sys_ddr_phy_write_field(unit,0x29,0xff,0,payload & 0xff,extra);
}
