/* input_block_get_reg0c_11bit  (FUN_a00f88cc)
 *
 * Return the 11-bit value of register 0x0C of an input block.
 * Returns: value
 * Name basis: descriptive - used when the output timing record is built
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f88cc @ 0xa00f88cc, flags -mcpu=v8 -O2 -g. A non-leaf routine: it has the
 * save %sp,-104,%sp frame.
 */
extern int input_capture_read16(int, int);

/* Read 16-bit register 0x0C of the capture block and keep its low 11 bits. Register 0x0C is the one
 * input_block_set_capture_reg0e writes. */
unsigned int input_block_get_reg0c_11bit(unsigned int block)
{
    unsigned int value = block & 0xff;
    value = input_capture_read16(value, 0xc);
    return value & 0x7ff;
}
