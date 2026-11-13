/* input_api_count_port_status_bits  (FUN_a014412c)
 *
 * Return how many of the four bits of the first port status word are set.
 * Returns: 0..4
 * Name basis: descriptive - bits 0..3 of the halfword at 0xA802C9FE
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014412c @ 0xa014412c, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Source form the exact build depends on: the callee is declared without a prototype and the two (unused)
 * parameters stay in the signature.
 */

extern int input_count_port_status_bits();

/*
 * Return how many of bits 0 to 3 of the first port status word (port_present_mask, 0xA802C9FE) are set (it
 * forwards to input_count_port_status_bits). Neither parameter is used.
 */
unsigned char input_api_count_port_status_bits(unsigned int unused1, unsigned int unused2)
{
  return input_count_port_status_bits();
}
