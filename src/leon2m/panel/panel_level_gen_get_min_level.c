/* panel_level_gen_get_min_level  (FUN_a0101cb4)
 *
 * Return the low byte of level generator register 0xCF0160C8.
 * Returns: byte
 * Note: Called by panel_level_gen_step_to_target and panel_level_gen_set_target right after they wrote the
 *   register.
 * Name basis: descriptive - register 0xCF0160C8, the one that receives the minimum level byte
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101cb4 @ 0xa0101cb4, flags -mcpu=v8 -O3 -g.
 * Source form: an unsigned int return of the register & 0xff.
 */
/* Level register of the level generator (reg_panel_level_gen_min_level, 0xCF0160C8). */
#define reg_panel_level_gen_min_level (*(volatile unsigned int *)0xcf0160c8)

/*
 * Return the low byte of the generator's level register.
 *
 * panel_level_gen_set_target and panel_level_gen_step_to_target read it back after
 * panel_level_gen_set_level_pair and search the level table for it.
 */
unsigned int panel_level_gen_get_min_level(void)
{
  return reg_panel_level_gen_min_level & 0xff;
}
