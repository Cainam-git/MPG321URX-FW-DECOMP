/* osd_set_event_flag  (FUN_a0088714)
 *
 * Set byte 0xA8024028 to 2.
 * Note: Called when a menu event maps to an action up to 3.
 * Name basis: descriptive - code only; caller osd_check_event_action
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0088714, flags -mcpu=v8 -O2 -g.
 */

extern unsigned char ddc_new_control_value;

/* Set ddc_new_control_value to 2. Called only by osd_check_event_action. */
void osd_set_event_flag(void)
{
  ddc_new_control_value = 2;
}
