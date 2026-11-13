/* sys_clear_all_channels_flag25  (FUN_a013cfc4)
 *
 * Clear flag bit 25 in all four channel records.
 * Name basis: descriptive - channel record word +0x70
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013cfc4 @ 0xa013cfc4-0xa013d008 (17 words), flags -mcpu=v8 -O3 -g. Caller: sys_api_clear_all_channels_flag25.
 * Source form: four separate statements, one per record.
 */
#define CHANNEL_FLAG_25 0x2000000   /* bit 25 of the flags word at +0x70 */

/* Channel record (0x78 bytes); only the flags word at +0x70 is used here. */
struct channel_record { unsigned char pad[0x70]; unsigned int flags; unsigned int pad74; };
extern struct channel_record channel_records[];

/* Clear bit 25 of the flags word (+0x70) in each of the four channel records. */
void sys_clear_all_channels_flag25(void)
{
    channel_records[0].flags &= ~CHANNEL_FLAG_25;
    channel_records[1].flags &= ~CHANNEL_FLAG_25;
    channel_records[2].flags &= ~CHANNEL_FLAG_25;
    channel_records[3].flags &= ~CHANNEL_FLAG_25;
}
