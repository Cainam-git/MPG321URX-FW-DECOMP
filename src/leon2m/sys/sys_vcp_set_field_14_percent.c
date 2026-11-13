/* sys_vcp_set_field_14_percent  (FUN_a00d4108)
 *
 * Set position field 0x14 of the active channel from a percentage.
 * Name basis: descriptive - level * 63 / 100
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d4108 @ 0xa00d4108, flags -mcpu=v8 -O3 -g.
 * The division by 100 is signed (the 0x51eb851f magic multiply). The last call is a tail call.
 * Callee prototypes: unsigned char return of input_api_find_channel_not_sync_mode5,
 * sys_api_set_channel_position_field(unsigned char, unsigned int, unsigned short, int).
 */
extern unsigned char input_api_find_channel_not_sync_mode5(void);
extern void sys_api_set_channel_position_field(unsigned char, unsigned int, unsigned short, int);

#define POSITION_FIELD_14      0x14
#define POSITION_FIELD_14_MAX  63       /* value of field 0x14 at 100 percent */
#define PERCENT_MAX            100

/*
 * Set field 0x14 of the channel found by input_api_find_channel_not_sync_mode5 from a percentage:
 * level (limited to 100) * 63 / 100.
 */
void sys_vcp_set_field_14_percent(unsigned char level)
{
    unsigned char channel;

    channel = input_api_find_channel_not_sync_mode5();
    if (level > PERCENT_MAX)
        level = PERCENT_MAX;
    sys_api_set_channel_position_field(channel, POSITION_FIELD_14, level * POSITION_FIELD_14_MAX / PERCENT_MAX, 1);
}
