/* osd_decrease_alarm_minutes_units  (FUN_a009e21c)
 *
 * Step the alarm timer's minutes units digit down by one (up key)
 * Note: Forwards to osd_step_alarm_digit(1, 0); digits wrap, a time of 00:00 becomes 00:01.
 * Name basis: derived - handler table 0xA802422C: up on state 0xC6; osd_step_alarm_digit steps settings +0x198
 *   (minutes) / +0x19C (seconds)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009e21c @ 0xa009e21c, flags -mcpu=v8 -O2 -g.
 * Calls osd_step_alarm_digit(1, 0) as a tail call, like osd_increase_alarm_minutes_tens.
 */

#define ALARM_DIGIT_MINUTES_UNITS   1   /* digit selector of osd_step_alarm_digit: 0 minutes tens, 1 minutes units */
#define ALARM_STEP_DOWN             0   /* direction of osd_step_alarm_digit: 0 down, 1 up */

extern void osd_step_alarm_digit(unsigned char, unsigned char);

/*
 * Up key on the minutes units digit of the Alarm Clock time editor (menu state 0xC6): step that digit down.
 */
void osd_decrease_alarm_minutes_units(void)
{
    osd_step_alarm_digit(ALARM_DIGIT_MINUTES_UNITS, ALARM_STEP_DOWN);
}
