/* osd_decrease_alarm_seconds_units  (FUN_a009e27c)
 *
 * Step the alarm timer's seconds units digit down by one (up key)
 * Note: Calls osd_step_alarm_digit(3, 0); the digit wraps, and a result of 00:00 becomes 00:09.
 * Name basis: derived - handler table 0xA802422C: up on state 0xC8; osd_step_alarm_digit steps settings +0x198
 *   (minutes) / +0x19C (seconds)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009e27c, flags -mcpu=v8 -O2 -g.
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
 * Up key in the alarm time editor: step the seconds units digit down (0 wraps to 9).
 * A result of 00:00 is not kept (see osd_step_alarm_digit).
 */
void osd_decrease_alarm_seconds_units(void)
{
    osd_step_alarm_digit(ALARM_DIGIT_SECONDS_UNITS, ALARM_STEP_DOWN);
}
