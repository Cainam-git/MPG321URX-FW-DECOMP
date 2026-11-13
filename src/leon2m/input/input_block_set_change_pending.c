/* input_block_set_change_pending  (FUN_a01216f8)
 *
 * Set the pending change flag of a block.
 * Name basis: derived - bit per block in the word at 0xA802C9E4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01216f8 @ 0xa01216f8, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the shift uses only the low five bits of blk, so the byte parameter goes to the sll without a
 * zero-extension.
 */
extern unsigned int sys_unit_event_bits;

/*
 * Set bit blk of sys_unit_event_bits, the change flag of the input block (read by
 * input_block_is_change_pending).
 *
 * Called twice from sys_set_channel_port.
 */
void input_block_set_change_pending(unsigned char blk)
{
    sys_unit_event_bits |= 1 << blk;
}
