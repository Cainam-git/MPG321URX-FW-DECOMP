/* sys_dsc_enc_set_route_bits  (FUN_a00dcc50)
 *
 * Keep bits 0-5 of the route register and OR in the value shifted left by 6.
 * Name basis: descriptive - two read-modify-writes of 0xCF0116DC
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00dcc50 @ 0xa00dcc50 (-mcpu=v8 -Os -g)
 * Source form: two separate read-modify-write statements on the volatile register; the firmware does not merge them.
 */
typedef unsigned int uint;

#define reg_dsc_enc_route (*(volatile unsigned int *)0xcf0116dc)

/* Set the route value in the register at 0xcf0116dc: the first write keeps only bits 0..5 (every bit from bit 6
 * up is cleared), the second ORs in the value shifted up by 6.
 *   route: value to place at bit 6 (low byte used); sys_dsc_enc_select_route passes the encoder's source
 */
void sys_dsc_enc_set_route_bits(uint route)
{
  reg_dsc_enc_route = reg_dsc_enc_route & 0x3f;
  reg_dsc_enc_route = reg_dsc_enc_route | (route & 0xff) << 6;
  return;
}
