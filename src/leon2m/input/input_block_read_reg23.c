/* input_block_read_reg23  (FUN_a0120c74)
 *
 * Read register 0x23 of an input block.
 * Returns: value
 * Name basis: descriptive - used when the port timing record is filled
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0120c74 @ 0xa0120c74, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the parameter is an unsigned int that is masked to 8 bits before the call, and the routine has
 * a second (unused) parameter; input_measure_read8 is declared unprototyped.
 */
extern int input_measure_read8();

/*
 * Read register 0x23 of the measure block of an input block.
 *
 * Called from input_fill_port_timing.
 */
unsigned char input_block_read_reg23(unsigned int blk, unsigned int unused)
{
    blk = blk & 0xff;
    return input_measure_read8(blk, 0x23);
}
