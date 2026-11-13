/* panel_level_gen_set_level_pair  (FUN_a0101a28)
 *
 * Write the minimum level byte to 0xCF0160C8 and the level byte to 0xCF0160DC.
 * Name basis: descriptive - 0xCF0160C8 and 0xCF0160DC; all callers pass the fixed byte 0x7E first and the RAM
 *   level second
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101a28 @ 0xa0101a28, no flags recorded: built with the section default -mcpu=v8 -O2 -g (every
 * optimised flag set of the section gives the same bytes).
 * Source form: register 0xCF0160DC is written before the level register.
 */
/* Level register of the level generator (reg_panel_level_gen_min_level, 0xCF0160C8) and its companion
   register 0xCF0160DC, which is written only here. */
#define reg_panel_level_gen_min_level (*(volatile unsigned int *)0xcf0160c8)
#define LEVEL_GEN_REG_DC          (*(volatile unsigned int *)0xcf0160dc)

/*
 * Write the generator's level and its companion byte.
 *
 *   level      the new level (low byte used), to 0xCF0160C8
 *   companion  the byte for 0xCF0160DC (low byte used)
 *
 * All three callers (startup_init_level_generator, panel_level_gen_step_to_target, panel_level_gen_set_target)
 * pass the byte at 0xA802CA03 as level and the level kept in RAM (panel_level_gen_level) as companion.
 */
void panel_level_gen_set_level_pair(unsigned int level, unsigned int companion)
{
  LEVEL_GEN_REG_DC = companion & 0xff;
  reg_panel_level_gen_min_level = level & 0xff;
}
