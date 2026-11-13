/* osd_api_write_reg_cc  (FUN_a0146ab0)
 *
 * Write a 16-bit value to registers 0xCC/0xCD of a menu layer.
 * Name basis: descriptive - forwards to osd_write_reg_cc
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146ab0 @ 0xa0146ab0, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype and returns int. The callee takes the layer first and
 * the value second, the reverse of this routine's parameters.
 */
extern int osd_write_reg_cc();

/* Write `value` to registers 0xCC (low byte) and 0xCD (high byte) of the menu layer (0 or 1). */
void osd_api_write_reg_cc(unsigned short value,unsigned char layer)

{
  osd_write_reg_cc(layer,value);
  return;
}
