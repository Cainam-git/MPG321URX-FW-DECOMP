/* osd_open_refresh_rate_position  (FUN_a00943a4)
 *
 * Open the free position editor for the refresh rate display.
 * Note: Saves the current location in 0xA8025C55; state 0x108 with editor target 0.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0xE1 = 'Customize' of the refresh rate
 *   location list
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00943a4, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a plain byte array; osd_edit_value is stored before the menu state.
 */
#define OVERLAY_REFRESH_RATE     0      /* position editor target: the refresh rate display */
#define SETTINGS_REFRESH_RATE_LOCATION 0x13e
#define SETTINGS_OVERLAY_TARGET  0x1a3
#define MENU_STATE_POSITION_EDITOR 0x108

extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern int osd_draw_overlay_position_preview();
extern void osd_hide_menu(void);
extern void panel_wait_sync_pulse(void);

/*
 * Open the free position editor for the refresh rate display (Customize location): the present location
 * (settings byte +0x13E) is saved in osd_edit_value, the menu state becomes 0x108, settings byte +0x1A3 (the
 * editor target) is set to 0, the menu layer and its windows are hidden, two sync pulses of the panel are
 * waited for, and the display is drawn for positioning with osd_draw_overlay_position_preview(0, 1, 0).
 */
void osd_open_refresh_rate_position(void)
{
    osd_edit_value = user_settings[SETTINGS_REFRESH_RATE_LOCATION];
    osd_menu_state = MENU_STATE_POSITION_EDITOR;
    user_settings[SETTINGS_OVERLAY_TARGET] = OVERLAY_REFRESH_RATE;
    osd_hide_menu();
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    osd_draw_overlay_position_preview(OVERLAY_REFRESH_RATE, 1, 0);
}
