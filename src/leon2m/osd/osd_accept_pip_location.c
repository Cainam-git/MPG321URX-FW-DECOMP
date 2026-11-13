/* osd_accept_pip_location  (FUN_a0094fc4)
 *
 * Keep the highlighted PIP window corner and go back to the PIP settings (OK)
 * Note: States 0xD8..0xDB = Left Top .. Right Bottom; returns to 'Location' (0x7C).
 * Name basis: derived - handler table 0xA802422C: OK on states 0xD8..0xDB; texts 0x1828C0 / 0x18E9F8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0094fc4, flags -mcpu=v8 -O3 -g.
 * Source form: the routine takes two unsigned int parameters and returns the first one unchanged; the
 * callees are declared without prototypes. Same sequence as osd_accept_pip_size with other constants.
 */
#define LIST_ID_PIP_ITEMS             0x0f      /* osd_list_id value set before the PIP items are drawn */
#define MENU_STATE_PIP_LOCATION_ITEM  0x7c      /* PIP items, Location row (item row 2) */
#define OSD_REQUEST_SETTINGS_CHANGED  0x02      /* bit of osd_request_bits */

extern unsigned char osd_edit_value;
extern unsigned char osd_request_bits;
extern unsigned char osd_list_id;
extern unsigned char user_settings_screen_size;
extern unsigned int osd_menu_state;
extern int osd_draw_pip_items();
extern int osd_clear_choice_column();
extern void osd_highlight_choice_row();

/*
 * OK key in the PIP Location choices: back to the PIP items. The list id is set to the PIP items, the choice
 * column is cleared and the PIP items are drawn, the menu state becomes the Location item with its row
 * highlighted, osd_edit_value is loaded with the Screen Size setting (+0x1A4) and the settings-changed request
 * is made. Returns its first parameter unchanged; the second is not used.
 */
unsigned int osd_accept_pip_location(unsigned int first_arg, unsigned int unused)
{
    osd_list_id = LIST_ID_PIP_ITEMS;
    osd_clear_choice_column();
    osd_draw_pip_items();
    osd_menu_state = MENU_STATE_PIP_LOCATION_ITEM;
    osd_highlight_choice_row(2, 1);
    osd_edit_value = user_settings_screen_size;
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
    return first_arg;
}
