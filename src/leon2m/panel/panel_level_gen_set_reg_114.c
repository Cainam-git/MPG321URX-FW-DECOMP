/* panel_level_gen_set_reg_114  (FUN_a0101b08)
 *
 * Write the level generator's register 0xCF016114.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101b08 @ 0xa0101b08, no flags recorded: built with the section default -mcpu=v8 -O2 -g (every
 * optimised flag set of the section gives the same bytes).
 * panel_level_gen_set_reg_114_copy is the same code at another address.
 */
/* Register 0xCF016114 of the level generator block, written together with 0xCF016110 (see
   panel_level_gen_set_reg_110). */
#define LEVEL_GEN_REG_114 (*(volatile unsigned int *)0xcf016114)

/*
 * Write a byte to register 0xCF016114.
 *
 *   value  the byte to write (its low byte is used)
 *
 * The only caller, startup_init_level_generator, writes 0. panel_level_gen_set_target and
 * panel_level_gen_step_to_target write this register through panel_level_gen_set_reg_114_copy.
 */
void panel_level_gen_set_reg_114(unsigned int value)
{
  LEVEL_GEN_REG_114 = value & 0xff;
}
