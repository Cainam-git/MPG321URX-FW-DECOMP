/* input_get_port_mask_bit  (FUN_a0140098)
 *
 * Return the bit of a port in the port mask at 0xA802CBD4.
 * Returns: 0 or 1
 * Name basis: descriptive - mask set by input_match_port_mode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0140098 @ 0xa0140098-0xa01400bc, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Source form the exact build depends on: "unsigned char r = 0; if (...) r = 1; return r & 1;" (a _Bool result
 * drops the "and 1"). The twin is input_get_port_mask_bit_alt, the same code on the neighbouring byte.
 */

extern unsigned char input_port_status_bit10_mask;      /* one bit per port: set by input_match_port_mode from port status bit 10 */

/*
 * Return the bit of a port in the port mask at 0xA802CBD4 (0 or 1).
 *
 *   port  the port number
 *
 * sys_api_get_channel_port_flag reads it for the port of a channel.
 */
unsigned char input_get_port_mask_bit(unsigned char port)
{
  unsigned char bit = 0;
  if (((int)input_port_status_bit10_mask >> port) & 1)
    bit = 1;
  return bit & 1;
}
