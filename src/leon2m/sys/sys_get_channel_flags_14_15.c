/* sys_get_channel_flags_14_15  (FUN_a013cea0)
 *
 * Return the 2-bit field at bits 14-15 of a channel's flag word.
 * Returns: 0..3
 * Name basis: descriptive - channel record word +0x70
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013cea0 @ 0xa013cea0-0xa013cecc (11 words), flags -mcpu=v8 -O3 -g.
 * Caller: sys_api_get_channel_flags_14_15 (the channel-checked wrapper).
 * Source form: the base as a 0x78-byte struct array with the word at +0x70; unsigned char parameter
 * and return. Aids: none.
 */
/* Channel record (0x78 bytes); only the flags word at +0x70 is used here. */
struct channel_record { unsigned char pad[0x70]; unsigned int flags; unsigned int pad74; };
extern struct channel_record channel_records[];

/* Return bits 14..15 of the flags word (+0x70) of channel ch. ch is not range-checked here. */
unsigned char sys_get_channel_flags_14_15(unsigned char ch)
{
    return (channel_records[ch].flags >> 14) & 3;
}
