/* osd_show_no_signal_message  (FUN_a009e9a8)
 *
 * Show the plain 'No Signal' message.
 * Note: Menu state 0x10E; skipped in factory mode (+0x1F6 = 0x55AA), with bit 14 of settings word 0 or bit 10
 *   of 0xA802CFF8.
 * Name basis: derived - application event table 0xA80241B0 entry 9; osd_draw_no_signal_message draws page 0x1B
 *   text 0x193008 'No Signal'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009e9a8, flags -mcpu=v8 -O3 -g. No direct callers (reached through the application event table).
 * Source form: user_settings is a local struct with word 0 and the halfword at +0x1F6; the last call is a tail call.
 */
/* The two fields of the user settings record that are read here. */
struct user_settings_record {
    unsigned int word_0x0;
    unsigned char pad4[0x1f6 - 4];
    unsigned short factory_mode_marker;         /* +0x1F6 */
};
extern struct user_settings_record user_settings;
extern unsigned short app_state_record_sleep_word;
extern unsigned int osd_menu_state;
extern void osd_draw_no_signal_message(void);

#define FACTORY_MODE_MARKER         0x55aa      /* value of settings +0x1F6 in factory mode */
#define SETTINGS_FACTORY_MODE       0x4000      /* bit 14 of settings word 0 */
#define MENU_STATE_NO_SIGNAL_ONLY   0x10e       /* the plain 'No Signal' message */

/*
 * Application event 9 (event table at 0xA80241B0): show the plain 'No Signal' message.
 *
 * Nothing happens when settings +0x1F6 holds the factory mode marker, when bit 14 of settings word 0 is set or
 * when bit 10 (0x400) of the halfword at +8 of the application state record (app_state_record_sleep_word) is set.
 * Otherwise the menu state becomes 0x10E and osd_draw_no_signal_message draws the message.
 */
void osd_show_no_signal_message(void)
{
    if (user_settings.factory_mode_marker != FACTORY_MODE_MARKER && !(user_settings.word_0x0 & SETTINGS_FACTORY_MODE) && !(app_state_record_sleep_word & 0x400)) {
        osd_menu_state = MENU_STATE_NO_SIGNAL_ONLY;
        osd_draw_no_signal_message();
    }
}
