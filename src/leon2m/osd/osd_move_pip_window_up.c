/* osd_move_pip_window_up  (FUN_a0093f90)
 *
 * Move the custom PIP window up by a step of 8.
 * Note: Lowers settings halfword +0x56 (pip_custom_y); the step does not grow.
 * Name basis: derived - handler table 0xA802422C: up on state 0x107
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0093f90 @ 0xa0093f90-0xa0094108 (94 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Source forms the exact build depends on:
 *  - the move_step byte is a union of a plain byte and two 4-bit bit-fields; the step is the low bit-field read
 *    into an unsigned short local;
 *  - the decrement is written out once for each of the values 0, 1 and 2 of pip_size (GCC merges the copies into
 *    one block behind a compare chain; an || of the three tests becomes a range test).
 */
#define MOVE_RUN_UP          3                  /* high nibble of move_step while an Up run is going */
#define MOVE_STEP_BASE       0x38               /* Up run id 3, step 8 pixels */
#define MOVE_GAP_TICKS       100                /* more ticks than this since the last move: a new run starts */
#define MOVE_HOLD_FAST_TICKS 2000               /* run held longer than this (the code resets the step; see the routine comment) */
#define MOVE_HOLD_FASTEST_TICKS 5000
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit of osd_request_bits: event 0x80 */

/* The part of the application state record used here (app_state_record, 0xA802CFF4). */
struct app_state_record {
    unsigned char pad[8];
    union {                                     /* +8 */
        unsigned char byte;
        struct { unsigned char run_id:4, step:4; } nibbles;    /* high nibble = move run id, low nibble = step in pixels */
    } move_step;
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

/*
 * Move the custom PIP window up by one key step (Up key in menu state 0x107, reached through the handler
 * table). The step is the low nibble of app_state_record.move_step. A run starts at 8 pixels: it restarts when
 * more than MOVE_GAP_TICKS passed since the previous move or when the run id in the high nibble is not the Up
 * id. For the two hold times the code sets the byte again to the same 0x38, so the step does not grow here.
 *
 * pip_custom_y moves up by the step when it is at least the step; below that it is set to 0. The window is then
 * recomputed (sys_user_resize_window_channel1) and the settings-changed request is made.
 */
void osd_move_pip_window_up(void)
{
    unsigned short step;

    /* A pause between key events ends the run: back to the base step. */
    if (timer_ticks_since(osd_move_key_ticks) > MOVE_GAP_TICKS) {
        app_state_record.move_step.byte = MOVE_STEP_BASE;
        osd_move_hold_ticks = timer_api_get_ticks16();
    }
    osd_move_key_ticks = timer_api_get_ticks16();
    /* A run begun by another key does not carry its step over. */
    if ((app_state_record.move_step.byte >> 4) != MOVE_RUN_UP) {
        app_state_record.move_step.byte = MOVE_STEP_BASE;
        osd_move_hold_ticks = timer_api_get_ticks16();
    }
    if (timer_ticks_since(osd_move_hold_ticks) > MOVE_HOLD_FAST_TICKS)
        if (timer_ticks_since(osd_move_key_ticks) <= MOVE_GAP_TICKS - 1)
            app_state_record.move_step.byte = MOVE_STEP_BASE;
    if (timer_ticks_since(osd_move_hold_ticks) > MOVE_HOLD_FASTEST_TICKS)
        if (timer_ticks_since(osd_move_key_ticks) <= MOVE_GAP_TICKS - 1)
            app_state_record.move_step.byte = MOVE_STEP_BASE;
    /* The same move for each of the three PIP sizes 0, 1 and 2 (no other value moves the window). */
    if (user_settings.pip_size == 0) {
        step = app_state_record.move_step.nibbles.step;
        if (step <= user_settings.pip_custom_y)
            user_settings.pip_custom_y -= step;
        else
            user_settings.pip_custom_y = 0;
    } else if (user_settings.pip_size == 1) {
        step = app_state_record.move_step.nibbles.step;
        if (step <= user_settings.pip_custom_y)
            user_settings.pip_custom_y -= step;
        else
            user_settings.pip_custom_y = 0;
    } else if (user_settings.pip_size == 2) {
        step = app_state_record.move_step.nibbles.step;
        if (step <= user_settings.pip_custom_y)
            user_settings.pip_custom_y -= step;
        else
            user_settings.pip_custom_y = 0;
    }
    sys_user_resize_window_channel1(0);
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
