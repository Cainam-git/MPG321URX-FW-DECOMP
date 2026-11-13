/* osd_draw_alarm_clock_choices  (FUN_a00ac388)
 *
 * Draw the Alarm Clock choices: OFF, the four timers (mm : ss) and Location.
 *   mode: draw mode
 * Note: Timer times = settings +0x198 (minutes) / +0x19C (seconds); current = +0x1A0.
 * Name basis: proven - format 'n%d%d : %d%d'; texts 0x193248 OFF/ON, 0x18E9F8 'Location'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ac388 @ 0xa00ac388-0xa00ac718 (912 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on: the format string appears as the symbol s_001981b0 (a literal in
 * both places); r is assigned in both arms of 'if (n <= 6)'; the length scan runs up to 15 in an unsigned char.
 */
/* Texts are word tables with 29 languages per entry (see osd_get_oled_care_text). */
#define LANGUAGE_COUNT 29

/* Alarm Clock rows: Location at row 6, OFF at row 8, the four timers at rows 10, 12, 14, 16. */
#define ALARM_ROW_LOCATION 6
#define ALARM_ROW_OFF      8
#define ALARM_ROW_TIMER(n) ((n) * 2 + 10)  /* timer n = 0..3 */
#define ALARM_COLUMN       0x2a            /* text column of all rows */

/* Settings record (user_settings): the fields used here. */
struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;                 /* +8 */
    unsigned char pad09[0x198 - 9];
    unsigned char alarm_minutes[4];         /* +0x198, one per timer */
    unsigned char alarm_seconds[4];         /* +0x19c, one per timer */
    unsigned char alarm_clock;              /* +0x1a0: 0 = OFF, 1..4 = the timer in use */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_location_texts[];
extern unsigned int osd_off_on_texts[];
extern void sprintf(unsigned char *, const char *, ...);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, int, unsigned short, int, unsigned int, int);

/* Draw the choices of the Alarm Clock list: Location, OFF and the four timers, each timer shown as
 * "mm : ss" built from its minutes and seconds bytes ("n%d%d : %d%d": tens and units of each).
 * The text buffer is a menu text: byte 0 holds the length, so the first character of the formatted
 * string is overwritten with the length of the rest.
 *   mode != 0: draw everything (the three fixed texts, all four timers, the mark on the chosen row);
 *              the row of the chosen timer is first cleared over 10 cells.
 *   mode == 0: redraw only the chosen timer (the row at alarm_clock * 3 + 10 is cleared over 11
 *              cells, then the timer text is drawn). */
void osd_draw_alarm_clock_choices(unsigned char mode)
{
    unsigned char buf[16];
    unsigned char i, k, j, n, r;

    if (mode != 0) {
        osd_api_set_glyph_write_address(0x111, 0);
        osd_api_set_text_mode(0, 0);
        osd_draw_text(0, ALARM_COLUMN, ALARM_ROW_LOCATION, 1, osd_get_text(osd_location_texts, user_settings.language + 0x91), 0);
        for (i = 1; i <= 1; i++)
            osd_draw_text(0, ALARM_COLUMN, i * 2 + 6, 1, osd_get_text(osd_off_on_texts, i * LANGUAGE_COUNT + user_settings.language - LANGUAGE_COUNT), 0);
        for (i = 0; i <= 3; i++) {
            sprintf(buf, "n%d%d : %d%d", user_settings.alarm_minutes[i] / 10, user_settings.alarm_minutes[i] % 10,
                         user_settings.alarm_seconds[i] / 10, user_settings.alarm_seconds[i] % 10);
            /* Find the string end, then store length - 1 in byte 0. */
            for (k = 0; k <= 0xe; k++)
                if (buf[k] == 0)
                    break;
            buf[0] = k - 1;
            if (i == user_settings.alarm_clock - 1)
                osd_api_fill_cell_bytes(0, ALARM_COLUMN, ALARM_ROW_TIMER(i), 10, 0, 0);
            osd_draw_text(0, ALARM_COLUMN, ALARM_ROW_TIMER(i), 1, (unsigned int)buf, 0);
        }
        /* Mark the chosen row: OFF (alarm_clock 0) is row 8, timer t is row 8 + 2 * t. */
        n = user_settings.alarm_clock + 1;
        if (n <= 6)
            r = n * 2 + 6;
        else
            r = n * 2 - 8;
        osd_api_fill_cell_bytes(0, 0x28, r, 1, 0xf, 0);
        osd_api_fill_cell_bytes(0, 0x29, r, 1, 0x10, 0);
    } else {
        osd_api_set_glyph_write_address(0x139, 0);
        osd_api_set_text_mode(0, 0);
        osd_api_fill_cell_bytes(0, ALARM_COLUMN, user_settings.alarm_clock * 3 + 10, 0xb, 0, 0);
        j = user_settings.alarm_clock - 1;
        sprintf(buf, "n%d%d : %d%d", user_settings.alarm_minutes[j] / 10, user_settings.alarm_minutes[j] % 10,
                     user_settings.alarm_seconds[j] / 10, user_settings.alarm_seconds[j] % 10);
        for (k = 0; k <= 0xe; k++)
            if (buf[k] == 0)
                break;
        buf[0] = k - 1;
        osd_draw_text(0, ALARM_COLUMN, ALARM_ROW_TIMER(j), 1, (unsigned int)buf, 0);
    }
}
