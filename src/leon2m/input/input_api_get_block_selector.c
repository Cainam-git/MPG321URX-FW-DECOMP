/* input_api_get_block_selector  (FUN_a0142fe4)
 *
 * Return the 2-bit selector of an input block, or 0xFF.
 * Returns: selector or 0xFF
 * Name basis: descriptive - forwards; bits 2-3 of block register 4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0142fe4 @ 0xa0142fe4, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Source form the exact build depends on: the callee is declared without a prototype, the argument is masked to
 * a byte before the call, and the parameter is unsigned int. A second parameter (unused) is part of the
 * firmware's signature.
 */

extern int input_block_get_selector();

/*
 * Return the 2-bit selector of an input block, or 0xFF (it forwards to input_block_get_selector).
 *
 *   block   the input block
 *   unused  not used
 */
unsigned char input_api_get_block_selector(unsigned int block, unsigned int unused)
{
  block = block & 0xff;
  return input_block_get_selector(block);
}
