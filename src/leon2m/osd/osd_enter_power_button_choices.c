/* osd_enter_power_button_choices  (FUN_a009906c)
 *
 * Open the Power Button list (OFF, Standby) on the current setting.
 * Note: States 0xB4/0xB5; setting = bit 15 of settings word +0xA8.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x2E = 'Power Button'; texts 0x19336C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009906c @ 0xa009906c, flags -mcpu=v8 -O3 -g.
 * Source form: the record is a structure with bit 15 of word +0xA8 as a 1-bit bit-field (big-endian numbering:
 * 16 high bits, then the bit, then 15 low bits); the bit is read again for each use.
 */
/* Settings word +0xA8; bit 15 is the Power Button choice. */
struct user_settings_record { unsigned char pad[0xa8]; unsigned int hi : 16, standby : 1, lo : 15; };
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);

#define PAGE_SETTINGS_ITEMS      0x2a   /* first item state of the Settings page; item row = state - 0x2a */
#define MENU_STATE_POWER_BUTTON_LIST 0xb4 /* + choice: OFF 0xB4, Standby 0xB5 */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define ITEM_ROW_LIST_OPEN       2      /* osd_highlight_item_row mode: parent of an open choice list */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK or right on the Power Button item: open its list (OFF, Standby) on the choice now stored (bit 15 of
 * settings word +0xA8: 0 = OFF, 1 = Standby).
 *
 * The choice is saved in osd_choice_row so that the left key can put it back. Its mark is cleared, the item row
 * is highlighted in the "list open" style, the menu state becomes 0xB4 plus the choice and the choice's row is
 * highlighted.
 */
void osd_enter_power_button_choices(void)
{
    osd_choice_row = user_settings.standby;
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.standby, MARK_CLEAR);
    osd_highlight_item_row(osd_menu_state - PAGE_SETTINGS_ITEMS, ITEM_ROW_LIST_OPEN);
    osd_menu_state = user_settings.standby + MENU_STATE_POWER_BUTTON_LIST;
    osd_highlight_choice_row(user_settings.standby, CHOICE_ROW_EDGED);
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
