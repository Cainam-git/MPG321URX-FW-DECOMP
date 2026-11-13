/* sys_api_set_channel_timeout  (FUN_a014a8d4)
 *
 * Set flag bit 16 and a 16-bit time value for one channel or for all four.
 * Name basis: descriptive - channel record word +0x70 bit 16 and halfword +0x74; prints the bit
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014a8d4 @ 0xa014a8d4-0xa014aa48 (93 words), flags -mcpu=v8 -O3 -g.
 * Source form: the channel remap is a static helper with a switch; the flag is a 1-bit bit-field (bit 16 of word
 * +0x70, big-endian layout) and the time value a halfword at +0x74 of the 0x78-byte record. For channel 4 the final
 * print reads the record after the four (word 0xa802e180).
 */
/* Channel record: the two fields written here. */
struct channel_record_delay {
    unsigned char head[0x70];
    unsigned int pad : 15;
    unsigned int display_delay_on : 1;          /* +0x70 bit 16: the firmware's bDisplayDelay */
    unsigned int low : 16;
    unsigned short display_delay;               /* +0x74: ticks to wait (see the channel state machine) */
    unsigned short tail;
};
extern struct channel_record_delay channel_records[4];
extern int dbg_printf();

#define ALL_CHANNELS 4

/* Channel number 0..3 as it is, anything else -1. */
static int remap_channel(int channel)
{
    switch (channel) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/*
 * Set the display delay flag and the delay time of one channel, or of all four, and print the flag.
 *
 *   channel  0..3, or 4 for all four; any other value prints "SYS remapping channel OOR" and uses channel 0
 *   on       the new flag (bit 0)
 *   ticks    the new delay time
 *
 * The channel state machine waits for the delay time (in state 11) when the flag is set.
 */
void sys_api_set_channel_timeout(unsigned char channel, unsigned int on, unsigned short ticks)
{
    if (channel == ALL_CHANNELS) {
        channel_records[0].display_delay_on = on;
        channel_records[1].display_delay_on = on;
        channel_records[2].display_delay_on = on;
        channel_records[3].display_delay_on = on;
        channel_records[0].display_delay = ticks;
        channel_records[1].display_delay = ticks;
        channel_records[2].display_delay = ticks;
        channel_records[3].display_delay = ticks;
    } else {
        channel = remap_channel(channel);
        if (channel > 3) { dbg_printf("SYS remapping channel OOR\r\n"); channel = 0; }
        channel_records[channel].display_delay_on = on;
        channel_records[channel].display_delay = ticks;
    }
    dbg_printf("MDHDLRs[%d].bDisplayDelay = %d \r\n", channel, channel_records[channel].display_delay_on);
}
