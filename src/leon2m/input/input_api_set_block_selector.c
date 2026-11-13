/* input_api_set_block_selector  (FUN_a0142fcc)
 *
 * Write the 2-bit selector of an input block.
 * Name basis: descriptive - forwards; bits 2-3 of block register 4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0142fcc @ 0xa0142fcc, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Source form the exact build depends on: the callee is declared without a prototype (int-returning, no
 * parameter list), so both arguments are passed as they stand.
 */

extern int input_block_set_selector();

/*
 * Write the 2-bit selector of an input block (it forwards to input_block_set_selector, which writes it when
 * the block is active).
 *
 *   block     the input block
 *   selector  the value to write
 */
void input_api_set_block_selector(unsigned char block, unsigned char selector)
{
  input_block_set_selector(block, selector);
}
