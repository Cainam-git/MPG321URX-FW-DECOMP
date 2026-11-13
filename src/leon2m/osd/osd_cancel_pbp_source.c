/* osd_cancel_pbp_source  (FUN_a009530c)
 *
 * Restore the PBP source saved on entry, re-apply it if changed, and go back (left)
 * Note: Returns to state 0x82 / 0x83.
 * Name basis: derived - handler table 0xA802422C: left on states 0xD4..0xD7
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009530c, flags -mcpu=v8 -O3 -g. No direct callers (reached through a table).
 * Source form: the old second source is read at the start of the routine.
 */
#define LIST_ID_PBP_ITEMS             0x10      /* osd_list_id value set before the PBP items are drawn */
#define MENU_STATE_PBP_SOURCE_1       0x82      /* menu state of the PBP Source 1 item */
#define MENU_STATE_PBP_SOURCE_2       0x83      /* menu state of the PBP Source 2 item */
#define PBP_ITEMS_STATE_BASE          0x7f      /* menu state - 0x7F = item row of the PBP items */

extern unsigned char user_settings[];
extern unsigned char osd_saved_choice_value, osd_edit_value;
extern unsigned char osd_list_id;
extern unsigned int osd_menu_state;
extern void sys_user_apply_pip_sources(int);
extern void osd_clear_choice_column(void);
extern void osd_draw_pbp_items(void);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_mark(int, unsigned char, int);

/*
 * Left key in the PBP Source choices. When settings byte +0x1A3 (the source slot of the open list) is not 0,
 * the source of the second picture (settings byte +0x20) is put back from osd_edit_value, and the sources are
 * applied again if that changed it. Then back to the PBP items: the choice column is cleared, the items are
 * drawn, the menu state becomes the Source 2 item (slot not 0) or the Source 1 item (slot 0), the row of
 * osd_saved_choice_value is highlighted and marked, and the item row of the new state is highlighted.
 * osd_edit_value is loaded with the Screen Size setting (+0x1A4) and the slot byte is cleared.
 */
void osd_cancel_pbp_source(void)
{
    unsigned char old_source = user_settings[0x20];

    osd_list_id = LIST_ID_PBP_ITEMS;
    if (user_settings[0x1a3] != 0) {
        user_settings[0x20] = osd_edit_value;
        if (osd_edit_value != old_source)
            sys_user_apply_pip_sources(1);
    }
    osd_clear_choice_column();
    osd_draw_pbp_items();
    if (user_settings[0x1a3] == 0)
        osd_menu_state = MENU_STATE_PBP_SOURCE_1;
    else
        osd_menu_state = MENU_STATE_PBP_SOURCE_2;
    osd_highlight_choice_row(osd_saved_choice_value, 2);
    osd_draw_choice_mark(1, osd_saved_choice_value, 1);
    osd_highlight_choice_row(osd_menu_state - PBP_ITEMS_STATE_BASE, 1);
    osd_edit_value = user_settings[0x1a4];
    user_settings[0x1a3] = 0;
}
