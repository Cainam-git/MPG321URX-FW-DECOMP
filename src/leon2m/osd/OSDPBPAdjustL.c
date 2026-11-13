/* OSDPBPAdjustL  (FUN_a00a0ff0)
 *
 * Move the custom PBP split left one step of 8 and redraw (left key)
 * Note: Split position 0xA802D02A, range 0x3C0..0xB40.
 * Name basis: proven - handler table 0xA802422C: left on state 0x109; prints 'OSDPBPAdjustL %d, %d' (original
 *   name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a0ff0, flags -mcpu=v8 -O3 -g. No direct callers (reached through the key handler table).
 * Source form: the right edge argument is cast to unsigned short; split_x and split_lines are read again after
 * the call.
 */
/* The fields of the application state record used here. */
struct app_state_record_split {
    unsigned char pad[0x36];
    unsigned short split_x, split_lines;        /* +0x36 / +0x38: the split line of the editor (x, height) */
};
extern struct app_state_record_split app_state_record;
extern int dbg_printf();
extern void osd_api_set_window_rect(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

#define SPLIT_WINDOW        6           /* menu window that shows the split line */
#define SPLIT_X_MIN         0x3c0
#define SPLIT_X_MAX         0xb40
#define SPLIT_STEP          8
#define SPLIT_LINE_WIDTH    4           /* the window is drawn from split_x to split_x + 4 */

/*
 * Left key in the custom PBP split editor (menu state 0x109): split_x is lowered by 8 down to 0x3C0.
 * Then the split line window is redrawn from the new value and the two values are printed.
 */
void OSDPBPAdjustL(void)
{
    if (app_state_record.split_x > SPLIT_X_MIN)
        app_state_record.split_x -= SPLIT_STEP;
    else
        app_state_record.split_x = SPLIT_X_MIN;
    osd_api_set_window_rect(SPLIT_WINDOW, app_state_record.split_x, 0, (unsigned short)(app_state_record.split_x + SPLIT_LINE_WIDTH), app_state_record.split_lines, 0);
    dbg_printf("OSDPBPAdjustL %d, %d\r\n", app_state_record.split_x, app_state_record.split_lines);
}
