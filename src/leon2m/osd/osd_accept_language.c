/* osd_accept_language  (FUN_a0098a74)
 *
 * Keep the highlighted menu language and go back (OK)
 * Note: Returns to state 0x2A.
 * Name basis: derived - handler table 0xA802422C: OK on states 0x92..0xAE
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0098a74 @ 0xa0098a74-0xa0098c08 (101 words), flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a struct whose byte +8 is the language; the page test divides the
 * osd_choice_row byte by 7 and casts it back to unsigned char.
 */
struct user_settings_record {
    unsigned char pad0[8];
    unsigned char language;                     /* +0x08: the menu language */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);

#define MENU_STATE_LANGUAGE_ITEM 0x2a   /* Language item of the Settings page (item row 0) */
#define MENU_STATE_LANGUAGE_LIST 0x92   /* + language: the 29 languages are the states 0x92..0xAE */
#define CHOICES_PER_PAGE         7      /* languages on one page of the list */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define MARK_DRAW                1
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */
#define CHOICE_ROW_PLAIN         0      /* osd_highlight_choice_row style: plain */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK on a language of the list: keep the language and go back to the Language item.
 *
 * osd_choice_row holds the language that was set when the list was opened; user_settings.language is the one
 * now set. When the page of the highlighted language ((state - 0x92) / 7) is the page of the saved language,
 * the highlight and the mark of the saved language's row are removed; otherwise the highlight of the row of the
 * language now set is removed. The row of the language now set then gets the plain highlight and the mark, the
 * menu state returns to the Language item and the item row is highlighted as active.
 */
void osd_accept_language(void)
{
    if ((osd_menu_state - MENU_STATE_LANGUAGE_LIST) / CHOICES_PER_PAGE == (unsigned char)(osd_choice_row / CHOICES_PER_PAGE)) {
        osd_clear_choice_highlight(osd_choice_row % CHOICES_PER_PAGE);
        osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row % CHOICES_PER_PAGE, MARK_CLEAR);
    } else {
        osd_clear_choice_highlight(user_settings.language % CHOICES_PER_PAGE);
    }
    osd_highlight_choice_row(user_settings.language % CHOICES_PER_PAGE, CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.language % CHOICES_PER_PAGE, MARK_DRAW);
    osd_menu_state = MENU_STATE_LANGUAGE_ITEM;
    osd_highlight_item_row(0, ITEM_ROW_ACTIVE);
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
