/* osd_accept_screen_size  (FUN_a0096b54)
 *
 * Store the highlighted screen size, close the menu and apply it (OK)
 * Name basis: derived - handler table 0xA802422C: OK on states 0x70..0x76; texts 0x1910B0: Auto, 4:3, 16:9,
 *   16:10, 1:1, 24.5", 27"
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0096b54 @ 0xa0096b54-0xa0096bd8 (33 words), flags -mcpu=v8 -O3 -g.
 * Source form: the flag word is the halfword at +4 of the record at app_state_record, declared as bit-fields (bit 15
 * and bit 10, big-endian). osd_menu_state is cleared before the calls. The routine has no parameters, and
 * osd_apply_screen_size is a tail call.
 */
/* The halfword at +4 of the application state record (the sleep word). */
struct app_state_record_layout {
  unsigned char pad0[4];
  unsigned short bit_15 : 1, bits_11_14 : 4, bit_10 : 1, bits_0_9 : 10;     /* bit 15 and bit 10 are used here */
};
extern struct app_state_record_layout app_state_record;
extern unsigned int osd_menu_state;
extern unsigned char osd_request_bits;
extern unsigned char user_settings_screen_size;
extern void input_rearm_port_event(unsigned char, unsigned char);
extern void osd_apply_screen_size(void);
extern void osd_hide_menu(void);

#define MENU_STATE_SCREEN_SIZE_LIST  0x70       /* + choice: the Screen Size list; the choice is the new Screen Size */
#define MENU_STATE_CLOSED            0
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit of osd_request_bits: event 0x80 */
#define ALL_PORTS                    4          /* input_rearm_port_event: every port */

/*
 * OK in the Screen Size list: store the highlighted choice (menu state minus 0x70) as the Screen Size setting
 * and set the settings-changed request bit.
 *
 * When bit 15 of the sleep word is set, bit 10 is set with it and the events of all ports are re-armed
 * (input_rearm_port_event). Then the menu state is set to closed, the menu is hidden and the new Screen Size is
 * applied (osd_apply_screen_size).
 */
void osd_accept_screen_size(void)
{
  user_settings_screen_size = osd_menu_state - MENU_STATE_SCREEN_SIZE_LIST;
  osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
  if (app_state_record.bit_15) {
    app_state_record.bit_10 = 1;
    input_rearm_port_event(ALL_PORTS, 0);
  }
  osd_menu_state = MENU_STATE_CLOSED;
  osd_hide_menu();
  osd_apply_screen_size();
}
