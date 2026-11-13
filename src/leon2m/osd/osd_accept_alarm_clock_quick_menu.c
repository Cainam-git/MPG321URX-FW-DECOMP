/* osd_accept_alarm_clock_quick_menu  (FUN_a0097498)
 *
 * Start the alarm timer highlighted in the quick menu and close it.
 * Note: Quick menu state 0xFD; copies the preset minutes/seconds and sets bit 14 of 0xA802CFF4.
 * Name basis: derived - handler table 0xA802422C: OK on state 0xFD; same fields as osd_accept_alarm_time
 *   (settings +0x1A0..+0x1A2)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0097498 @ 0xa0097498-0xa0097508 (28 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through the handler table).
 * Source form: both source bytes are read into locals (+0x197 first) before the two stores. The settings record
 * is a byte array and app_state_record is declared as a plain halfword.
 */
extern unsigned char user_settings[];
extern unsigned char osd_alarm_clock_choice;
extern unsigned int osd_menu_state;
extern unsigned short app_state_record;
extern unsigned char osd_request_bits;
extern void osd_hide_menu(void);

#define USER_SETTINGS_ALARM_CLOCK    0x1a0      /* Alarm Clock timer choice; minutes +0x1A1, seconds +0x1A2 */
#define USER_SETTINGS_ALARM_MINUTES  0x1a1
#define USER_SETTINGS_ALARM_SECONDS  0x1a2
#define ALARM_TABLE_0X197            0x197      /* alarm_table_0x197[choice]: copied to +0x1A1 */
#define ALARM_TABLE_0X19B            0x19b      /* alarm_table_0x19b[choice]: copied to +0x1A2 */
#define APP_STATE_FLAG0_ALARM_RUNNING 0x4000    /* bit 14 of the first halfword of the application state record */
#define MENU_STATE_CLOSED            0
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit of osd_request_bits: event 0x80 */

/*
 * OK on an alarm timer in the Alarm Clock quick menu (menu state 0xFD): start the timer chosen in settings
 * byte +0x1A0 and close the menu.
 *
 * When the choice is not 0, the two table bytes of that choice (+0x197 + choice and +0x19B + choice) are copied to
 * +0x1A1 and +0x1A2 (minutes and seconds). The choice is saved in osd_alarm_clock_choice, bit 14 of the first
 * halfword of the application state record is set, the menu state is set to closed, the menu is hidden, and the
 * settings-changed request bit is set.
 */
void osd_accept_alarm_clock_quick_menu(void)
{
    unsigned char choice = user_settings[USER_SETTINGS_ALARM_CLOCK];

    if (choice != 0) {
        unsigned char minutes = user_settings[choice + ALARM_TABLE_0X197];
        unsigned char seconds = user_settings[choice + ALARM_TABLE_0X19B];
        user_settings[USER_SETTINGS_ALARM_MINUTES] = minutes;
        user_settings[USER_SETTINGS_ALARM_SECONDS] = seconds;
    }
    osd_alarm_clock_choice = choice;
    app_state_record |= APP_STATE_FLAG0_ALARM_RUNNING;
    osd_menu_state = MENU_STATE_CLOSED;
    osd_hide_menu();
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
