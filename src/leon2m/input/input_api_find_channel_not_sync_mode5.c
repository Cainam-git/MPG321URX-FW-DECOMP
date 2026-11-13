/* input_api_find_channel_not_sync_mode5  (FUN_a0144414)
 *
 * Return the first channel whose port does not have sync mode 5, or 0xFF.
 * Returns: channel or 0xFF
 * Name basis: descriptive - byte 9 (sync mode) of each channel's port record
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0144414 @ 0xa0144414-0xa0144484, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 */

/* The channel record (0x78 bytes), up to the field used here. */
struct channel_record_head {
    unsigned int status_word;       /* +0: port in bits 12-15 */
    unsigned char rest[0x74];
};
/* The port record (0x2A bytes), up to the field used here. */
struct port_record_sync {
    unsigned char pad0[9];
    unsigned char sync_mode;        /* +9: 1 = none recognised, 2..5 */
    unsigned char rest[0x20];
};
extern struct channel_record_head channel_records[4];
extern struct port_record_sync port_records[];

#define CHANNEL_COUNT      4
#define CHANNEL_PORT_SHIFT 12           /* the port is bits 12-15 of the channel's status word */
#define SYNC_MODE_5        5
#define NO_CHANNEL         0xff

/*
 * Return the number of the first channel whose port record does not hold sync mode 5, or 0xFF when all four
 * channels have sync mode 5.
 */
unsigned char input_api_find_channel_not_sync_mode5(void)
{
    unsigned char channel;

    for (channel = 0; channel < CHANNEL_COUNT; channel++)
        if (port_records[(channel_records[channel].status_word >> CHANNEL_PORT_SHIFT) & 0xf].sync_mode != SYNC_MODE_5)
            break;
    if (channel == CHANNEL_COUNT)
        return NO_CHANNEL;
    return channel;
}
