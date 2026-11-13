/* sys_frc_set_active  (FUN_a0109110)
 *
 * Switch the frame-rate converter's active bit on or off.
 * Name basis: derived - bit 7 of 0xCF011AA0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0109110 @ 0xa0109110, flags -mcpu=v8 -O3 -g.
 */
#define reg_sys_frc_active_control (*(volatile unsigned int *)0xcf011aa0)

/*
 * Set (active != 0) or clear the active bit, bit 7 of the register 0xCF011AA0. sys_frc_is_active reads it back.
 *
 * Called by SYSAPI_ConfigSystemPIPMode, GMDHEnableFRC and the OLED frame-rate-converter handler (oled_frc_task).
 */
void sys_frc_set_active(unsigned char active)
{
    if (active != 0) {
        reg_sys_frc_active_control = reg_sys_frc_active_control | 0x80;
    } else {
        reg_sys_frc_active_control = reg_sys_frc_active_control & 0xffffff7f;
    }
}
