/* osd_cancel_language  (FUN_a0098c08)
 *
 * Restore the menu language saved on entry, redraw if it changed, and go back (left)
 * Note: Writes 0xA8025C56 back into settings byte +0x08.
 * Name basis: derived - handler table 0xA802422C: left on states 0x92..0xAE; redraws with
 *   osd_draw_language_list (texts 0x18D3D4)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0098c08 @ 0xa0098c08-0xa0098d4c (81 words), flags -mcpu=v8 -O3 -g.
 * Source form: one osd_draw_language_list call per arm of the if chain (the compiler merges them into one call).
 */
struct user_settings_record {
    unsigned char pad0[8];
    unsigned char language;                     /* +0x08: the menu language */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_choice_row;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_clear_choice_column(void);
extern void osd_draw_language_list(unsigned char);
extern void osd_redraw_settings_page(void);

#define MENU_STATE_LANGUAGE_ITEM 0x2a   /* Language item of the Settings page (item row 0) */
#define MENU_STATE_LANGUAGE_LIST 0x92   /* + language: the 29 languages are the states 0x92..0xAE */
#define CHOICES_PER_PAGE         7      /* languages on one page of the list */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_DRAW                1
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */
#define CHOICE_ROW_PLAIN         0      /* osd_highlight_choice_row style: plain */

/*
 * Left key in the language list: put back the language that was set when the list was opened and go back to the
 * Language item.
 *
 * osd_choice_row holds that saved language. The highlight of the row under the cursor is removed first. When
 * user_settings.language differs from the saved one it is restored, the choice column is cleared and the page of
 * the list that holds the language is drawn (page 0 = languages 0..6, 1 = 7..13, 2 = 14..20, 3 = 21..27,
 * 4 = language 28), then the Settings page is redrawn in the restored language. The row of the language gets the
 * plain highlight and the mark, the menu state returns to the Language item and the item row is highlighted as
 * active.
 */
void osd_cancel_language(void)
{
    osd_clear_choice_highlight((osd_menu_state - MENU_STATE_LANGUAGE_LIST) % CHOICES_PER_PAGE);
    if (user_settings.language != osd_choice_row) {
        user_settings.language = osd_choice_row;
        osd_clear_choice_column();
        if (user_settings.language == 0x1c)
            osd_draw_language_list(4);
        else if (user_settings.language > 0x14)
            osd_draw_language_list(3);
        else if (user_settings.language > 0xd)
            osd_draw_language_list(2);
        else if (user_settings.language > 6)
            osd_draw_language_list(1);
        else
            osd_draw_language_list(0);
        osd_redraw_settings_page();
    }
    osd_highlight_choice_row(user_settings.language % CHOICES_PER_PAGE, CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.language % CHOICES_PER_PAGE, MARK_DRAW);
    osd_menu_state = MENU_STATE_LANGUAGE_ITEM;
    osd_highlight_item_row(0, ITEM_ROW_ACTIVE);
}
