/* osd_decrease_alarm_minutes_tens  (FUN_a009e1ec)
 *
 * Step the alarm timer's minutes tens digit down by one (up key)
 * Note: Forwards to osd_step_alarm_digit(0, 0); digits wrap, a time of 00:00 becomes 00:01.
 * Name basis: derived - handler table 0xA802422C: up on state 0xC5; osd_step_alarm_digit steps settings +0x198
 *   (minutes) / +0x19C (seconds)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009e1ec @ 0xa009e1ec, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: osd_step_alarm_digit is declared without a prototype and returns int, as the decompiler had it;
 * the second argument is written as the character constant '\0'.
 */

#define ALARM_DIGIT_MINUTES_TENS    0   /* digit selector of osd_step_alarm_digit: 0 minutes tens, 1 minutes units */
#define ALARM_STEP_DOWN             0   /* direction of osd_step_alarm_digit: 0 down, 1 up */

extern int osd_step_alarm_digit();

/*
 * Up key on the minutes tens digit of the Alarm Clock time editor (menu state 0xC5): step that digit down.
 */
void osd_decrease_alarm_minutes_tens(void)

{
  osd_step_alarm_digit(ALARM_DIGIT_MINUTES_TENS, '\0');
  return;
}
