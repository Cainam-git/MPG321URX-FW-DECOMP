/* input_block_detect_sync_mode_auto  (FUN_a01211ac)
 *
 * Work out the sync mode of an input block using its own signal code.
 * Returns: mode
 * Name basis: derived - input_block_detect_sync_mode with the block's code; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01211ac @ 0xa01211ac, flags -mcpu=v8 -O2 -g (section default).
 * Source form: both callees are declared unprototyped and int-returning; the block number is masked to 8 bits
 * and so is the signal code, and the result is returned as an unsigned char.
 */
extern int input_block_get_signal_code();
extern int input_block_detect_sync_mode();

/*
 * Run input_block_detect_sync_mode for a block with the block's current signal code
 * (input_block_get_signal_code) and return its result.
 *
 * No routine in the image calls it.
 */
unsigned char input_block_detect_sync_mode_auto(unsigned int blk, unsigned int unused)
{
    unsigned int code;

    blk = blk & 0xff;
    code = blk;
    code = input_block_get_signal_code(blk) & 0xff;
    return input_block_detect_sync_mode(code, blk);
}
