/* osd_cancel_scope_size  (FUN_a0095510)
 *
 * Restore the Optix Scope size saved on entry, re-apply it if changed, and go back.
 * Note: Size = settings byte +0x4B (0xA802D2DB).
 * Name basis: derived - handler table 0xA802422C: left on states 0xE7..0xE9
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095510, flags -mcpu=v8 -O3 -g. No direct callers (reached through a table).
 * Source form: the settings record is a plain byte array; the last call (osd_draw_choice_mark) is a tail call.
 */
#define SETTINGS_SCOPE_SIZE           0x4b      /* settings offset: Optix Scope size */
#define MENU_STATE_SCOPE_SIZE_ITEM    0x44      /* Optix Scope items, Scope Size row (item row 0) */

extern unsigned char user_settings[];
extern unsigned char osd_edit_value, osd_choice_row;
extern unsigned int osd_menu_state;
extern void sys_user_apply_second_picture_enable(int);
extern void osd_clear_choice_column(void);
extern void osd_draw_optix_scope_items(void);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_mark(int, unsigned char, int);

/*
 * Left key in the Scope Size choices: put back the scope size that was saved in osd_edit_value when the list
 * was opened. When it differs from the present one, it is stored and sys_user_apply_second_picture_enable(1)
 * is called. Then back to the Optix Scope items as in osd_accept_scope_size, without the settings-changed request.
 */
void osd_cancel_scope_size(void)
{
    if (user_settings[SETTINGS_SCOPE_SIZE] != osd_edit_value) {
        user_settings[SETTINGS_SCOPE_SIZE] = osd_edit_value;
        sys_user_apply_second_picture_enable(1);
    }
    osd_clear_choice_column();
    osd_draw_optix_scope_items();
    osd_menu_state = MENU_STATE_SCOPE_SIZE_ITEM;
    osd_highlight_choice_row(0, 1);
    osd_highlight_choice_row(osd_choice_row + 2, 2);
    osd_draw_choice_mark(1, osd_choice_row + 2, 1);
}
