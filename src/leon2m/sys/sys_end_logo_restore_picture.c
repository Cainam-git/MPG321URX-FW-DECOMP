/* sys_end_logo_restore_picture  (FUN_a008f354)
 *
 * Close the logo screen and re-apply the picture settings and layout.
 * Note: Re-applies PIP mode only when bit 12 of the status halfword 0xA802CFF8 is clear.
 * Name basis: derived - called by sys_release_logo_hold and the timer task; calls osd_close_menu, picture
 *   setters, UserSetPIPMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008f354 @ 0xa008f354, flags -mcpu=v8 -O3 -g.
 * The record base is a symbol (the firmware loads 0xa802cff4 with sethi/or and keeps it in %l0). Bit 12 of the halfword
 * at +4 is a 1-bit bit-field (big-endian: 3 bits, bit 12, 12 bits from the most significant end). The mask form
 * '& 0x1000' (also with a mask variable, a cast, '!', '1 << 12' or an empty then-arm) gives 'btst %o5,%g1'; the
 * bit-field gives the firmware's 'btst %g1,%o5'. The halves at +0 and +2 are unnamed halfwords. No volatile.
 * Callers: sys_release_logo_hold and the timer task (sys_run_app_timer_task).
 */
extern void osd_close_menu(void);
extern void SYSAPI_PanelOnOffControl(unsigned int param_1, unsigned int param_2);
extern void pq_api_set_fill_color(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4, unsigned int param_5);
extern void sys_user_apply_brightness(void);
extern void pq_user_apply_color_gain(void);
extern void pq_user_apply_color_settings(void);
extern void pq_user_apply_gamma(void);
extern void UserSetPIPMode(void);
extern void osd_set_layout(unsigned int param_1);
/* The application state record as far as this routine uses it. */
extern struct app_state_fields {
    unsigned short word_0, word_2;
    unsigned short bits_15_13:3, bit_12:1, bits_11_0:12;        /* halfword +4 */
} app_state_record;

/*
 * Close the logo screen and put the picture back: close the menu, call SYSAPI_PanelOnOffControl(0, 1), call
 * pq_api_set_fill_color(0, 0, 0, 0, 0), re-apply brightness, colour gain, colour settings and
 * gamma, set the PIP mode again, and set the layout with osd_set_layout(1).
 *
 * The PIP mode (UserSetPIPMode) is only set again when bit 12 of the halfword at +4 of app_state_record is clear.
 * That bit is cleared at the end in every case.
 * Called by sys_release_logo_hold and by the timer task.
 */
void sys_end_logo_restore_picture(void)
{
    osd_close_menu();
    SYSAPI_PanelOnOffControl(0, 1);
    pq_api_set_fill_color(0, 0, 0, 0, 0);
    sys_user_apply_brightness();
    pq_user_apply_color_gain();
    pq_user_apply_color_settings();
    pq_user_apply_gamma();

    if (app_state_record.bit_12 == 0) {
        UserSetPIPMode();
    }

    osd_set_layout(1);
    app_state_record.bit_12 = 0;
}
