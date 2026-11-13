/* osd_enter_night_vision_choices  (FUN_a0095afc)
 *
 * Open the Night Vision levels on the current setting.
 * Note: States 0x4E..0x52; current level = settings byte +0x15B, saved in 0xA8025C56.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x0F = 'Night Vision'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095afc @ 0xa0095afc-0xa0095b58 (23 words), flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is reached through a struct pointer; the Night Vision byte is read again
 * for every use. The callees are declared with byte parameters.
 */

/* The one field of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x15b];
    unsigned char night_vision;                 /* +0x15B: the Night Vision level */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);

#define MENU_STATE_NIGHT_VISION_LIST 0x4e       /* + level: the Night Vision list, one state per level */
#define PAGE_GAMING_ITEMS 0xe        /* first item state of the Gaming page; item row = state - 0xE */
#define CHOICE_MARK_LIST             1          /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_OFF              0
#define HIGHLIGHT_ITEM_LIST_OPEN     2          /* item row highlight while its choice list is open */
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row in the open list */

/*
 * OK or right on the Night Vision item: open its list of levels.
 *
 * The highlight of the item row changes to the "list open" style, the menu state moves to the list state of the
 * stored level (0x4E + level), that level's row is highlighted, and the level is saved in osd_choice_row so that
 * leaving the list with the left key can put it back.
 */
void osd_enter_night_vision_choices(void)
{
  struct user_settings_record *settings = &user_settings;

  osd_draw_choice_mark(CHOICE_MARK_LIST, settings->night_vision, CHOICE_MARK_OFF);
  osd_highlight_item_row(osd_menu_state - PAGE_GAMING_ITEMS, HIGHLIGHT_ITEM_LIST_OPEN);
  osd_menu_state = settings->night_vision + MENU_STATE_NIGHT_VISION_LIST;
  osd_highlight_choice_row(settings->night_vision, CHOICE_ROW_EDGED);
  osd_choice_row = settings->night_vision;
}
