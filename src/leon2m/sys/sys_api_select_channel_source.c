/* sys_api_select_channel_source  (FUN_a0149978)
 *
 * Set the source of a channel, update its port records and note the time of the change.
 * Name basis: derived - port record update for the channel, block selector when sys_config bit 23 is set and
 *   the port code is 0x71, tick count stored in the port record
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0149978 @ 0xa0149978-0xa0149b8c, flags -mcpu=v8 -O3 -g.
 * Source form: remap() and kind() are static helpers; the block-selector switch has one explicit arm per
 * channel (0..3), as in the firmware's jump table.
 */
#define SYS_CONFIG_BLOCK_SELECT_BIT 0x800000    /* bit 23 of sys_config word 0 */
#define SYS_CONFIG_CHANNEL3_BIT     0x200000    /* bit 21 of sys_config word 0 */
#define PORT_CODE_71                0x71        /* port code that takes the block selector of sys_config */

/* Channel record: word 0 bit field `port` = bits 12..15. */
struct Rec { unsigned int top : 16; unsigned int port : 4; unsigned int low : 12; unsigned char rest[0x74]; };
/* sys_config: word 0 holds flag bits; the bytes m[0..3] at +0x1e..+0x21 are the block selectors of the channels. */
struct Sys { unsigned int flags; unsigned char p04[0x1a]; unsigned char m[4]; };
extern struct Rec channel_records[4];
extern struct Sys sys_config;
extern int dbg_printf();
extern unsigned char input_port_table_find_code(unsigned char);
extern unsigned char input_find_port_entry_by_bus_id(unsigned char);
extern unsigned char input_entry_index_to_port_code(unsigned char);
extern void sys_set_channel_port(unsigned char, unsigned char, int);
extern void input_set_channel_block_selector(int, int);
extern void input_stamp_port_time(unsigned int);

/* Channel numbers 0..3 stay as they are; anything else gives -1. */
static int remap(int ch)
{
    switch (ch) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/* Port code for a source: the source goes to its index in the port table, from there to its port entry by bus
   id, and from the entry's index to the port code. */
static unsigned char kind(unsigned char source)
{
    return input_entry_index_to_port_code(input_find_port_entry_by_bus_id(input_port_table_find_code(source)));
}

/*
 * Give channel ch the source `source`, apply the block selector where one is set, and stamp the port's time.
 *
 *   ch      channel number 0..3; another number is reported ("SYS remapping channel OOR") and counts as 0
 *   source  the input to show (the argument of input_port_table_find_code)
 *
 * 1. sys_set_channel_port gives the channel the port code derived from `source`.
 * 2. With bit 23 of sys_config word 0 set and that port code equal to 0x71, input_set_channel_block_selector gets
 *    the channel and the low 2 bits of its byte m[ch] of sys_config.
 * 3. For channel 0 with bit 21 of sys_config word 0 set, channel 3 gets the same port code too.
 * 4. input_stamp_port_time stores the current tick count in the port record of the channel's port.
 * Called by UserSetPIPMode, ddc_handle_request and the sys_user_* source routines, among others.
 */
void sys_api_select_channel_source(unsigned char ch, unsigned char source)
{
    unsigned char i;

    i = remap(ch);
    if (i > 3) { dbg_printf("SYS remapping channel OOR\r\n"); i = 0; }
    sys_set_channel_port(i, kind(source), 0);
    if ((sys_config.flags & SYS_CONFIG_BLOCK_SELECT_BIT) && kind(source) == PORT_CODE_71) {
        switch (i) {
        case 0: input_set_channel_block_selector(0, sys_config.m[0] & 3); break;
        case 1: input_set_channel_block_selector(1, sys_config.m[1] & 3); break;
        case 2: input_set_channel_block_selector(2, sys_config.m[2] & 3); break;
        case 3: input_set_channel_block_selector(3, sys_config.m[3] & 3); break;
        }
    }
    if (i == 0 && (sys_config.flags & SYS_CONFIG_CHANNEL3_BIT))
        sys_set_channel_port(3, kind(source), 0);
    if (i < 4)
        input_stamp_port_time(channel_records[i].port);
}
