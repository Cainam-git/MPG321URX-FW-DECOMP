/* panel_level_gen_clear_ctrl_bit3  (FUN_a01019e4)
 *
 * Clear bit 3 of the level generator's first control register.
 * Name basis: descriptive - 0xCF0160C0; unused
 *
 * Matching notes
 * --------------
 * FUN_a01019e4 (leon2m 0xa01019e4-0xa0101a00, 28 bytes, leaf), no flags recorded: built with the section default
 * -mcpu=v8 -O2 -g (every optimised flag set of the section gives the same bytes).
 */
/* First control register of the level generator (reg_panel_level_gen_ctrl, 0xCF0160C0). */
#define reg_panel_level_gen_ctrl (*(volatile unsigned int *)0xcf0160c0)

#define LEVEL_GEN_CTRL_BIT3 0x08    /* set by panel_level_gen_set_ctrl_high_bits */

/*
 * Clear bit 3 of the level generator's first control register; the other bits keep their value.
 *
 * Nothing in the firmware calls this routine or holds its address.
 */
void panel_level_gen_clear_ctrl_bit3(void)
{
    reg_panel_level_gen_ctrl &= ~LEVEL_GEN_CTRL_BIT3;
}
