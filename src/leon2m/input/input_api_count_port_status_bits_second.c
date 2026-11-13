/* input_api_count_port_status_bits_second  (FUN_a0144280)
 *
 * Return how many of the four bits of the second port status word are set.
 * Returns: 0..4
 * Name basis: descriptive - bits 0..3 of the halfword at 0xA802CA00; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0144280 @ 0xa0144280, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Source form the exact build depends on: the callee is declared without a prototype and the two (unused)
 * parameters stay in the signature.
 */

extern int input_count_port_status_bits_second();

/*
 * Return how many of bits 0 to 3 of the second port status word (port_present_mask_alt, 0xA802CA00) are set (it
 * forwards to input_count_port_status_bits_second). Neither parameter is used.
 */
unsigned char input_api_count_port_status_bits_second(unsigned int unused1, unsigned int unused2)
{
  return input_count_port_status_bits_second();
}
