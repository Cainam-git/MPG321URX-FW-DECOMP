/* dp_set_reg226_bit2  (FUN_a00ad6cc)
 *
 * Set bit 2 of register 0x226 of a port.
 * Name basis: descriptive - register bit write
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad6cc @ 0xa00ad6cc, flags -mcpu=v8 -Os -g. The register routine is declared without a prototype.
 */
extern int dp_reg_update_bits();

/* Set bit 2 of receiver register 0x226. dp_run_link_state calls it.
 *   port: DP receiver
 */
void dp_set_reg226_bit2(unsigned char port)

{
  dp_reg_update_bits(port,0x226,4,1);
  return;
}
