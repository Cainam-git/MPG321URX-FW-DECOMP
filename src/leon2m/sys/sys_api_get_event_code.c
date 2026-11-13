/* sys_api_get_event_code  (FUN_a0143fb8)
 *
 * Return the stored event code.
 * Returns: code
 * Name basis: descriptive - byte at 0xA802A47D; used by the event generator
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0143fb8 @ 0xa0143fb8 (-mcpu=v8 -O2)
 * A leaf routine without a register window.
 */
extern unsigned char sys_event_code;

/* Return the event code stored by sys_api_set_event_code. */
unsigned char sys_api_get_event_code(void)

{
  return sys_event_code;
}
