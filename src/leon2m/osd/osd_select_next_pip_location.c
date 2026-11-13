/* osd_select_next_pip_location  (FUN_a009bdcc)
 *
 * Move to the next allowed PIP window location (down key) and apply it.
 * Note: Wraps inside the states 0xD8..0xDC; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: down on states 0xD8..0xDC; writes bits 4..7 of settings word
 *   +0x30, re-applies with sys_user_resize_window_channel1
 *
 * Matching notes
 * --------------
 * leon2m, flags -mcpu=v8 -O3 -g.
 * Source form: the wrap-around is written as an int 'entry = (low halfword of menu state - 0xd7) % 5' that is stored
 * back as 'entry + 0xd8' and is also the index tested by osd_is_choice_enabled. The location is written through a
 * bit-field of the settings word.
 */

/* The five locations are the menu states 0xD8..0xDC, in the order of the PIP_LOCATION_* values 0..4. */
#define MENU_STATE_PIP_LOCATION_FIRST 0xd8
#define PIP_LOCATION_COUNT            5
#define PIP_LOCATION_CUSTOMIZE        4
#define KEY_TEXT_ENTER                1   /* key guide texts at 0x1928B0 */
#define KEY_TEXT_SELECT               4

/* Settings word +0x30; only the two location fields are named here (location bits 4..7). */
struct pip_word {
    unsigned char pad0[0x30];
    unsigned int upper_bits : 24;     /* 0xa802d2c0 */
    unsigned int location : 4;
    unsigned int second_location : 4;
};
extern struct pip_word user_settings;
extern unsigned char osd_edit_value;   /* the stored (marked) location */
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern void sys_user_resize_window_channel1(int);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_update_key_guide(unsigned int, unsigned int);

/*
 * The menu state is the highlighted location: MENU_STATE_PIP_LOCATION_FIRST + location index. The next entry is
 * found by adding 1 and wrapping, then the step repeats while osd_is_choice_enabled rejects the entry. The
 * chosen location is written into the settings at once and the window of channel 1 is resized to it.
 * The choice mark of the stored location (osd_edit_value) is redrawn with last argument 0 when the highlight is on
 * that location and 1 otherwise.
 */
void osd_select_next_pip_location(void)
{
    int entry;
    unsigned char location;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_PIP_LOCATION_FIRST);
    do {
        entry = (unsigned short)osd_menu_state - (MENU_STATE_PIP_LOCATION_FIRST - 1);
        entry = entry % PIP_LOCATION_COUNT;
        osd_menu_state = entry + MENU_STATE_PIP_LOCATION_FIRST;
    } while (osd_is_choice_enabled(entry) != 1);
    location = osd_menu_state - MENU_STATE_PIP_LOCATION_FIRST;
    user_settings.location = location;
    osd_highlight_choice_row(location, 1);
    sys_user_resize_window_channel1(1);
    if (osd_menu_state - MENU_STATE_PIP_LOCATION_FIRST == osd_edit_value)
        osd_draw_choice_mark(1, osd_edit_value, 0);
    else
        osd_draw_choice_mark(1, osd_edit_value, 1);
    /* The last entry (Customize) shows the key guide text Enter, the others Select. */
    if (osd_menu_state == MENU_STATE_PIP_LOCATION_FIRST + PIP_LOCATION_CUSTOMIZE) {
        osd_draw_key_guide(1, 2);
        osd_update_key_guide(0, KEY_TEXT_ENTER);
    } else {
        osd_draw_key_guide(1, 3);
        osd_update_key_guide(0, KEY_TEXT_SELECT);
    }
}
