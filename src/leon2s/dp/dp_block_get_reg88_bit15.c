/* dp_block_get_reg88_bit15  (FUN_a00aeadc)
 *
 * Return 1 when bit 15 of the word at +0x88 of the DisplayPort block and bit 0 of register 0x463 are both set,
 * else 0.
 * Returns: 0 or 1
 * Name basis: descriptive - block pointer at 0xA807DC04
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00aeadc @ 0xa00aeadc-0xa00aeb24 (18 words), flags -mcpu=v8 -Os -g.
 * Source form: bit 15 is a 1-bit bit-field (the firmware does 'srl 15; btst 1'; the mask form gives one
 * 'sethi 0x8000; btst'), one '&&' condition with r = 1 / r = 0 arms and 'return r & 1' (as dp_block_get_reg88_bit7).
 */

/* The register block that sys_dsc_dec_records points to; word +0x88 is the only field used here. */
struct dp_reg_block {
    unsigned char before_0x88[0x88];
    struct {
        unsigned int upper_half : 16, bit15 : 1, lower_bits : 15;
    } word_0x88;
};
extern struct dp_reg_block *sys_dsc_dec_records;
extern unsigned int dp_reg_read8(unsigned char, unsigned short);

/*
 * Return 1 when bit 15 of the word at +0x88 of the register block is set and bit 0 of register 0x463 of the
 * port is set; otherwise 0. Called by dp_handle_block_event.
 *   port: DP receiver (0 or 1)
 */
unsigned char dp_block_get_reg88_bit15(unsigned char port)
{
    unsigned char result;

    if (sys_dsc_dec_records->word_0x88.bit15 && (dp_reg_read8(port, 0x463) & 1))
        result = 1;
    else
        result = 0;
    return result & 1;
}
