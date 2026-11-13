/* input_block_get_reg8c_bit7  (FUN_a00f92d4)
 *
 * Return bit 7 of register 0x8C of an input block.
 * Returns: 0 or 1
 * Name basis: descriptive - part of the signal code
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f92d4 @ 0xa00f92d4, flags -mcpu=v8 -O2 -g.
 * Source form: the bit is taken with a left shift by 24 and a logical right shift by 31. The unsigned local makes
 * the compiler use srl (not sra), and the two separate assignments keep the shifts as two instructions.
 */
extern int input_capture_read8(int, int);

/* Return bit 7 of register 0x8C of the capture block (0 or 1). input_block_get_signal_code returns the
 * code 0xE8 when it is set. The second parameter is not used. */
int input_block_get_reg8c_bit7(int block, int unused)
{
    unsigned int value;
    value = (unsigned int)input_capture_read8(block & 0xff, 0x8c);
    value = value << 24;
    return (int)(value >> 31);
}
