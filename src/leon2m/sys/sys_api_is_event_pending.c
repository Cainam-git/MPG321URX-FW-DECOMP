/* sys_api_is_event_pending  (FUN_a0143fa8)
 *
 * Return the pending flag of the stored event.
 * Returns: 0 or 1
 * Name basis: descriptive - bit 7 of the byte at 0xA802D991; used by the event generator
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0143fa8 @ 0xa0143fa8 (-mcpu=v8 -O2 -g)
 * Source form: result type byte (unsigned char), plain shift right by 7.
 */
extern unsigned char sys_event_pending_byte;

/* Return bit 7 of the byte at 0xA802D991, the pending flag that sys_api_set_event_code clears. */
unsigned char sys_api_is_event_pending(void)

{
  return sys_event_pending_byte >> 7;
}
