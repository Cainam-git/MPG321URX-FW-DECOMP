/* sys_vcp_get_field_b_percent  (FUN_a00d43b4)
 *
 * Return position field 0x0B of the active channel as a percentage of its range.
 * Returns: percent
 * Name basis: descriptive - limits from fields 0x0D and 0x0E
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d43b4 @ 0xa00d43b4, flags -mcpu=v8 -O3 -g.
 * Fields are read in the order 0xB, 0xE, 0xD, 0xE (0xE twice), each as a 16-bit value.
 */
extern int input_api_find_channel_not_sync_mode5(void);
extern int input_api_get_timing_field(int, int);

#define POSITION_FIELD_B       0x0b
#define POSITION_FIELD_B_HIGH  0x0d
#define POSITION_FIELD_B_LOW   0x0e
#define PERCENT_MAX            100

/*
 * Return field 0x0B of the channel found by input_api_find_channel_not_sync_mode5 as a percentage of its range, counted
 * backwards: 100 - (field 0xB - field 0xE) * 100 / (field 0xD - field 0xE), low byte.
 * Inverse of sys_vcp_set_field_b_percent.
 */
int sys_vcp_get_field_b_percent(void)
{
    int channel = input_api_find_channel_not_sync_mode5() & 0xff;
    int value = (unsigned short)input_api_get_timing_field(channel, POSITION_FIELD_B);
    int low = (unsigned short)input_api_get_timing_field(channel, POSITION_FIELD_B_LOW);
    int scaled = (value - low) * PERCENT_MAX;
    int high = (unsigned short)input_api_get_timing_field(channel, POSITION_FIELD_B_HIGH);
    int low_again = (unsigned short)input_api_get_timing_field(channel, POSITION_FIELD_B_LOW);
    return (PERCENT_MAX - (scaled / (high - low_again))) & 0xff;
}
