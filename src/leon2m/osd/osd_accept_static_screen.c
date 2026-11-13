/* osd_accept_static_screen  (FUN_a0099f20)
 *
 * Switch Static Screen Detection off or on as highlighted and go back (OK)
 * Note: Updates bit 15 of settings word +0x1DC; returns to state 0x37.
 * Name basis: derived - handler table 0xA802422C: OK on states 0xBB/0xBC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099f20 @ 0xa0099f20-0xa009a018 (248 bytes), flags -mcpu=v8 -O3 -g.
 */
struct user_settings_record { unsigned char p0[0x1dc]; unsigned int oled_care_flags; /* +0x1DC: bit 15 = Static Screen Detection on */ };
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_choice_row, osd_request_bits;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(unsigned char mode, unsigned char sel, unsigned char on);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_key_guide(unsigned char sel, unsigned char mode);
extern void osd_update_key_guide(unsigned char hi, unsigned char lo);
extern void oled_user_apply_screen_saver_range(void);

#define SETTINGS_STATIC_SCREEN_ON 0x8000 /* bit 15 of settings word +0x1DC */
#define MENU_STATE_STATIC_SCREEN_OFF 0xbb /* the OFF row of the Static Screen Detection choices; ON is 0xBC */
#define MENU_STATE_STATIC_SCREEN_ON 0xbc
#define MENU_STATE_STATIC_SCREEN_ITEM 0x37 /* Static Screen Detection item of the MSI OLED Care page */
#define PAGE_OLED_CARE_ITEMS     0x34   /* first item state of the MSI OLED Care page; item row = state - 0x34 */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define MARK_DRAW                1
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */
#define CHOICE_ROW_PLAIN         0      /* osd_highlight_choice_row style: plain */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK on OFF or ON in the Static Screen Detection choices (states 0xBB, 0xBC): store the choice and go back to the
 * Static Screen Detection item.
 *
 * State 0xBB clears and state 0xBC sets bit 15 of settings word +0x1DC. The highlight is removed with
 * osd_clear_choice_highlight(osd_choice_row + 0x45) and the mark of the row saved on entry is cleared. The row of
 * the stored choice gets the plain highlight and the mark, the menu state returns to 0x37, the item row is
 * highlighted as active, the key guide is redrawn and the setting is applied (oled_user_apply_screen_saver_range).
 * The routine ends by reporting a settings change.
 */
void osd_accept_static_screen(void)
{
    if (osd_menu_state == MENU_STATE_STATIC_SCREEN_OFF)
        user_settings.oled_care_flags &= ~SETTINGS_STATIC_SCREEN_ON;
    else if (osd_menu_state == MENU_STATE_STATIC_SCREEN_ON)
        user_settings.oled_care_flags |= SETTINGS_STATIC_SCREEN_ON;
    osd_clear_choice_highlight(osd_choice_row + 0x45);
    osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, MARK_CLEAR);
    osd_menu_state = MENU_STATE_STATIC_SCREEN_ITEM;
    osd_highlight_choice_row((user_settings.oled_care_flags >> 15) & 1, CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, (user_settings.oled_care_flags >> 15) & 1, MARK_DRAW);
    osd_highlight_item_row(osd_menu_state - 52, ITEM_ROW_ACTIVE);
    osd_draw_key_guide(1, 2);
    osd_update_key_guide(0, 1);
    oled_user_apply_screen_saver_range();
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
