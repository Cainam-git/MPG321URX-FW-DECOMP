/* panel_level_gen_clear_ctrl_bit0  (FUN_a01016e8)
 *
 * Clear bit 0 of the level generator's first control register.
 * Name basis: descriptive - 0xCF0160C0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01016e8 @ 0xa01016e8, flags -mcpu=v8 -O2 -g (section default; -O3 -g and -Os -g give the same
 * bytes).
 */
#define reg_panel_level_gen_ctrl (*(volatile unsigned int *)0xcf0160c0)

#define LEVEL_GEN_CTRL_BIT0 0x01

/*
 * Clear bit 0 of the level generator's control register (0xCF0160C0). Used once, at the end of
 * startup_init_level_generator, one sync pulse after panel_level_gen_set_ctrl_bit0.
 */
void panel_level_gen_clear_ctrl_bit0(void)
{
  reg_panel_level_gen_ctrl = reg_panel_level_gen_ctrl & ~LEVEL_GEN_CTRL_BIT0;
  return;
}
