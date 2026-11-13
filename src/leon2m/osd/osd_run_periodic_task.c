/* osd_run_periodic_task  (FUN_a009f42c)
 *
 * Run the menu timers: message time-outs, alarm countdown, overlays and panel prompts.
 * Note: Called every main-loop pass; returns at once while the start-up logo holds events.
 * Name basis: derived - called by sys_run_app_main_task; state switch over 0x10A..0x116, 1000 ms alarm
 *   countdown of settings +0x1A0..0x1A2
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009f42c @ 0xa009f42c-0xa00a012c (832 words), flags -mcpu=v8 -O3 -g (also matches with -msoft-float).
 * Source forms the exact build depends on:
 *   - oled_get_care_table_byte declared int-returning; oled_care_flags as the bit-fields bit31 / bit30; the alarm
 *     countdown tests 'seconds != 0' first; 'if (t != a) if (t != 0)' nested; the five-state test is the inlined
 *     early-return function is_timeout_action_state().
 *   1. The one-second countdown is 'if (osd_seconds_countdown != 0) osd_seconds_countdown--; if (... == 0) {...}'
 *      with no early return. With 'if (osd_seconds_countdown != 0 && --osd_seconds_countdown != 0) return;' the
 *      branch prediction gives the return edge PRED_EARLY_RETURN (67 %), the rest of the default path gets about
 *      half the frequency, and bb-reorder's triangle rule (bb-reorder.c:596, integer frequencies: 2 * freq(arm)
 *      >= EDGE_FREQUENCY(skip)) then fails, so both sleep_word.bit15 arms go out of line. Same code, only the
 *      prediction changes.
 *   2. flags_0xe.bit15 is set from one '||' condition '(half_0x12 == 5 && osd_choice_row == 1) || (half_0x10 == 4
 *      && osd_choice_row == 0)' (the firmware has one shared set path).
 *   3. flags_0x0 is a bit-field halfword (alarm_running, bit9, after_display). With the mask form the 0x4000
 *      constant of the 0x106 arm is materialised next to its use; the bit-field form gives the firmware's
 *      'sethi 0x4000' in the first call's delay slot (call-saved %l0).
 *   4. The 0x10A arm is written 'if (!(bit31 && bit30)) { 0x35 / osd_redraw_page_after_notice path } else {
 *      flags_0xe.bit15 path }', and the time-out test 'if (!is_timeout_action_state(...)) { close path } else {
 *      0xE1 / 0xE6 / 0x41 / 0x81 arms }'. rnreg LRU ticks follow the source arm order; the other order breaks the
 *      rename chain from the half_0x12 == 5 test on, and reorg then deletes the 0x81 test's reloads as redundant
 *      (the firmware reloads osd_seconds_countdown and the state in every test).
 *   5. Statement orders (all stores are to different RAM bytes, so the order is free in C): alarm countdown
 *      else-arm 'seconds = 59' before 'minutes--'; 0xE1 arm osd_edit_value before osd_seconds_countdown;
 *      byte_0x1e4 before byte_0x1e5.
 * Register-allocation forms (the last 38 words):
 *   6. osd_seconds_countdown HIGH (firmware %o2 from 0xa009f84c; %o1 with other statement orders): local-alloc
 *      gives the 0xE6 arm's osd_timeout value %o2, a hard conflict for the global HIGH pseudo, which then takes
 *      %o1. The 0xE6 arm 'countdown = osd_timeout; byte_0x1a3 = 1; osd_edit_value = alarm_clock_location; state =
 *      0x108;' and the 0xE1 arm 'countdown = osd_timeout; osd_edit_value = refresh_rate_location; state = 0x108;
 *      byte_0x1a3 = 0;' give the firmware arms and free %o2 (sched2 puts them back in the firmware order). The
 *      same orders give the osd_alarm_clock_choice sethi order at 0xa009f8a0 (reorg fills the branch delay slot of
 *      the five-state test with the first insn whose register is dead at the target: with the countdown HIGH in
 *      %o2 that is the osd_alarm_clock_choice sethi, not the user_settings sethi).
 *   7. Alarm row copy (row address firmware %i2, t %o3, seconds value %o4): local-alloc of that block sorts its
 *      quantities by int(floor_log2(refs) * freq / (death - birth) * 10), ties by birth order (local-alloc.c
 *      QTY_CMP_PRI, qty_compare_1); each takes the first free of %g1 %o5 %o4 %o3 .. over a +-2 widened lifetime.
 *      With the stores 'minutes = alarm_table_0x197[t]; seconds = alarm_table_0x19b[t]; osd_alarm_clock_choice =
 *      t;' sched1 gives the order lduh c4000 ior ld19b ld197 st1a2 stafea st1a1 sth, where the seconds value gets
 *      %o4 before the row address, which then gets %o3 (and t prefers it). That order alone makes the t byte (QI)
 *      live 16 insns instead of 15 (global priority 1 < 2 of the user_settings pointer, so the two swap %o1/%o2);
 *      reading osd_alarm_clock_choice into 'unsigned char shown_choice' before the t load keeps t's life at 15
 *      insns, so t is allocated first (%o2) and the user_settings pointer gets %o1, as in the firmware.
 * No volatile (all RAM globals).
 */

/* The fields of the application state record used here. */
struct app_state_record {
    struct {
        unsigned short bit15 : 1,
                       alarm_running : 1,       /* bit 14: the Alarm Clock countdown runs */
                       bits_10_13 : 4,
                       bit9 : 1,                /* when set, the HDR icon follows the 0x10F message */
                       after_display : 1,       /* bit 8: set by AFTER_DISPLAY_ALL, cleared by MUTE_ALL */
                       low_bits : 8;
    } flags_0x0;                                /* +0x00 */
    unsigned short half_0x2;
    struct {
        unsigned short bit15 : 1,               /* when set, closing the menu re-arms the port events */
                       sleep_state : 2,         /* bits 13..14: SLEEP_STATE_* */
                       bit12 : 1,
                       bit11 : 1,
                       bit10 : 1,               /* set together with that re-arm */
                       burnin_started : 1,      /* bit 9: set by the first burn-in step */
                       bit8 : 1,
                       bit7 : 1,
                       low_bits : 7;
    } sleep_word;                               /* +0x04 */
    unsigned short half_0x6, half_0x8, half_0xa;
    unsigned short half_0xc;                    /* +0x0C: set to 1 by phase 5 after its 30 s wait */
    struct { unsigned short bit15 : 1, rest : 15; } flags_0xe;    /* +0x0E */
    unsigned short half_0x10;                   /* +0x10: index into the OLED care table (see phase 5) */
    unsigned short half_0x12;                   /* +0x12 */
    struct { unsigned short bit15 : 1, rest : 15; } flags_0x14;   /* +0x14: bit 15 set = no protect step check */
    unsigned char pad16[0x3f - 0x16];
    unsigned char dialog_button_index;          /* +0x3F: the selected button of a dialog or prompt */
};

/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0xc];
    unsigned char osd_timeout;                  /* +0x0C: OSD Time out, in seconds */
    unsigned char pad0d[0xa8 - 0xd];
    unsigned int gaming_flags;                  /* +0xA8: GAMING_FLAG_* */
    unsigned int settings_page_flags;           /* +0xAC: SETTINGS_PAGE_FLAG_* */
    unsigned char padb0[0x13e - 0xb0];
    unsigned char refresh_rate_location;        /* +0x13E: location of the Refresh Rate overlay */
    unsigned char alarm_clock_location;         /* +0x13F: location of the Alarm Clock overlay */
    unsigned char pad140[0x17b - 0x140];
    unsigned char crosshair_color;              /* +0x17B: Smart Crosshair colour (CROSSHAIR_COLOR_AUTO = automatic) */
    unsigned char pad17c[0x190 - 0x17c];
    unsigned char crosshair_icon;               /* +0x190: Smart Crosshair icon (0 = off) */
    unsigned char pad191[0x197 - 0x191];
    unsigned char alarm_table_0x197[4];         /* +0x197: start minutes of each Alarm Clock choice */
    unsigned char alarm_table_0x19b[4];         /* +0x19B: start seconds of each Alarm Clock choice */
    unsigned char pad19f;
    union { unsigned int word; unsigned char bytes[4]; } alarm;   /* +0x1A0: bytes ALARM_* */
    unsigned char pad1a4[0x1aa - 0x1a4];
    unsigned char byte_0x1aa;                   /* +0x1AA: the button highlighted in the change notice */
    unsigned char pad1ab[0x1dc - 0x1ab];
    struct { unsigned int bit31 : 1, bit30 : 1, rest : 30; } oled_care_flags;    /* +0x1DC */
    unsigned char bytes_0x1e0[4];
    unsigned char byte_0x1e4, byte_0x1e5;
    unsigned char pad1e6[0x1f6 - 0x1e6];
    unsigned short factory_marker;              /* +0x1F6: FACTORY_MODE_MARKER while factory mode is on */
};

/* The four bytes of user_settings.alarm. The countdown runs from minutes:seconds down to 0:00. */
#define ALARM_CLOCK             0       /* +0x1A0 alarm_clock: the Alarm Clock choice (0 = off) */
#define ALARM_MINUTES           1       /* +0x1A1 alarm_byte_0x1a1: minutes left */
#define ALARM_SECONDS           2       /* +0x1A2 alarm_byte_0x1a2: seconds left (59..0) */
#define ALARM_BYTE_0x1A3        3       /* +0x1A3 byte_0x1a3: the overlay in the position editor */
#define ALARM_TIME_MASK         0xffff00        /* minutes and seconds in alarm.word */

extern struct app_state_record app_state_record;
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_alarm_clock_choice, osd_led_bar_query_sent, osd_protect_prompt_step, factory_record_key_test_bits, user_settings_burn_in_flag, osd_request_bits;
extern unsigned char osd_edit_value, osd_choice_row;
extern unsigned short osd_last_key_ticks, osd_seconds_countdown, osd_alarm_second_ticks, osd_protect_wait_ticks, osd_move_hold_ticks, osd_message_ticks;

extern unsigned char sys_is_logo_hold(void);
extern unsigned char input_is_port_used(unsigned char port);
extern unsigned char sys_api_get_channel_state_code(unsigned char ch);
extern unsigned char sys_api_get_channel_flag29(unsigned char ch);
extern unsigned short timer_api_get_ticks16(void);
extern unsigned short nvram_get_device_setting(unsigned int id);
extern int oled_get_care_table_count(void);
extern int oled_get_care_table_byte(unsigned char i);
extern unsigned char oled_power_get_state(void);
extern unsigned char oled_power_get_step(void);
extern unsigned char oled_get_protect_step_code(unsigned char offs_hours, unsigned char offs_count);
extern void osd_draw_panel_protect_prompt(unsigned char v, unsigned char mode);
extern void osd_redraw_page_after_notice(unsigned char a, unsigned char b);
extern unsigned char sys_get_app_flag42_bit5(void);
extern void input_rearm_port_event(int, int);
extern void osd_show_screen_overlays(unsigned char on);
extern void osd_update_crosshair_color(unsigned char v);
extern void osd_draw_overlay_position_preview(unsigned char a, unsigned char b, unsigned char c);
extern void osd_open_factory_info_page(void);
extern void osd_factory_show_pressed_key(void);
extern void osd_factory_show_keys_passed(void);
extern void osd_hide_menu(void);
extern void osd_user_apply_menu_timeout(void);
extern void sys_led_bar_send_query(void);
extern void osd_check_panel_protect_prompt(void);
extern void osd_accept_panel_protect_prompt(void);
extern void osd_apply_choice_on_timeout(void);
extern void sys_user_save_mode_slot(void);
extern void osd_draw_out_of_range_message(void);
extern void osd_update_header_refresh_rate(void);
extern void osd_close_change_notice(void);
extern void osd_open_pbp_custom_split(void);
extern void osd_draw_hdr_icon(void);
extern void panel_wait_sync_pulse(void);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);

/* Menu states (osd_menu_state) handled here; the list states are named by their handlers in osd_menu_key_table. */
enum {
    MENU_STATE_CLOSED            = 0,
    MENU_STATE_PANEL_PROTECT_ITEM = 0x35,       /* MSI OLED Care page, item Panel Protect */
    MENU_STATE_CROSSHAIR_ITEMS   = 0x41,        /* Smart Crosshair item list; OK = osd_open_crosshair_position */
    MENU_STATE_PBP_ITEMS         = 0x81,        /* PIP/PBP item list; OK = osd_open_pbp_custom_split */
    MENU_STATE_REFRESH_RATE_LOCATION = 0xe1,    /* Refresh Rate location list; OK = osd_open_refresh_rate_position */
    MENU_STATE_LAST_HEADER       = 0xe5,        /* up to here: osd_update_header_refresh_rate every 100 ms */
    MENU_STATE_ALARM_LOCATION    = 0xe6,        /* Alarm Clock location list; OK = osd_open_alarm_clock_position */
    MENU_STATE_SCREEN_OVERLAYS   = 0x106,       /* menu closed, overlays shown; same key handlers as state 0 */
    MENU_STATE_POSITION_EDITOR   = 0x108,       /* overlay position editor (osd_move_overlay_*) */
    MENU_STATE_PANEL_PROTECT     = 0x10a,       /* the OLED panel protect prompt */
    MENU_STATE_10B               = 0x10b,       /* OK = osd_close_menu_and_panel_off */
    MENU_STATE_OUT_OF_RANGE      = 0x10c,       /* 'Out Of Range!' (osd_draw_out_of_range_message) */
    MENU_STATE_NO_SIGNAL         = 0x10d,       /* the no-signal message */
    MENU_STATE_NO_SIGNAL_ONLY    = 0x10e,       /* 'No Signal' */
    MENU_STATE_10F               = 0x10f,       /* set with the protect step prompt and the HDR icon */
    MENU_STATE_FACTORY_MENU      = 0x111,
    MENU_STATE_FACTORY_ITEM_EDIT = 0x112,
    MENU_STATE_FACTORY_INFO      = 0x113,       /* the factory information page (osd_open_factory_info_page) */
    MENU_STATE_FACTORY_INFO_DONE = 0x114,       /* that page hidden after 17 s without a key */
    MENU_STATE_115               = 0x115,       /* every key = osd_factory_open_menu */
    MENU_STATE_CHANGE_NOTICE     = 0x116        /* the mode change notice */
};

/* Overlays of osd_draw_overlay_position_preview (and values of byte_0x1a3). */
#define OVERLAY_REFRESH_RATE    0
#define OVERLAY_ALARM_CLOCK     1
#define OVERLAY_CROSSHAIR       2

/* State codes of sys_api_get_channel_state_code. */
#define CHANNEL_CODE_4          4       /* raw channel states 3, 5 (CH_STATE_WAIT_SYNC) and above 12 */
#define CHANNEL_CODE_LAST       10      /* raw channel state 12 (MODE_WAITMODECHANGE) */

#define LAST_PORT               3       /* ports and channels 0..3 */
#define ALL_PORTS               4       /* input_rearm_port_event: every port */
#define MAIN_CHANNEL            0

#define GAMING_FLAG_REFRESH_RATE    0x1000      /* gaming_flags bit 12: the Refresh Rate overlay is on */
#define SETTINGS_INFO_ON_SCREEN     0x400000    /* settings_page_flags bit 22: Info. On Screen
                                                   (osd_draw_info_on_screen_switch) */
#define CROSSHAIR_COLOR_AUTO        2
#define FACTORY_MODE_MARKER         0x55aa
#define ALL_KEYS_PASSED             0x3f        /* factory_record_key_test_bits: all six front keys */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* osd_request_bits bit 1 */

/* Device settings (nvram_get_device_setting) of the OLED panel care. */
#define DEVICE_SETTING_OFFS_COUNT   0xb         /* the count below an OFFS hour (0..59) */
#define DEVICE_SETTING_OFFS_HOURS   0xd         /* the hour count printed as "OFFS H" */
#define DEVICE_SETTING_SENSING_TEST 0x10        /* factory menu switch "Sensing Test" */

#define PROMPT_MODE_3           3       /* second argument of osd_draw_panel_protect_prompt here */
#define NOTICE_PAGE_7           7       /* first argument of osd_redraw_page_after_notice here */

/* The menu states in which the end of the menu time-out runs an action instead of closing the menu. */
static int is_timeout_action_state(unsigned int s)
{
    if (s == MENU_STATE_SCREEN_OVERLAYS)
        return 1;
    if (s == MENU_STATE_REFRESH_RATE_LOCATION)
        return 1;
    if (s == MENU_STATE_ALARM_LOCATION)
        return 1;
    if (s == MENU_STATE_CROSSHAIR_ITEMS)
        return 1;
    if (s == MENU_STATE_PBP_ITEMS)
        return 1;
    return 0;
}

/*
 * The menu's timed work, run twice per main-loop pass: by osd_run_task_post_redraw_event (inside
 * sys_pump_app_events) and by sys_run_app_main_task. No arguments; times are 16-bit tick stamps compared with
 * timer_ticks_since, in milliseconds.
 *
 * Phases, in order:
 *   0. Nothing runs while the start-up logo holds events or the sleep state is not 0.
 *   1. Factory information page: when every port in use reports state code 4, a started burn-in opens the page
 *      from the closed menu or the no-signal message; the page is hidden after 17 s without a key (state
 *      MENU_STATE_FACTORY_INFO_DONE).
 *   2. Factory menu: the move-hold time stamp is renewed every 100 ms.
 *   3. Screen overlays (crosshair, refresh rate, alarm clock, Info. On Screen): while the main channel is at
 *      state code 10 with after_display set and its flag 29 clear, and one overlay is switched on, the closed
 *      menu goes to MENU_STATE_SCREEN_OVERLAYS and draws them; in that state they are updated on every pass.
 *   4. Alarm Clock countdown: one second off minutes:seconds every 1000 ms; alarm_running is cleared at 0:00.
 *   5. OLED panel protect: 30 s after the main channel reached state code 10 with after_display set (not on
 *      the protect prompt, not in factory mode), the protect step is checked; a new step draws its prompt,
 *      else osd_check_panel_protect_prompt decides. One second before, the LED light bar gets its query once.
 *   6. Per-state timers: the message time-outs (0x10B, 0x10F: 3 s; 0x116: the OSD time-out; 0x10A: 60 s;
 *      0x10D, 0x10E: closed at once while burn-in is on), and in all other states the refresh rate in the menu
 *      header (every 100 ms) and the one-second menu countdown. At the end of the countdown the list states of is_timeout_action_state run their OK action;
 *      every other state closes the menu, starts a newly chosen Alarm Clock and saves the settings.
 */
void osd_run_periodic_task(void)
{
    unsigned char all_used, i;

    /* 0. Gates. */
    if (sys_is_logo_hold() == 1)
        return;
    if (app_state_record.sleep_word.sleep_state)
        return;

    /* 1. Factory information page, while every port in use reports state code 4. */
    all_used = 1;
    for (i = 0; i < LAST_PORT + 1; i++) {
        if (input_is_port_used(i) && sys_api_get_channel_state_code(i) != CHANNEL_CODE_4) {
            all_used = 0;
            break;
        }
    }
    if (all_used && !sys_is_logo_hold()) {
        if ((osd_menu_state == MENU_STATE_CLOSED || osd_menu_state == MENU_STATE_NO_SIGNAL) && app_state_record.sleep_word.burnin_started) {
            osd_open_factory_info_page();
            osd_factory_show_pressed_key();
            if (factory_record_key_test_bits == ALL_KEYS_PASSED)
                osd_factory_show_keys_passed();
            osd_last_key_ticks = timer_api_get_ticks16();
        }
        if (osd_menu_state == MENU_STATE_FACTORY_INFO && timer_ticks_since(osd_last_key_ticks) > 17000) {
            /* The steps of osd_close_menu, then remember that the page was hidden. */
            if (app_state_record.sleep_word.bit15) {
                app_state_record.sleep_word.bit10 = 1;
                input_rearm_port_event(ALL_PORTS, 0);
            }
            osd_menu_state = MENU_STATE_CLOSED;
            osd_hide_menu();
            osd_menu_state = MENU_STATE_FACTORY_INFO_DONE;
        }
    }

    /* 2. Factory menu. */
    if (osd_menu_state == MENU_STATE_FACTORY_MENU && timer_ticks_since(osd_move_hold_ticks) > 100)
        osd_move_hold_ticks = timer_api_get_ticks16();

    /* 3. Screen overlays, when at least one of them is switched on. */
    if (sys_api_get_channel_state_code(MAIN_CHANNEL) == CHANNEL_CODE_LAST && app_state_record.flags_0x0.after_display
        && !sys_api_get_channel_flag29(MAIN_CHANNEL)
        && (user_settings.crosshair_icon || (user_settings.gaming_flags & GAMING_FLAG_REFRESH_RATE)
            || user_settings.alarm.bytes[ALARM_CLOCK] || (user_settings.settings_page_flags & SETTINGS_INFO_ON_SCREEN))) {
        if (osd_menu_state == MENU_STATE_CLOSED) {
            panel_wait_sync_pulse();
            panel_wait_sync_pulse();
            osd_menu_state = MENU_STATE_SCREEN_OVERLAYS;
            osd_show_screen_overlays(1);
            if (app_state_record.flags_0x0.alarm_running)
                osd_alarm_second_ticks = timer_api_get_ticks16();
        } else if (osd_menu_state == MENU_STATE_SCREEN_OVERLAYS) {
            osd_show_screen_overlays(0);
            if (user_settings.crosshair_color == CROSSHAIR_COLOR_AUTO)
                osd_update_crosshair_color(0);
            osd_message_ticks = timer_api_get_ticks16();
            osd_user_apply_menu_timeout();
        } else if (osd_menu_state == MENU_STATE_POSITION_EDITOR && user_settings.crosshair_color == CROSSHAIR_COLOR_AUTO)
            osd_update_crosshair_color(0);
    }

    /* 4. Alarm Clock countdown. */
    if (app_state_record.flags_0x0.alarm_running) {
        if (timer_ticks_since(osd_alarm_second_ticks) > 1000) {
            osd_alarm_second_ticks = timer_api_get_ticks16();
            if (user_settings.alarm.bytes[ALARM_CLOCK] && (user_settings.alarm.word & ALARM_TIME_MASK)) {
                if (user_settings.alarm.bytes[ALARM_SECONDS] != 0)
                    user_settings.alarm.bytes[ALARM_SECONDS]--;
                else {
                    user_settings.alarm.bytes[ALARM_SECONDS] = 0x3b;
                    user_settings.alarm.bytes[ALARM_MINUTES]--;
                }
            }
        }
        if ((user_settings.alarm.word & ALARM_TIME_MASK) == 0)
            app_state_record.flags_0x0.alarm_running = 0;
    }

    /* 5. OLED panel protect, 30 s after these conditions start to hold; the wait restarts while they do not. */
    if (sys_api_get_channel_state_code(MAIN_CHANNEL) == CHANNEL_CODE_LAST && app_state_record.flags_0x0.after_display
        && (unsigned short)osd_menu_state != MENU_STATE_PANEL_PROTECT && user_settings.factory_marker != FACTORY_MODE_MARKER) {
        if (timer_ticks_since(osd_protect_wait_ticks) > 30000 && app_state_record.half_0xc == 0)
            app_state_record.half_0xc = 1;
        if (timer_ticks_since(osd_protect_wait_ticks) > 29000 && app_state_record.half_0xc == 0 && osd_led_bar_query_sent == 0) {
            sys_led_bar_send_query();
            osd_led_bar_query_sent = 1;
        }
        if (app_state_record.half_0xc != 0) {
            unsigned char offs_hours, offs_count;

            /* half_0x10: the number of care table entries up to the OFFS hours, or with "Sensing Test" on
               (OFFS hours * 60 + count) / 20. */
            if (nvram_get_device_setting(DEVICE_SETTING_SENSING_TEST) == 0) {
                unsigned char n;
                for (n = 0; n < oled_get_care_table_count(); n++)
                    if (oled_get_care_table_byte(n) > nvram_get_device_setting(DEVICE_SETTING_OFFS_HOURS))
                        break;
                app_state_record.half_0x10 = n;
            } else
                app_state_record.half_0x10 = (nvram_get_device_setting(DEVICE_SETTING_OFFS_HOURS) * 60 + nvram_get_device_setting(DEVICE_SETTING_OFFS_COUNT)) / 20;
            /* Only while the OLED power state machine is idle. */
            if (!oled_power_get_state() && !oled_power_get_step() && !app_state_record.flags_0x14.bit15) {
                offs_hours = nvram_get_device_setting(DEVICE_SETTING_OFFS_HOURS);
                offs_count = nvram_get_device_setting(DEVICE_SETTING_OFFS_COUNT);
                if (oled_get_protect_step_code(offs_hours, offs_count) != osd_protect_prompt_step && oled_get_protect_step_code(offs_hours, offs_count)) {
                    /* A new protect step: show its prompt. */
                    osd_protect_prompt_step = oled_get_protect_step_code(offs_hours, offs_count);
                    osd_draw_panel_protect_prompt(osd_protect_prompt_step, PROMPT_MODE_3);
                    osd_menu_state = MENU_STATE_10F;
                    osd_message_ticks = timer_get_ticks16();
                } else
                    osd_check_panel_protect_prompt();
            }
        }
    } else {
        osd_protect_wait_ticks = timer_api_get_ticks16();
        osd_led_bar_query_sent = 0;
    }

    /* 6. Per-state timers. */
    if (osd_menu_state == MENU_STATE_CLOSED || osd_menu_state == MENU_STATE_FACTORY_MENU || osd_menu_state == MENU_STATE_FACTORY_INFO
        || osd_menu_state == MENU_STATE_FACTORY_ITEM_EDIT || osd_menu_state == MENU_STATE_115 || osd_menu_state == MENU_STATE_FACTORY_ITEM_EDIT) {
        /* No time-out in these states: keep the message time stamp current. */
        osd_message_ticks = timer_api_get_ticks16();
        osd_user_apply_menu_timeout();
    } else if (osd_menu_state == MENU_STATE_NO_SIGNAL_ONLY) {
        if (user_settings_burn_in_flag) {
            /* The steps of osd_close_menu. */
            if (app_state_record.sleep_word.bit15) {
                app_state_record.sleep_word.bit10 = 1;
                input_rearm_port_event(ALL_PORTS, 0);
            }
            osd_menu_state = MENU_STATE_CLOSED;
            osd_hide_menu();
        }
    } else if (osd_menu_state == MENU_STATE_NO_SIGNAL) {
        if (user_settings_burn_in_flag) {
            if (app_state_record.sleep_word.bit15) {
                app_state_record.sleep_word.bit10 = 1;
                input_rearm_port_event(ALL_PORTS, 0);
            }
            osd_menu_state = MENU_STATE_CLOSED;
            osd_hide_menu();
        }
    } else if (osd_menu_state == MENU_STATE_OUT_OF_RANGE) {
        if (timer_ticks_since(osd_message_ticks) > 100)
            osd_message_ticks = timer_get_ticks16();
    } else if (osd_menu_state == MENU_STATE_10B) {
        if (timer_ticks_since(osd_message_ticks) > 3000) {
            if (app_state_record.sleep_word.bit15) {
                app_state_record.sleep_word.bit10 = 1;
                input_rearm_port_event(ALL_PORTS, 0);
            }
            osd_menu_state = MENU_STATE_CLOSED;
            osd_hide_menu();
        }
    } else if (osd_menu_state == MENU_STATE_CHANGE_NOTICE) {
        if (timer_ticks_since(osd_message_ticks) > user_settings.osd_timeout * 1000) {
            user_settings.byte_0x1aa = 0;
            osd_close_change_notice();
        }
    } else if (osd_menu_state == MENU_STATE_10F) {
        if (timer_ticks_since(osd_message_ticks) > 3000) {
            if (app_state_record.sleep_word.bit15) {
                app_state_record.sleep_word.bit10 = 1;
                input_rearm_port_event(ALL_PORTS, 0);
            }
            osd_menu_state = MENU_STATE_CLOSED;
            osd_hide_menu();
            /* Then the HDR icon for another 3 s, once. */
            if (app_state_record.flags_0x0.bit9) {
                app_state_record.flags_0x0.bit9 = 0;
                osd_message_ticks = timer_get_ticks16();
                osd_menu_state = MENU_STATE_10F;
                osd_draw_hdr_icon();
            }
        }
    } else if (osd_menu_state == MENU_STATE_PANEL_PROTECT) {
        /* The protect prompt has had no answer for 60 s. */
        if (timer_ticks_since(osd_message_ticks) > 60000) {
            if (!(user_settings.oled_care_flags.bit31 && user_settings.oled_care_flags.bit30)) {
                if (!user_settings.oled_care_flags.bit31)
                    osd_menu_state = MENU_STATE_PANEL_PROTECT_ITEM;
                osd_redraw_page_after_notice(NOTICE_PAGE_7, osd_menu_state - MENU_STATE_PANEL_PROTECT_ITEM);
            } else {
                if ((app_state_record.half_0x12 == 5 && osd_choice_row == 1) || (app_state_record.half_0x10 == 4 && osd_choice_row == 0))
                    app_state_record.flags_0xe.bit15 = 1;
                else
                    app_state_record.flags_0xe.bit15 = 0;
                if (osd_edit_value == 2)
                    osd_edit_value = 0;
                if (app_state_record.dialog_button_index && osd_edit_value == 0 && !app_state_record.flags_0xe.bit15)
                    osd_edit_value = 1;
                /* Run the button now chosen in osd_edit_value. */
                osd_accept_panel_protect_prompt();
            }
            user_settings.oled_care_flags.bit31 = 1;
            user_settings.oled_care_flags.bit30 = 1;
            user_settings.byte_0x1e4 = 0;
            user_settings.byte_0x1e5 = 0;
        }
    } else {
        /* Every other state: the menu header's refresh rate and the menu time-out. */
        if (osd_menu_state <= MENU_STATE_LAST_HEADER && timer_ticks_since(osd_move_hold_ticks) > 100) {
            osd_move_hold_ticks = timer_api_get_ticks16();
            osd_update_header_refresh_rate();
        }
        if (timer_ticks_since(osd_message_ticks) > 1000) {
            osd_message_ticks = timer_api_get_ticks16();
            if (osd_seconds_countdown != 0)
                osd_seconds_countdown--;
            if (osd_seconds_countdown == 0) {
                if (!is_timeout_action_state(osd_menu_state)) {
                    /* Time-out: start a newly chosen Alarm Clock, save, and close the menu. */
                    unsigned char shown_choice = osd_alarm_clock_choice;
                    unsigned char t = user_settings.alarm.bytes[ALARM_CLOCK];
                    if (t != shown_choice)
                    if (t != 0) {
                        user_settings.alarm.bytes[ALARM_MINUTES] = user_settings.alarm_table_0x197[t];
                        user_settings.alarm.bytes[ALARM_SECONDS] = user_settings.alarm_table_0x19b[t];
                        osd_alarm_clock_choice = t;
                        app_state_record.flags_0x0.alarm_running = 1;
                    }
                    if (app_state_record.sleep_word.bit15) {
                        app_state_record.sleep_word.bit15 = 0;
                        app_state_record.sleep_word.bit10 = 1;
                        input_rearm_port_event(ALL_PORTS, 0);
                    }
                    osd_apply_choice_on_timeout();
                    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
                    sys_user_save_mode_slot();
                    /* The steps of osd_close_menu. */
                    if (app_state_record.sleep_word.bit15) {
                        app_state_record.sleep_word.bit10 = 1;
                        input_rearm_port_event(ALL_PORTS, 0);
                    }
                    osd_menu_state = MENU_STATE_CLOSED;
                    osd_hide_menu();
                    /* Port 0's bit 5 of app_port_flags: show 'Out Of Range!'. */
                    if (sys_get_app_flag42_bit5()) {
                        osd_menu_state = MENU_STATE_OUT_OF_RANGE;
                        osd_draw_out_of_range_message();
                    }
                } else {
                    /* The list states run their OK action: the bodies of osd_open_refresh_rate_position,
                       osd_open_alarm_clock_position and osd_open_crosshair_position (with the countdown
                       restarted), or osd_open_pbp_custom_split. State 0x106 does nothing. */
                    if (osd_seconds_countdown == 0 && osd_menu_state == MENU_STATE_REFRESH_RATE_LOCATION) {
                        osd_seconds_countdown = user_settings.osd_timeout;
                        osd_edit_value = user_settings.refresh_rate_location;
                        osd_menu_state = MENU_STATE_POSITION_EDITOR;
                        user_settings.alarm.bytes[ALARM_BYTE_0x1A3] = OVERLAY_REFRESH_RATE;
                        osd_hide_menu();
                        panel_wait_sync_pulse();
                        panel_wait_sync_pulse();
                        osd_draw_overlay_position_preview(OVERLAY_REFRESH_RATE, 1, 0);
                    } else if (osd_seconds_countdown == 0 && osd_menu_state == MENU_STATE_ALARM_LOCATION) {
                        osd_seconds_countdown = user_settings.osd_timeout;
                        user_settings.alarm.bytes[ALARM_BYTE_0x1A3] = OVERLAY_ALARM_CLOCK;
                        osd_edit_value = user_settings.alarm_clock_location;
                        osd_menu_state = MENU_STATE_POSITION_EDITOR;
                        osd_hide_menu();
                        panel_wait_sync_pulse();
                        panel_wait_sync_pulse();
                        osd_draw_overlay_position_preview(OVERLAY_ALARM_CLOCK, 1, 0);
                    } else if (osd_seconds_countdown == 0 && osd_menu_state == MENU_STATE_CROSSHAIR_ITEMS) {
                        osd_seconds_countdown = user_settings.osd_timeout;
                        user_settings.alarm.bytes[ALARM_BYTE_0x1A3] = OVERLAY_CROSSHAIR;
                        osd_menu_state = MENU_STATE_POSITION_EDITOR;
                        osd_hide_menu();
                        panel_wait_sync_pulse();
                        panel_wait_sync_pulse();
                        osd_draw_overlay_position_preview(OVERLAY_CROSSHAIR, 1, 0);
                    } else if (osd_seconds_countdown == 0 && osd_menu_state == MENU_STATE_PBP_ITEMS) {
                        osd_open_pbp_custom_split();
                        osd_user_apply_menu_timeout();
                    }
                }
            }
        }
    }
}
