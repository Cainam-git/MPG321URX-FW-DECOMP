/* osd_accept_protect_notice  (FUN_a009a0d4)
 *
 * Keep the highlighted Protect Notice choice (Auto, Usage 24 hrs) and go back (OK)
 * Note: Writes 0 (Auto, state 0xC3) or 1 (Usage 24 hrs, 0xC4) to settings byte +0x1EE; texts 0x18B29C.
 * Name basis: derived - handler table 0xA802422C: OK on states 0xC3/0xC4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009a0d4 @ 0xa009a0d4-0xa009a198 (49 words), flags -mcpu=v8 -O3 -g. Caller: osd_apply_choice_on_timeout.
 * Source form: the settings record is a byte array; the Protect Notice byte is user_settings[0x1ee], read again
 * for each use.
 */
extern unsigned char user_settings[];
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char osd_request_bits;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_update_key_guide(unsigned int, unsigned int);

#define USER_SETTINGS_PROTECT_NOTICE 0x1ee /* 0 = Auto, 1 = Usage 24 hrs */
#define MENU_STATE_PROTECT_NOTICE_AUTO 0xc3 /* the Auto row of the Protect Notice choices; Usage 24 hrs is 0xC4 */
#define MENU_STATE_PROTECT_NOTICE_ITEM 0x36 /* Protect Notice item of the MSI OLED Care page */
#define PAGE_OLED_CARE_ITEMS     0x34   /* first item state of the MSI OLED Care page; item row = state - 0x34 */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define MARK_DRAW                1
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */
#define CHOICE_ROW_PLAIN         0      /* osd_highlight_choice_row style: plain */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK on Auto or Usage 24 hrs in the Protect Notice choices (states 0xC3, 0xC4): store the choice and go back to
 * the Protect Notice item.
 *
 * State 0xC3 stores 0 in settings byte +0x1EE, any other state stores 1. The highlight is removed with
 * osd_clear_choice_highlight(osd_choice_row + 0x3D) and the mark of the row saved on entry is cleared. The row
 * of the stored choice gets the plain highlight and the mark, the menu state returns to 0x36, the item row is
 * highlighted as active and the key guide is redrawn. The routine ends by reporting a settings change.
 */
void osd_accept_protect_notice(void)
{
    if (osd_menu_state == MENU_STATE_PROTECT_NOTICE_AUTO)
        user_settings[USER_SETTINGS_PROTECT_NOTICE] = 0;
    else
        user_settings[USER_SETTINGS_PROTECT_NOTICE] = 1;
    osd_clear_choice_highlight(osd_choice_row + 0x3d);
    osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, MARK_CLEAR);
    osd_menu_state = MENU_STATE_PROTECT_NOTICE_ITEM;
    osd_highlight_choice_row(user_settings[USER_SETTINGS_PROTECT_NOTICE], CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings[USER_SETTINGS_PROTECT_NOTICE], MARK_DRAW);
    osd_highlight_item_row(osd_menu_state - 52, ITEM_ROW_ACTIVE);
    osd_draw_key_guide(1, 2);
    osd_update_key_guide(0, 1);
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
