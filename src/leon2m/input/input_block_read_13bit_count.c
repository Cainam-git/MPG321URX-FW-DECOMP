/* input_block_read_13bit_count  (FUN_a00f9354)
 *
 * Return the 13-bit value held in registers 0xAC and 0x9E of an input block.
 * Returns: value
 * Name basis: descriptive - used by the sync state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f9354 @ 0xa00f9354, flags -mcpu=v8 -O3 -g.
 */
extern int input_capture_read8(unsigned char blk, unsigned char reg);

/* Return a 13-bit value of the capture block: the byte of register 0x9E as the low 8 bits and the low
 * 5 bits of register 0xAC as the high 5 bits. */
unsigned short input_block_read_13bit_count(unsigned char block)
{
    unsigned char low = input_capture_read8(block, 0x9e);

    return low | (input_capture_read8(block, 0xac) & 0x1f) << 8;
}
