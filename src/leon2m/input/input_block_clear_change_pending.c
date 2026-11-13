/* input_block_clear_change_pending  (FUN_a0121388)
 *
 * Clear the pending change flag of a block.
 * Name basis: derived - bit per block in the word at 0xA802C9E4; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0121388 @ 0xa0121388, flags -mcpu=v8 -O2 -g.
 */
extern unsigned int sys_unit_event_bits;

/*
 * Clear bit blk of sys_unit_event_bits, the change flag of the input block.
 *
 * No routine in the image calls it.
 */
void input_block_clear_change_pending(unsigned int blk)
{
    sys_unit_event_bits &= ~(1 << blk);
}
