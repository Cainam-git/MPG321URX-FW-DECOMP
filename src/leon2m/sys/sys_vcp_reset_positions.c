/* sys_vcp_reset_positions  (FUN_a00d5748)
 *
 * Reset the channel positions and write the four position fields back.
 * Name basis: descriptive - sys_api_copy_channel_position_fields(1), then four get / set pairs
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5748 @ 0xa00d5748 (-mcpu=v8 -O3 -g)
 * Calls sys_api_copy_channel_position_fields(1), then for n = 4, 0xB, 0xF and 0x14 in turn passes the result of input_api_get_timing_field(0, n),
 * truncated to 16 bits, to sys_api_set_channel_position_field(0, n, value, 1). The last call is a
 * tail call (restore in the delay slot).
 */
extern int sys_api_copy_channel_position_fields();
extern int input_api_get_timing_field();
extern void sys_api_set_channel_position_field();

#define MAIN_CHANNEL 0                  /* channel 0: the main picture */

/*
 * Call sys_api_copy_channel_position_fields(1), then read the fields 4, 0x0B, 0x0F and 0x14 of channel 0 and write
 * each back to the same field with the apply flag 1.
 */
void sys_vcp_reset_positions(void)
{
    unsigned short value;

    sys_api_copy_channel_position_fields(1);
    value = input_api_get_timing_field(MAIN_CHANNEL, 4);
    sys_api_set_channel_position_field(MAIN_CHANNEL, 4, value, 1);
    value = input_api_get_timing_field(MAIN_CHANNEL, 0xb);
    sys_api_set_channel_position_field(MAIN_CHANNEL, 0xb, value, 1);
    value = input_api_get_timing_field(MAIN_CHANNEL, 0xf);
    sys_api_set_channel_position_field(MAIN_CHANNEL, 0xf, value, 1);
    value = input_api_get_timing_field(MAIN_CHANNEL, 0x14);
    sys_api_set_channel_position_field(MAIN_CHANNEL, 0x14, value, 1);
}
