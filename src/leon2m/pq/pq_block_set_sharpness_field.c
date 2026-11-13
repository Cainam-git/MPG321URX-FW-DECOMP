/* pq_block_set_sharpness_field  (FUN_a00f6834)
 *
 * Write a 4-bit value and an on/off flag into register 0x20 of a picture block.
 * Name basis: descriptive - item 13 of pq_api_set_window_item
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6834 @ 0xa00f6834-0xa00f6898 (25 words), flags -mcpu=v8 -O3 -g.
 * Source form: the 'reg_val | (sharpness & 0xf)' term is written inside each of the two calls (one shared statement before
 * the test is computed ahead of the sharpness == 0 branch).
 */
extern unsigned char pq_block_read8(unsigned char blk, unsigned char reg);
extern void pq_block_write8(unsigned char blk, unsigned char reg, unsigned char val);

#define REG_SHARPNESS 0x20          /* register holding the sharpness field */
#define SHARPNESS_CLEAR_MASK 0x5f   /* bits cleared before writing: low nibble and enable bits */
#define SHARPNESS_VALUE_MASK 0x0f   /* low nibble: the sharpness value */
#define SHARPNESS_ENABLE_BITS 0x50  /* bits 4 and 6: the on/off flag */
#define SHARPNESS_FLAG_BIT 0x80     /* bit 7 of the parameter: selects enable or disable */

/*
 * Write the sharpness field of a picture block.
 *
 * The parameter carries a 4-bit value in its low nibble and an on/off flag in bit 7.
 * The routine reads register 0x20, clears the bits that make up the field (low nibble
 * and bits 4 and 6), then writes back the new value: if the parameter is zero, the
 * field is cleared; otherwise the low nibble is set and bits 4 and 6 are set when
 * bit 7 is set, or cleared when bit 7 is clear.
 *
 * Caller: pq_api_set_window_item (item 13, block 8 = all eight picture blocks).
 */
void pq_block_set_sharpness_field(unsigned char block, unsigned char sharpness)
{
    unsigned char reg_val = pq_block_read8(block, REG_SHARPNESS) & ~SHARPNESS_CLEAR_MASK;

    if (sharpness == 0) {
        pq_block_write8(block, REG_SHARPNESS, reg_val);
        return;
    }
    if (sharpness & SHARPNESS_FLAG_BIT)
        pq_block_write8(block, REG_SHARPNESS, reg_val | (sharpness & SHARPNESS_VALUE_MASK) | SHARPNESS_ENABLE_BITS);
    else
        pq_block_write8(block, REG_SHARPNESS, (reg_val | (sharpness & SHARPNESS_VALUE_MASK)) & ~SHARPNESS_ENABLE_BITS);
}
