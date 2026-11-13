/* sys_vcp_rewrite_field_b  (FUN_a00d42e0)
 *
 * Write position field 0x0B of a channel back unchanged.
 * Name basis: descriptive - get, then set with apply; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d42e0 @ 0xa00d42e0, flags -mcpu=v8 -O2 -g (section default).
 * channel = ch & 0xff; calls sys_api_set_channel_position_field(channel, 0xb, input_api_get_timing_field(channel, 0xb)
 * & 0xffff, 1). Both callees are declared with empty parameter lists. Nothing calls it.
 */
extern int input_api_get_timing_field();
extern int sys_api_set_channel_position_field();

#define POSITION_FIELD_B       0x0b

/* Read field 0x0B of channel ch and write the same value back, with the apply flag 1. Nothing calls it. */
void sys_vcp_rewrite_field_b(unsigned int ch)
{
  unsigned short value;

  ch = ch & 0xff;
  value = input_api_get_timing_field(ch, POSITION_FIELD_B);
  sys_api_set_channel_position_field(ch, POSITION_FIELD_B, value & 0xffff, 1);
}
