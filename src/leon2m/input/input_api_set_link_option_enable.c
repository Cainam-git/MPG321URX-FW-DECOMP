/* input_api_set_link_option_enable  (FUN_a0149588)
 *
 * Store configuration bit 23 and send each channel's link option, or 0 when it is off.
 * Name basis: descriptive - stSysConfig bit 23; forwards per channel when its port type is 0x71
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0149588 @ 0xa0149588-0xa0149978 (252 words), flags -mcpu=v8 -O3 -g.
 * Source form: channel_port returns 0xff for a channel above 3 (two returns). The code after that helper is a new
 * block for the compiler, so the record addresses are formed again where the firmware forms them: 0xa802df30 once
 * in each arm (0xa0149640, 0xa0149644) and 0xa802e3d0 before each of the four option reads (0xa014962c,
 * 0xa01496b4, 0xa0149724, 0xa0149798). send_link_option is a helper with one case per channel.
 */

#define PORT_CODE_ENTRY2          0x71          /* port code of port entry 2 (DisplayPort class) */
#define LINK_OPTION_ENABLE_BIT    0x800000      /* bit 23 of sys_config word 0 */
#define PORT_ENTRY_COUNT          7             /* entries in port_entries; a larger index is replaced by 0 */

/* Channel record: bits 12..15 of word 0 are the port. */
struct channel_record { unsigned int top : 16; unsigned int port : 4; unsigned int low : 12; unsigned char rest[0x74]; };
/* Port record: only the port code is read here. */
struct port_record { unsigned char pad00[0xa]; unsigned char port_code; unsigned char rest[0x1f]; };
/* Port entry: byte +0x10 is the bus id. */
struct port_entry { unsigned char pad00[0x10]; unsigned char bus_id; unsigned char byte_0x11; };
/* System configuration record: flags word and the four link option bytes at +0x1E. */
struct sys_config_record { unsigned int flags; unsigned char pad04[0x1a]; unsigned char link_option[4]; };
extern struct channel_record channel_records[4];
extern struct port_record port_records[];
extern struct port_entry port_entries[];
extern struct sys_config_record sys_config;
extern unsigned char input_port_id_to_entry_index(unsigned char);
extern unsigned char input_port_table_get_code(unsigned char);
extern unsigned char input_port_table_find_code(unsigned char);
extern unsigned char input_find_port_entry_by_bus_id(unsigned char);
extern unsigned char input_entry_index_to_port_code(unsigned char);
extern void input_set_channel_block_selector(int, int);

/* The port of a channel; 0xff for a channel above 3. */
static unsigned char channel_port(unsigned char channel)
{
    if (channel > 3)
        return 0xff;
    return channel_records[channel].port;
}

/* Port code reached from a port table index: port table entry, then port entry, then its port code. */
static unsigned char port_code_of_table_index(unsigned char table_index)
{
    return input_entry_index_to_port_code(input_find_port_entry_by_bus_id(input_port_table_find_code(table_index)));
}

/*
 * The port code of the input a channel is fed from: the port code in the channel's port record gives a port
 * entry index (0 when it is 7 or more); the bus id of that entry gives the port table index.
 */
static unsigned char channel_port_code(unsigned char channel)
{
    unsigned char entry_index;

    entry_index = input_port_id_to_entry_index(port_records[channel_port(channel)].port_code);
    if (entry_index >= PORT_ENTRY_COUNT)
        entry_index = 0;
    return port_code_of_table_index(input_port_table_get_code(port_entries[entry_index].bus_id));
}

/* Send the stored link option of a channel (its low two bits). */
static void send_link_option(unsigned char channel)
{
    switch (channel) {
    case 0: input_set_channel_block_selector(0, sys_config.link_option[0] & 3); break;
    case 1: input_set_channel_block_selector(1, sys_config.link_option[1] & 3); break;
    case 2: input_set_channel_block_selector(2, sys_config.link_option[2] & 3); break;
    case 3: input_set_channel_block_selector(3, sys_config.link_option[3] & 3); break;
    }
}

/*
 * Switch the link options on or off (sys_config bit 23) and pass the result to the channels.
 *
 * enable: bit 0 becomes sys_config bit 23.
 *
 * Only channels whose input has port code 0x71 are touched. Channel 0 always sends its stored option. Channels
 * 1..3 send their stored option when bit 23 is now set, and send 0 when it is clear. The stored options are the
 * bytes written by input_api_set_channel_link_option.
 * Caller: input_user_apply_link_option_enable.
 */
void input_api_set_link_option_enable(unsigned char enable)
{
    sys_config.flags = (sys_config.flags & ~LINK_OPTION_ENABLE_BIT) | ((enable & 1) << 23);
    if (channel_port_code(0) == PORT_CODE_ENTRY2)
        send_link_option(0);
    if (sys_config.flags & LINK_OPTION_ENABLE_BIT) {
        if (channel_port_code(1) == PORT_CODE_ENTRY2)
            send_link_option(1);
        if (channel_port_code(2) == PORT_CODE_ENTRY2)
            send_link_option(2);
        if (channel_port_code(3) == PORT_CODE_ENTRY2)
            send_link_option(3);
    } else {
        if (channel_port_code(1) == PORT_CODE_ENTRY2)
            input_set_channel_block_selector(1, 0);
        if (channel_port_code(2) == PORT_CODE_ENTRY2)
            input_set_channel_block_selector(2, 0);
        if (channel_port_code(3) == PORT_CODE_ENTRY2)
            input_set_channel_block_selector(3, 0);
    }
}
