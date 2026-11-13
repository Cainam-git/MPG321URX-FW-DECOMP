/* osd_open_crosshair_icon  (FUN_a0095778)
 *
 * Open the crosshair icon picker on the current icon.
 * Note: Current icon = settings byte +0x190, saved in 0xA8025C56; state 0x43.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x3F = 'Icon' (texts 0x18F984)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095778, flags -mcpu=v8 -O3 -g.
 * Source form: the routine takes six unsigned int parameters; the last four are passed on to
 * osd_update_key_guide (declared with six parameters), which is a tail call. The icon byte is a plain byte
 * array element, read again after each call.
 */
#define MENU_STATE_CROSSHAIR_ICON_LIST 0x43     /* the Smart Crosshair icon choices */
#define SETTINGS_CROSSHAIR_ICON        0x190    /* settings offset: Smart Crosshair icon (1..6) */
#define KEY_TEXT_MOVE                  0        /* key guide texts: Move, Select */
#define KEY_TEXT_SELECT                4

extern unsigned char osd_choice_row;
extern unsigned char user_settings[];
extern unsigned int osd_menu_state;
extern void osd_clear_choice_column(void);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_highlight_crosshair_icon(unsigned int, unsigned int);
extern void osd_draw_crosshair_icon_page(unsigned int);
extern void osd_update_key_guide(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

/*
 * OK or right key on the Icon item of the Smart Crosshair items: open the icon choices. The present icon is
 * saved in osd_choice_row so that the left key can restore it, the menu state becomes 0x43, the choice column
 * is cleared, the icon's row is highlighted (both styles) and the icon page is drawn, then the key guide with
 * the texts Move and Select.
 * Parameters 3 to 6 are passed on to osd_update_key_guide; parameters 1 and 2 are not used.
 */
void osd_open_crosshair_icon(unsigned int unused_1, unsigned int unused_2, unsigned int arg3, unsigned int arg4,
                  unsigned int arg5, unsigned int arg6)
{
    osd_choice_row = user_settings[SETTINGS_CROSSHAIR_ICON];
    osd_menu_state = MENU_STATE_CROSSHAIR_ICON_LIST;
    osd_clear_choice_column();
    osd_highlight_crosshair_icon(user_settings[SETTINGS_CROSSHAIR_ICON], 1);
    osd_highlight_crosshair_icon(user_settings[SETTINGS_CROSSHAIR_ICON], 0);
    osd_draw_crosshair_icon_page(0);
    osd_draw_key_guide(0, 0);
    osd_draw_key_guide(1, 3);
    osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_SELECT, arg3, arg4, arg5, arg6);
}
