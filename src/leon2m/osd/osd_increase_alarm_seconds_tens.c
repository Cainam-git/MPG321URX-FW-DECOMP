/* osd_increase_alarm_seconds_tens  (FUN_a009e264)
 *
 * Step the alarm timer's seconds tens digit up by one (down key)
 * Note: Forwards to osd_step_alarm_digit(2, 1); digits wrap, a time of 00:00 becomes 00:01.
 * Name basis: derived - handler table 0xA802422C: down on state 0xC7; osd_step_alarm_digit steps settings
 *   +0x198 (minutes) / +0x19C (seconds)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009e264, flags -mcpu=v8 -O2 -g.
 * Source form: the call is a tail call, so the callee returns straight to this routine's caller. The last word
 * is the nop the compiler places behind such a call sequence.
 */
extern void osd_step_alarm_digit(unsigned char, unsigned char);

/* Digit argument of osd_step_alarm_digit: 0 and 1 are the tens and units digit of the value at settings +0x198
   (minutes), 2 and 3 those of the value at +0x19C (seconds). */
enum {
    ALARM_DIGIT_MINUTES_TENS  = 0,
    ALARM_DIGIT_MINUTES_UNITS = 1,
    ALARM_DIGIT_SECONDS_TENS  = 2,
    ALARM_DIGIT_SECONDS_UNITS = 3
};

/* Direction argument of osd_step_alarm_digit. */
#define ALARM_STEP_DOWN 0
#define ALARM_STEP_UP   1

/*
 * Down key in the alarm time editor: step the seconds tens digit up (5 wraps to 0).
 * A result of 00:00 is not kept (see osd_step_alarm_digit).
 */
void osd_increase_alarm_seconds_tens(void)
{
    osd_step_alarm_digit(ALARM_DIGIT_SECONDS_TENS, ALARM_STEP_UP);
}
