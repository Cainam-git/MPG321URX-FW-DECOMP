/* dp_tx_write_link_config  (FUN_a0086df4)
 *
 * Write link rate and lane count (with enhanced framing) to the sink.
 *   port: output
 * Returns: 1 on success
 * Name basis: derived - two bytes to DPCD 0x100/0x101, bit 7 = enhanced framing from the caps record
 *
 * Matching notes
 * --------------
 * FUN_a0086df4 (leon2s 0xa0086df4-0xa0086e58, 100 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the two bytes are first stored as given, then byte 1 is rewritten when the record bit is set.
 */
struct dp_tx_caps_record { unsigned char byte_0; unsigned char rest[5]; };
extern struct dp_tx_caps_record dp_tx_sink_caps_records[];    /* 6-byte caps record per output */
extern unsigned char dp_tx_aux_request(unsigned char, unsigned char, unsigned int, signed char, unsigned char *);

/*
 * Write two bytes to DPCD 0x100 and 0x101 (command 0x80). Byte 1 gets bit 7 added when bit 4 of byte 0 of
 * the output's caps record is set. Returns 1 when the request succeeded.
 *   port:   link output
 *   second: byte for DPCD 0x101
 *   first:  byte for DPCD 0x100
 */
int dp_tx_write_link_config(unsigned char port, unsigned char second, unsigned char first)
{
    unsigned char buf[2];
    buf[1] = second;
    buf[0] = first;
    if (dp_tx_sink_caps_records[port].byte_0 & 0x10)
        buf[1] = second | 0x80;
    return dp_tx_aux_request(port, 0x80, 0x100, 1, buf) != 0;
}
