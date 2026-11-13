/* input_block_clear_flags_1e_1f  (FUN_a0121cf4)
 *
 * Write the clear masks to registers 0x1E and 0x1F of an input block.
 * Name basis: descriptive - values 0x3F and 0x1F; used by the sync state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0121cf4 @ 0xa0121cf4, flags -mcpu=v8 -O2 -g (section default).
 * Source form: input_measure_write8 is declared unprototyped and the routine has six parameters; the second
 * call passes the incoming fourth to sixth parameters on (extra4..extra6), as the firmware does.
 */
extern int input_measure_write8();

/*
 * Write 0x3F to register 0x1E and 0x1F to register 0x1F of the measure block of an input block.
 *
 * Called from input_port_sync_task.
 */
void input_block_clear_flags_1e_1f(unsigned char blk, unsigned int extra2, unsigned int extra3, unsigned int extra4,
                                   unsigned int extra5, unsigned int extra6)
{
    input_measure_write8(blk, 0x1e, 0x3f);
    input_measure_write8(blk, 0x1f, 0x1f, extra4, extra5, extra6);
}
