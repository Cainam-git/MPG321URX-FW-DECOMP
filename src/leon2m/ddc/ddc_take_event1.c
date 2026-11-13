/* ddc_take_event1  (FUN_a008866c)
 *
 * Return and clear pending DDC/CI event flag 1.
 * Returns: 0 or 1
 * Note: Flags in byte 0xA802AF99; ddc_post_pending_event posts them as events 0xC0..0xC6.
 * Name basis: proven - polled by ddc_post_pending_event, which posts event type 0xC0 = DDCCiEvent in
 *   APPActionDispatcher
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008866c, flags -mcpu=v8 -O2 -g.
 * Source form: the shifted flag is held in an int local before the store and masked with 1 on return.
 */
extern unsigned char ddc_pending_events;

/* Flag bit 1 of ddc_pending_events: take it. Returns 1 if it was set, and clears it. Raised by ddc_raise_event1. */
int ddc_take_event1(void)
{
    int flag;

    flag = ddc_pending_events >> 1;
    ddc_pending_events = ddc_pending_events & 0xfd;
    return flag & 1;
}
