/* dp_get_color_depth  (FUN_a00acb94)
 *
 * Return the colour depth of a port's stream in bits per colour: 6, 8, 10, 12 or 16.
 * Returns: 6, 8, 10, 12 or 16
 * Note: The code comes from register 0xBD when status 5 bit 2 and register 0x8E bit 6 are set, else from bits
 *   5..7 of register 0x8D.
 * Name basis: proven - the callers print the result as 'DP ucColordepth(%d)' and 'Color Depth Changed from %d
 *   to %d'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00acb94 @ 0xa00acb94, flags -mcpu=v8 -Os -g.
 * Source form: a dense switch (it builds the jump table) and a short-circuit && for the first condition.
 */
extern unsigned int dp_reg_read8(unsigned int, unsigned short);
extern unsigned int dp_status_reg_read8(unsigned int, unsigned short);
extern void dp_reg_update_bits(unsigned int, unsigned short, unsigned short, unsigned short);

/*
 * Read a 3-bit code from the receiver and turn it into a number: code 0, 1, 2, 3, 4 gives 6, 8, 10, 12, 16;
 * any other code gives 8. The callers (DP_GetClrSpace, dp_check_timing_change) store the result as the colour depth of
 * the port.
 *
 * The code is bits 0..2 of register 0xBD when bit 2 of status register 5 and bit 6 of register 0x8E are both
 * set (bit 7 of register 0xBE is set first); otherwise it is bits 5..7 of register 0x8D.
 *   port_arg: DP receiver
 */
unsigned int dp_get_color_depth(unsigned int port_arg)
{
  unsigned int code;
  unsigned char depth;

  port_arg &= 0xff;
  if ((dp_status_reg_read8(port_arg, 5) & 4) != 0 &&
      (dp_reg_read8(port_arg, 0x8e) & 0x40) != 0) {
    dp_reg_update_bits(port_arg, 0xbe, 0x80, 1);
    code = dp_reg_read8(port_arg, 0xbd) & 7;
  }
  else {
    code = (dp_reg_read8(port_arg, 0x8d) & 0xff) >> 5;
  }

  depth = 8;
  switch (code & 0xff) {
    case 0: depth = 6; break;
    case 1: depth = 8; break;
    case 2: depth = 10; break;
    case 3: depth = 12; break;
    case 4: depth = 16; break;
  }
  return depth & 0x1e;
}
