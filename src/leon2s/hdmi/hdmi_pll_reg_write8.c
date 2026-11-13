/* hdmi_pll_reg_write8  (FUN_a00a832c)
 *
 * Write a byte register of a pixel PLL unit.
 *   unit
 *   reg: register
 *   value
 * Name basis: derived - block table 0xA00B4D30 (units 0..8); callers the PLL set-up used by
 *   hdmi_rx21_modedet_set_pll_mode on older chips and hdmi_unit_pulse_reg3
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a832c, flags -mcpu=v8 -Os -g.
 */
extern unsigned char hdmi_pll_reg_bases;

#define REGISTER_SPACE 0xcf000000       /* register address = REGISTER_SPACE | ((block base + register) * 4) */
#define HDMI_PLL_UNITS 9                /* pixel PLL units 0..8 */

/*
 * Write a byte register of a pixel PLL unit. Only the low 8 bits of `value` are stored.
 *   unit:  pixel PLL unit (0..8; any other value does nothing)
 *   reg:   register number inside the unit
 *   value: byte to write
 * The base of each unit comes from the halfword table hdmi_pll_reg_bases.
 */
void hdmi_pll_reg_write8(unsigned int unit, unsigned short reg, unsigned int value)

{
  if ((unit & 0xff) < HDMI_PLL_UNITS) {
    *(unsigned int *)(((unsigned int)*(unsigned short *)(&hdmi_pll_reg_bases + (unit & 0xff) * 2) + (reg & 0xffff)) * 4 |
             REGISTER_SPACE) = value & 0xff;
  }
  return;
}
