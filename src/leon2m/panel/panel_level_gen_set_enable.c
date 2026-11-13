/* panel_level_gen_set_enable  (FUN_a0101c64)
 *
 * Switch the level generator on or off.
 * Name basis: descriptive - bit 7 of 0xCF016118
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101c64 @ 0xa0101c64, flags -mcpu=v8 -O3 -g.
 * Source form: the clear is written as & 0xffffff7f. sys_frc_set_active is the same code with other constants.
 */
/* Register 0xCF016118 of the level generator (reg_panel_level_gen_enable): bit 7 switches the generator on. */
#define reg_panel_level_gen_enable (*(volatile unsigned int *)0xcf016118)

#define LEVEL_GEN_ON 0x80

/*
 * Switch the level generator on (on != 0) or off (on == 0); the other bits of the register keep their value.
 *
 * Callers: panel_level_gen_enable and panel_level_gen_ramp_step switch it on, panel_level_gen_set_target
 * switches it off before it sets the generator up. None of these three is called in the firmware.
 */
void panel_level_gen_set_enable(unsigned char on)
{
    if (on != 0) {
        reg_panel_level_gen_enable = reg_panel_level_gen_enable | LEVEL_GEN_ON;
    } else {
        reg_panel_level_gen_enable = reg_panel_level_gen_enable & 0xffffff7f;
    }
}
