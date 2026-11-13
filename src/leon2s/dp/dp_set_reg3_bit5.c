/* dp_set_reg3_bit5  (FUN_a00add0c)
 *
 * Set or clear bit 5 of register 3 of a port.
 * Name basis: descriptive - register bit write
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00add0c @ 0xa00add0c, flags -mcpu=v8 -Os -g (set in symbols/leon2s.json). The register routine is
 * declared without a prototype.
 */
extern int dp_reg_update_bits();

/* Set (value non-zero) or clear (value 0) bit 5 of receiver register 3. dp_run_link_state calls it.
 *   port: DP receiver
 *   value: bit value
 */
void dp_set_reg3_bit5(unsigned char port, unsigned char value)
{
    if (value != 0)
        dp_reg_update_bits(port, 0x3, 0x20, 1);
    else
        dp_reg_update_bits(port, 0x3, 0x20, 0);
    return;
}
