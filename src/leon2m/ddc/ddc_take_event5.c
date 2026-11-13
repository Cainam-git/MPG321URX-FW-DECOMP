/* ddc_take_event5  (FUN_a00886dc)
 *
 * Return and clear pending DDC/CI event flag 5.
 * Returns: 0 or 1
 * Note: Flags in byte 0xA802AF99; ddc_post_pending_event posts them as events 0xC0..0xC6.
 * Name basis: proven - polled by ddc_post_pending_event, which posts event type 0xC0 = DDCCiEvent in
 *   APPActionDispatcher
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00886dc, flags -mcpu=v8 -O2 -g.
 * Source form: the shifted flag is held in an int local before the store and masked with 1 on return.
 */
extern unsigned char ddc_pending_events;

/* Flag bit 5 of ddc_pending_events (DDC_EVENT_POWER_OFF): take it. Returns 1 if it was set, and clears it. */
unsigned int ddc_take_event5(void)
{
    int flag;

    flag = ddc_pending_events >> 5;
    ddc_pending_events = ddc_pending_events & 0xdf;
    return flag & 1;
}
