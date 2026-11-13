/* osd_dispatch_key_event  (FUN_a009eb38)
 *
 * Run the menu action for one key or menu event in the current menu state.
 *   event: event code (type in bits 6-7)
 * Note: Key roles come from ROM 0x1080F8, menu-event slots from 0x1080B8 / 0xA80241B0; handlers from
 *   0xA802422C[state][role].
 * Name basis: proven - reads the menu key handler table 0xA802422C and the event table 0xA80241B0; called by
 *   sys_pump_app_events
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009eb38 @ 0xa009eb38-0xa009f184 (1612 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the result of the first port loop is tested as 'all_used == 1';
 *  - the event type is tested twice with (event & EVENT_TYPE_MASK), the key case first;
 *  - the states MENU_STATE_FACTORY_INFO_DONE and MENU_STATE_FACTORY_INFO each carry the full time stamp /
 *    menu time-out / key test sequence (the compiler merges the common tail);
 *  - the redundant 'role != KEY_ROLE_NONE' test and the four separate input_api_menu_index_to_source_id calls are
 *    written as in the firmware.
 */

/* The fields of the application state record used here. */
struct app_state_record {
    unsigned short half_0x0;
    unsigned short half_0x2;
    struct {
        unsigned short bit15 : 1,               /* when set, closing the menu re-arms the port events */
                       sleep_state : 2,         /* bits 13..14: SLEEP_STATE_* */
                       bit12 : 1,
                       bit11 : 1,
                       bit10 : 1,               /* set together with that re-arm */
                       burnin_started : 1,      /* bit 9: set by the first burn-in step */
                       bit8 : 1,
                       bit7 : 1,                /* set when the factory menu opens from the closed menu */
                       low_bits : 7;
    } sleep_word;                               /* +0x04 */
    unsigned char pressed_key_bit;              /* +0x06: key bit of the last key read, for the factory key test */
    unsigned char byte_0x7;
    unsigned char pad08[0x18 - 0x08];
    unsigned short half_0x18;                   /* +0x18 */
    unsigned char pad1a[0x3e - 0x1a];
    struct {
        unsigned short flag_15 : 1,             /* set with the input quick menu; skips the menu time-out below */
                       flag_14 : 1,             /* set with the input quick menu */
                       rest : 14;
    } flags_0x3e;                               /* +0x3E */
};

/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned int word_0x0;                      /* +0x00: SETTINGS_WORD0_* bits */
    unsigned char pad04[0x1e - 0x04];
    unsigned char input_source;                 /* +0x1E: the selected Input Source */
    unsigned char pad1f[0x1d5 - 0x1f];
    unsigned char burn_in_flag;                 /* +0x1D5: burn-in mode on (1) or off (0) */
    unsigned char byte_0x1d6;                   /* +0x1D6: factory tool status 2 */
    unsigned char pad1d7[0x1f6 - 0x1d7];
    unsigned short factory_marker;              /* +0x1F6: FACTORY_MODE_MARKER while factory mode is on */
};
extern struct app_state_record app_state_record;
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned short osd_last_key_ticks, osd_seconds_countdown, osd_message_ticks;
extern unsigned char factory_record_key_test_bits, osd_request_bits;
extern const unsigned char osd_app_event_handler_rows[], osd_key_roles[];
extern void (*osd_app_event_handlers[])(void);
extern void (*osd_menu_key_table[][6])(void);
extern void (*osd_menu_key_table_state1_ok)(void);

extern unsigned char input_is_port_used(unsigned char port);
extern unsigned char sys_api_get_channel_state_code(unsigned char ch);
extern unsigned short timer_api_get_ticks16(void);
extern unsigned short nvram_get_device_setting(unsigned int id);
extern unsigned char osd_api_is_enabled(int);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern void osd_open_factory_info_page(void);
extern void osd_factory_show_pressed_key(void);
extern void osd_factory_show_keys_passed(void);
extern void osd_hide_menu(void);
extern void osd_user_apply_menu_timeout(void);
extern void sys_user_reset_display_path(void);
extern void input_rearm_port_event(int, int);
extern void pq_set_color_fill_enable(int);
extern void pq_api_set_fill_color(int, int, int, int, int);
extern void SYSAPI_PanelOnOffControl(unsigned int, unsigned int);
extern void sys_set_app_flag_bit3(int);
extern void osd_draw_factory_menu(void);
extern void sys_set_key_blocked(int, int);
extern void SetBrightness(unsigned short);
extern void sys_app_timer_start(int, int);
extern void osd_draw_input_quick_menu(void);
extern void osd_show_menu_layer(void);
extern void sys_set_key_modes_for_menu(void);
extern void panel_wait_sync_pulse(void);
extern void timer_sleep_ticks(int ms);
extern unsigned short timer_get_ticks16(void);

/* Application event codes: the type in bits 6..7, the index in bits 0..5. */
#define EVENT_TYPE_MASK         0xc0
#define EVENT_TYPE_APP          0x00    /* application events, made by sys_app_generate_events */
#define EVENT_TYPE_KEY          0x40    /* front keys, posted by sys_scan_keys_post_event */
#define EVENT_INDEX_MASK        0x3f

#define APP_EVENT_ROW_NONE      0x1e    /* osd_app_event_handler_rows: no menu routine for this event */

/* Key roles (osd_key_roles, one byte per key event 0x40..0x4F) = column of osd_menu_key_table. */
enum {
    KEY_ROLE_OK    = 0,                 /* key event 0x41 */
    KEY_ROLE_LEFT  = 1,                 /* key event 0x47 (left / back) */
    KEY_ROLE_DOWN  = 2,                 /* key event 0x46 */
    KEY_ROLE_UP    = 3,                 /* key event 0x45 */
    KEY_ROLE_RIGHT = 4,                 /* key event 0x48 */
    KEY_ROLE_5     = 5,                 /* key event 0x42 */
    KEY_ROLE_NONE  = 6,                 /* key events 0x40, 0x43 and 0x4A..0x4F: no menu action */
    KEY_ROLE_HOOK  = 7,                 /* key event 0x49: the OK entry of menu state 1 */
    KEY_ROLE_8     = 8                  /* key event 0x44 */
};

/* Menu states (osd_menu_state) handled here. */
#define MENU_STATE_CLOSED            0
#define MENU_STATE_INPUT_QUICK_MENU  0xfe   /* osd_open_input_quick_menu */
#define MENU_STATE_NO_SIGNAL         0x10d  /* the no-signal message */
#define MENU_STATE_FACTORY_MENU      0x111  /* osd_factory_open_menu */
#define MENU_STATE_FACTORY_INFO      0x113  /* the factory information page (osd_open_factory_info_page) */
#define MENU_STATE_FACTORY_INFO_DONE 0x114  /* set by osd_run_periodic_task when it hides that page after 17 s
                                               without a key */

/* State codes of sys_api_get_channel_state_code. */
#define CHANNEL_CODE_OFF        0       /* raw channel state CH_STATE_OFF */
#define CHANNEL_CODE_4          4       /* raw channel states 3, 5 (CH_STATE_WAIT_SYNC) and above 12 */
#define CHANNEL_CODE_LAST       10      /* raw channel state 12 (MODE_WAITMODECHANGE) */

#define LAST_PORT               3       /* ports and channels 0..3 */
#define ALL_PORTS               4       /* input_rearm_port_event: every port */
#define MAIN_CHANNEL            0
#define SECOND_CHANNEL          1

#define SLEEP_STATE_DC_ON       1       /* the value power_enter_app_state takes as "dc on" */

#define SETTINGS_WORD0_BIT9         0x200   /* user settings word +0, bit 9 */
#define SETTINGS_WORD0_FACTORY_MODE 0x4000  /* user settings word +0, bit 14: the factory mode flag */
#define FACTORY_MODE_MARKER         0x55aa  /* user settings +0x1F6 while factory mode is on */
#define FACTORY_STATUS_2_VALUE      0x55    /* user settings +0x1D6 (factory tool status 2) */
#define ALL_KEYS_PASSED             0x3f    /* factory_record_key_test_bits: all six front keys */
#define KEY_BIT_1                   1       /* pressed_key_bit of the first front key */

#define DEVICE_SETTING_PHY_CTS_AUTO 2       /* factory menu switch "PHY CTS AUTO" */
#define MENU_LAYER_MAIN             0       /* the layer osd_show_menu_layer switches on */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02   /* osd_request_bits bit 1 */

#define KEY_ID_ALL              0xff    /* sys_set_key_blocked: every key */
#define KEY_UNBLOCKED           0
#define PANEL_ON                1       /* SYSAPI_PanelOnOffControl: first argument */
#define NO_WAIT                 0       /* SYSAPI_PanelOnOffControl: second argument */
#define WAIT_DONE               1
#define LEVEL_MAX               0x3ff   /* SetBrightness: the highest panel level */
#define APP_STATE18_BIT12       0x1000  /* app_state_record half_0x18, bit 12 */

#define APP_TIMER_PORT0         4       /* application timer 4 */
#define APP_TIMER_B             0xb     /* application timer 0xB */
#define QUICK_MENU_SECONDS      20      /* osd_seconds_countdown of the input quick menu */

/*
 * Handle one event from the application event queue in the menu.
 *
 *   event  the application event code: type in bits 6..7, index in bits 0..5
 *
 * Called by sys_pump_app_events for every queued event, after APPActionDispatcher.
 *
 * Phases, in order:
 *   1. Gate: nothing happens while no port in use has a channel that is not off, or while the sleep state is
 *      "dc on".
 *   2. Key events (type 0x40):
 *      a. On the factory information pages with burn-in on, the key with key bit 1 is shown and logged for
 *         the key test.
 *      b. The key event gives a key role (osd_key_roles). Role KEY_ROLE_HOOK runs the OK entry of menu state 1
 *         (osd_factory_open_menu in the stored table); KEY_ROLE_NONE does nothing.
 *      c. Every port in use has state code 4, and settings bit 9 or burn-in is on: the factory arms. With
 *         factory mode marked, factory status 2 = 0x55, burn-in off and the menu layer off, the four arrow keys
 *         select an input source directly. On the factory information pages any key shows the page again and
 *         logs the key. With the menu closed and the factory mode flag set, any key opens the factory menu.
 *         Otherwise the handler of osd_menu_key_table[menu state][role] is run.
 *      d. Otherwise, with the menu closed or the no-signal message shown and the main channel at state code 4
 *         or lower: an arrow key, OK or KEY_ROLE_8 opens the input quick menu with the panel switched on.
 *      e. Otherwise the handler of osd_menu_key_table[menu state][role] is run.
 *   3. Application events (type 0): the event index selects a row of osd_app_event_handler_rows and that row a
 *      routine of osd_app_event_handlers, which is run. Menu (0x80) and DDC/CI (0xC0) events are ignored.
 *   After each handler: the message time stamp is taken, the menu time-out applied (in arm e not when flag_15 of
 *   app_state_record +0x3E is set) and the key rules set for the new menu state.
 *
 * Each row of osd_menu_key_table has six columns. Role KEY_ROLE_8 indexes past them: the entry read is column 2
 * of the next state's row.
 */
void osd_dispatch_key_event(unsigned int event)
{
    unsigned char all_used, i, role;

    /* 1. Gate: ignore the event while every port in use has its channel off. */
    all_used = 1;
    for (i = 0; i < LAST_PORT + 1; i++) {
        if (input_is_port_used(i) && sys_api_get_channel_state_code(i)) {
            all_used = 0;
            break;
        }
    }
    if (all_used == 1)
        return;
    if (app_state_record.sleep_word.sleep_state == SLEEP_STATE_DC_ON)
        return;

    if ((event & EVENT_TYPE_MASK) == EVENT_TYPE_KEY) {
        /* 2a. Factory key test on the information pages. */
        if ((osd_menu_state == MENU_STATE_FACTORY_INFO || osd_menu_state == MENU_STATE_FACTORY_INFO_DONE)
            && user_settings.burn_in_flag != 0 && app_state_record.pressed_key_bit == KEY_BIT_1) {
            osd_factory_show_pressed_key();
            if (factory_record_key_test_bits == ALL_KEYS_PASSED)
                osd_factory_show_keys_passed();
            osd_last_key_ticks = timer_api_get_ticks16();
        }

        /* 2b. The role of the key in the menu. */
        role = osd_key_roles[event & EVENT_INDEX_MASK];
        if (role == KEY_ROLE_HOOK) {
            if (osd_menu_key_table_state1_ok == 0)
                return;
            osd_menu_key_table_state1_ok();
            sys_set_key_modes_for_menu();
            return;
        }
        if (role == KEY_ROLE_NONE)
            return;

        /* 2c. Every port in use reports state code 4. */
        all_used = 1;
        for (i = 0; i < LAST_PORT + 1; i++) {
            if (input_is_port_used(i) && sys_api_get_channel_state_code(i) != CHANNEL_CODE_4) {
                all_used = 0;
                break;
            }
        }
        if (all_used && ((user_settings.word_0x0 & SETTINGS_WORD0_BIT9) || user_settings.burn_in_flag != 0)) {
            /* Factory mode with the menu layer off: the arrow keys pick the input source. */
            if (user_settings.factory_marker == FACTORY_MODE_MARKER && user_settings.byte_0x1d6 == FACTORY_STATUS_2_VALUE
                && (unsigned char)(role - KEY_ROLE_LEFT) <= KEY_ROLE_RIGHT - KEY_ROLE_LEFT
                && osd_api_is_enabled(MENU_LAYER_MAIN) == 0
                && user_settings.burn_in_flag == 0) {
                if (role == KEY_ROLE_LEFT)
                    user_settings.input_source = input_api_menu_index_to_source_id(2);
                else if (role == KEY_ROLE_DOWN)
                    user_settings.input_source = input_api_menu_index_to_source_id(3);
                else if (role == KEY_ROLE_UP)
                    user_settings.input_source = input_api_menu_index_to_source_id(1);
                else if (role == KEY_ROLE_RIGHT)
                    user_settings.input_source = input_api_menu_index_to_source_id(0);
                sys_user_reset_display_path();
                input_rearm_port_event(ALL_PORTS, 0);
                osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
                return;
            }
            /* The factory information pages: any key shows the page again and logs the key. */
            if (role != KEY_ROLE_NONE) {
                if (osd_menu_state == MENU_STATE_FACTORY_INFO_DONE) {
                    osd_open_factory_info_page();
                    osd_message_ticks = timer_get_ticks16();
                    osd_user_apply_menu_timeout();
                    osd_factory_show_pressed_key();
                    if (factory_record_key_test_bits == ALL_KEYS_PASSED)
                        osd_factory_show_keys_passed();
                    osd_last_key_ticks = timer_api_get_ticks16();
                    return;
                }
                if (osd_menu_state == MENU_STATE_FACTORY_INFO) {
                    osd_message_ticks = timer_get_ticks16();
                    osd_user_apply_menu_timeout();
                    osd_factory_show_pressed_key();
                    if (factory_record_key_test_bits == ALL_KEYS_PASSED)
                        osd_factory_show_keys_passed();
                    osd_last_key_ticks = timer_api_get_ticks16();
                    return;
                }
            }
            /* Menu closed and the factory mode flag set: open the factory menu on a black, switched-on panel. */
            if (osd_menu_state == MENU_STATE_CLOSED && (user_settings.word_0x0 & SETTINGS_WORD0_FACTORY_MODE)
                && user_settings.burn_in_flag == 0) {
                pq_set_color_fill_enable(0);
                pq_api_set_fill_color(MAIN_CHANNEL, 0, 0, 0, 0);
                SYSAPI_PanelOnOffControl(PANEL_ON, NO_WAIT);
                sys_set_app_flag_bit3(1);
                app_state_record.sleep_word.bit7 = 1;
                osd_menu_state = MENU_STATE_FACTORY_MENU;
                osd_draw_factory_menu();
                sys_set_key_blocked(KEY_ID_ALL, KEY_UNBLOCKED);
                return;
            }
            if (osd_menu_key_table[osd_menu_state][role] == 0)
                return;
            osd_menu_key_table[osd_menu_state][role]();
            osd_message_ticks = timer_get_ticks16();
            osd_user_apply_menu_timeout();
            sys_set_key_modes_for_menu();
            return;
        }

        /* 2d. Menu closed or no-signal message: open the input quick menu. */
        if ((osd_menu_state == MENU_STATE_CLOSED || osd_menu_state == MENU_STATE_NO_SIGNAL)
            && sys_api_get_channel_state_code(MAIN_CHANNEL) <= CHANNEL_CODE_4
            && (!(user_settings.word_0x0 & SETTINGS_WORD0_BIT9) || nvram_get_device_setting(DEVICE_SETTING_PHY_CTS_AUTO) == 1)
            && (role < KEY_ROLE_5 || role == KEY_ROLE_8)) {
            pq_set_color_fill_enable(0);
            panel_wait_sync_pulse();
            /* The steps of osd_close_menu. */
            if (app_state_record.sleep_word.bit15) {
                app_state_record.sleep_word.bit10 = 1;
                input_rearm_port_event(ALL_PORTS, 0);
            }
            osd_menu_state = MENU_STATE_CLOSED;
            osd_hide_menu();
            /* Switch the panel on at the highest level, unless channel 1 is at state code 10. */
            if (sys_api_get_channel_state_code(SECOND_CHANNEL) != CHANNEL_CODE_LAST && osd_menu_state == MENU_STATE_CLOSED) {
                pq_api_set_fill_color(MAIN_CHANNEL, 0, 0, 0, 0);
                SetBrightness(LEVEL_MAX);
                SYSAPI_PanelOnOffControl(PANEL_ON, WAIT_DONE);
                app_state_record.half_0x18 |= APP_STATE18_BIT12;
                timer_sleep_ticks(400);
            }
            sys_set_app_flag_bit3(1);
            sys_set_key_blocked(KEY_ID_ALL, KEY_UNBLOCKED);
            sys_app_timer_start(APP_TIMER_PORT0, 8000);
            sys_app_timer_start(APP_TIMER_B, 10000);
            /* The steps of osd_open_input_quick_menu, with a 20 s countdown. */
            osd_menu_state = MENU_STATE_INPUT_QUICK_MENU;
            osd_draw_input_quick_menu();
            osd_show_menu_layer();
            osd_seconds_countdown = QUICK_MENU_SECONDS;
            app_state_record.flags_0x3e.flag_14 = 1;
            app_state_record.flags_0x3e.flag_15 = 1;
            return;
        }

        /* 2e. The handler of the current menu state for this key. */
        if (osd_menu_key_table[osd_menu_state][role] == 0)
            return;
        osd_menu_key_table[osd_menu_state][role]();
        osd_message_ticks = timer_get_ticks16();
        if (app_state_record.flags_0x3e.flag_15) {
            sys_set_key_modes_for_menu();
            return;
        }
        osd_user_apply_menu_timeout();
        sys_set_key_modes_for_menu();
        return;
    }

    /* 3. Application events. */
    if ((event & EVENT_TYPE_MASK) != EVENT_TYPE_APP)
        return;
    role = osd_app_event_handler_rows[event & EVENT_INDEX_MASK];
    if (role == APP_EVENT_ROW_NONE)
        return;
    if (osd_app_event_handlers[role] == 0)
        return;
    osd_app_event_handlers[role]();
    osd_message_ticks = timer_get_ticks16();
    sys_set_key_modes_for_menu();
}
