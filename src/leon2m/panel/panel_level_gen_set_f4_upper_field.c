/* panel_level_gen_set_f4_upper_field  (FUN_a0101984)
 *
 * Write the 2-bit field at bits 5-6 of register 0xCF0160F4.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101984 @ 0xa0101984, flags -mcpu=v8 -O3 -g.
 * Source form: the cleared value is written back first, then the register is read again for the second write
 * (two volatile read-modify-writes).
 */
/* Register 0xCF0160F4 of the level generator block: a 1-bit field at bit 4 (panel_level_gen_set_f4_bit4),
   a 2-bit field at bits 5..6 (this routine) and a 3-bit field at bits 1..3 (panel_level_gen_set_f4_lower_field). */
#define LEVEL_GEN_REG_F4 (*(volatile unsigned int *)0xcf0160f4)

#define F4_UPPER_FIELD_KEEP  0x9f   /* every bit of the low byte except bits 5..6 */
#define F4_UPPER_FIELD_SHIFT 5

/*
 * Write the field at bits 5..6 of register 0xCF0160F4.
 *
 *   value  the new field value; its low byte is shifted into place
 *
 * The rest of the low byte keeps its value, bits 8..31 are written as 0. panel_level_gen_is_ready reports
 * ready only while this field is 0. The only caller, panel_level_gen_set_target (itself never called), writes 1.
 */
void panel_level_gen_set_f4_upper_field(unsigned int value)
{
    unsigned int reg;

    reg = LEVEL_GEN_REG_F4 & F4_UPPER_FIELD_KEEP;
    LEVEL_GEN_REG_F4 = reg;

    reg = LEVEL_GEN_REG_F4;
    reg |= (value & 0xff) << F4_UPPER_FIELD_SHIFT;
    LEVEL_GEN_REG_F4 = reg;
}
