/* osd_enter_pip_size_choices  (FUN_a0097bec)
 *
 * Open the PIP Size list (Small, Medium, Large) on the current size.
 * Note: States 0xCD..0xCF in reverse order of settings byte +0x31.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x7B = 'PIP Size'; texts 0x18F550
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0097bec @ 0xa0097bec-0xa0097c54 (26 words), flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a plain (non-volatile) byte array; the size byte (+0x31) is read again
 * after each call because the call may change it.
 */
extern unsigned char osd_list_id;
extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern void osd_draw_pip_size_choices(void);
extern void osd_highlight_choice_row(unsigned char, int);

#define USER_SETTINGS_PIP_SIZE       0x31       /* offset of the PIP size byte (0..2) */
#define MENU_STATE_PIP_SIZE_LIST     0xcf       /* - size: the PIP Size list (states 0xCD..0xCF, in reverse order of the size) */
#define PIP_SIZE_LAST                2          /* the choice row of a size is 2 minus the size */
#define LIST_ID_PIP_PBP_ITEMS        5          /* osd_list_id value set when a PIP list opens */
#define CHOICE_ROW_PLAIN             0          /* highlight style of a choice row while the list is left */
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row in the open list */

/*
 * OK or right on the PIP Size item of the PIP list: open the list of sizes (Small, Medium, Large).
 *
 * osd_list_id becomes 5 and the size choices are drawn. The menu state becomes 0xCF minus the stored size, the
 * stored size is saved in osd_edit_value, and the row 2 minus the size is highlighted, first in the plain and then
 * in the edged style.
 */
void osd_enter_pip_size_choices(void)
{
    osd_list_id = LIST_ID_PIP_PBP_ITEMS;
    osd_draw_pip_size_choices();
    osd_menu_state = MENU_STATE_PIP_SIZE_LIST - user_settings[USER_SETTINGS_PIP_SIZE];
    osd_edit_value = user_settings[USER_SETTINGS_PIP_SIZE];
    osd_highlight_choice_row(PIP_SIZE_LAST - user_settings[USER_SETTINGS_PIP_SIZE], CHOICE_ROW_PLAIN);
    osd_highlight_choice_row(PIP_SIZE_LAST - user_settings[USER_SETTINGS_PIP_SIZE], CHOICE_ROW_EDGED);
}
