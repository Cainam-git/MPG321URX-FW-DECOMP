/* osd_accept_input_quick_menu  (FUN_a0097190)
 *
 * Switch to the input highlighted in the input quick menu and close it.
 * Note: Quick menu state 0xFE; highlighted input in settings byte +0x1A3.
 * Name basis: derived - handler table 0xA802422C: OK on state 0xFE; copies +0x1A3 to the input byte +0x1E
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0097190 @ 0xa0097190-0xa00972cc (79 words), flags -mcpu=v8 -O3 -g. No direct callers (reached through
 * a table). Source form: the equal case is written first; input_api_source_id_to_menu_index returns int and both
 * results are compared as bytes; bit 15 is tested as '(short)(half_0x4 & 0x8000)' (as osd_run_navi_key_right).
 */
struct user_settings_record {
    unsigned int word_0x0;                      /* +0: SETTINGS_WORD0_BIT9 = bit 9 */
    unsigned char p004[0x1e - 4];
    unsigned char input_source;                 /* +0x1E: the input of the main picture */
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 = PiP / PBP off */
    unsigned char p020[0x1a3 - 0x20];
    unsigned char quick_menu_input;             /* +0x1A3: the input highlighted in the quick menu */
};
struct app_state_record {
    unsigned short half_0x0;
    unsigned short half_0x2;
    unsigned short half_0x4;                    /* bit 15 = SLEEP_WORD_BIT15, bit 10 = SLEEP_WORD_BIT10 */
};
extern struct user_settings_record user_settings;
extern struct app_state_record app_state_record;
extern unsigned int osd_menu_state;
extern void input_rearm_port_event(int, int);
extern int input_api_source_id_to_menu_index(unsigned char);
extern void osd_hide_menu(void);
extern unsigned char sys_api_get_channel_state_code(unsigned char);
extern void osd_apply_input_change(void);

#define MENU_STATE_INPUT_QUICK_MENU 0xfe        /* the input quick menu */
#define SLEEP_WORD_BIT15            0x8000      /* when set, closing the menu re-arms the port events */
#define SLEEP_WORD_BIT10            0x400       /* set together with that re-arm */
#define SETTINGS_WORD0_BIT9         0x200
#define CHANNEL_CODE_LAST           10          /* a state code of sys_api_get_channel_state_code */

/*
 * OK in the input quick menu (menu state 0xFE, reached through the handler table): take the input highlighted
 * in the menu (user_settings.quick_menu_input) and close the menu.
 *
 * Both inputs go through input_api_source_id_to_menu_index and are compared as source ids. Either way the menu is
 * closed first: all port events are re-armed, and when bit 15 of app_state_record halfword +4 is set its bit
 * 10 is set and they are re-armed again; the menu state is cleared and osd_hide_menu is called.
 *  - Same input: nothing is switched. The menu state is set back to 0xFE when channel 0 is not in state code 10,
 *    settings word bit 9 is clear and PiP / PBP is off (pip_pbp_mode 0).
 *  - Different input: it is stored in input_source and osd_apply_input_change switches to it.
 */
void osd_accept_input_quick_menu(void)
{
    input_rearm_port_event(4, 0);
    if ((unsigned char)input_api_source_id_to_menu_index(user_settings.input_source) == (unsigned char)input_api_source_id_to_menu_index(user_settings.quick_menu_input)) {
        if ((short)(app_state_record.half_0x4 & SLEEP_WORD_BIT15)) {
            app_state_record.half_0x4 |= SLEEP_WORD_BIT10;
            input_rearm_port_event(4, 0);
        }
        osd_menu_state = 0;
        osd_hide_menu();
        if (sys_api_get_channel_state_code(0) != CHANNEL_CODE_LAST && !(user_settings.word_0x0 & SETTINGS_WORD0_BIT9) && user_settings.pip_pbp_mode == 0)
            osd_menu_state = MENU_STATE_INPUT_QUICK_MENU;
        return;
    }
    if ((short)(app_state_record.half_0x4 & SLEEP_WORD_BIT15)) {
        app_state_record.half_0x4 |= SLEEP_WORD_BIT10;
        input_rearm_port_event(4, 0);
    }
    osd_menu_state = 0;
    osd_hide_menu();
    user_settings.input_source = user_settings.quick_menu_input;
    osd_apply_input_change();
}
