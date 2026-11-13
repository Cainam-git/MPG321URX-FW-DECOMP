/* sys_get_channel_port  (FUN_a012f3b4)
 *
 * Return the port field of a channel.
 * Returns: port or 0xFF
 * Name basis: derived - bits 12..15 of the first word of the channel record; unused
 *
 * Matching notes
 * --------------
 * FUN_a012f3b4 (leon2m 0xa012f3b4-0xa012f3ec, 56 bytes, leaf), flags -mcpu=v8 -O3 -g. Source form: an int result
 * set to -1 and returned as unsigned char.
 */
/* Channel record, word 0 only (0x78 bytes in all); the shared bit field names. */
struct channel_record {
    unsigned int state:4, bits_24_27:4, step:4, bits_16_19:4, port:4, receiver:4, window:4, bits_1_3:3, bit0:1;
    unsigned char p04[0x74];
};
extern struct channel_record channel_records[4];

/* Return the port field (bits 12..15 of word 0) of channel record ch, or 0xFF when ch is above 3. */
unsigned char sys_get_channel_port(unsigned char ch)
{
    unsigned char port = 0xff;
    if (ch <= 3)
        port = channel_records[ch].port;
    return port;
}
