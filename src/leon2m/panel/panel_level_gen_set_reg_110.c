/* panel_level_gen_set_reg_110  (FUN_a0101af0)
 *
 * Write the level generator's register 0xCF016110.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101af0 @ 0xa0101af0, no flags recorded: built with the section default -mcpu=v8 -O2 -g (every
 * optimised flag set of the section gives the same bytes).
 * panel_level_gen_set_reg_110_copy is the same code at another address.
 */
/* Register 0xCF016110 of the level generator block. It is always written together with 0xCF016114 and the
   same value (see panel_level_gen_ramp_next and panel_level_gen_step_to_target). */
#define LEVEL_GEN_REG_110 (*(volatile unsigned int *)0xcf016110)

/*
 * Write a byte to register 0xCF016110.
 *
 *   value  the byte to write (its low byte is used)
 *
 * The only caller, startup_init_level_generator, writes 0. panel_level_gen_set_target and
 * panel_level_gen_step_to_target write this register through panel_level_gen_set_reg_110_copy.
 */
void panel_level_gen_set_reg_110(unsigned int value)
{
  LEVEL_GEN_REG_110 = value & 0xff;
}
