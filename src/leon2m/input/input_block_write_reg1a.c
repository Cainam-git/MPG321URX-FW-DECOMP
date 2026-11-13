/* input_block_write_reg1a  (FUN_a012082c)
 *
 * Write register 0x1A of an input block.
 * Name basis: descriptive - used by the sync state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012082c @ 0xa012082c, flags -mcpu=v8 -O2 -g (section default).
 * Source form: input_measure_write8 is declared as an unprototyped int-returning routine.
 */
extern int input_measure_write8();

/*
 * Write a value to register 0x1A of an input block. input_block_set_sync_source reads this register back.
 *
 * Called from input_port_sync_task.
 */
void input_block_write_reg1a(unsigned char blk, unsigned char value)
{
    input_measure_write8(blk, 0x1a, value);
}
