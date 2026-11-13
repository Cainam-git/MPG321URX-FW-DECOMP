/* osd_draw_alarm_digit_cursor  (FUN_a00b6514)
 *
 * Place the cursor window on the alarm time digit being edited.
 *   digit: digit 0..3
 * Note: Digit columns 0x2A, 0x2B, 0x2D, 0x2E.
 * Name basis: derived - called by osd_select_alarm_minutes_tens/units and _seconds_tens/units
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b6514 @ 0xa00b6514, flags -mcpu=v8 -O3 -g.
 * Source form: row and column are unsigned char locals; the +9 is added to the row before the multiplication
 * by 36 (the firmware adds 9, masks with 0xff, then multiplies).
 */
extern unsigned char user_settings_byte_0x1a3;   /* alarm_cursor_row: the timer being edited */
extern void osd_api_set_window_effect(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void osd_api_set_window_rect(unsigned int window, unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1, unsigned int unused);
extern void osd_api_set_window_enable(unsigned int window, unsigned int on, unsigned int unused);

#define ALARM_DIGIT_MINUTES_TENS  0
#define ALARM_DIGIT_MINUTES_UNITS 1
#define ALARM_DIGIT_SECONDS_TENS  2
#define ALARM_DIGIT_SECONDS_UNITS 3
#define ALARM_MINUTES_TENS_COLUMN 0x2a
#define ALARM_MINUTES_UNITS_COLUMN 0x2b
#define ALARM_SECONDS_TENS_COLUMN 0x2d
#define ALARM_SECONDS_UNITS_COLUMN 0x2e
#define CURSOR_WINDOW             0
#define CURSOR_EFFECT             0xc    /* sixth argument of osd_api_set_window_effect */
#define CELL_WIDTH                24     /* pixel width of a cell column */
#define CELL_HEIGHT               36     /* pixel height of a cell row */

/* Place the cursor window (window 0) over one digit of the alarm time being edited.
 *   digit: 0 minutes tens, 1 minutes units, 2 seconds tens, 3 seconds units (columns 0x2A, 0x2B, 0x2D, 0x2E).
 * The row comes from user_settings byte +0x1A3 (the timer being edited): row = timer * 2 + 9. The window is
 * switched off, its effect is set, its rectangle (one cell column wide, from row * 36 + 0x1A to row * 36 + 0x51
 * in pixels) is set, and the window is switched on. */
void osd_draw_alarm_digit_cursor(unsigned char digit)
{
    unsigned char row;
    unsigned char column;

    row = user_settings_byte_0x1a3 * 2 + 9;
    column = ALARM_MINUTES_TENS_COLUMN;
    if (digit == ALARM_DIGIT_MINUTES_UNITS) {
        column = ALARM_MINUTES_UNITS_COLUMN;
    } else if (digit == ALARM_DIGIT_SECONDS_TENS) {
        column = ALARM_SECONDS_TENS_COLUMN;
    } else if (digit == ALARM_DIGIT_SECONDS_UNITS) {
        column = ALARM_SECONDS_UNITS_COLUMN;
    }
    osd_api_set_window_enable(CURSOR_WINDOW, 0, 0);
    osd_api_set_window_effect(CURSOR_WINDOW, 0, 0, 0, 0, CURSOR_EFFECT, 0, 0, 0, 0, 0);
    osd_api_set_window_rect(CURSOR_WINDOW, column * CELL_WIDTH, row * CELL_HEIGHT + 0x1a, column * CELL_WIDTH + 0x17, row * CELL_HEIGHT + 0x51, 0);
    osd_api_set_window_enable(CURSOR_WINDOW, 1, 0);
}
