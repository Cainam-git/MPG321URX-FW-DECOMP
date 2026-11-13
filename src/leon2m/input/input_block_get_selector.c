/* input_block_get_selector  (FUN_a0100434)
 *
 * Return the 2-bit selector of an input block, or 0xFF.
 * Returns: selector or 0xFF
 * Name basis: descriptive - bits 2-3 of register 4 when its low bits are 3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0100434 @ 0xa0100434, flags -mcpu=v8 -O3 -g.
 * Source form: the '== 3' arm comes first (the 'result = ...; if (!=) result = 0xff' form puts the 'and 3' before
 * the shift); the result variable is an int, the return type unsigned char.
 */
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);

/*
 * Read back the selector that input_block_set_selector stores in bits 2..3 of register 4 of an input block.
 * Returns 0xFF when bits 0..1 of that register are not both set.
 *
 *   blk  input block
 *
 * Called from input_api_get_block_selector.
 */
unsigned char input_block_get_selector(unsigned char blk)
{
    unsigned char reg4;
    int selector;

    reg4 = input_capture_read8(blk, 4);
    if ((reg4 & 3) == 3)
        selector = (reg4 >> 2) & 3;
    else
        selector = 0xff;
    return selector;
}
