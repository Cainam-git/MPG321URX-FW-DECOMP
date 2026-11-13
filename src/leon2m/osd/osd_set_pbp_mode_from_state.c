/* osd_set_pbp_mode_from_state  (FUN_a0097d3c)
 *
 * Set the PBP mode to 0 or 1 from the menu state and rebuild the picture if it changed.
 * Note: Called by osd_apply_choice_on_timeout; acts only in menu states 0x7F and 0x80.
 * Name basis: descriptive - code: state 0x7F/0x80 -> settings byte +0x2F
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0097d3c @ 0xa0097d3c-0xa0097dec (44 words), flags -mcpu=v8 -O3 -g. Caller: osd_apply_choice_on_timeout.
 * Source form: the two cases have separate bodies; the settings record is a byte array.
 */
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern void panel_user_set_output_on(int);
extern void sys_api_restart_channel_at_level(int, int);
extern void UserSetPIPMode(void);

#define USER_SETTINGS_PBP_LAYOUT     0x2f       /* offset of the PBP layout byte */
#define MENU_STATE_PBP_LIST          0x7f       /* + row: the PBP settings list; rows 0 and 1 are layouts 0 and 1 */
#define PBP_LAYOUT_0                 0
#define PBP_LAYOUT_1                 1
#define MAIN_CHANNEL                 0
#define SECOND_CHANNEL               1
#define RESTART_LEVEL_1              1          /* sys_api_restart_channel_at_level: level 1 */

/*
 * Set the PBP layout from the menu state: state 0x7F gives layout 0 and state 0x80 gives layout 1. Other states do
 * nothing.
 *
 * When the layout differs from the stored one, the new layout is stored, the picture output is switched off,
 * both channels are restarted at level 1 and UserSetPIPMode applies the layout.
 */
void osd_set_pbp_mode_from_state(void)
{
    if (osd_menu_state == MENU_STATE_PBP_LIST) {
        if (user_settings[USER_SETTINGS_PBP_LAYOUT] != PBP_LAYOUT_0) {
            user_settings[USER_SETTINGS_PBP_LAYOUT] = PBP_LAYOUT_0;
            panel_user_set_output_on(0);
            sys_api_restart_channel_at_level(MAIN_CHANNEL, RESTART_LEVEL_1);
            sys_api_restart_channel_at_level(SECOND_CHANNEL, RESTART_LEVEL_1);
            UserSetPIPMode();
        }
    } else if (osd_menu_state == MENU_STATE_PBP_LIST + 1) {
        if (user_settings[USER_SETTINGS_PBP_LAYOUT] != PBP_LAYOUT_1) {
            user_settings[USER_SETTINGS_PBP_LAYOUT] = PBP_LAYOUT_1;
            panel_user_set_output_on(0);
            sys_api_restart_channel_at_level(MAIN_CHANNEL, RESTART_LEVEL_1);
            sys_api_restart_channel_at_level(SECOND_CHANNEL, RESTART_LEVEL_1);
            UserSetPIPMode();
        }
    }
}
