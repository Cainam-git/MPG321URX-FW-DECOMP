/* panel_api_reapply_nominal_rate  (FUN_a0148500)
 *
 * Apply the nominal refresh rate of the active row again.
 * Name basis: derived - FRCConfigPostFRC, then the lock / free-run set-up; called from the OLED power state
 *   machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148500 @ 0xa0148500, flags -mcpu=v8 -O3 -g and -O3 -msoft-float.
 * The second call is a tail call.
 */

/* The active panel mode row (0x58 bytes, see struct panel_mode_row); only its nominal rate is used here. */
struct active_row { unsigned char before_rate[0x52]; unsigned short nominal_rate; unsigned char after_rate[4]; };
extern struct active_row panel_active_row;
extern unsigned char sys_config_byte_3;
extern void FRCConfigPostFRC(int, unsigned short, int);
extern void sys_frc_setup_lock(int, int, int, unsigned short);

/*
 * Program the output side again from the nominal rate of the active panel row (in tenths of a hertz: 2400, 1200
 * or 600 for the modes 0, 1 and 2). It never uses the measured input rate.
 *
 * Called from the OLED power state machine.
 */
void panel_api_reapply_nominal_rate(void)
{
    FRCConfigPostFRC(sys_config_byte_3 != 0, panel_active_row.nominal_rate, 1);
    sys_frc_setup_lock(0, 0, 0, panel_active_row.nominal_rate);
}
