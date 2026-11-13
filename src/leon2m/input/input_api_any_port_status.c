/* input_api_any_port_status  (FUN_a0144114)
 *
 * Return whether any bit of the first port status word is set.
 * Returns: 0 or 1
 * Name basis: descriptive - bits 0..3 of the halfword at 0xA802C9FE
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0144114 @ 0xa0144114, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Source form the exact build depends on: the callee is declared without a prototype and the two (unused)
 * parameters stay in the signature.
 */

extern int input_any_port_status();

/*
 * Return whether any of bits 0 to 3 of the first port status word (port_present_mask, 0xA802C9FE) is set
 * (it forwards to input_any_port_status). Neither parameter is used.
 */
unsigned char input_api_any_port_status(unsigned int unused1, unsigned int unused2)
{
  return input_any_port_status();
}
