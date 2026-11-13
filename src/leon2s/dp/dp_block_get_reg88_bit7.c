/* dp_block_get_reg88_bit7  (FUN_a00aeb24)
 *
 * Return 1 when bit 7 of the word at +0x88 of the DisplayPort block or bit 2 of register 0x463 is set, else 0.
 * Returns: 0 or 1
 * Name basis: descriptive - block pointer at 0xA807DC04
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00aeb24 @ 0xa00aeb24-0xa00aeb6c (18 words), flags -mcpu=v8 -Os -g.
 * Source form: the pointer is dereferenced as a struct pointer (word at +0x88) with the bit-7 arm first
 * ('result = 1' in both arms of an if / else if); unsigned char result returned as 'result & 1'.
 */

/* The register block that sys_dsc_dec_records points to; word +0x88 is the only field used here. */
struct dp_reg_block { unsigned char before_0x88[0x88]; unsigned int word_0x88; };
extern struct dp_reg_block *sys_dsc_dec_records;
extern unsigned int dp_reg_read8(unsigned char, unsigned short);

/*
 * Return 1 when bit 7 of the word at +0x88 of the register block is set or bit 2 of register 0x463 of the port
 * is set (the block word is tested first); otherwise 0. Called by dp_handle_block_event.
 *   port: DP receiver (0 or 1)
 */
unsigned char dp_block_get_reg88_bit7(unsigned char port)
{
    unsigned char result = 0;

    if (sys_dsc_dec_records->word_0x88 & 0x80)
        result = 1;
    else if (dp_reg_read8(port, 0x463) & 4)
        result = 1;
    return result & 1;
}
