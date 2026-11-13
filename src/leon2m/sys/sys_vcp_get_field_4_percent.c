/* sys_vcp_get_field_4_percent  (FUN_a00d4250)
 *
 * Return position field 4 of the active channel as a percentage.
 * Returns: percent
 * Name basis: descriptive - from four field reads
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d4250 @ 0xa00d4250, flags -mcpu=v8 -O3 -g.
 * The fields are read in the order 4, 6, 5, 6 (field 6 twice). The (unsigned short) casts give the sll 0x10 / srl 0x10
 * zero-extension pairs of the firmware.
 */
extern int input_api_find_channel_not_sync_mode5(void);
extern int input_api_get_timing_field(int, int);

#define POSITION_FIELD_4       4
#define POSITION_FIELD_4_HIGH  5
#define POSITION_FIELD_4_LOW   6
#define PERCENT_MAX            100

/*
 * Return field 4 of the channel found by input_api_find_channel_not_sync_mode5 as a percentage of its range:
 * (field 4 - field 6) * 100 / (field 5 - field 6), low byte. Inverse of sys_vcp_set_field_4_percent.
 */
int sys_vcp_get_field_4_percent(void)
{
    int channel = input_api_find_channel_not_sync_mode5() & 0xff;
    int value = (unsigned short)input_api_get_timing_field(channel, POSITION_FIELD_4);
    int low = (unsigned short)input_api_get_timing_field(channel, POSITION_FIELD_4_LOW);
    int scaled = (value - low) * PERCENT_MAX;
    int high = (unsigned short)input_api_get_timing_field(channel, POSITION_FIELD_4_HIGH);
    int low_again = (unsigned short)input_api_get_timing_field(channel, POSITION_FIELD_4_LOW);
    return (scaled / (high - low_again)) & 0xff;
}
