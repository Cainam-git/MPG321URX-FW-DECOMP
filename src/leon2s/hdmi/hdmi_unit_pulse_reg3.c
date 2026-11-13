/* hdmi_unit_pulse_reg3  (FUN_a00b1e30)
 *
 * Pulse bit 2 of register 3 of a PLL unit.
 * Name basis: descriptive - values 3, 7, wait, 3 through hdmi_pll_reg_write8; called by dp_pulse_pll_unit_reg3
 *   with unit 4 or 6
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1e30, flags -mcpu=v8 -Os -g.
 * Source form: the routine keeps the decompiler's six-parameter form; the last call passes three extra
 * arguments (param_4..param_6) that the callee ignores. Types and symbol names are the decompiler's.
 */
extern void hdmi_pll_reg_write8();
extern int timer_delay_long_units();

#define PLL_REG_3 3             /* the register that is written */

/*
 * Write 3, 7, wait, then 3 to register 3 of a pixel PLL unit, so that bit 2 of the register is set for the
 * duration of the wait. The wait is timer_delay_long_units(1). Called by dp_pulse_pll_unit_reg3 with unit 4 or 6.
 *   unit: pixel PLL unit
 * The other five parameters are not used here (the last call passes the last three on).
 */
void hdmi_unit_pulse_reg3(unsigned char unit,unsigned int param_2,unsigned int param_3,unsigned int param_4,
                 unsigned int param_5,unsigned int param_6)

{
  hdmi_pll_reg_write8(unit,PLL_REG_3,3);
  hdmi_pll_reg_write8(unit,PLL_REG_3,7);
  timer_delay_long_units(1);
  hdmi_pll_reg_write8(unit,PLL_REG_3,3,param_4,param_5,param_6);
  return;
}
