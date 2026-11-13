/* osd_enter_screen_size_choices  (FUN_a00967f0)
 *
 * Open the Screen Size list on the current setting.
 * Note: States 0x70..0x76; current size = settings byte +0x1A4, saved in 0xA8025C56.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x1C = 'Screen Size'; texts 0x1910B0:
 *   Auto, 4:3, 16:9, 16:10, 1:1, 24.5", 27"
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00967f0 @ 0xa00967f0 (-mcpu=v8 -O3 -g)
 * Source form: the settings record is accessed through a volatile byte pointer, so the Screen Size byte (+0x1A4)
 * is loaded twice as in the target. Same shape as osd_enter_color_temp_choices with other constants.
 */
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char osd_list_id;
extern unsigned char user_settings_color_temperature;   /* not used in this routine */

extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(int, int);
extern void osd_highlight_choice_row(int, int);

#define USER_SETTINGS_ADDRESS        0xA802D290 /* the user settings record */
#define USER_SETTINGS_SCREEN_SIZE    0x1a4      /* offset of the Screen Size byte */
#define PAGE_IMAGE_ITEMS  0x18       /* first item state of the Image page: Brightness (item row = state - 0x18) */
#define MENU_STATE_SCREEN_SIZE_LIST  0x70       /* + choice: the Screen Size list */
#define LIST_ID_SCREEN_SIZE          0xe        /* value written to osd_list_id when this list opens */
#define CHOICE_MARK_LIST             1          /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_OFF              0
#define HIGHLIGHT_ITEM_LIST_OPEN     2          /* item row highlight while its choice list is open */
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row in the open list */

/*
 * OK or right on the Screen Size item: open its list.
 *
 * The present Screen Size is saved in osd_choice_row so that the left key can put it back. The item row is
 * highlighted in the "list open" style, the menu state moves to the list state of the choice (0x70 + choice),
 * that choice's row is highlighted, and osd_list_id is set to 0xE.
 */
void osd_enter_screen_size_choices(void)
{
    volatile unsigned char *settings = (volatile unsigned char *)USER_SETTINGS_ADDRESS;
    unsigned char choice;

    choice = settings[USER_SETTINGS_SCREEN_SIZE];
    osd_choice_row = choice;
    osd_draw_choice_mark(CHOICE_MARK_LIST, choice, CHOICE_MARK_OFF);
    osd_highlight_item_row((osd_menu_state - PAGE_IMAGE_ITEMS) & 0xff, HIGHLIGHT_ITEM_LIST_OPEN);
    choice = settings[USER_SETTINGS_SCREEN_SIZE];
    osd_menu_state = choice + MENU_STATE_SCREEN_SIZE_LIST;
    osd_highlight_choice_row((int)choice, CHOICE_ROW_EDGED);
    osd_list_id = LIST_ID_SCREEN_SIZE;
}
