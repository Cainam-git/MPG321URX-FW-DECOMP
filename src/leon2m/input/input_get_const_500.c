/* input_get_const_500  (FUN_a00f9398)
 *
 * Return the constant 500.
 * Returns: 500
 * Name basis: descriptive - used for the port timing record
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f9398 @ 0xa00f9398, flags -mcpu=v8 -O2 -g.
 */
unsigned int input_get_const_500(void)
{
    /* input_fill_port_timing stores this as the vertical frequency of the port timing record (offset 0x20),
       in place of the value input_block_measure_vfreq would give, when bit 7 of register 0x8C of the block
       (input_block_get_reg8c_bit7) is set. */
    return 500;
}
