/* sys_vcp_get_field_15  (FUN_a00d4164)
 *
 * Return the low byte of timing field 0x15 of the channel input_api_find_channel_not_sync_mode5 gives.
 * Returns: value
 * Note: Its setter sys_vcp_set_field_14_percent writes field 0x14, not 0x15.
 * Name basis: descriptive - input_api_get_timing_field(channel, 0x15)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d4164 @ 0xa00d4164, flags -mcpu=v8 -O2 -g (section default).
 * Returns the low byte of input_api_get_timing_field(input_api_find_channel_not_sync_mode5() & 0xFF, 0x15). It reads field
 * 0x15, not field 0x14 (the field its setter sys_vcp_set_field_14_percent writes). Declared without parameters.
 */
extern int input_api_find_channel_not_sync_mode5(void); /* 0xa0144414 */
extern int input_api_get_timing_field(int a, int b); /* 0xa0145660 */

#define POSITION_FIELD_15      0x15

/*
 * Return the low byte of field 0x15 of the channel found by input_api_find_channel_not_sync_mode5.
 * (The matching setter sys_vcp_set_field_14_percent writes field 0x14.)
 */
int sys_vcp_get_field_15(void)
{
    int channel = input_api_find_channel_not_sync_mode5() & 0xff;
    return input_api_get_timing_field(channel, POSITION_FIELD_15) & 0xff;
}
