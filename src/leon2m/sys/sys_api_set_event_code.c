/* sys_api_set_event_code  (FUN_a0143fc4)
 *
 * Store an event code and clear its pending flag.
 * Name basis: descriptive - byte at 0xA802A47D and bit 7 of 0xA802D991
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0143fc4, flags -mcpu=v8 -O2 -g.
 * The pending flag is a 1-bit bit-field (bit 7 of the byte at 0xA802D991); a plain &= 0x7f schedules
 * differently.
 */
extern unsigned char sys_event_code;
/* The byte at 0xA802D990 and the byte after it; bit 7 of the second one is the pending flag. */
struct event_flags { unsigned char byte_0x0; unsigned char pending : 1; unsigned char rest : 7; };
extern struct event_flags sys_event_code_byte;

/* Store code as the event code and clear the pending flag. */
void sys_api_set_event_code(unsigned char code)
{
    sys_event_code = code;
    sys_event_code_byte.pending = 0;
}
