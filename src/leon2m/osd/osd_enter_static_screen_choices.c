/* osd_enter_static_screen_choices  (FUN_a0099cfc)
 *
 * Open the Static Screen Detection choices on the current setting.
 * Note: States 0xBB..0xBF; on/off = bit 15 of settings word +0x1DC.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x37 = 'Static Screen Detection' (MSI OLED
 *   Care texts 0x185E78)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099cfc @ 0xa0099cfc-0xa0099d6c (28 words), flags -mcpu=v8 -O3 -g.
 * Twin of the Night Vision list entry routine osd_enter_refresh_rate_choices (bit 12 at +0xa8). Source form: the bit is a 1-bit
 * bit-field of the settings record (16 high bits, the bit, 15 low bits in big-endian numbering); a mask and
 * shift on the absolute word would lose the firmware's [base + 0x1dc] addressing. The bit is read again for each
 * use.
 */
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
/* Settings word +0x1DC; bit 15 is Static Screen Detection (0 = OFF, 1 = ON). */
struct user_settings_record {
    unsigned char pad[0x1dc];
    unsigned int hi : 16;
    unsigned int static_screen : 1;
    unsigned int lo : 15;
};
extern struct user_settings_record user_settings;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);

#define PAGE_OLED_CARE_ITEMS     0x34   /* first item state of the MSI OLED Care page; item row = state - 0x34 */
#define MENU_STATE_STATIC_SCREEN_LIST 0xbb /* + choice: OFF 0xBB, ON 0xBC, then Starting in, Time required, Reducing Level */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define ITEM_ROW_LIST_OPEN       2      /* osd_highlight_item_row mode: parent of an open choice list */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * OK or right on the Static Screen Detection item of the MSI OLED Care page: open its choices on the OFF / ON
 * setting now stored (bit 15 of settings word +0x1DC).
 *
 * The setting is saved in osd_choice_row for the left key. The item row is highlighted in the "list open" style,
 * the menu state becomes 0xBB plus the setting, the setting's row is highlighted with edge glyphs and its mark is
 * cleared.
 */
void osd_enter_static_screen_choices(void)
{
    osd_choice_row = user_settings.static_screen;
    osd_highlight_item_row(osd_menu_state - PAGE_OLED_CARE_ITEMS, ITEM_ROW_LIST_OPEN);
    osd_menu_state = user_settings.static_screen + MENU_STATE_STATIC_SCREEN_LIST;
    osd_highlight_choice_row(user_settings.static_screen, CHOICE_ROW_EDGED);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.static_screen, MARK_CLEAR);
}
