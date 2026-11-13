/* ddc_take_event3  (FUN_a0088688)
 *
 * Return and clear pending DDC/CI event flag 3.
 * Returns: 0 or 1
 * Note: Flags in byte 0xA802AF99; ddc_post_pending_event posts them as events 0xC0..0xC6.
 * Name basis: proven - polled by ddc_post_pending_event, which posts event type 0xC0 = DDCCiEvent in
 *   APPActionDispatcher
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0088688, flags -mcpu=v8 -O2 -g.
 * Source form: the byte is copied to an unsigned int local, the shift is formed before the store.
 */
extern unsigned char ddc_pending_events;

/* Flag bit 3 of ddc_pending_events: take it. Returns 1 if it was set, and clears it. Raised by ddc_raise_event3. */
unsigned int ddc_take_event3(void)
{
    unsigned int flags = ddc_pending_events;
    unsigned int shifted = flags >> 3;

    ddc_pending_events = flags & 0xf7;
    return shifted & 1;
}
