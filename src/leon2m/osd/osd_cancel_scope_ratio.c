/* osd_cancel_scope_ratio  (FUN_a0095610)
 *
 * Restore the Optix Scope ratio saved on entry, re-apply it if changed, and go back.
 * Note: Ratio = settings byte +0x4C (0xA802D2DC).
 * Name basis: derived - handler table 0xA802422C: left on states 0xEA..0xEC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095610, flags -mcpu=v8 -O3 -g. No direct callers (reached through a table).
 * Source form: the settings record is a plain byte array; the last call (osd_draw_choice_mark) is a tail call.
 */
#define SETTINGS_SCOPE_RATIO          0x4c      /* settings offset: Optix Scope ratio */
#define MENU_STATE_SCOPE_RATIO_ITEM   0x45      /* Optix Scope items, Scope Ratio row (item row 1) */

extern unsigned char user_settings[];
extern unsigned char osd_edit_value, osd_choice_row;
extern unsigned int osd_menu_state;
extern void sys_user_apply_second_picture_enable(int);
extern void osd_clear_choice_column(void);
extern void osd_draw_optix_scope_items(void);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_mark(int, unsigned char, int);

/*
 * Left key in the Scope Ratio choices: put back the scope ratio that was saved in osd_edit_value when the list
 * was opened. When it differs from the present one, it is stored and sys_user_apply_second_picture_enable(1)
 * is called. Then back to the Optix Scope items as in osd_accept_scope_ratio, without the settings-changed request.
 */
void osd_cancel_scope_ratio(void)
{
    if (user_settings[SETTINGS_SCOPE_RATIO] != osd_edit_value) {
        user_settings[SETTINGS_SCOPE_RATIO] = osd_edit_value;
        sys_user_apply_second_picture_enable(1);
    }
    osd_clear_choice_column();
    osd_draw_optix_scope_items();
    osd_menu_state = MENU_STATE_SCOPE_RATIO_ITEM;
    osd_highlight_choice_row(osd_choice_row + 2, 2);
    osd_highlight_choice_row(1, 1);
    osd_draw_choice_mark(1, osd_choice_row + 2, 1);
}
