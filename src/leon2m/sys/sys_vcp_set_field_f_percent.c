/* sys_vcp_set_field_f_percent  (FUN_a00d44bc)
 *
 * Set a further position field of the active channel from a percentage.
 * Name basis: descriptive - twin of sys_vcp_set_field_4_percent with other constants
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d44bc @ 0xa00d44bc, flags -mcpu=v8 -O3 -g.
 * Same code as sys_vcp_set_field_4_percent with the fields 4, 5, 6 replaced by 0xF, 0x12, 0x13.
 */
extern unsigned char input_api_find_channel_not_sync_mode5(void);
extern int input_api_get_timing_field(unsigned char, unsigned int);
extern void sys_api_set_channel_position_field(unsigned char, unsigned int, unsigned short, int);

#define POSITION_FIELD_F       0x0f     /* the field that is set */
#define POSITION_FIELD_F_HIGH  0x12     /* the value of field 0xF at 100 percent */
#define POSITION_FIELD_F_LOW   0x13     /* the value of field 0xF at 0 percent */
#define PERCENT_MAX            100

/*
 * Set field 0x0F of the channel found by input_api_find_channel_not_sync_mode5 from a percentage:
 * level (limited to 100) * (field 0x12 - field 0x13) / 100 + field 0x13. Same scale as sys_vcp_set_field_4_percent.
 */
void sys_vcp_set_field_f_percent(unsigned char level)
{
  unsigned char channel = input_api_find_channel_not_sync_mode5();
  int high, low;
  if (level > PERCENT_MAX)
    level = PERCENT_MAX;
  high = (unsigned short)input_api_get_timing_field(channel, POSITION_FIELD_F_HIGH);
  low = (unsigned short)input_api_get_timing_field(channel, POSITION_FIELD_F_LOW);
  sys_api_set_channel_position_field(channel, POSITION_FIELD_F, level * (high - low) / PERCENT_MAX + input_api_get_timing_field(channel, POSITION_FIELD_F_LOW), 1);
}
