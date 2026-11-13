/* dp_get_reg2a9_bit2  (FUN_a00b1434)
 *
 * Return bit 2 of register 0x2A9 of a port.
 * Returns: 0 or 4
 * Name basis: descriptive - plain getter
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1434 @ 0xa00b1434 (-mcpu=v8 -Os -g)
 * The result is the masked value, not 0/1.
 */
extern unsigned int dp_reg_read8(unsigned int port, unsigned short reg);

/* Bit 2 of register 0x2A9 of DisplayPort receiver `port` (0 or 4). */
unsigned int dp_get_reg2a9_bit2(unsigned int port)
{
    return dp_reg_read8(port & 0xff, 0x2a9) & 0x4;
}
