/* osd_enter_pixel_shift_choices  (FUN_a0099c0c)
 *
 * Open the Pixel Shift speed list (Slow, Normal, Fast) on the current setting.
 * Note: Setting = settings byte +0x1DD, saved in 0xA8025C55.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x34 = 'Pixel Shift' (MSI OLED Care texts
 *   0x185E78)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099c0c @ 0xa0099c0c-0xa0099c64 (22 words), flags -mcpu=v8 -O3 -g.
 * Twin of osd_enter_protect_notice_choices (other field, other mirror byte, other offset). Source form: the
 * speed byte is reached through a struct pointer (the firmware loads the record base with sethi/or into one
 * register) and is read again after each call; the callee prototypes take unsigned char.
 */
struct user_settings_record { unsigned char pad[0x1dd]; unsigned char pixel_shift_speed; /* +0x1DD */ };
extern struct user_settings_record user_settings;
extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);

#define PAGE_OLED_CARE_ITEMS     0x34   /* first item state of the MSI OLED Care page; item row = state - 0x34 */
#define MENU_STATE_PIXEL_SHIFT_SPEED_LIST 0xf1 /* + speed: the Pixel Shift speed list (states 0xF1..0xF3) */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define ITEM_ROW_LIST_OPEN       2      /* osd_highlight_item_row mode: parent of an open choice list */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * Open the Pixel Shift speed list (Slow, Normal, Fast) on the speed now stored (settings byte +0x1DD).
 *
 * The speed is saved in osd_edit_value for the left key. The item row of the OLED Care page is highlighted in
 * the "list open" style, the menu state becomes 0xF1 plus the speed, the speed's row is highlighted with edge
 * glyphs and its mark is cleared.
 */
void osd_enter_pixel_shift_choices(void)
{
  struct user_settings_record *p = &user_settings;

  osd_edit_value = p->pixel_shift_speed;
  osd_highlight_item_row(osd_menu_state - PAGE_OLED_CARE_ITEMS, ITEM_ROW_LIST_OPEN);
  osd_menu_state = p->pixel_shift_speed + MENU_STATE_PIXEL_SHIFT_SPEED_LIST;
  osd_highlight_choice_row(p->pixel_shift_speed, CHOICE_ROW_EDGED);
  osd_draw_choice_mark(CHOICE_MARK_LIST, p->pixel_shift_speed, MARK_CLEAR);
}
