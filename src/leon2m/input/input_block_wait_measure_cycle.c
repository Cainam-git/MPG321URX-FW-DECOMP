/* input_block_wait_measure_cycle  (FUN_a0121c6c)
 *
 * Wait until the busy bit of an input block has been set and cleared again.
 * Name basis: derived - bit 7 of register 0x20; each wait bounded by a counter
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0121c6c @ 0xa0121c6c, flags -mcpu=v8 -O3 -g.
 * Source form: two for loops with an empty body; the counter is an unsigned short and each loop tests the
 * register first, then the counter against 0x61a7.
 */
extern unsigned char input_measure_read8(unsigned char blk, unsigned char reg);

#define WAIT_LIMIT 0x61a7                   /* bound of each wait, in register reads */

/*
 * Wait for bit 7 of register 0x20 of the measure block of an input block to become set, then for it to become
 * clear again. Each wait gives up after about 0x61A9 reads of the register.
 *
 *   blk  input block
 *
 * Called from input_bring_up_check_free_run (twice), input_bring_up_lock_port (three times) and input_block_compare_two_measurements (twice).
 */
void input_block_wait_measure_cycle(unsigned char blk)
{
    unsigned short i;

    for (i = 0; !(input_measure_read8(blk, 0x20) & 0x80) && i <= WAIT_LIMIT; i++)
        ;
    for (i = 0; (input_measure_read8(blk, 0x20) & 0x80) && i <= WAIT_LIMIT; i++)
        ;
}
