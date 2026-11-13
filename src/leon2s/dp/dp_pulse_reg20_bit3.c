/* dp_pulse_reg20_bit3  (FUN_a00ad734)
 *
 * Pulse bit 3 of register 0x20 of a port.
 * Name basis: descriptive - set, then clear
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad734 @ 0xa00ad734, flags -mcpu=v8 -Os -g. The register routine is declared without a prototype.
 */
extern int dp_reg_update_bits();

/* Set bit 3 of receiver register 0x20, then clear it. dp_run_link_state calls it.
 *   port: DP receiver
 */
void dp_pulse_reg20_bit3(unsigned int port)

{
  dp_reg_update_bits(port & 0xff,0x20,8,1);
  dp_reg_update_bits(port & 0xff,0x20,8,0);
  return;
}
