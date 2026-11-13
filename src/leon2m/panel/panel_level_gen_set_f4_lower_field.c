/* panel_level_gen_set_f4_lower_field  (FUN_a0101a70)
 *
 * Write the 3-bit field at bits 1-3 of register 0xCF0160F4.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101a70 @ 0xa0101a70-0xa0101aa0 (12 words), flags -mcpu=v8 -O3 -g.
 * Source form: two read-modify-writes of the volatile register; the parameter is unsigned char (the firmware
 * masks it with 0xff and doubles it with add x,x).
 */
/* Register 0xCF0160F4 of the level generator block (see panel_level_gen_set_f4_upper_field). */
#define LEVEL_GEN_REG_F4 (*(volatile unsigned int *)0xcf0160f4)

#define F4_LOWER_FIELD_KEEP 0xf1    /* every bit of the low byte except bits 1..3 */

/*
 * Write the 3-bit field at bits 1..3 of register 0xCF0160F4.
 *
 *   value  the new field value, shifted into place
 *
 * Bit 0 and bits 4..7 keep their value, bits 8..31 are written as 0.
 * The only caller, startup_init_level_generator, writes 2.
 */
void panel_level_gen_set_f4_lower_field(unsigned char value)
{
    LEVEL_GEN_REG_F4 &= F4_LOWER_FIELD_KEEP;
    LEVEL_GEN_REG_F4 |= value << 1;
}
