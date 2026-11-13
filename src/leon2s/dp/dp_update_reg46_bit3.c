/* dp_update_reg46_bit3  (FUN_a00b06e0)
 *
 * Set bit 3 of a port's register 0x46 while dp_is_trained_with_reg223_bit7 holds, else clear it.
 * Name basis: descriptive - one call of dp_is_trained_with_reg223_bit7, then register 0x46 bit 3 set or
 *   cleared
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b06e0 @ 0xa00b06e0 (-mcpu=v8 -Os -g)
 * dp_is_trained_with_reg223_bit7 takes one argument (only %o0 is set before the call); the second parameter
 * of this routine is declared but not used.
 */
extern int dp_is_trained_with_reg223_bit7(unsigned int port);
extern void dp_reg_update_bits(unsigned int port, unsigned int reg, unsigned int mask, unsigned int on);

/* Mirror the result of dp_is_trained_with_reg223_bit7(port) into bit 3 of register 0x46 of the port:
 * set when it returns non-zero, cleared otherwise. `unused` is not used. */
void dp_update_reg46_bit3(unsigned int port, unsigned int unused)
{
    unsigned int trained;
    
    trained = dp_is_trained_with_reg223_bit7(port & 0xff);
    if ((trained & 0xff) != 0) {
        dp_reg_update_bits(port & 0xff, 0x46, 8, 1);
    } else {
        dp_reg_update_bits(port & 0xff, 0x46, 8, 0);
    }
    return;
}
