/* input_get_port_mask_bit_alt  (FUN_a01400bc)
 *
 * Return the bit of a port in the port mask at 0xA802CBD3.
 * Returns: 0 or 1
 * Name basis: descriptive - twin of input_get_port_mask_bit
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01400bc @ 0xa01400bc-0xa01400e0, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Source form the exact build depends on: "unsigned char r = 0; if (...) r = 1; return r & 1;" (a _Bool result
 * drops the "and 1"). The twin is input_get_port_mask_bit, the same code on the neighbouring byte.
 */

extern unsigned char input_port_status_bit7_mask;      /* one bit per port: set by input_match_port_mode from port status bit 7 */

/*
 * Return the bit of a port in the port mask at 0xA802CBD3 (0 or 1).
 *
 *   port  the port number
 */
unsigned char input_get_port_mask_bit_alt(unsigned char port)
{
  unsigned char bit = 0;
  if (((int)input_port_status_bit7_mask >> port) & 1)
    bit = 1;
  return bit & 1;
}
