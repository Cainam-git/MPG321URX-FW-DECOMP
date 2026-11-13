/* sys_vcp_rewrite_field_4  (FUN_a00d4188)
 *
 * Write position field 4 of a channel back unchanged.
 * Name basis: descriptive - get, then set with apply; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d4188 @ 0xa00d4188, flags -mcpu=v8 -O2 -g (section default).
 * channel = ch & 0xff; calls sys_api_set_channel_position_field(channel, 4, input_api_get_timing_field(channel, 4)
 * & 0xffff, 1). Both callees are declared with empty parameter lists. Nothing calls it.
 */
extern int input_api_get_timing_field();
extern int sys_api_set_channel_position_field();

#define POSITION_FIELD_4       4

/* Read field 4 of channel ch and write the same value back, with the apply flag 1. Nothing calls it. */
void sys_vcp_rewrite_field_4(unsigned int ch)
{
  unsigned short value;

  ch = ch & 0xff;
  value = input_api_get_timing_field(ch, POSITION_FIELD_4);
  sys_api_set_channel_position_field(ch, POSITION_FIELD_4, value & 0xffff, 1);
}
