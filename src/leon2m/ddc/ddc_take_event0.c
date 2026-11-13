/* ddc_take_event0  (FUN_a0088654)
 *
 * Return and clear pending DDC/CI event flag 0.
 * Returns: 0 or 1
 * Note: Flags in byte 0xA802AF99; ddc_post_pending_event posts them as events 0xC0..0xC6.
 * Name basis: proven - polled by ddc_post_pending_event, which posts event type 0xC0 = DDCCiEvent in
 *   APPActionDispatcher
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0088654, flags -mcpu=v8 -O2 -g.
 * Source form: the old byte value is copied to a local first and the cleared byte is stored before the return value
 * is formed.
 */
extern unsigned char ddc_pending_events;

/* Flag bit 0 of ddc_pending_events: take it. Returns 1 if it was set, and clears it. Raised by ddc_raise_event0. */
unsigned char ddc_take_event0(void)
{
    unsigned char flags;

    flags = ddc_pending_events;
    ddc_pending_events = ddc_pending_events & 0xfe;
    return flags & 1;
}
