/* input_block_set_reg5c_bit2  (FUN_a00f8f58)
 *
 * Write bit 2 of register 0x5C of an input block.
 * Name basis: descriptive - used by the sync state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f8f58 @ 0xa00f8f58, flags -mcpu=v8 -O2 -g.
 */
extern int input_capture_update_bits();

/* Set bit 2 of register 0x5C of the capture block to the given value (0 clears, 1 sets).
 * Called by input_port_sync_task. */
void input_block_set_reg5c_bit2(unsigned char block, unsigned char value)
{
    input_capture_update_bits(block, 0x5c, 4, value);
    return;
}
