/* sys_app_generate_events  (FUN_a0080c10)
 *
 * Turn port state changes and expired timers into application events.
 * Note: Runs each application step unless bit 0 of 0xA802AF41 is set; posts to the queue at 0xA802AFA8.
 * Name basis: proven - header: APP event generator; calls the event post sys_post_app_event
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0080c10 @ 0xa0080c10..0xa0081e0c, flags -mcpu=v8 -O3 -g (-msoft-float gives the same code).
 * Source forms the exact build depends on:
 *  - helpers written as static functions and inlined by GCC (standalone copies of three of them exist in the
 *    firmware): port_is_used = input_is_port_used (input_is_port_used), forget_port_state(port, 0) =
 *    input_rearm_port_event (input_rearm_port_event), all_used_ports_at_most = the family of input_used_ports_settled
 *    (input_used_ports_settled), here also used with the limits 3 and 8;
 *  - the helper results are tested as '== 1' (the changed flag, all_used_ports_at_most(3) in the event-0 arm,
 *    (4) in the after-mute and delayed-event arms, (8), and the two flag-28 / flag-29 port loops);
 *  - every port loop skips an unused port with 'if (!port_is_used(i)) continue;' before its test; the
 *    other-ports loop of the delayed-event arm is 'continue' for an unused port and for i == port, then
 *    'if (timer running && port_rearm_requested(i) != 1) others_ready = 0;';
 *  - the chain after a posted event is one block 'if (event != APP_EV_NONE) { sys_post_app_event(event); ... }';
 *  - the case orders: port_timer_id 3, 1, 2; the add-port switch of a delayed event 1, 3, 2; the state switch
 *    0, 3, 1, 2, 4, 5, 6, 8, 9, 10; the add-port switch of a new event 2, 3, 1; the app_port_flags clear
 *    default, 1, 2, 3 (every case ends in break or return);
 *  - port_is_active calls input_api_count_port_status_bits before it tests anything;
 *  - clear_port_rearm keeps its arm for port 4 (all ports), which this routine never takes.
 */

/*
 * The application events made here. APPActionDispatcher turns an event into an action through the tables
 * app_event_indexes and app_event_actions; the comment names that action by the text it prints, or by what
 * it does. "+port" means the event of port n is the code + n (port 0 gives the code itself). Events marked
 * "no action" lead to no action in APPActionDispatcher (the other consumers of sys_pump_app_events still
 * receive them).
 */
enum app_event {
    APP_EV_STATE_3                 = 0x00,  /* state code 3, the same code for every port; no action */
    APP_EV_STATE_0                 = 0x01,  /* state code 0; no action */
    APP_EV_STATE_1                 = 0x02,  /* state code 1; no action */
    APP_EV_POWER_ON_INIT           = 0x03,  /* "APPATN_PWR_ON_INIT" */
    APP_EV_DELAYED_ACTIVE          = 0x04,  /* +port: sets app_port_flags bit (port) */
    APP_EV_DELAYED_ALL             = 0x08,  /* sets bit 4 when every used port has bit (port) or bit (10 + port) */
    APP_EV_DELAYED_INACTIVE        = 0x0a,  /* +port: sets app_port_flags bit (10 + port) */
    APP_EV_DELAYED_ALL_INACTIVE    = 0x0e,  /* sets bit 14 when every used port has bit (10 + port) */
    APP_EV_AFTER_MUTE              = 0x0f,  /* +port: "APPTasksAfterMute_Main" / "_P1"; starts timer 4 + port */
    APP_EV_AFTER_MUTE_ANY          = 0x13,  /* no action */
    APP_EV_MUTE_ALL                = 0x14,  /* "APPATN_MUTE_ALL" */
    APP_EV_SYNC_DET                = 0x18,  /* +port: "APPATN_SYNC_DET_MAIN" for port 0 */
    APP_EV_TIMING_GET              = 0x1c,  /* +port: "APPATN_TIMING_GET_MAIN" for port 0 */
    APP_EV_STATE_8                 = 0x20,  /* +port: state code 8 after 10; no action */
    APP_EV_MUTE_WAIT2SHOW          = 0x24,  /* "APPATN_MUTE_WAIT2SHOW" */
    APP_EV_BEFORE_DISPLAY          = 0x25,  /* +port: "APPATN_BEFOREDISPLAY_MAIN" / "_P1" */
    APP_EV_BEFORE_DISPLAY_ALL      = 0x29,  /* "APPTasksBeforeDisplay" */
    APP_EV_BEFORE_DISPLAY_APP_ONLY = 0x2a,  /* "APPATN_BEFOREDISPLAY_APP_ONLY"; no state leads to it here */
    APP_EV_AFTER_DISPLAY           = 0x2e,  /* +port: "APPATN_AFTERDISPLAY_MAIN" / "APPTasksAfterDisplay_P1" */
    APP_EV_AFTER_DISPLAY_ALL       = 0x32,  /* "APPTasksAfterDisplay" */
    APP_EV_STATE_10_FLAG28         = 0x33,  /* +port: no action */
    APP_EV_STATE_10_FLAG28_ALL     = 0x37,  /* no action */
    APP_EV_STATE_10_FLAG29         = 0x38,  /* +port: sets app_port_flags bit (5 + port) */
    APP_EV_STATE_10_FLAG29_ALL     = 0x3c,  /* sets bit 9 and starts timer 0xB with 60000 ms */
    APP_EV_EVENT_PENDING           = 0x3d,  /* the pending flag of the stored event rose; action 52, no case */
    APP_EV_STATE_2                 = 0x3e,  /* state code 2; no action */
    APP_EV_NONE                    = 0x3f   /* "no event": sys_post_app_event drops it */
};

#define APP_FLAG_LOGO_HOLD      1       /* app_flags bit 0: logo hold, set by the power-on logo routine */
#define APP_FLAG_MUTE_ALL_SENT  8       /* app_flags bit 3: APP_EV_MUTE_ALL was posted in this pass */

/* app_port_flags: three bits per port that the dispatcher sets (bits port, 5 + port, 10 + port, see the
   events above) and three bits for all ports (4, 9, 14). A new event of a port clears its three bits and
   the three all-port bits. */
#define APP_PORT_FLAGS_OF_PORT(n)   (0x421 << (n))
#define APP_PORT_FLAGS_ALL_PORTS    0x4210

#define PORT_STATE_UNKNOWN      0xff    /* last state after a re-arm; no state code takes it */
#define APP_TIMER_PORT0         4       /* timers 4..7: one per port, started by the after-mute actions */

#define SLEEP_STATE_DC_ON       1       /* the value power_enter_app_state takes as "dc on" */
#define SLEEP_STATE_FAKE_SLEEP  2

#define SETTINGS_WORD0_BIT9     0x200   /* user settings word +0, bit 9 */
#define GAMING_FLAG_BIT15       0x8000  /* user_settings_gaming_flags (+0xA8), bit 15 */

/* The application state record (0xA802CFF4), up to the fields used here. */
struct app_state_record { unsigned short half_0x0, half_0x2; unsigned short bit15 : 1, sleep_state : 2, low_bits : 13;
               unsigned char pad06[0x16]; unsigned char port_flag_bits; };
extern struct app_state_record app_state_record;
/* The user settings record (0xA802D290), up to the fields used here. */
struct user_settings_record { unsigned int word_0x0; unsigned char pad04[0x1b]; unsigned char pip_pbp_mode;
             unsigned char pad20[0x88]; unsigned int gaming_flags; };
extern struct user_settings_record user_settings;
/* app_port_events_ready: 0 until the per-port tables below have been filled the first time. */
extern unsigned char app_flags, app_port_rearm_bits, app_event_pending_last, app_port_events_ready, app_port_active_bits;
extern unsigned short app_port_flags;
extern unsigned char app_port_pending_events[4], app_port_last_states[4];

extern unsigned char sys_api_get_event_code(void);
extern unsigned char sys_api_is_event_pending(void);
extern void sys_api_set_event_code(unsigned char);
extern void sys_post_app_event(unsigned char);
extern unsigned char sys_api_get_channel_state_code(unsigned char);
extern unsigned char input_api_get_channel_status_bit(unsigned char);
extern unsigned char sys_api_get_channel_flags_14_15(unsigned char);
extern unsigned char sys_api_get_channel_flag29(unsigned char);
extern unsigned char sys_api_get_channel_flag28(unsigned char);
extern unsigned char input_api_count_port_status_bits(void);
extern unsigned char input_api_any_port_status(void);
extern unsigned short sys_app_timer_read(int);
extern void power_escape_fake_sleep(void);
extern unsigned char oled_power_get_field_12(void);
extern unsigned char oled_power_get_field_11(void);
extern void gpio_set_port4_bit4_low_if_allowed(void);
extern void gpio_set_port4_bit7_high_if_allowed(void);

/* Whether port 0..3 takes part in the PIP/PBP layout: port 0 always, port 1 in every mode but 0, port 2 in
   modes 4 to 7, port 3 in mode 7 (the rule of input_is_port_used). */
static unsigned char port_is_used(unsigned char port)
{
    unsigned char used = 0;
    if (port == 0) used = 1;
    else if (port == 1) { if (user_settings.pip_pbp_mode != 0) used = 1; }
    else if (port == 2) { if ((unsigned char)(user_settings.pip_pbp_mode - 4) <= 3) used = 1; }
    else if (port == 3) { if (user_settings.pip_pbp_mode == 7) used = 1; }
    return used & 1;
}

/* The application timer of a port: APP_TIMER_PORT0 + port. */
static int port_timer_id(unsigned char port)
{
    switch (port) {
    case 3: return 7;
    case 1: return 5;
    case 2: return 6;
    }
    return 4;
}

/* 1 when input_rearm_port_event has asked for the port's delayed event to be posted at once. */
static unsigned char port_rearm_requested(unsigned char port)
{
    if (port == 0) { if (app_port_rearm_bits & 1) return 1; }
    else if (port == 1) { if (app_port_rearm_bits & 2) return 1; }
    else if (port == 2) { if (app_port_rearm_bits & 4) return 1; }
    else if (port == 3) { if (app_port_rearm_bits & 8) return 1; }
    return 0;
}

static void clear_port_rearm(unsigned char port)
{
    if (port == 0) app_port_rearm_bits &= ~1;
    else if (port == 1) app_port_rearm_bits &= ~2;
    else if (port == 2) app_port_rearm_bits &= ~4;
    else if (port == 3) app_port_rearm_bits &= ~8;
    else if (port == 4) app_port_rearm_bits = 0;
}

/* = input_rearm_port_event: forget the last state of the port (4 = all), so that its present state counts
   as a change; with force == 1 also ask for the delayed event at once. */
static void forget_port_state(unsigned char port, unsigned char force)
{
    if (port == 4) {
        app_port_last_states[0] = 0xff;
        app_port_last_states[1] = 0xff;
        app_port_last_states[2] = 0xff;
        app_port_last_states[3] = 0xff;
        if (force == 1)
            app_port_rearm_bits |= 0xf;
    } else {
        app_port_last_states[port] = 0xff;
        if (force == 1) {
            if (port == 0)
                app_port_rearm_bits |= 1;
            else if (port == 1)
                app_port_rearm_bits |= 2;
            else if (port == 2)
                app_port_rearm_bits |= 4;
            else if (port == 3)
                app_port_rearm_bits |= 8;
        }
    }
}

/* The port's bit of the first port status word. With settings word +0 bit 9 set, port 0 instead counts as
   active when any of the four bits is set. */
static unsigned char port_is_active(unsigned char port)
{
    unsigned char count = input_api_count_port_status_bits();
    if ((user_settings.word_0x0 & SETTINGS_WORD0_BIT9) && port == 0) {
        if (count) return 1;
    } else
        return input_api_get_channel_status_bit(port);
    return 0;
}

/* 1 when no used port has a state code above the limit (input_used_ports_settled is the limit 4). */
static unsigned char all_used_ports_at_most(unsigned char limit)
{
    unsigned char ok = 1;
    unsigned char i;
    for (i = 0; i <= 3; i++) {
        if (!port_is_used(i))
            continue;
        if (sys_api_get_channel_state_code(i) > limit) { ok = 0; break; }
    }
    return ok & 1;
}

/* 1 when every used port has a state code of at most 4 or channel flag 29 set. */
static unsigned char all_used_ports_at_most_4_or_flag29(void)
{
    unsigned char ok = 1;
    unsigned char i;
    for (i = 0; i <= 3; i++) {
        if (!port_is_used(i))
            continue;
        if (sys_api_get_channel_state_code(i) > 4 && !sys_api_get_channel_flag29(i)) { ok = 0; break; }
    }
    return ok & 1;
}

/* 1 when every used port has a state code of at most 4 or channel flag 28 set. */
static unsigned char all_used_ports_at_most_4_or_flag28(void)
{
    unsigned char ok = 1;
    unsigned char i;
    for (i = 0; i <= 3; i++) {
        if (!port_is_used(i))
            continue;
        if (sys_api_get_channel_state_code(i) > 4 && !sys_api_get_channel_flag28(i)) { ok = 0; break; }
    }
    return ok & 1;
}

/*
 * The event of one port for this pass, or APP_EV_NONE.
 *
 * A delayed event waits in app_port_pending_events[port]. When the port's timer has run out, or a re-arm
 * asks for it, that event (+port) is the result and nothing else is looked at. Otherwise the port's state
 * code is read and compared with the one seen in the last pass; a change gives the event of the new state.
 */
static unsigned char port_next_event(unsigned char port)
{
    unsigned char event;

    if (app_port_pending_events[port] != APP_EV_NONE
        && (sys_app_timer_read(port_timer_id(port)) == 0 || port_rearm_requested(port) == 1)) {
        /* Phase A: post the delayed event. */
        event = app_port_pending_events[port];
        app_port_pending_events[port] = APP_EV_NONE;
        clear_port_rearm(port);
        switch (port) {
        case 1: event += 1; break;
        case 3: event += 3; break;
        case 2: event += 2; break;
        }
        return event;
    } else {
        unsigned char state = sys_api_get_channel_state_code(port);
        unsigned char changed;

        /* Phase B: read the state; in sleep state "dc on" every port reads as state 0. */
        if (app_state_record.sleep_state == SLEEP_STATE_DC_ON)
            state = 0;
        event = APP_EV_NONE;

        /* Phase C: in state 4, a change of the port's active bit since the last pass. */
        changed = 0;
        if (state == 4) {
            if (((app_port_active_bits >> port) & 1) != port_is_active(port))
                changed = 1;
        }
        if (port_is_active(port) == 1)
            app_port_active_bits |= 1 << port;
        else
            app_port_active_bits &= ~(1 << port);
        if (changed == 1) {
            if (app_state_record.sleep_state == SLEEP_STATE_FAKE_SLEEP
                && (!(user_settings.word_0x0 & SETTINGS_WORD0_BIT9) || (user_settings.gaming_flags & GAMING_FLAG_BIT15)))
                power_escape_fake_sleep();
            else if (oled_power_get_field_12() == 1 && oled_power_get_field_11() != 2) {
                gpio_set_port4_bit4_low_if_allowed();
                gpio_set_port4_bit7_high_if_allowed();
            }
            /* The last state becomes unknown, so state 4 is reported again just below. */
            forget_port_state(port, 0);
        }

        /* Phase D: a changed state gives the event of the new state. The port's bit of port_flag_bits is set
           only in the pass of such a change. */
        app_state_record.port_flag_bits &= ~(1 << port);
        if (app_port_last_states[port] != state) {
            app_port_pending_events[port] = APP_EV_NONE;
            switch (state) {
            case 0: event = APP_EV_STATE_0; break;
            case 3: event = APP_EV_STATE_3; break;
            case 1: event = APP_EV_STATE_1; break;
            case 2: event = APP_EV_STATE_2; break;
            case 4: event = port_is_active(port) == 1 ? APP_EV_DELAYED_ACTIVE : APP_EV_DELAYED_INACTIVE; break;
            case 5:
                if (sys_api_get_channel_flags_14_15(port)) app_state_record.port_flag_bits |= 1 << port;
                event = APP_EV_SYNC_DET; break;
            case 6:
                if (sys_api_get_channel_flags_14_15(port)) app_state_record.port_flag_bits |= 1 << port;
                event = APP_EV_TIMING_GET; break;
            case 8:
                /* Only a step down from state 10 is reported. */
                if (app_port_last_states[port] == 10) event = APP_EV_STATE_8;
                break;
            case 9:
                if (sys_api_get_channel_flags_14_15(port)) app_state_record.port_flag_bits |= 1 << port;
                event = APP_EV_BEFORE_DISPLAY; break;
            case 10:
                if (sys_api_get_channel_flag29(port) == 1) event = APP_EV_STATE_10_FLAG29;
                else if (sys_api_get_channel_flag28(port) == 1) event = APP_EV_STATE_10_FLAG28;
                else {
                    if (sys_api_get_channel_flags_14_15(port)) app_state_record.port_flag_bits |= 1 << port;
                    event = APP_EV_AFTER_DISPLAY;
                }
                break;
            }
            /* State 4: its event waits for the port's timer; the after-mute event goes out now. */
            if (event == APP_EV_DELAYED_ACTIVE || event == APP_EV_DELAYED_INACTIVE) {
                app_port_pending_events[port] = event;
                event = APP_EV_AFTER_MUTE;
            }
            /* Port events: add the port number (4 and 10 have already become APP_EV_AFTER_MUTE here). */
            if (event == APP_EV_DELAYED_INACTIVE || event == APP_EV_DELAYED_ACTIVE || event == APP_EV_AFTER_MUTE
                || event == APP_EV_SYNC_DET || event == APP_EV_TIMING_GET || event == APP_EV_BEFORE_DISPLAY
                || event == APP_EV_BEFORE_DISPLAY_APP_ONLY || event == APP_EV_STATE_10_FLAG29
                || event == APP_EV_STATE_10_FLAG28 || event == APP_EV_AFTER_DISPLAY || event == APP_EV_STATE_8
                || event == APP_EV_STATE_8 + 1 || event == APP_EV_STATE_8 + 2 || event == APP_EV_STATE_8 + 3) {
                switch (port) {
                case 2: event += 2; break;
                case 3: event += 3; break;
                case 1: event += 1; break;
                }
            }
            /* Any new event of the port clears the port's flags and the all-port flags. */
            if (event != APP_EV_NONE) {
                switch (port) {
                default: app_port_flags &= ~APP_PORT_FLAGS_OF_PORT(0); break;
                case 1: app_port_flags &= ~APP_PORT_FLAGS_OF_PORT(1); break;
                case 2: app_port_flags &= ~APP_PORT_FLAGS_OF_PORT(2); break;
                case 3: app_port_flags &= ~APP_PORT_FLAGS_OF_PORT(3); break;
                }
                app_port_flags &= ~APP_PORT_FLAGS_ALL_PORTS;
            }
            app_port_last_states[port] = state;
        }
        return event;
    }
}

/*
 * Turn the state changes of the used ports and their expired timers into application events.
 *
 * sys_pump_app_events calls this first in each pass, after it has set the event queue empty; the events posted
 * here are then dispatched in the same pass. Nothing happens while the power-on logo holds (APP_FLAG_LOGO_HOLD).
 *
 * Phases:
 *  1. The stored event (sys_api_get_event_code): a non-zero code is cleared. Otherwise a rise of its pending
 *     flag from 0 posts APP_EV_EVENT_PENDING.
 *  2. For each used port (port_is_used), in order 0..3:
 *     a. the first time: no delayed events, all last states unknown, no active bits;
 *     b. port_next_event gives the port's event, which is posted;
 *     c. a follow-up event for the whole layout when the other used ports allow it:
 *        - APP_EV_STATE_3 and every used port at state 3 or below: APP_EV_POWER_ON_INIT;
 *        - an after-mute event: APP_EV_AFTER_MUTE_ANY, and APP_EV_MUTE_ALL once per pass when every used port
 *          is at state 4 or below, unless a final event has been chosen already;
 *        - a delayed event, every used port at state 4 or below, and every other used port's timer run out
 *          or re-armed: the final event APP_EV_DELAYED_ALL or APP_EV_DELAYED_ALL_INACTIVE is chosen;
 *        - APP_EV_STATE_8 (+port) and every used port at 8 or below: APP_EV_MUTE_WAIT2SHOW;
 *        - APP_EV_STATE_10_FLAG29 / _FLAG28 (+port) and every used port at 4 or below or with that flag:
 *          the matching _ALL event;
 *        - APP_EV_BEFORE_DISPLAY / APP_EV_AFTER_DISPLAY (+port): the matching _ALL event at once.
 *  3. The final event, when one was chosen, is posted last.
 */
void sys_app_generate_events(void)
{
    unsigned char final_event = APP_EV_NONE;
    unsigned char final_chosen = 0;
    unsigned char port, i;

    if (app_flags & APP_FLAG_LOGO_HOLD)
        return;

    /* Phase 1: the stored event. */
    if (sys_api_get_event_code()) {
        app_event_pending_last = 0;
        sys_api_set_event_code(0);
    } else {
        if (sys_api_is_event_pending() != app_event_pending_last && app_event_pending_last == 0)
            sys_post_app_event(APP_EV_EVENT_PENDING);
        app_event_pending_last = sys_api_is_event_pending();
    }

    /* Phase 2: the ports. */
    for (port = 0; port < 4; port++) {
        unsigned char event;

        if (!port_is_used(port))
            continue;
        /* 2a: fill the per-port tables the first time. */
        if (app_port_events_ready == 0) {
            for (i = 0; i < 4; i++) {
                app_port_pending_events[i] = APP_EV_NONE;
                app_port_last_states[i] = PORT_STATE_UNKNOWN;
            }
            app_port_events_ready = 1;
            app_port_active_bits = 0;
        }
        /* 2b: the port's own event. */
        event = port_next_event(port);
        if (event != APP_EV_NONE) {
            sys_post_app_event(event);
            /* 2c: the follow-up event for the whole layout. */
            if (event == APP_EV_STATE_3 && all_used_ports_at_most(3) == 1) {
                sys_post_app_event(APP_EV_POWER_ON_INIT);
            } else if ((unsigned char)(event - APP_EV_AFTER_MUTE) <= 3) {
                sys_post_app_event(APP_EV_AFTER_MUTE_ANY);
                if (all_used_ports_at_most(4) == 1 && !(app_flags & APP_FLAG_MUTE_ALL_SENT)) {
                    if (!final_chosen) {
                        app_flags |= APP_FLAG_MUTE_ALL_SENT;
                        sys_post_app_event(APP_EV_MUTE_ALL);
                    }
                }
            } else if ((unsigned char)(event - APP_EV_DELAYED_ACTIVE) < 4
                       || (unsigned char)(event - APP_EV_DELAYED_INACTIVE) < 4) {
                if (all_used_ports_at_most(4) == 1) {
                    /* The other used ports must have no delayed event still timing. */
                    unsigned char others_ready = 1;
                    for (i = 0; i <= 3; i++) {
                        if (!port_is_used(i))
                            continue;
                        if (i == port)
                            continue;
                        if (sys_app_timer_read(port_timer_id(i)) != 0 && port_rearm_requested(i) != 1)
                            others_ready = 0;
                    }
                    if (others_ready == 1) {
                        final_chosen = 1;
                        /* One picture: by this (port 0) event; a PIP/PBP layout: by the port status word. */
                        if (user_settings.pip_pbp_mode == 0) {
                            if (event == APP_EV_DELAYED_INACTIVE) final_event = APP_EV_DELAYED_ALL_INACTIVE; else final_event = APP_EV_DELAYED_ALL;
                        } else {
                            if (input_api_any_port_status() == 0) final_event = APP_EV_DELAYED_ALL_INACTIVE; else final_event = APP_EV_DELAYED_ALL;
                        }
                    }
                }
            } else if ((unsigned char)(event - APP_EV_STATE_8) <= 3) {
                if (all_used_ports_at_most(8) == 1)
                    sys_post_app_event(APP_EV_MUTE_WAIT2SHOW);
            } else if ((unsigned char)(event - APP_EV_STATE_10_FLAG29) <= 3) {
                if (all_used_ports_at_most_4_or_flag29() == 1)
                    sys_post_app_event(APP_EV_STATE_10_FLAG29_ALL);
            } else if ((unsigned char)(event - APP_EV_STATE_10_FLAG28) <= 3) {
                if (all_used_ports_at_most_4_or_flag28() == 1)
                    sys_post_app_event(APP_EV_STATE_10_FLAG28_ALL);
            } else if ((unsigned char)(event - APP_EV_BEFORE_DISPLAY) <= 3)
                sys_post_app_event(APP_EV_BEFORE_DISPLAY_ALL);
            else if ((unsigned char)(event - APP_EV_AFTER_DISPLAY) <= 3)
                sys_post_app_event(APP_EV_AFTER_DISPLAY_ALL);
        }
    }

    /* Phase 3: the mute-all mark lasts one pass; the final event goes out last. */
    app_flags &= ~APP_FLAG_MUTE_ALL_SENT;
    if (final_event != APP_EV_NONE)
        sys_post_app_event(final_event);
}
