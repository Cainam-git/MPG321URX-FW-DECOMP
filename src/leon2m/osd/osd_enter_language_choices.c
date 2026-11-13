/* osd_enter_language_choices  (FUN_a00989c8)
 *
 * Open the Language list on the current language.
 * Note: States 0x92..0xAE (29 languages); language = settings byte +0x08, saved in 0xA8025C56.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x2A = 'Language' (Settings texts
 *   0x1874F8)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00989c8 @ 0xa00989c8-0xa0098a74 (43 words), flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a byte array; the language byte is user_settings[8], read again for each
 * use.
 */
extern unsigned char user_settings[];
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);

#define USER_SETTINGS_LANGUAGE   8      /* the menu language (1 = English) */
#define PAGE_SETTINGS_ITEMS      0x2a   /* first item state of the Settings page; item row = state - 0x2a */
#define MENU_STATE_LANGUAGE_LIST 0x92   /* + language: the 29 languages are the states 0x92..0xAE */
#define CHOICES_PER_PAGE         7      /* languages on one page of the list */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define ITEM_ROW_LIST_OPEN       2      /* osd_highlight_item_row mode: parent of an open choice list */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * OK or right on the Language item of the Settings page: open the language list at the language now set.
 *
 * The language is saved in osd_choice_row so that the left key can put it back. The mark of its row (language
 * modulo 7, seven languages per page) is cleared, the item row is highlighted in the "list open" style, the
 * menu state becomes 0x92 plus the language and the language's row is highlighted.
 */
void osd_enter_language_choices(void)
{
    osd_choice_row = user_settings[USER_SETTINGS_LANGUAGE];
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings[USER_SETTINGS_LANGUAGE] % CHOICES_PER_PAGE, MARK_CLEAR);
    osd_highlight_item_row(osd_menu_state - PAGE_SETTINGS_ITEMS, ITEM_ROW_LIST_OPEN);
    osd_menu_state = user_settings[USER_SETTINGS_LANGUAGE] + MENU_STATE_LANGUAGE_LIST;
    osd_highlight_choice_row(user_settings[USER_SETTINGS_LANGUAGE] % CHOICES_PER_PAGE, CHOICE_ROW_EDGED);
}
