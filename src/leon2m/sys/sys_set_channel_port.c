/* sys_set_channel_port  (FUN_a012f43c)
 *
 * Set the port code of a channel's port, re-select the channel's source and note the code's class.
 * Name basis: derived - port mode, source fields of the channel record, two commands to the input processor
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012f43c @ 0xa012f43c-0xa012f7a8 (876 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - channel_port_of and pip_picture_count are same-file copies of sys_get_channel_port and
 *    sys_get_pip_channel_count (the switch of pip_picture_count gives the jump table at 0xa012f16c, run-time
 *    address 0xcf16c);
 *  - the two arms repeat the same steps (sys_set_channel_source gets 0 in the first, channel in the second), each
 *    starting with 'port = channel_port';
 *  - the case order 0x71, 0x81, 0x51, 0x61, default of the last switch gives the firmware's register choices.
 */

/* The channel record (0x78 bytes): the first word and port_flags_mask. */
struct channel_record {
    union {
        unsigned int word;
        struct {
            unsigned int state : 4;             /* bits 28..31 */
            unsigned int bits_24 : 4, bits_20 : 4, bits_16 : 4;
            unsigned int port : 4;              /* bits 12..15 */
            unsigned int receiver_index : 4;    /* bits 8..11 */
            unsigned int bits_4 : 4;
            unsigned int path : 3;              /* bits 1..3 */
            unsigned int bit0 : 1;
        } f;
    } status_word;                              /* +0 */
    unsigned char pad04[0x76 - 0x04];
    unsigned char port_flags_mask;              /* +0x76: one bit for the class of the port code, see below */
    unsigned char byte_0x77;
};
/* The port record (0x2A bytes): the port code at +0xA (called the port's mode by input_set_port_mode). */
struct port_record { unsigned char byte_0x00, byte_0x01, byte_0x02; unsigned char pad03[7]; unsigned char port_code; unsigned char rest[0x2a - 0x0b]; };
extern struct channel_record channel_records[4];
extern struct port_record port_records[];
extern unsigned char device_settings_pip_mode;
extern unsigned char pq_block_is_blanked(unsigned char blk);
extern void pq_block_blank(unsigned char);
extern void input_set_port_mode(unsigned char port, unsigned char port_code, unsigned char force);
extern void sys_set_channel_source(unsigned char channel, unsigned char source, unsigned char force);
extern void ipc_select_hdr_source(unsigned char port_code);
extern unsigned char sys_get_chip_revision(void);
extern unsigned char input_port_id_to_entry_index(unsigned char port_code);
extern void ipc_set_hdmi21_port_mask(unsigned char entry_index, unsigned char a, unsigned char mask);
extern void input_block_set_change_pending(unsigned char block);

#define LAST_CHANNEL        3
#define LAST_PORT           7
#define HDMI21_MASK_PORTS   4                   /* ipc_set_hdmi21_port_mask is sent only for ports 0..3 */
#define CHIP_REV_HDMI21_MASK 0x82               /* ... and only on chip revision codes above this */

/* Port codes (port record +0xA) and the bit each gives in port_flags_mask. */
#define PORT_CODE_0X51      0x51
#define PORT_CODE_0X61      0x61
#define PORT_CODE_0X71      0x71
#define PORT_CODE_0X81      0x81

/* The port field of a channel; 0xFF for a channel above 3. */
static unsigned char channel_port_of(unsigned char c)
{
    unsigned char r = 0xff;
    if (c <= 3)
        r = channel_records[c].status_word.f.port;
    return r;
}

/* The number of pictures of the current picture-in-picture mode (1 for mode 0, one picture). */
static unsigned char pip_picture_count(void)
{
    unsigned char r;

    switch (device_settings_pip_mode) {
    default:
        r = 1;
        break;
    case 0:
        r = 1;
        break;
    case 4:
    case 7:
        r = 4;
        break;
    case 3:
    case 6:
        r = 3;
        break;
    case 1:
    case 2:
    case 5:
        r = 2;
        break;
    }
    return r & 7;
}

/*
 * Set the port code of the port a channel uses, re-select the channel's source, and note the class of the code
 * in the channel record.
 *
 *   channel    channel 0..3
 *   port_code  the new code for port record +0xA (0x51, 0x61, 0x71, 0x81 and others)
 *   force      non-zero: do the update even when the port record already holds port_code
 *
 * Called from sys_channels_idle_task, startup_select_default_port and sys_api_select_channel_source.
 *
 * Phases:
 *  1. The channel's port (bits 12..15 of its first word).
 *  2. When the port record's code differs or force is set: blank the port's picture block if it is not blanked
 *     yet, set the port mode (input_set_port_mode), store the port as the channel's source, tell the input
 *     processor the HDR source for port 0, send the HDMI 2.1 port mask for ports 0..3 on chip revisions above
 *     0x82, and mark the block's change as pending. With one picture (pip_picture_count 1) and channel 0 the port
 *     is taken as it is and the source goes to channel 0; otherwise a port above 7 ends the routine here.
 *  3. port_flags_mask (+0x76) of the channel: 4 / 8 / 0x10 / 0x20 for port code 0x51 / 0x61 / 0x71 / 0x81,
 *     else 0. A channel above 3 never gets here: its port reads 0xFF and ends the routine in phase 2.
 */
void sys_set_channel_port(unsigned char channel, unsigned char port_code, unsigned char force)
{
    unsigned char channel_port, port;

    /* 1. */
    channel_port = channel_port_of(channel);
    /* 2. */
    if (pip_picture_count() == 1 && channel == 0) {
        port = channel_port;
        if (port_records[port].port_code != port_code || force) {
            if (pq_block_is_blanked(port) == 0)
                pq_block_blank(port);
            input_set_port_mode(port, port_code, force);
            sys_set_channel_source(0, port, 1);
            if (port == 0)
                ipc_select_hdr_source(port_code);
            if (sys_get_chip_revision() > CHIP_REV_HDMI21_MASK && port < HDMI21_MASK_PORTS)
                ipc_set_hdmi21_port_mask(input_port_id_to_entry_index(port_code), 0, 1 << port);
            input_block_set_change_pending(port);
        }
    } else {
        port = channel_port;
        if (port > LAST_PORT)
            return;
        if (port_records[port].port_code != port_code || force) {
            if (pq_block_is_blanked(port) == 0)
                pq_block_blank(port);
            input_set_port_mode(port, port_code, force);
            sys_set_channel_source(channel, port, 1);
            if (port == 0)
                ipc_select_hdr_source(port_code);
            if (sys_get_chip_revision() > CHIP_REV_HDMI21_MASK && port < HDMI21_MASK_PORTS)
                ipc_set_hdmi21_port_mask(input_port_id_to_entry_index(port_code), 0, 1 << port);
            input_block_set_change_pending(port);
        }
        if (channel > LAST_CHANNEL)
            return;
    }
    /* 3. */
    switch (port_code) {
    case PORT_CODE_0X71:
        channel_records[channel].port_flags_mask = 0x10;
        break;
    case PORT_CODE_0X81:
        channel_records[channel].port_flags_mask = 0x20;
        break;
    case PORT_CODE_0X51:
        channel_records[channel].port_flags_mask = 4;
        break;
    case PORT_CODE_0X61:
        channel_records[channel].port_flags_mask = 8;
        break;
    default:
        channel_records[channel].port_flags_mask = 0;
        break;
    }
}
