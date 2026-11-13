/* panel_level_gen_set_reg_108  (FUN_a0101a4c)
 *
 * Write two 4-bit fields of register 0xCF016108.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101a4c @ 0xa0101a4c, flags -mcpu=v8 -O3 -g.
 * Source form: one store of (high & 0xff) << 4 | low & 0xff; neither value is narrowed to four bits.
 */
/* Register 0xCF016108 of the level generator block: two 4-bit fields, bits 0..3 and bits 4..7. */
#define LEVEL_GEN_REG_108 (*(volatile unsigned int *)0xcf016108)

/*
 * Write both 4-bit fields of register 0xCF016108 in one store.
 *
 *   low   the field at bits 0..3 (its low byte is used as it is)
 *   high  the field at bits 4..7 (its low byte is shifted into place)
 *
 * The old content is not kept. The only caller, startup_init_level_generator, writes 5 into both fields.
 */
void panel_level_gen_set_reg_108(unsigned int low, unsigned int high)
{
  LEVEL_GEN_REG_108 = (high & 0xff) << 4 | low & 0xff;
}
