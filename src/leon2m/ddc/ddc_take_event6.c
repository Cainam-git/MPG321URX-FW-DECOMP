/* ddc_take_event6  (FUN_a00886f8)
 *
 * Return and clear pending DDC/CI event flag 6.
 * Returns: 0 or 1
 * Note: Flags in byte 0xA802AF99; ddc_post_pending_event posts them as events 0xC0..0xC6.
 * Name basis: proven - polled by ddc_post_pending_event, which posts event type 0xC0 = DDCCiEvent in
 *   APPActionDispatcher
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00886f8, flags -mcpu=v8 -O2 -g.
 * Source form: the shifted flag is held in an int local before the store and masked with 1 on return.
 */
extern unsigned char ddc_pending_events;

/* Flag bit 6 of ddc_pending_events (DDC_EVENT_POWER_SAVING): take it. Returns 1 if it was set, and clears it. */
int ddc_take_event6(void)
{
    int flag;

    flag = ddc_pending_events >> 6;
    ddc_pending_events = ddc_pending_events & 0xbf;
    return flag & 1;
}
