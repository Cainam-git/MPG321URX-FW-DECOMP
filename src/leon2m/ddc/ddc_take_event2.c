/* ddc_take_event2  (FUN_a00886a4)
 *
 * Return and clear pending DDC/CI event flag 2.
 * Returns: 0 or 1
 * Note: Flags in byte 0xA802AF99; ddc_post_pending_event posts them as events 0xC0..0xC6.
 * Name basis: proven - polled by ddc_post_pending_event, which posts event type 0xC0 = DDCCiEvent in
 *   APPActionDispatcher
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00886a4, flags -mcpu=v8 -O2 -g.
 * Source form: the shifted flag is held in an int local before the store and masked with 1 on return.
 */
extern unsigned char ddc_pending_events;

/* Flag bit 2 of ddc_pending_events: take it. Returns 1 if it was set, and clears it. Raised by ddc_raise_event2. */
int ddc_take_event2(void)
{
    int flag;

    flag = ddc_pending_events >> 2;
    ddc_pending_events = ddc_pending_events & 0xfb;
    return flag & 1;
}
