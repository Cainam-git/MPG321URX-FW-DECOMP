/* input_get_const_375  (FUN_a00f9390)
 *
 * Return the constant 375.
 * Returns: 375
 * Name basis: descriptive - 0x177; used for the port timing record
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f9390 @ 0xa00f9390, flags -mcpu=v8 -O2 -g.
 */
unsigned int input_get_const_375(void)
{
    /* input_fill_port_timing stores this as the horizontal frequency of the port timing record (offset 0x1E),
       in place of the value input_block_measure_hfreq would give, when bit 7 of register 0x8C of the block
       (input_block_get_reg8c_bit7) is set. */
    return 0x177;
}
