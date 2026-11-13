/* sys_set_channel_source  (FUN_a013d018)
 *
 * Store the source and its receiver index in a channel record.
 * Name basis: derived - nibbles 12..15 and 8..11 of the first word, written when changed or forced
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013d018 @ 0xa013d018-0xa013d0ec (53 words), flags -mcpu=v8 -O3 -g. Callers: sys_set_channel_port (twice).
 * The nibbles are 4-bit bit-fields; the state nibble is compared with 5u (unsigned compare).
 */
/* Channel record (0x78 bytes). The status word at +0 is split into bit-fields, from bit 31 down:
 * state (4 bits), 12 bits not used here, port (4 bits), receiver_index (4 bits), 8 bits not used here. */
struct channel_record {
    unsigned int state : 4, unused_27_16 : 12, port : 4, receiver_index : 4, unused_7_0 : 8;
    unsigned char pad4[0x6c];
    unsigned char flags_byte;       /* +0x70, low byte of the flags word */
    unsigned char rest[7];
};
/* Port record (0x2a bytes); only the port code at +0xa is used here. */
struct port_record { unsigned char pad[0xa]; unsigned char port_code; unsigned char rest[0x1f]; };
extern struct channel_record channel_records[];
extern struct port_record port_records[];
extern unsigned char input_port_code_to_receiver_index(unsigned char port_code);

/* Set the source (port) of channel ch (0..3; a larger number does nothing). The record is only touched
 * when the port differs from the stored one or force is not 0. Then the receiver index is looked up from
 * the port code of the source's port record; and a state above 5 is lowered to 5 when bit 0 of the flags
 * byte (+0x70) is set. */
void sys_set_channel_source(unsigned char ch, unsigned char src, unsigned char force)
{
    if (ch > 3)
        return;
    if (src != channel_records[ch].port || force) {
        channel_records[ch].port = src;
        channel_records[ch].receiver_index = input_port_code_to_receiver_index(port_records[src].port_code);
        if (channel_records[ch].state > 5u && (channel_records[ch].flags_byte & 1))
            channel_records[ch].state = 5;
    }
}
