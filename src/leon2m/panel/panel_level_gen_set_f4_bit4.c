/* panel_level_gen_set_f4_bit4  (FUN_a01019b4)
 *
 * Write bit 4 of register 0xCF0160F4.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01019b4 @ 0xa01019b4, flags -mcpu=v8 -O3 -g.
 * Source form: two separate volatile read-modify-writes of the register (clear, then OR).
 */
/* Register 0xCF0160F4 of the level generator block (see panel_level_gen_set_f4_upper_field). */
#define LEVEL_GEN_REG_F4 (*(volatile unsigned int *)0xcf0160f4)

#define F4_BIT4_KEEP  0xef          /* every bit of the low byte except bit 4 */
#define F4_BIT4_SHIFT 4

/*
 * Write bit 4 of register 0xCF0160F4.
 *
 *   value  0 or 1; its low byte is shifted into place
 *
 * The rest of the low byte keeps its value, bits 8..31 are written as 0.
 * The only caller, panel_level_gen_set_target (itself never called), writes 1.
 */
void panel_level_gen_set_f4_bit4(unsigned int value)
{
    LEVEL_GEN_REG_F4 = LEVEL_GEN_REG_F4 & F4_BIT4_KEEP;
    LEVEL_GEN_REG_F4 = LEVEL_GEN_REG_F4 | ((value & 0xff) << F4_BIT4_SHIFT);
}
