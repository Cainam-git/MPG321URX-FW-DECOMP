/* osd_open_alarm_clock_position  (FUN_a00943ec)
 *
 * Open the free position editor for the alarm clock display.
 * Note: Saves the current location in 0xA8025C55; state 0x108 with editor target 1.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0xE6 = 'Customize' of the alarm clock
 *   location list
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00943ec, flags -mcpu=v8 -O3 -g. No direct callers (reached through a table).
 * Source form: the settings record is a plain byte array; osd_edit_value is stored before the menu state; the
 * last call is a tail call.
 */
#define OVERLAY_ALARM_CLOCK      1      /* position editor target: the alarm clock */
#define SETTINGS_ALARM_CLOCK_LOCATION 0x13f
#define SETTINGS_OVERLAY_TARGET  0x1a3
#define MENU_STATE_POSITION_EDITOR 0x108

extern unsigned char user_settings[];
extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern void osd_hide_menu(void);
extern void panel_wait_sync_pulse(void);
extern void osd_draw_overlay_position_preview(int, int, int);

/*
 * Open the free position editor for the alarm clock display (Customize location): the present location
 * (settings byte +0x13F) is saved in osd_edit_value, the menu state becomes 0x108, settings byte +0x1A3 (the
 * editor target) is set to 1, the menu layer and its windows are hidden, two sync pulses of the panel are
 * waited for, and the display is drawn for positioning with osd_draw_overlay_position_preview(1, 1, 0).
 */
void osd_open_alarm_clock_position(void)
{
    osd_edit_value = user_settings[SETTINGS_ALARM_CLOCK_LOCATION];
    osd_menu_state = MENU_STATE_POSITION_EDITOR;
    user_settings[SETTINGS_OVERLAY_TARGET] = OVERLAY_ALARM_CLOCK;
    osd_hide_menu();
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    osd_draw_overlay_position_preview(OVERLAY_ALARM_CLOCK, 1, 0);
}
