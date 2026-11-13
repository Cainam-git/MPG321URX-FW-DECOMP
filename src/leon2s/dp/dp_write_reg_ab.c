/* dp_write_reg_ab  (FUN_a0084c74)
 *
 * Write register 0xAB of a DP receiver.
 *   port
 *   value
 * Name basis: descriptive - value from the port's settings record; caller the DP settings apply routine
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0084c74 @ 0xa0084c74 (-mcpu=v8 -Os -g)
 * Source form: the mapped port is masked to a byte before the call.
 */
extern int dp_map_port();
extern int dp_paged_reg_write8();

/*
 * Write a value to register 0xab of the DP receiver of a port.
 *   port:  DP port, mapped to its receiver by dp_map_port
 *   value: byte to write
 * The caller passes byte 0x118 of the port's record.
 */
int dp_write_reg_ab(unsigned char port, unsigned char value)
{
    unsigned char block = dp_map_port(port) & 0xff;
    return dp_paged_reg_write8(block, 0xab, value);
}
