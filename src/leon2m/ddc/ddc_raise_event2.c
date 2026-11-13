/* ddc_raise_event2  (FUN_a0089f38)
 *
 * Set pending DDC/CI event flag 2.
 * Note: Taken by ddc_take_event2.
 * Name basis: proven - sets bit 2 of 0xA802AF99
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0089f38, flags -mcpu=v8 -O2 -g.
 */
extern unsigned char ddc_pending_events;

/* Set flag bit 2 (4) of ddc_pending_events. ddc_post_pending_event turns it into application event 0xC3. */
void ddc_raise_event2(void)
{
    ddc_pending_events = ddc_pending_events | 4;
}
