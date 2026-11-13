/* osd_enter_image_enhancement_choices  (FUN_a00961d4)
 *
 * Open the Image Enhancement levels on the current setting.
 * Note: States 0x64..0x68; current level = low 4 bits of settings halfword +0x34.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x17 = 'Image Enhancement'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00961d4 @ 0xa00961d4-0xa0096230 (23 words), flags -mcpu=v8 -O3 -g.
 * Source form: the level is a 4-bit bit-field at the end of a 16-bit container (a mask on a plain 16-bit field
 * narrows the load to a byte load at +0x35); the firmware reads it again for every use. The record is reached
 * through a struct pointer.
 */

/* The field of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x34];
    unsigned short other_bits : 12, image_enhancement : 4;      /* +0x34: bits 0-3 = Image Enhancement level */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);

#define PAGE_PROFESSIONAL_ITEMS         0x15   /* first item state of the Professional page; item row = state - 0x15 */
#define MENU_STATE_IMAGE_ENHANCEMENT_LIST 100   /* + level: the Image Enhancement list (states 0x64..0x68) */
#define CHOICE_MARK_LIST                 1      /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_OFF                  0
#define HIGHLIGHT_ITEM_LIST_OPEN         2      /* item row highlight while its choice list is open */
#define CHOICE_ROW_EDGED                 1      /* highlight style of a choice row in the open list */

/*
 * OK or right on the Image Enhancement item: open its list of levels.
 *
 * The present level is saved in osd_choice_row so that the left key can put it back. The item row is
 * highlighted in the "list open" style, the menu state moves to the list state of the level (100 + level) and that
 * level's row is highlighted.
 */
void osd_enter_image_enhancement_choices(void)
{
  struct user_settings_record *settings = &user_settings;

  osd_choice_row = settings->image_enhancement;
  osd_draw_choice_mark(CHOICE_MARK_LIST, settings->image_enhancement, CHOICE_MARK_OFF);
  osd_highlight_item_row(osd_menu_state - PAGE_PROFESSIONAL_ITEMS, HIGHLIGHT_ITEM_LIST_OPEN);
  osd_menu_state = settings->image_enhancement + MENU_STATE_IMAGE_ENHANCEMENT_LIST;
  osd_highlight_choice_row(settings->image_enhancement, CHOICE_ROW_EDGED);
}
