/* input_set_channel_block_selector  (FUN_a01328d4)
 *
 * Write the 2-bit selector of the input block that a channel uses.
 * Name basis: descriptive - port field of the channel record, then the block selector write
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01328d4 @ 0xa01328d4, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the port is read as (unsigned char)(word >> 12) & 0xf from a plain
 * byte-array label indexed by channel * 0x78, and the local holding it is an unsigned char.
 */

extern unsigned char channel_records;
extern void input_api_set_block_selector(unsigned char port, unsigned char selector);

#define CHANNEL_RECORD_SIZE 0x78        /* bytes per channel record */
#define CHANNEL_COUNT       4
#define CHANNEL_PORT_SHIFT  12          /* the port is bits 12-15 of word 0 of a channel record */
#define NO_PORT             0xff

/*
 * Write the 2-bit selector of the input block that a channel uses.
 *
 *   channel   channel number 0..3
 *   selector  the value to write
 *
 * The port field of the channel record is passed on as the input block number. A channel number above 3 passes
 * 0xFF instead.
 */
void input_set_channel_block_selector(unsigned int channel, unsigned char selector)
{
  unsigned char port;

  port = NO_PORT;
  if ((channel & 0xff) < CHANNEL_COUNT) {
    port = (unsigned char)(*(unsigned int *)(&channel_records + (channel & 0xff) * CHANNEL_RECORD_SIZE) >> CHANNEL_PORT_SHIFT) & 0xf;
  }
  input_api_set_block_selector(port, selector);
}
