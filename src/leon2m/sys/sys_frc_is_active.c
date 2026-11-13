/* sys_frc_is_active  (FUN_a0108e54)
 *
 * Return whether the frame-rate converter is active.
 * Returns: 0 or 1
 * Name basis: derived - bit 7 of 0xCF011AA0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0108e54 @ 0xa0108e54, flags -mcpu=v8 -O3 -g.
 * Source form: the masked value is kept in a local and compared with 0 (and/cmp/addx).
 */
#define reg_sys_frc_active_control (*(volatile unsigned int *)0xcf011aa0)

/*
 * Return 1 when the active bit (bit 7) of the register 0xCF011AA0 is set, else 0. sys_frc_set_active writes
 * that bit.
 *
 * Called by SYSAPI_GetPanelParamStruct, which prints it, and by oled_frc_task, oled_frc_apply_default_row and
 * sys_api_is_frc_active_unlocked.
 */
unsigned int sys_frc_is_active(void)
{
    unsigned int active = reg_sys_frc_active_control & 0x80;
    return active != 0;
}
