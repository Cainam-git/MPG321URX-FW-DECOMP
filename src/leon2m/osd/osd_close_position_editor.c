/* osd_close_position_editor  (FUN_a0094438)
 *
 * Leave the position editor and return to the item that opened it (OK key)
 * Note: Editor target by byte 0xA802D433: 0 refresh rate display, 1 alarm clock, 2 Smart Crosshair.
 * Name basis: derived - handler table 0xA802422C: OK on state 0x108; back to 0xE1 / 0xE6 / 0x41
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0094438 @ 0xa0094438-0xa00945a8 (92 words), flags -mcpu=v8 -O3 -g. No direct callers (reached through
 * a table). Source form: one if / else if arm per editor target; the calls of the first two arms are written out
 * twice, not shared.
 */
struct user_settings_record {
    unsigned char pad[0x1a3];
    unsigned char overlay_target;               /* +0x1A3: what the position editor moves, OVERLAY_* */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_request_bits;
extern void osd_draw_main_menu_frame(void);
extern void osd_highlight_tab(unsigned char, int);
extern void osd_clear_menu_rows(void);
extern void osd_draw_gaming_items(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_pip_location_choices_copy2(void);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_gi_items(void);
extern void osd_clear_choice_column(void);
extern void osd_draw_crosshair_items(void);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_update_key_guide(int, int);
extern void osd_show_menu_layer(void);

#define OVERLAY_REFRESH_RATE            0       /* position editor target: the refresh rate display */
#define OVERLAY_ALARM_CLOCK             1       /* the alarm clock */
#define OVERLAY_CROSSHAIR               2       /* the Smart Crosshair */
#define MENU_STATE_REFRESH_RATE_LOCATION 0xe1   /* Gaming page, location choices of the refresh rate display */
#define MENU_STATE_ALARM_LOCATION       0xe6    /* Gaming page, location choices of the alarm clock */
#define MENU_STATE_CROSSHAIR_ITEMS      0x41    /* Smart Crosshair items, on the Position row (0x3F + row 2) */

/*
 * Leave the position editor (OK key in menu state 0x108) and redraw the menu page that opened it. The editor
 * target in user_settings.overlay_target picks the page: the refresh rate display and the alarm clock return to
 * the Gaming page (menu states 0xE1 and 0xE6, item row 3 or 4, location choices with row 4 highlighted);
 * the Smart Crosshair returns to its own items (state 0x41). Every arm redraws the menu frame, then the
 * tabs, item list, choice list and key guide. The menu layer is switched on again at the end and the
 * settings-changed request is made.
 */
void osd_close_position_editor(void)
{
    if (user_settings.overlay_target == OVERLAY_REFRESH_RATE) {
        osd_menu_state = MENU_STATE_REFRESH_RATE_LOCATION;
        osd_draw_main_menu_frame();
        osd_highlight_tab(1, 1);
        osd_highlight_tab(1, 2);
        osd_clear_menu_rows();
        osd_draw_gaming_items(0, 0);
        osd_highlight_item_row(3, 2);
        osd_draw_pip_location_choices_copy2();
        osd_highlight_choice_row(4, 2);
        osd_highlight_choice_row(4, 1);
    } else if (user_settings.overlay_target == OVERLAY_ALARM_CLOCK) {
        osd_menu_state = MENU_STATE_ALARM_LOCATION;
        osd_draw_main_menu_frame();
        osd_highlight_tab(1, 1);
        osd_highlight_tab(1, 2);
        osd_clear_menu_rows();
        osd_draw_gaming_items(0, 0);
        osd_highlight_item_row(4, 2);
        osd_draw_pip_location_choices_copy2();
        osd_highlight_choice_row(4, 2);
        osd_highlight_choice_row(4, 1);
    } else if (user_settings.overlay_target == OVERLAY_CROSSHAIR) {
        osd_menu_state = MENU_STATE_CROSSHAIR_ITEMS;
        osd_draw_main_menu_frame();
        osd_highlight_tab(0, 1);
        osd_highlight_tab(0, 2);
        osd_clear_menu_rows();
        osd_draw_gi_items();
        osd_highlight_item_row(1, 2);
        osd_clear_choice_column();
        osd_draw_crosshair_items();
        osd_highlight_choice_row(2, 1);
        osd_draw_key_guide(1, 2);
        osd_update_key_guide(0, 1);
    }
    osd_show_menu_layer();
    osd_request_bits |= 2;
}
