/* ddc_raise_event3  (FUN_a0089f24)
 *
 * Set pending DDC/CI event flag 3.
 * Note: Taken by ddc_take_event3.
 * Name basis: proven - sets bit 3 of 0xA802AF99
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0089f24, flags -mcpu=v8 -O2 -g.
 */
extern unsigned char ddc_pending_events;

/* Set flag bit 3 (8) of ddc_pending_events. ddc_post_pending_event turns it into application event 0xC1. */
void ddc_raise_event3(void)
{
    ddc_pending_events = ddc_pending_events | 8;
}
