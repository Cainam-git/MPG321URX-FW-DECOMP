/* OSDPBPAdjustD  (FUN_a00a0f6c)
 *
 * Raise the custom PBP split by 8 lines, not above the limit 0x870, and redraw (down key)
 * Note: split_lines below 0x870 is raised by 8, otherwise set to 0x870; only while the split editor byte is
 *   above 2.
 * Name basis: proven - handler table 0xA802422C: down on state 0x109; prints 'OSDPBPAdjustD %d, %d' (original
 *   name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a0f6c, flags -mcpu=v8 -O3 -g. No direct callers (reached through the key handler table).
 * Source form: the right edge argument is cast to unsigned short; split_lines and split_x are read again after
 * each call.
 */
/* The fields of the application state record used here. */
struct app_state_record_split {
    unsigned char pad[0x34];
    unsigned char split_editor;                 /* +0x34 */
    unsigned char pad35;
    unsigned short split_x, split_lines;        /* +0x36 / +0x38: the split line of the editor (x, height) */
};
extern struct app_state_record_split app_state_record;
extern int dbg_printf();
extern void osd_api_set_window_rect(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

#define SPLIT_WINDOW        6           /* menu window that shows the split line */
#define SPLIT_LINES_LIMIT   0x870       /* the value split_lines is held at */
#define SPLIT_STEP          8
#define SPLIT_LINE_WIDTH    4           /* the window is drawn from split_x to split_x + 4 */

/*
 * Down key in the custom PBP split editor (menu state 0x109): a value below 0x870 is raised by 8; any other value
 * is set to 0x870.
 * Then the split line window is redrawn from the new value and the two values are printed.
 *
 * Only acts when the split editor byte at +0x34 is above 2.
 */
void OSDPBPAdjustD(void)
{
    if (app_state_record.split_editor > 2) {
        if (app_state_record.split_lines < SPLIT_LINES_LIMIT)
            app_state_record.split_lines += SPLIT_STEP;
        else
            app_state_record.split_lines = SPLIT_LINES_LIMIT;
        osd_api_set_window_rect(SPLIT_WINDOW, 0, app_state_record.split_lines, app_state_record.split_x, (unsigned short)(app_state_record.split_lines + SPLIT_LINE_WIDTH), 0);
        dbg_printf("OSDPBPAdjustD %d, %d\r\n", app_state_record.split_x, app_state_record.split_lines);
    }
}
