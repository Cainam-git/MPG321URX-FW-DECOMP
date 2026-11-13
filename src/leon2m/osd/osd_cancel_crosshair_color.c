/* osd_cancel_crosshair_color  (FUN_a0095704)
 *
 * Restore the crosshair colour saved on entry and go back (left)
 * Note: Colour = settings byte +0x17B (0xA802D40B).
 * Name basis: derived - handler table 0xA802422C: left on states 0xED..0xEF
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095704, flags -mcpu=v8 -O3 -g.
 * Source form: the callees are declared without prototypes; 'osd_request_bits = osd_request_bits | 2' is
 * written as an assignment.
 */
#define MENU_STATE_CROSSHAIR_COLOR_ITEM 0x40    /* Smart Crosshair items, Color row (item row 1) */
#define OSD_REQUEST_SETTINGS_CHANGED    0x02    /* bit of osd_request_bits */
#define KEY_TEXT_MOVE                   0       /* key guide texts: Move, Enter */
#define KEY_TEXT_ENTER                  1

extern unsigned char osd_edit_value;
extern unsigned char osd_request_bits;
extern unsigned char user_settings_crosshair_color;
extern unsigned int osd_menu_state;
extern int osd_draw_crosshair_items();
extern int osd_clear_choice_column();
extern void osd_draw_key_guide();
extern void osd_highlight_choice_row();
extern int osd_update_key_guide();
extern int osd_update_crosshair_color();

/*
 * Left key in the Smart Crosshair Color choices: put back the colour saved in osd_edit_value when the list
 * was opened (settings byte +0x17B), then do what osd_accept_crosshair_color does: clear the choice column,
 * draw the items, recolour the crosshair, return to the Color item, draw the key guide and make the
 * settings-changed request.
 */
void osd_cancel_crosshair_color(void) {
    osd_clear_choice_column();
    osd_draw_crosshair_items();
    user_settings_crosshair_color = osd_edit_value;
    osd_update_crosshair_color(1);
    osd_menu_state = MENU_STATE_CROSSHAIR_COLOR_ITEM;
    osd_highlight_choice_row(1, 1);
    osd_draw_key_guide(1, 2);
    osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
