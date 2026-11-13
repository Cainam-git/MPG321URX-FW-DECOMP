/* osd_open_alarm_clock_location  (FUN_a00936fc)
 *
 * Open the screen-position list for the alarm clock display.
 * Note: States 0xE2..0xE6 = Left Top .. Customize; current position = settings byte +0x13F.
 * Name basis: derived - OK on state 0x56; position texts 0x18E9F8 drawn by osd_draw_pip_location_choices_copy
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00936fc, flags -mcpu=v8 -O3 -g.
 * Source form: the store to osd_edit_value comes before the store to the menu state; the location byte is read
 * through a struct pointer, once for the saved value and again for the last call (a tail call).
 */
#define MENU_STATE_ALARM_CHOICES        0x56    /* + choice row; row 0 = Location */
#define MENU_STATE_ALARM_LOCATION_LIST  0xe2    /* + location (0..4): the location choices, states 0xE2..0xE6 */
#define CHOICE_ROW_PLAIN       0        /* osd_highlight_choice_row styles */
#define CHOICE_ROW_EDGED       1

/* The Alarm Clock overlay location in the user settings record. */
struct settings_overlay_locations {
    unsigned char pad[0x13f];
    unsigned char alarm_clock_location;         /* +0x13F: 0..4, see OVERLAY_LOCATION_* */
};
extern struct settings_overlay_locations user_settings;
extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_pip_location_choices_copy(void);

/*
 * OK or right key on the Location row of the Alarm Clock choices (menu state 0x56): take the highlight off
 * that row, draw the location choices (four corners and Customize), save the present location in osd_edit_value,
 * and make the menu state that location's state. The row of the present location is highlighted in both styles.
 */
void osd_open_alarm_clock_location(void)
{
  struct settings_overlay_locations *settings;
  unsigned char location;

  osd_clear_choice_highlight(osd_menu_state - MENU_STATE_ALARM_CHOICES);
  osd_draw_pip_location_choices_copy();
  settings = &user_settings;
  location = settings->alarm_clock_location;
  osd_edit_value = location;
  osd_menu_state = location + MENU_STATE_ALARM_LOCATION_LIST;
  osd_highlight_choice_row(location, CHOICE_ROW_PLAIN);
  osd_highlight_choice_row(settings->alarm_clock_location, CHOICE_ROW_EDGED);
}
