/* panel_level_gen_set_ctrl_bit1  (FUN_a01018e8)
 *
 * Set bit 1 of the level generator's first control register.
 * Name basis: descriptive - 0xCF0160C0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01018e8 @ 0xa01018e8, flags -mcpu=v8 -O2 -g (section default; -O3 -g and -Os -g give the same
 * bytes).
 */
#define reg_panel_level_gen_ctrl (*(volatile unsigned int *)0xcf0160c0)

#define LEVEL_GEN_CTRL_BIT1 0x02

/*
 * Set bit 1 of the level generator's control register (0xCF0160C0). The only caller, panel_level_gen_set_target,
 * sets it at the end of the set-up, after bit 0 (panel_level_gen_set_ctrl_bit0).
 */
void panel_level_gen_set_ctrl_bit1(void)
{
  reg_panel_level_gen_ctrl = reg_panel_level_gen_ctrl | LEVEL_GEN_CTRL_BIT1;
  return;
}
