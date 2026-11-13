/* osd_move_pip_window_down  (FUN_a0094108)
 *
 * Move the custom PIP window down, in bigger steps while the key is held.
 * Note: Raises settings halfword +0x56 up to the panel height minus the window height.
 * Name basis: derived - handler table 0xA802422C: down on state 0x107; limits 972/756/540 by PIP size
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0094108 @ 0xa0094108-0xa0094368 (152 words), flags -mcpu=v8 -O3 -g. No direct callers (reached through
 * a table). Source form: the limit test is written out once for each of the three window sizes, with
 * panel_api_get_active_size(1) called afresh in every test.
 */
struct app_state_record {
    unsigned char pad[8];
    unsigned char move_step;                    /* +8: high nibble = move run id, low nibble = step in pixels */
};
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

#define MOVE_RUN_DOWN        4                  /* high nibble of move_step while a Down run is going */
#define MOVE_STEP_BASE       0x48               /* Down run id 4, step 8 pixels */
#define MOVE_GAP_TICKS       100                /* more ticks than this since the last move: a new run starts */
#define MOVE_HOLD_FAST_TICKS 2000               /* run held longer than this: the step may grow */
#define MOVE_HOLD_FASTEST_TICKS 5000            /* run held longer than this: the step may grow again */
#define PANEL_SIZE_HEIGHT    1                  /* selector of panel_api_get_active_size */

/*
 * Move the custom PIP window down by one key step (Down key in menu state 0x107, reached through the handler
 * table). The step is the low nibble of app_state_record.move_step. A run starts at 8 pixels: it restarts when
 * more than MOVE_GAP_TICKS passed since the previous move or when the run id in the high nibble is not the Down
 * id. For the two hold times the code sets the byte again to the same 0x48, so the step does not grow here.
 *
 * pip_custom_y moves down by the step while it stays within panel height minus the window height (972, 756 or
 * 540 lines for pip_size 0, 1 or 2). Past that limit it moves by 1 as long as it is still below the limit.
 * The window is then recomputed (sys_user_resize_window_channel1) and the settings-changed request is made.
 */
void osd_move_pip_window_down(void)
{
    /* A pause between key events ends the run: back to the base step. */
    if (timer_ticks_since(osd_move_key_ticks) > MOVE_GAP_TICKS) {
        app_state_record.move_step = MOVE_STEP_BASE;
        osd_move_hold_ticks = timer_api_get_ticks16();
    }
    osd_move_key_ticks = timer_api_get_ticks16();
    /* A run begun by another key does not carry its step over. */
    if ((app_state_record.move_step >> 4) != MOVE_RUN_DOWN) {
        app_state_record.move_step = MOVE_STEP_BASE;
        osd_move_hold_ticks = timer_api_get_ticks16();
    }
    if (timer_ticks_since(osd_move_hold_ticks) > MOVE_HOLD_FAST_TICKS)
        if (timer_ticks_since(osd_move_key_ticks) <= MOVE_GAP_TICKS - 1)
            app_state_record.move_step = MOVE_STEP_BASE;
    if (timer_ticks_since(osd_move_hold_ticks) > MOVE_HOLD_FASTEST_TICKS)
        if (timer_ticks_since(osd_move_key_ticks) <= MOVE_GAP_TICKS - 1)
            app_state_record.move_step = MOVE_STEP_BASE;
    /* The window height depends on the PIP size: PIP_SIZE0_LINES, PIP_SIZE1_LINES, 540. */
    if (user_settings.pip_size == 0) {
        if (user_settings.pip_custom_y + (app_state_record.move_step & 0xf) <= panel_api_get_active_size(PANEL_SIZE_HEIGHT) - 972)
            user_settings.pip_custom_y += (app_state_record.move_step & 0xf);
        else if (user_settings.pip_custom_y < panel_api_get_active_size(PANEL_SIZE_HEIGHT) - 972)
            user_settings.pip_custom_y += 1;
    } else if (user_settings.pip_size == 1) {
        if (user_settings.pip_custom_y + (app_state_record.move_step & 0xf) <= panel_api_get_active_size(PANEL_SIZE_HEIGHT) - 756)
            user_settings.pip_custom_y += (app_state_record.move_step & 0xf);
        else if (user_settings.pip_custom_y < panel_api_get_active_size(PANEL_SIZE_HEIGHT) - 756)
            user_settings.pip_custom_y += 1;
    } else if (user_settings.pip_size == 2) {
        if (user_settings.pip_custom_y + (app_state_record.move_step & 0xf) <= panel_api_get_active_size(PANEL_SIZE_HEIGHT) - 540)
            user_settings.pip_custom_y += (app_state_record.move_step & 0xf);
        else if (user_settings.pip_custom_y < panel_api_get_active_size(PANEL_SIZE_HEIGHT) - 540)
            user_settings.pip_custom_y += 1;
    }
    sys_user_resize_window_channel1(0);
    osd_request_bits |= 2;
}
