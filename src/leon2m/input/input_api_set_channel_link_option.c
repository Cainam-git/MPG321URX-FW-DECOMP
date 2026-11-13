/* input_api_set_channel_link_option  (FUN_a014931c)
 *
 * Store an option per channel and send it for channels fed by port code 0x71.
 * Name basis: descriptive - per-channel byte; forwarded with the low two bits when the channel's port type is
 *   0x71
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014931c @ 0xa014931c-0xa0149588 (155 words), flags -mcpu=v8 -O3 -g, leaf.
 * Source form: link_channel_index is the static helper of pq_api_load_level_table, inlined; every case indexes the channel
 * records with the variable k (GCC folds the constant index in cases 1..3 only), so the four cases are written
 * out one by one.
 */

#define PORT_CODE_ENTRY2          0x71          /* port code of port entry 2 (DisplayPort class) */
#define LINK_OPTION_ENABLE_BIT    0x800000      /* bit 23 of sys_config word 0 */
#define CHANNEL_PORT(status)      (((status) >> 12) & 0xf)   /* port of a channel: bits 12..15 of its word 0 */

/* The parts of the system configuration record used here. */
struct sys_config_record {
    unsigned int flags;                         /* +0: bit 23 = link options enabled */
    unsigned char pad04[0x1e - 4];
    unsigned char link_option0;                 /* +0x1E: link option of channel 0 */
    unsigned char link_option1;                 /* +0x1F: channel 1 */
    unsigned char link_option2;                 /* +0x20: channel 2 */
    unsigned char link_option3;                 /* +0x21: channel 3 */
};
/* Channel record: only word 0 is read here. */
struct channel_record {
    unsigned int status_word;                   /* +0: port in bits 12..15 */
    unsigned char rest[0x74];
};
/* Port record: only the port code is read here. */
struct port_record {
    unsigned char pad00[0x0a];
    unsigned char port_code;                    /* +0xA */
    unsigned char pad0b[0x2a - 0x0b];
};
extern struct sys_config_record sys_config;
extern struct channel_record channel_records[4];
extern struct port_record port_records[];
extern void input_set_channel_block_selector(int, int);

/* Channels 0..3 map to themselves; any other value gives -1. */
static int link_channel_index(int channel)
{
    switch (channel) {
    case 1: return 1;
    case 0: return 0;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/*
 * Store the link option of a channel and pass it on to that channel's block selector.
 *
 * channel: 0..3; any other value does nothing.
 * option:  the link option byte. It is kept in sys_config (+0x1E + channel) as it is.
 *
 * The option reaches input_set_channel_block_selector only when the port record of the channel's port has
 * port code 0x71. Channel 0 sends its low two bits. Channels 1..3 send their low two bits only while link
 * options are enabled (sys_config bit 23, set by input_api_set_link_option_enable); while disabled they send 0.
 * Callers: the input_user_apply_channel<n>_link_option routines and sys_api_config.
 */
void input_api_set_channel_link_option(unsigned char channel, unsigned char option)
{
    unsigned char k = link_channel_index(channel);

    switch (k) {
    case 0:
        sys_config.link_option0 = option;
        if (port_records[CHANNEL_PORT(channel_records[k].status_word)].port_code == PORT_CODE_ENTRY2)
            input_set_channel_block_selector(0, option & 3);
        break;
    case 1:
        sys_config.link_option1 = option;
        if (sys_config.flags & LINK_OPTION_ENABLE_BIT) {
            if (port_records[CHANNEL_PORT(channel_records[k].status_word)].port_code == PORT_CODE_ENTRY2)
                input_set_channel_block_selector(1, option & 3);
        } else if (port_records[CHANNEL_PORT(channel_records[k].status_word)].port_code == PORT_CODE_ENTRY2)
            input_set_channel_block_selector(1, 0);
        break;
    case 2:
        sys_config.link_option2 = option;
        if (sys_config.flags & LINK_OPTION_ENABLE_BIT) {
            if (port_records[CHANNEL_PORT(channel_records[k].status_word)].port_code == PORT_CODE_ENTRY2)
                input_set_channel_block_selector(2, option & 3);
        } else if (port_records[CHANNEL_PORT(channel_records[k].status_word)].port_code == PORT_CODE_ENTRY2)
            input_set_channel_block_selector(2, 0);
        break;
    case 3:
        sys_config.link_option3 = option;
        if (sys_config.flags & LINK_OPTION_ENABLE_BIT) {
            if (port_records[CHANNEL_PORT(channel_records[k].status_word)].port_code == PORT_CODE_ENTRY2)
                input_set_channel_block_selector(3, option & 3);
        } else if (port_records[CHANNEL_PORT(channel_records[k].status_word)].port_code == PORT_CODE_ENTRY2)
            input_set_channel_block_selector(3, 0);
        break;
    }
}
