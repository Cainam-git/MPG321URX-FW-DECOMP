/* ddc_raise_event0  (FUN_a0089f10)
 *
 * Set pending DDC/CI event flag 0.
 * Note: Taken by ddc_take_event0.
 * Name basis: proven - sets bit 0 of 0xA802AF99; callers are DDC/CI command handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0089f10, flags -mcpu=v8 -O2 -g.
 */
extern unsigned char ddc_pending_events;

/* Set flag bit 0 (1) of ddc_pending_events. ddc_post_pending_event turns it into application event 0xC0. */
void ddc_raise_event0(void)
{
    ddc_pending_events = ddc_pending_events | 1;
}
