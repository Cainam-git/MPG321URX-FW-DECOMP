/* panel_layer_set_field_2c_clear_bit0  (FUN_a010d838)
 *
 * Clear bit 0 and put a value in bits 16..18 of register 0x2C; write the result to both halves.
 * Note: Same as panel_layer_set_field_2c plus the clearing of bit 0. Nothing calls it.
 * Name basis: descriptive - 0xD003002C / 0xD003802C, keep mask 0xFFF8FFFE
 *
 * Matching notes
 * --------------
 * FUN_a010d838, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 */
#define REG_2C_HALF0 (*(volatile unsigned int *)0xd003002c)
#define REG_2C_HALF1 (*(volatile unsigned int *)0xd003802c)

#define REG_2C_KEEP_MASK 0xfff8fffe     /* clears bit 0 and bits 16..18 */

/*
 * Clear bit 0 and bits 16..18 of register 0x2C of the first output half (0xD003002C), put value in bits 16..18
 * (value is not masked), and write the result to that register and to 0xD003802C of the second half.
 * The second half's old contents are not read.
 */
void panel_layer_set_field_2c_clear_bit0(unsigned char value)
{
    unsigned int word = (REG_2C_HALF0 & REG_2C_KEEP_MASK) | (value << 16);

    REG_2C_HALF0 = word;
    REG_2C_HALF1 = word;
}
