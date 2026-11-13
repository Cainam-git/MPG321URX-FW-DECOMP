/* input_api_any_port_status_second  (FUN_a0144268)
 *
 * Return whether any bit of the second port status word is set.
 * Returns: 0 or 1
 * Name basis: descriptive - bits 0..3 of the halfword at 0xA802CA00; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0144268 @ 0xa0144268, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Source form the exact build depends on: the callee is declared without a prototype and the two (unused)
 * parameters stay in the signature.
 */

extern int input_any_port_status_second();

/*
 * Return whether any of bits 0 to 3 of the second port status word (port_present_mask_alt, 0xA802CA00) is set
 * (it forwards to input_any_port_status_second). Neither parameter is used.
 */
unsigned char input_api_any_port_status_second(unsigned int unused1, unsigned int unused2)
{
  return input_any_port_status_second();
}
