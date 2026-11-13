/* osd_step_alarm_digit  (FUN_a00b65e4)
 *
 * Step one digit of the edited alarm time up or down and redraw it.
 *   digit: digit 0..3
 *   step_up: 1 up, 0 down
 * Note: Minutes digits wrap 0..9, seconds tens 0..5; 00:00 becomes 00:01 (or 00:09).
 * Name basis: proven - called by osd_increase|decrease_alarm_*; settings +0x198 / +0x19C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b65e4 @ 0xa00b65e4-0xa00b6994 (236 words), flags -mcpu=v8 -O3 -g. Called by osd_decrease_alarm_minutes_tens (and
 * the other increase / decrease alarm handlers).
 * Source form: every statement reads the entry through the record and the index again (no local copies); the
 * macros MINUTES and SECONDS expand to those reads.
 */
/* Fields of the settings record used here. */
struct user_settings_record {
    unsigned char pad[0x198];
    unsigned char alarm_minutes[4];    /* +0x198: two-digit decimal value per entry */
    unsigned char alarm_seconds[4];    /* +0x19C: two-digit decimal value per entry */
    unsigned char pad1a0[3];
    unsigned char alarm_entry;         /* +0x1A3: the entry of both tables being edited */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern void osd_draw_alarm_time_editor(unsigned char);

#define ALARM_DIGIT_MINUTES_TENS   0   /* digit selectors */
#define ALARM_DIGIT_MINUTES_UNITS  1
#define ALARM_DIGIT_SECONDS_TENS   2
#define ALARM_DIGIT_SECONDS_UNITS  3
#define OSD_REQUEST_SETTINGS_CHANGED 0x02    /* bit 1 of osd_request_bits */

#define MINUTES user_settings.alarm_minutes[user_settings.alarm_entry]
#define SECONDS user_settings.alarm_seconds[user_settings.alarm_entry]

/* Step one decimal digit of the alarm time being edited (entry alarm_entry of the minutes and seconds tables,
 * shown as mm:ss) and redraw the editor.
 *   digit:   0 tens of the minutes (0..9), 1 units of the minutes (0..9), 2 tens of the seconds (0..5),
 *            3 units of the seconds (0..9); any other value changes nothing
 *   step_up: non-zero steps the digit up, 0 down; the digit wraps round at both ends and the other digit of
 *            the pair is kept
 * An alarm time of 00:00 is not allowed: when both values are 0 after the step, the seconds are set to 1
 * (to 9 when the digit is the seconds units and was stepped down). Called by the increase and decrease
 * handlers of the alarm time editor. */
void osd_step_alarm_digit(unsigned char digit, unsigned char step_up)
{
    if (digit == ALARM_DIGIT_MINUTES_TENS) {
        if (step_up)
            MINUTES = (MINUTES / 10 + 1) % 10 * 10 + MINUTES % 10;
        else
            MINUTES = (MINUTES / 10 + 9) % 10 * 10 + MINUTES % 10;
        if (MINUTES == 0 && SECONDS == 0)
            SECONDS = 1;
    } else if (digit == ALARM_DIGIT_MINUTES_UNITS) {
        if (step_up)
            MINUTES = MINUTES / 10 * 10 + (MINUTES % 10 + 1) % 10;
        else
            MINUTES = MINUTES / 10 * 10 + (MINUTES % 10 + 9) % 10;
        if (MINUTES == 0 && SECONDS == 0)
            SECONDS = 1;
    } else if (digit == ALARM_DIGIT_SECONDS_TENS) {
        if (step_up)
            SECONDS = (SECONDS / 10 + 1) % 6 * 10 + SECONDS % 10;
        else
            SECONDS = (SECONDS / 10 + 5) % 6 * 10 + SECONDS % 10;
        if (MINUTES == 0 && SECONDS == 0)
            SECONDS = 1;
    } else if (digit == ALARM_DIGIT_SECONDS_UNITS) {
        if (step_up)
            SECONDS = SECONDS / 10 * 10 + (SECONDS % 10 + 1) % 10;
        else
            SECONDS = SECONDS / 10 * 10 + (SECONDS % 10 + 9) % 10;
        if (MINUTES == 0 && SECONDS == 0) {
            if (step_up)
                SECONDS = 1;
            else
                SECONDS = 9;
        }
    }
    osd_draw_alarm_time_editor(0);
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
