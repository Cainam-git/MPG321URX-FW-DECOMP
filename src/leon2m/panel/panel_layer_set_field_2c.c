/* panel_layer_set_field_2c  (FUN_a010ec70)
 *
 * Write a 3-bit field of register 0x2C of both halves.
 * Name basis: descriptive - bits 16..18 of 0xD003002C / 0xD003802C; unused
 *
 * Matching notes
 * --------------
 * FUN_a010ec70 (leon2m 0xa010ec70-0xa010eca8, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 */
/* Register 0x2C in the first and in the second register set (the second sits 0x8000 higher). */
#define FIELD_2C_FIRST_SET  (*(volatile unsigned int *)0xd003002c)
#define FIELD_2C_SECOND_SET (*(volatile unsigned int *)0xd003802c)

/*
 * Replace bits 16..18 of register 0x2C with value, keeping the other bits of the first set's register, and write the
 * result to both sets. No routine in the image calls it.
 */
void panel_layer_set_field_2c(unsigned char value)
{
    unsigned int word = (FIELD_2C_FIRST_SET & ~0x70000u) | (value << 16);

    FIELD_2C_FIRST_SET = word;
    FIELD_2C_SECOND_SET = word;
}
