/* sys_api_mark_channel_port  (FUN_a014de48)
 *
 * Mark the port of a channel as enabled or disabled without switching it.
 * Name basis: derived - bit 4 of the port record only; unused
 *
 * Matching notes
 * --------------
 * FUN_a014de48 (leon2m 0xa014de48-0xa014deec, 164 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: a switch mapping the channel; a one-bit bit-field for bit 4. The test 'channel <= 4' is part of the
 * exact build.
 */
/* Channel record (0x78 bytes); only the status word at +0 is used here (port = bits 12..15). */
struct channel_record { unsigned int status_word; unsigned char pad[0x74]; };
/* Port record (0x2a bytes); the status halfword at +0 seen from the top: 11 bits, bit 4, 4 bits. */
struct port_status { unsigned short high:11, bit4:1, low:4; };
struct port_record { struct port_status status; unsigned char rest[0x28]; };
extern struct channel_record channel_records[4];
extern struct port_record port_records[];

#define CHANNEL_NONE 0xff       /* the value the remap gives to a number that is no channel */

/*
 * Store bit 4 of the status halfword of the port record that a channel is on, without switching the port
 * (sys_api_enable_channel_port does the same and then switches it).
 *
 *   channel  channel number 0..3; any other value is mapped to 0xFF, fails the test and does nothing
 *   enable   bit 0 is the new value of the bit
 *
 * Nothing in the firmware calls it.
 */
void sys_api_mark_channel_port(unsigned char channel, unsigned int enable)
{
    unsigned char mapped;

    switch (channel) {
    case 0:
        mapped = 0;
        break;
    case 1:
        mapped = 1;
        break;
    case 2:
        mapped = 2;
        break;
    case 3:
        mapped = 3;
        break;
    default:
        mapped = CHANNEL_NONE;
        break;
    }
    if (mapped <= 4)
        port_records[(channel_records[mapped].status_word >> 12) & 0xf].status.bit4 = enable;
}
