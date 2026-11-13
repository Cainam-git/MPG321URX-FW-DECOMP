/* panel_level_gen_set_reg_104  (FUN_a0101868)
 *
 * Write two 4-bit fields of register 0xCF016104.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101868 @ 0xa0101868, flags -mcpu=v8 -O3 -g.
 * Source form: the two values are combined without masking.
 */
#define LEVEL_GEN_REG_104 (*(volatile unsigned int *)0xcf016104)

/*
 * Write register 0xCF016104 of the level generator: low_field in bits 0..3, high_field from bit 4 up. The values
 * are not masked.
 *
 * startup_init_level_generator writes (8, 0); panel_level_gen_set_target writes (0, 0).
 */
void panel_level_gen_set_reg_104(unsigned int low_field, int high_field)
{
  LEVEL_GEN_REG_104 = high_field << 4 | low_field;
  return;
}
