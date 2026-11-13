/* dp_clear_reg223_bit7  (FUN_a00ad764)
 *
 * Clear bit 7 of register 0x223 of a port.
 * Name basis: descriptive - set by a command from the main processor
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad764 @ 0xa00ad764, flags -mcpu=v8 -Os -g. The register routine is declared without a prototype.
 */
extern int dp_reg_update_bits();

/* Clear bit 7 of receiver register 0x223. Mailbox command 0x2B calls it (ipc_dispatch_command).
 *   port: DP receiver
 */
void dp_clear_reg223_bit7(unsigned char port)

{
  dp_reg_update_bits(port,0x223,0x80,0);
  return;
}
