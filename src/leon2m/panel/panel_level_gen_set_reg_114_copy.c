/* panel_level_gen_set_reg_114_copy  (FUN_a0101b60)
 *
 * Write the level generator's register 0xCF016114.
 * Note: Identical copy of panel_level_gen_set_reg_114.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101b60 @ 0xa0101b60, no flags recorded: built with the section default -mcpu=v8 -O2 -g (every
 * optimised flag set of the section gives the same bytes).
 * The same code as panel_level_gen_set_reg_114 at another address.
 */
/* Register 0xCF016114 of the level generator block (see panel_level_gen_set_reg_110). */
#define LEVEL_GEN_REG_114 (*(volatile unsigned int *)0xcf016114)

/*
 * Write a byte to register 0xCF016114.
 *
 *   value  the byte to write (its low byte is used)
 *
 * Callers: panel_level_gen_set_target and panel_level_gen_step_to_target, each right after the same value
 * went to register 0xCF016110 (panel_level_gen_set_reg_110_copy).
 */
void panel_level_gen_set_reg_114_copy(unsigned int value)
{
  LEVEL_GEN_REG_114 = value & 0xff;
}
