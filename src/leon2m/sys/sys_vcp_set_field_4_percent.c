/* sys_vcp_set_field_4_percent  (FUN_a00d41b4)
 *
 * Set position field 4 of the active channel from a percentage.
 * Name basis: descriptive - scaled around the stored base
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d41b4 @ 0xa00d41b4, flags -mcpu=v8 -O3 -g.
 * hi and lo are int locals assigned from (unsigned short) casts of the two timing-field reads (a u16 local delays the
 * zero extension past the second call). input_api_get_timing_field is declared int-returning because the function's own
 * retl extends its result to 16 bits. The division is signed (the 0x51eb851f magic multiply); the last call is a tail
 * call and reads field 6 a second time.
 */
extern unsigned char input_api_find_channel_not_sync_mode5(void);
extern int input_api_get_timing_field(unsigned char, unsigned int);
extern void sys_api_set_channel_position_field(unsigned char, unsigned int, unsigned short, int);

#define POSITION_FIELD_4       4        /* the field that is set */
#define POSITION_FIELD_4_HIGH  5        /* the value of field 4 at 100 percent */
#define POSITION_FIELD_4_LOW   6        /* the value of field 4 at 0 percent */
#define PERCENT_MAX            100

/*
 * Set field 4 of the channel found by input_api_find_channel_not_sync_mode5 from a percentage:
 * level (limited to 100) * (field 5 - field 6) / 100 + field 6.
 */
void sys_vcp_set_field_4_percent(unsigned char level)
{
  unsigned char channel = input_api_find_channel_not_sync_mode5();
  int high, low;
  if (level > PERCENT_MAX)
    level = PERCENT_MAX;
  high = (unsigned short)input_api_get_timing_field(channel, POSITION_FIELD_4_HIGH);
  low = (unsigned short)input_api_get_timing_field(channel, POSITION_FIELD_4_LOW);
  sys_api_set_channel_position_field(channel, POSITION_FIELD_4, level * (high - low) / PERCENT_MAX + input_api_get_timing_field(channel, POSITION_FIELD_4_LOW), 1);
}
