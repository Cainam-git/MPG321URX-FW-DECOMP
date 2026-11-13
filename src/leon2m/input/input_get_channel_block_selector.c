/* input_get_channel_block_selector  (FUN_a013291c)
 *
 * Return the 2-bit selector of the input block that a channel uses.
 * Returns: selector or 0xFF
 * Name basis: descriptive - port field of the channel record; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013291c @ 0xa013291c, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the port is held in an unsigned char temporary; the channel record array
 * is indexed in words (channel * 30 = 0x78 bytes).
 */

extern unsigned int channel_records[];      /* 0x78 bytes (30 words) per channel record */
extern int input_api_get_block_selector(unsigned char port);

#define CHANNEL_RECORD_WORDS 30         /* a channel record is 0x78 bytes */
#define CHANNEL_COUNT        4
#define CHANNEL_PORT_SHIFT   12         /* the port is bits 12-15 of word 0 of a channel record */
#define NO_PORT              0xff

/*
 * Return the 2-bit selector of the input block that a channel uses.
 *
 *   channel   channel number 0..3
 *
 * The port field of the channel record is passed on as the input block number. A channel number above 3 passes
 * 0xFF instead. Only the low byte of the answer is returned. Nothing in the image calls this routine.
 */
unsigned int input_get_channel_block_selector(unsigned int channel)
{
    unsigned int index = channel & 0xff;
    unsigned char port;

    if (index > CHANNEL_COUNT - 1) {
        port = NO_PORT;
    } else {
        port = (channel_records[index * CHANNEL_RECORD_WORDS] >> CHANNEL_PORT_SHIFT) & 0xf;
    }
    return input_api_get_block_selector(port) & 0xff;
}
