/* dp_get_reg3a_bit6  (FUN_a00b1418)
 *
 * Return bit 6 of register 0x3A of a port.
 * Returns: 0 or 0x40
 * Name basis: descriptive - plain getter
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1418 @ 0xa00b1418 (-mcpu=v8 -Os -g)
 * The result is the masked value, not 0/1.
 */
extern unsigned int dp_reg_read8(unsigned int port, unsigned short reg);

/* Bit 6 of register 0x3A of DisplayPort receiver `port` (0 or 0x40). */
unsigned int dp_get_reg3a_bit6(unsigned int port)
{
    return dp_reg_read8(port & 0xff, 0x3a) & 0x40;
}
