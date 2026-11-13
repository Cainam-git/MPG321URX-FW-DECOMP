/* panel_level_gen_set_reg_110_copy  (FUN_a0101b48)
 *
 * Write the level generator's register 0xCF016110.
 * Note: Identical copy of panel_level_gen_set_reg_110.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101b48 @ 0xa0101b48, no flags recorded: built with the section default -mcpu=v8 -O2 -g (every
 * optimised flag set of the section gives the same bytes).
 * The same code as panel_level_gen_set_reg_110 at another address.
 */
/* Register 0xCF016110 of the level generator block (see panel_level_gen_set_reg_110). */
#define LEVEL_GEN_REG_110 (*(volatile unsigned int *)0xcf016110)

/*
 * Write a byte to register 0xCF016110.
 *
 *   value  the byte to write (its low byte is used)
 *
 * Callers: panel_level_gen_set_target writes 0x40 and then the table index times 4,
 * panel_level_gen_step_to_target the table index times 4. Each call is followed by the same value for
 * register 0xCF016114 (panel_level_gen_set_reg_114_copy).
 */
void panel_level_gen_set_reg_110_copy(unsigned int value)
{
  LEVEL_GEN_REG_110 = value & 0xff;
}
