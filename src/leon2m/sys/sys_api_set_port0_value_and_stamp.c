/* sys_api_set_port0_value_and_stamp  (FUN_a0148358)
 *
 * Store a 16-bit value for port 0 and note the time.
 * Name basis: descriptive - halfword of port record 0, then the tick stamp
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148358 @ 0xa0148358 (-mcpu=v8 -O2 -g)
 * Source form: input_stamp_port_time is declared int-returning with no prototype; explicit return at
 * the end.
 */
extern void input_set_port0_value(unsigned short value);
extern int input_stamp_port_time();

/* Call input_set_port0_value(value), then input_stamp_port_time(0, stamp_arg): port 0 and the argument
 * passed on. */
void sys_api_set_port0_value_and_stamp(unsigned short value, unsigned int stamp_arg)

{
  input_set_port0_value(value);
  input_stamp_port_time(0, stamp_arg);
  return;
}
