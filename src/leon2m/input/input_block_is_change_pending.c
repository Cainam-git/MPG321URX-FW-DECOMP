/* input_block_is_change_pending  (FUN_a0121374)
 *
 * Return whether a block has a pending change flag.
 * Returns: 0 or 1
 * Name basis: derived - bit per block in the word at 0xA802C9E4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0121374 @ 0xa0121374, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the shift count has no '& 0x1f' mask (SPARC srl uses only the low 5 bits of the count); the
 * compiler emits sethi, ld, srl, retl, and.
 */
extern unsigned int sys_unit_event_bits;        /* one bit per input block; see the routines below */

/*
 * Return bit blk of sys_unit_event_bits: 1 when the change flag of the input block is set. The flag is set by
 * input_block_set_change_pending and cleared by input_block_clear_change_pending and by
 * input_block_handle_mode_change.
 *
 * Called from the routines at 0xa00f3c18, 0xa00f3f64, 0xa00f40e4, 0xa00f446c, 0xa00f4e60, 0xa00f51b4,
 * 0xa00f557c, 0xa00f59c4 and 0xa0123840.
 */
unsigned int input_block_is_change_pending(unsigned int blk)
{
    return (sys_unit_event_bits >> blk) & 1;
}
