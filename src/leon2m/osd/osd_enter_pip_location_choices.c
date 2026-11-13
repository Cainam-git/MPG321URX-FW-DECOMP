/* osd_enter_pip_location_choices  (FUN_a0097c54)
 *
 * Open the PIP Location list (four corners, Customize) on the current one.
 * Note: States 0xD8..0xDC; location = bits 4..7 of settings word +0x30.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x7C = 'Location'; texts 0x18E9F8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0097c54 @ 0xa0097c54-0xa0097cb4 (24 words), flags -mcpu=v8 -O3 -g.
 * Source form: the PIP location is a 4-bit bit-field (bits 4-7 of the word at +0x30, between a 24-bit and a
 * 4-bit field; the same field as in osd_cancel_pip_location). The local is an unsigned int with the byte cast at
 * the addition (an unsigned char local drops the 'and 0xff'). The settings record is plain RAM, not volatile.
 */
struct user_settings_record {
  unsigned char pad0[0x30];
  unsigned int other_bits_hi : 24, pip_location : 4, other_bits_lo : 4;     /* +0x30: bits 4-7 = the PIP location */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_edit_value;
extern unsigned char osd_list_id;
extern unsigned int osd_menu_state;
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_pip_location_choices(void);

#define MENU_STATE_PIP_LOCATION_LIST 0xd8       /* + location: the PIP Location list (states 0xD8..0xDC, the last is Customize) */
#define LIST_ID_PIP_PBP_ITEMS        5          /* osd_list_id value set when a PIP list opens */
#define CHOICE_ROW_PLAIN             0          /* highlight style of a choice row while the list is left */
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row in the open list */

/*
 * OK or right on the Location item of the PIP list: open the list of locations (four corners and Customize).
 *
 * osd_list_id becomes 5 and the location choices are drawn. The menu state becomes 0xD8 plus the stored location,
 * the stored location is saved in osd_edit_value, and its row is highlighted, first in the plain and then in the
 * edged style.
 */
void osd_enter_pip_location_choices(void)
{
  unsigned int location;

  osd_list_id = LIST_ID_PIP_PBP_ITEMS;
  osd_draw_pip_location_choices();
  location = user_settings.pip_location;
  osd_menu_state = (unsigned char)location + MENU_STATE_PIP_LOCATION_LIST;
  osd_edit_value = location;
  osd_highlight_choice_row(location, CHOICE_ROW_PLAIN);
  osd_highlight_choice_row(user_settings.pip_location, CHOICE_ROW_EDGED);
}
