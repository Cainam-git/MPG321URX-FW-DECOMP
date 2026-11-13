/* osd_move_pip_window_right  (FUN_a0093d30)
 *
 * Move the custom PIP window right by a step of 8.
 * Note: Raises settings halfword +0x54 (pip_custom_x) up to the panel width minus the window width of the PIP
 *   size; the step does not grow.
 * Name basis: derived - handler table 0xA802422C: right on state 0x107; limits 1728/1344/960 by PIP size byte
 *   +0x31
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0093d30 @ 0xa0093d30-0xa0093f90 (152 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Source forms the exact build depends on: move_step is a plain byte here (the shifts and masks are written out);
 * the limit test is written out once for each of the three window sizes, with panel_api_get_active_size(0)
 * called afresh in every test (signed compares).
 */
#define MOVE_RUN_RIGHT       1                  /* high nibble of move_step while a Right run is going */
#define MOVE_STEP_BASE       0x18               /* Right run id 1, step 8 pixels */
#define MOVE_GAP_TICKS       100                /* more ticks than this since the last move: a new run starts */
#define MOVE_HOLD_FAST_TICKS 2000               /* run held longer than this (the code resets the step; see the routine comment) */
#define MOVE_HOLD_FASTEST_TICKS 5000
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit of osd_request_bits: event 0x80 */
#define PANEL_SIZE_WIDTH     0                  /* selector of panel_api_get_active_size */

/* The part of the application state record used here (app_state_record, 0xA802CFF4). */
struct app_state_record {
    unsigned char pad[8];
    unsigned char move_step;                    /* +8: high nibble = move run id, low nibble = step in pixels */
};
/* The part of the user settings record used here (user_settings, 0xA802D290). */
struct user_settings_record {
    unsigned char pad[0x31];
    unsigned char pip_size;                     /* +0x31: size of the custom PIP window, 0..2 */
    unsigned char pad32[0x22];
    unsigned short pip_custom_x;                /* +0x54 */
    unsigned short pip_custom_y;                /* +0x56 */
};
extern struct app_state_record app_state_record;
extern struct user_settings_record user_settings;
extern unsigned short osd_move_key_ticks, osd_move_hold_ticks;
extern unsigned char osd_request_bits;
extern unsigned short timer_api_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);
extern void sys_user_resize_window_channel1(int);
extern unsigned short panel_api_get_active_size(unsigned char p);

/*
 * Move the custom PIP window right by one key step (Right key in menu state 0x107, reached through the handler
 * table). The step is the low nibble of app_state_record.move_step. A run starts at 8 pixels: it restarts when
 * more than MOVE_GAP_TICKS passed since the previous move or when the run id in the high nibble is not the Right
 * id. For the two hold times the code sets the byte again to the same 0x18, so the step does not grow here.
 *
 * pip_custom_x moves right by the step while it stays within panel width minus the window width (1728, 1344 or
 * 960 for pip_size 0, 1 or 2). Past that limit it moves by 2 as long as it is still below the limit. The window
 * is then recomputed (sys_user_resize_window_channel1) and the settings-changed request is made.
 */
void osd_move_pip_window_right(void)
{
    /* A pause between key events ends the run: back to the base step. */
    if (timer_ticks_since(osd_move_key_ticks) > MOVE_GAP_TICKS) {
        app_state_record.move_step = MOVE_STEP_BASE;
        osd_move_hold_ticks = timer_api_get_ticks16();
    }
    osd_move_key_ticks = timer_api_get_ticks16();
    /* A run begun by another key does not carry its step over. */
    if ((app_state_record.move_step >> 4) != MOVE_RUN_RIGHT) {
        app_state_record.move_step = MOVE_STEP_BASE;
        osd_move_hold_ticks = timer_api_get_ticks16();
    }
    if (timer_ticks_since(osd_move_hold_ticks) > MOVE_HOLD_FAST_TICKS)
        if (timer_ticks_since(osd_move_key_ticks) <= MOVE_GAP_TICKS - 1)
            app_state_record.move_step = MOVE_STEP_BASE;
    if (timer_ticks_since(osd_move_hold_ticks) > MOVE_HOLD_FASTEST_TICKS)
        if (timer_ticks_since(osd_move_key_ticks) <= MOVE_GAP_TICKS - 1)
            app_state_record.move_step = MOVE_STEP_BASE;
    /* The window width depends on the PIP size: 1728, 1344 or 960. */
    if (user_settings.pip_size == 0) {
        if (user_settings.pip_custom_x + (app_state_record.move_step & 0xf) <= panel_api_get_active_size(PANEL_SIZE_WIDTH) - 1728)
            user_settings.pip_custom_x += (app_state_record.move_step & 0xf);
        else if (user_settings.pip_custom_x < panel_api_get_active_size(PANEL_SIZE_WIDTH) - 1728)
            user_settings.pip_custom_x += 2;
    } else if (user_settings.pip_size == 1) {
        if (user_settings.pip_custom_x + (app_state_record.move_step & 0xf) <= panel_api_get_active_size(PANEL_SIZE_WIDTH) - 1344)
            user_settings.pip_custom_x += (app_state_record.move_step & 0xf);
        else if (user_settings.pip_custom_x < panel_api_get_active_size(PANEL_SIZE_WIDTH) - 1344)
            user_settings.pip_custom_x += 2;
    } else if (user_settings.pip_size == 2) {
        if (user_settings.pip_custom_x + (app_state_record.move_step & 0xf) <= panel_api_get_active_size(PANEL_SIZE_WIDTH) - 960)
            user_settings.pip_custom_x += (app_state_record.move_step & 0xf);
        else if (user_settings.pip_custom_x < panel_api_get_active_size(PANEL_SIZE_WIDTH) - 960)
            user_settings.pip_custom_x += 2;
    }
    sys_user_resize_window_channel1(0);
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
