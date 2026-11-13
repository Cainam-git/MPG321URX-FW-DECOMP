/* ddc_raise_event1  (FUN_a0089f4c)
 *
 * Set pending DDC/CI event flag 1.
 * Note: Taken by ddc_take_event1.
 * Name basis: proven - sets bit 1 of 0xA802AF99
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0089f4c, flags -mcpu=v8 -O2 -g.
 */
extern unsigned char ddc_pending_events;

/* Set flag bit 1 (2) of ddc_pending_events. ddc_post_pending_event turns it into application event 0xC2. */
void ddc_raise_event1(void)
{
    ddc_pending_events = ddc_pending_events | 2;
}
