/* osd_increase_alarm_minutes_tens  (FUN_a009e204)
 *
 * Step the alarm timer's minutes tens digit up by one (down key)
 * Note: Forwards to osd_step_alarm_digit(0, 1); digits wrap, a time of 00:00 becomes 00:01.
 * Name basis: derived - handler table 0xA802422C: down on state 0xC5; osd_step_alarm_digit steps settings
 *   +0x198 (minutes) / +0x19C (seconds)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009e204 @ 0xa009e204, flags -mcpu=v8 -O2 -g.
 * Calls osd_step_alarm_digit(0, 1) as a tail call. The caller's return address is handed on, so the callee returns
 * straight to this routine's caller. The last word is the nop the compiler places behind such a call sequence.
 * Its address is stored at file offset 0xed4ac.
 */

#define ALARM_DIGIT_MINUTES_TENS    0   /* digit selector of osd_step_alarm_digit: 0 minutes tens, 1 minutes units */
#define ALARM_STEP_UP               1   /* direction of osd_step_alarm_digit: 0 down, 1 up */

extern void osd_step_alarm_digit(unsigned char, unsigned char);

/*
 * Down key on the minutes tens digit of the Alarm Clock time editor (menu state 0xC5): step that digit up.
 */
void osd_increase_alarm_minutes_tens(void)
{
    osd_step_alarm_digit(ALARM_DIGIT_MINUTES_TENS, ALARM_STEP_UP);
}
