/* osd_enter_protect_notice_choices  (FUN_a009a020)
 *
 * Open the Protect Notice choices (Auto, Usage 24 hrs) on the current setting.
 * Note: States 0xC3/0xC4; setting = settings byte +0x1EE.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x36 = 'Protect Notice' (MSI OLED Care
 *   texts 0x185E78)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009a020 @ 0xa009a020-0xa009a078 (22 words), flags -mcpu=v8 -O3 -g.
 * Twin of osd_enter_pixel_shift_choices (other field, other mirror byte, other offset). Source form: the field is
 * reached through a struct pointer (the firmware loads the record base with sethi/or into one register), not as
 * a mid-record int; the callee prototypes take unsigned char.
 */
struct user_settings_record { unsigned char pad[0x1ee]; unsigned char protect_notice; /* +0x1EE: 0 = Auto, 1 = Usage 24 hrs */ };
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);

#define PAGE_OLED_CARE_ITEMS     0x34   /* first item state of the MSI OLED Care page; item row = state - 0x34 */
#define MENU_STATE_PROTECT_NOTICE_LIST 0xc3 /* + choice: Auto 0xC3, Usage 24 hrs 0xC4 */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define ITEM_ROW_LIST_OPEN       2      /* osd_highlight_item_row mode: parent of an open choice list */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * OK or right on the Protect Notice item of the MSI OLED Care page: open its choices (Auto, Usage 24 hrs) on the
 * setting now stored (settings byte +0x1EE).
 *
 * The setting is saved in osd_choice_row for the left key. The item row is highlighted in the "list open" style,
 * the menu state becomes 0xC3 plus the setting, the setting's row is highlighted with edge glyphs and its mark is
 * cleared.
 */
void osd_enter_protect_notice_choices(void)
{
  struct user_settings_record *p = &user_settings;

  osd_choice_row = p->protect_notice;
  osd_highlight_item_row(osd_menu_state - PAGE_OLED_CARE_ITEMS, ITEM_ROW_LIST_OPEN);
  osd_menu_state = p->protect_notice + MENU_STATE_PROTECT_NOTICE_LIST;
  osd_highlight_choice_row(p->protect_notice, CHOICE_ROW_EDGED);
  osd_draw_choice_mark(CHOICE_MARK_LIST, p->protect_notice, MARK_CLEAR);
}
