/* input_block_clear_flags_1c_1d  (FUN_a0121d1c)
 *
 * Write the clear masks to registers 0x1C and 0x1D of an input block.
 * Name basis: descriptive - values 0x3F and 0x1F; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0121d1c @ 0xa0121d1c, flags -mcpu=v8 -O2 -g (section default).
 * Source form: input_measure_write8 is declared unprototyped and the routine has six parameters; the second
 * call passes the incoming fourth to sixth parameters on (extra4..extra6), as the firmware does.
 */
extern int input_measure_write8();

/*
 * Write 0x3F to register 0x1C and 0x1F to register 0x1D of the measure block of an input block.
 *
 * No routine in the image calls it.
 */
void input_block_clear_flags_1c_1d(unsigned char blk, unsigned int extra2, unsigned int extra3, unsigned int extra4,
                                   unsigned int extra5, unsigned int extra6)
{
    input_measure_write8(blk, 0x1c, 0x3f);
    input_measure_write8(blk, 0x1d, 0x1f, extra4, extra5, extra6);
}
