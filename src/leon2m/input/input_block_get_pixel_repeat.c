/* input_block_get_pixel_repeat  (FUN_a0120bf4)
 *
 * Return the factor 1, 2, 4 or 8 selected by the low bits of register 0x11.
 * Returns: factor
 * Name basis: descriptive - mapping 0/1/2/3 -> 1/4/2/8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0120bf4 @ 0xa0120bf4, flags -mcpu=v8 -O3 -g.
 * Required form: a switch with an explicit 'case 3: r = 8' equal to the default. It makes 1 the root of the
 * compare tree like the firmware; the block crosses into the default and adds no code. The result is an unsigned
 * char (the firmware's 'and 0xf').
 */
extern unsigned char input_measure_read8(unsigned char, unsigned char);

/*
 * Map bits 0..1 of register 0x11 of an input block to a factor: 0 gives 1, 1 gives 4, 2 gives 2, 3 gives 8.
 *
 *   blk  input block
 *
 * Called from input_fill_port_timing.
 */
unsigned char input_block_get_pixel_repeat(unsigned char blk)
{
    unsigned char factor;

    switch (input_measure_read8(blk, 0x11) & 3) {
    case 0: factor = 1; break;
    case 1: factor = 4; break;
    case 2: factor = 2; break;
    case 3: factor = 8; break;
    default: factor = 8; break;
    }
    return factor;
}
