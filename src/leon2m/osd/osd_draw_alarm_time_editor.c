/* osd_draw_alarm_time_editor  (FUN_a00b6290)
 *
 * Draw the alarm timer being edited as mm:ss digits.
 *   draw: mode
 * Note: Timer = settings +0x198 / +0x19C entry of +0x1A3.
 * Name basis: derived - called by osd_open_alarm_time_editor and the alarm digit handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b6290 @ 0xa00b6290, flags -mcpu=v8 -O3 -g.
 * Source form: the colon is written by a one-pass loop whose row is an unsigned int local passed as
 * (unsigned char) (the firmware masks it with 0xff, not 0xfe); the frame loop builds the glyph in a local
 * (j != 0, then + 0xa4).
 */
struct user_settings_record {
    unsigned char pad[0x198];
    unsigned char alarm_minutes[4];         /* +0x198 */
    unsigned char alarm_seconds[4];         /* +0x19C */
    unsigned char pad2[0x1a3 - 0x1a0];
    unsigned char alarm_cursor_row;         /* +0x1A3: timer being edited, 0..3 */
};
extern struct user_settings_record user_settings;
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern void osd_api_write_reg_cc(unsigned short value, unsigned char layer);

#define PLANE_0              0
#define PLANE_1              1
#define MENU_LAYER_MAIN      0
#define ALARM_LIST_FIRST_TIMER_ROW 2    /* the timers are choices 2..5 of the Alarm Clock list (0 is Location, 1 OFF) */
#define ALARM_MINUTES_COLUMN 0x2a       /* tens at 0x2A, units at 0x2B */
#define ALARM_COLON_COLUMN   0x2c
#define ALARM_SECONDS_COLUMN 0x2d       /* tens at 0x2D, units at 0x2E */
#define ALARM_FIELD_CELLS    8          /* cells cleared in the digit row (columns 0x2A..0x31) */
#define ALARM_DIGIT_GLYPH_BASE 2        /* glyph of digit d is d + 2 */
#define ALARM_COLON_GLYPH    0xc
#define ALARM_FRAME_TOP_GLYPH 0xa4      /* glyph above the digit pair; the one below is 0xA5 */
#define CELL_ALARM_FRAME     0xb69a
#define CELL_ALARM_DIGITS    0x746      /* value written to registers 0xCC/0xCD before the digits and colon */

/* Draw the alarm timer that is being edited as mm:ss in the Alarm Clock time list. The timer is
 * user_settings byte +0x1A3 (0..3); its minutes and seconds are alarm_minutes[] and alarm_seconds[]. It is
 * shown on list row timer + 2, which is screen row 2 * (timer + 2) + 6.
 *   draw: non-zero first clears the 8 cells of the digit row and draws the frame cells (glyphs 0xA4 and 0xA5
 *         on the rows above and below) around the minutes pair (column 0x2A) and the seconds pair (column 0x2D).
 * Then the four digits (glyph = digit + 2) and the colon (glyph 0xC at column 0x2C) are written. Called by
 * osd_open_alarm_time_editor and the alarm digit handlers. */
void osd_draw_alarm_time_editor(unsigned char draw)
{
    unsigned char choice_row = user_settings.alarm_cursor_row + ALARM_LIST_FIRST_TIMER_ROW;
    unsigned char i, j;
    unsigned int row;

    if (draw) {
        for (i = 0; i < ALARM_FIELD_CELLS; i++)
            osd_api_fill_cell_bytes(PLANE_0, i + ALARM_MINUTES_COLUMN, choice_row * 2 + 6, 1, 0, 0);
        for (j = 0; j <= 1; j++) {
            unsigned char glyph = j != 0;

            glyph += ALARM_FRAME_TOP_GLYPH;

            osd_api_fill_cells(ALARM_MINUTES_COLUMN, (j + choice_row) * 2 + 5, 2, CELL_ALARM_FRAME, 0);
            osd_api_fill_cell_bytes(PLANE_0, ALARM_MINUTES_COLUMN, (j + choice_row) * 2 + 5, 2, glyph, 0);
            osd_api_fill_cells(ALARM_SECONDS_COLUMN, (j + choice_row) * 2 + 5, 2, CELL_ALARM_FRAME, 0);
            osd_api_fill_cell_bytes(PLANE_0, ALARM_SECONDS_COLUMN, (j + choice_row) * 2 + 5, 2, glyph, 0);
        }
    }
    osd_api_fill_cell_bytes(PLANE_0, ALARM_MINUTES_COLUMN, choice_row * 2 + 6, 1, user_settings.alarm_minutes[user_settings.alarm_cursor_row] / 10 + ALARM_DIGIT_GLYPH_BASE, 0);
    osd_api_fill_cell_bytes(PLANE_0, ALARM_MINUTES_COLUMN + 1, choice_row * 2 + 6, 1, user_settings.alarm_minutes[user_settings.alarm_cursor_row] % 10 + ALARM_DIGIT_GLYPH_BASE, 0);
    osd_api_write_reg_cc(CELL_ALARM_DIGITS, 0);
    row = choice_row * 2 + 6;
    for (i = 0; i < 1; i++)
        osd_api_fill_cell_bytes(PLANE_1, i + ALARM_COLON_COLUMN, (unsigned char)row, 1, ALARM_COLON_GLYPH, 0);
    osd_api_fill_cell_bytes(PLANE_0, ALARM_SECONDS_COLUMN, choice_row * 2 + 6, 1, user_settings.alarm_seconds[user_settings.alarm_cursor_row] / 10 + ALARM_DIGIT_GLYPH_BASE, 0);
    osd_api_fill_cell_bytes(PLANE_0, ALARM_SECONDS_COLUMN + 1, choice_row * 2 + 6, 1, user_settings.alarm_seconds[user_settings.alarm_cursor_row] % 10 + ALARM_DIGIT_GLYPH_BASE, 0);
}
