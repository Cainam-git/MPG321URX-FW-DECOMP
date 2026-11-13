/* sys_vcp_set_field_b_percent  (FUN_a00d430c)
 *
 * Set position field 0x0B of the active channel from a percentage between its limits.
 * Name basis: descriptive - (100 - level) * (high - low) / 100 + low
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d430c @ 0xa00d430c, flags -mcpu=v8 -O3 -g.
 * Called by ddc_handle_request. Source form: that of sys_vcp_set_field_4_percent, with inverted = (100 - level) & 0xff in an
 * unsigned short local (the masked '100 - value' of the getter sys_vcp_get_field_b_percent). The last call is a tail call;
 * field 0xE is read twice.
 */
extern unsigned char input_api_find_channel_not_sync_mode5(void);
extern int input_api_get_timing_field(unsigned char, unsigned int);
extern void sys_api_set_channel_position_field(unsigned char, unsigned int, unsigned short, int);

#define POSITION_FIELD_B       0x0b     /* the field that is set */
#define POSITION_FIELD_B_HIGH  0x0d     /* the value of field 0xB at level 0 */
#define POSITION_FIELD_B_LOW   0x0e     /* the value of field 0xB at level 100 */
#define PERCENT_MAX            100

/*
 * Set field 0x0B of the channel found by input_api_find_channel_not_sync_mode5 from a percentage. The scale runs
 * backwards: with inverted = 100 - level (level limited to 100) the value is
 * inverted * (field 0xD - field 0xE) / 100 + field 0xE, so level 0 gives field 0xD and level 100 field 0xE.
 * Called by ddc_handle_request.
 */
void sys_vcp_set_field_b_percent(unsigned char level)
{
  unsigned char channel = input_api_find_channel_not_sync_mode5();
  int high, low;
  unsigned short inverted;

  if (level > PERCENT_MAX)
    level = PERCENT_MAX;
  inverted = (PERCENT_MAX - level) & 0xff;
  high = (unsigned short)input_api_get_timing_field(channel, POSITION_FIELD_B_HIGH);
  low = (unsigned short)input_api_get_timing_field(channel, POSITION_FIELD_B_LOW);
  sys_api_set_channel_position_field(channel, POSITION_FIELD_B, inverted * (high - low) / PERCENT_MAX + input_api_get_timing_field(channel, POSITION_FIELD_B_LOW), 1);
}
