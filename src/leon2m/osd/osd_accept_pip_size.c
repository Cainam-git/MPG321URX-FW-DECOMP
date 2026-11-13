/* osd_accept_pip_size  (FUN_a00953d4)
 *
 * Keep the highlighted PIP window size and go back to the PIP settings (OK)
 * Note: States 0xCD..0xCF; returns to 'PIP Size' (0x7B).
 * Name basis: derived - handler table 0xA802422C: OK on states 0xCD..0xCF; texts 0x1828C0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00953d4, flags -mcpu=v8 -O3 -g.
 * Source form: 'osd_request_bits = osd_request_bits | 2' is written as an assignment.
 */
#define LIST_ID_PIP_ITEMS             0x0f      /* osd_list_id value set before the PIP items are drawn */
#define MENU_STATE_PIP_SIZE_ITEM      0x7b      /* PIP items, PIP Size row (item row 1) */
#define OSD_REQUEST_SETTINGS_CHANGED  0x02      /* bit of osd_request_bits */

extern unsigned char osd_list_id;
extern unsigned char osd_request_bits;
extern unsigned int  osd_menu_state;
extern unsigned char user_settings_screen_size;
extern unsigned char osd_edit_value;
extern void osd_clear_choice_column(void);
extern void osd_draw_pip_items(void);
extern void osd_highlight_choice_row(unsigned int, unsigned int);

/*
 * OK key in the PIP Size choices: back to the PIP items. The list id is set to the PIP items, the choice
 * column is cleared and the PIP items are drawn, the menu state becomes the PIP Size item with its row
 * highlighted, osd_edit_value is loaded with the Screen Size setting (+0x1A4) and the settings-changed request
 * is made.
 */
void osd_accept_pip_size(void)
{
    osd_list_id = LIST_ID_PIP_ITEMS;
    osd_clear_choice_column();
    osd_draw_pip_items();
    osd_menu_state = MENU_STATE_PIP_SIZE_ITEM;
    osd_highlight_choice_row(1, 1);
    osd_edit_value = user_settings_screen_size;
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
