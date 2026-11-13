/* osd_enter_color_temp_choices  (FUN_a0096494)
 *
 * Open the Color Temperature list on the current setting.
 * Note: States 0x6C..0x6F; current choice = settings byte +0x11, saved in 0xA8025C56.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x1B = 'Color Temperature'; texts
 *   0x18DB28: Cool, Normal, Warm, Customization
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0096494 @ 0xa0096494 (-mcpu=v8 -O3 -g)
 * Source form: the settings record is accessed through a volatile byte pointer, so the Color Temperature byte
 * (+0x11) is loaded twice as in the target.
 */
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char osd_list_id;
extern unsigned char user_settings_color_temperature;

extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(int, int);
extern void osd_highlight_choice_row(int, int);

#define USER_SETTINGS_ADDRESS        0xA802D290 /* the user settings record */
#define USER_SETTINGS_COLOR_TEMP     0x11       /* offset of the Color Temperature byte */
#define PAGE_IMAGE_ITEMS  0x18       /* first item state of the Image page: Brightness (item row = state - 0x18) */
#define MENU_STATE_COLOR_TEMP_LIST   0x6c       /* + choice: the Color Temperature list (states 0x6C..0x6F) */
#define LIST_ID_COLOR_TEMP           0xd        /* value written to osd_list_id when this list opens */
#define CHOICE_MARK_LIST             1          /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_OFF              0
#define HIGHLIGHT_ITEM_LIST_OPEN     2          /* item row highlight while its choice list is open */
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row in the open list */

/*
 * OK or right on the Color Temperature item: open its list (Cool, Normal, Warm, Customization).
 *
 * The present choice is saved in osd_choice_row so that the left key can put it back. The item row is
 * highlighted in the "list open" style, the menu state moves to the list state of the choice (0x6C + choice),
 * that choice's row is highlighted, and osd_list_id is set to 0xD.
 */
void osd_enter_color_temp_choices(void)
{
    volatile unsigned char *settings = (volatile unsigned char *)USER_SETTINGS_ADDRESS;
    unsigned char choice;

    choice = settings[USER_SETTINGS_COLOR_TEMP];
    osd_choice_row = choice;
    osd_draw_choice_mark(CHOICE_MARK_LIST, choice, CHOICE_MARK_OFF);
    osd_highlight_item_row((osd_menu_state - PAGE_IMAGE_ITEMS) & 0xff, HIGHLIGHT_ITEM_LIST_OPEN);
    choice = settings[USER_SETTINGS_COLOR_TEMP];
    osd_menu_state = choice + MENU_STATE_COLOR_TEMP_LIST;
    osd_highlight_choice_row((int)choice, CHOICE_ROW_EDGED);
    osd_list_id = LIST_ID_COLOR_TEMP;
}
