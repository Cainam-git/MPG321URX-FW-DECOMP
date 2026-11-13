/* dp_write_port_reg  (FUN_a00856a8)
 *
 * Write a register of a DP receiver, mapping the port to its block.
 *   param_1: port
 *   param_2: register
 *   param_3: value
 * Name basis: derived - dp_map_port then the block register write
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00856a8 @ 0xa00856a8 (-mcpu=v8 -Os -g)
 * Tail-calls dp_paged_reg_write8 with all six parameters passed on; the register is truncated to 16 bits and
 * the value to 8 bits by the parameter types.
 */
extern int dp_map_port();
extern int dp_paged_reg_write8();

/*
 * Write a paged register of the DP receiver of a port: the port is mapped with dp_map_port and the call is
 * passed to dp_paged_reg_write8.
 *   port:  DP port
 *   reg:   register number
 *   value: byte to write
 *   extra_4..extra_6: passed on unchanged
 */
int dp_write_port_reg(unsigned int port, unsigned short reg, unsigned char value,
                 unsigned int extra_4, unsigned int extra_5, unsigned int extra_6)
{
    unsigned int block = dp_map_port(port & 0xff) & 0xff;
    return dp_paged_reg_write8(block, reg, value, extra_4, extra_5, extra_6);
}
