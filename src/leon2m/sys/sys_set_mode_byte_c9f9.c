/* sys_set_mode_byte_c9f9  (FUN_a01243b0)
 *
 * Store the mode byte at 0xA802C9F9.
 * Name basis: descriptive - tested by the cable detection
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01243b0 @ 0xa01243b0 (-mcpu=v8 -O2 -g)
 */
extern unsigned char sys_cable_mode_byte;

/* Set sys_cable_mode_byte. input_is_port_cable_present reads it: while it is 0, the second pin of a type-1 port entry decides. */
void sys_set_mode_byte_c9f9(unsigned char mode)
{
  sys_cable_mode_byte = mode;
}
