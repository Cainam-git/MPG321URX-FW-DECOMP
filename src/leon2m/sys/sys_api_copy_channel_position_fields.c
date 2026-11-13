/* sys_api_copy_channel_position_fields  (FUN_a0145508)
 *
 * Copy halfwords +0x28/+0x2A/+0x2C to +0x0E/+0x1E/+0x20 in the records of running channels.
 * Note: Only for channels in state 12 whose port record byte +9 is not 5; also sets byte +0x26 to 0x20. Mode 0
 *   calls an empty routine.
 * Name basis: descriptive - mode 1 copies three halfwords for channels that pass two tests
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0145508 @ 0xa0145508-0xa0145644, flags -mcpu=v8 -O3 -g.
 * Source form: switch (mode) as in nvram_api_store_by_selector. The port-type test is the static helper port_type_is_5(ch), the
 * body of input_api_is_channel_sync_mode5 (input_api_is_channel_sync_mode5: remap, the "SYS remapping channel OOR" print, type == 5),
 * inlined into `if (sys_get_channel_state(i) == 0xc && !port_type_is_5(i))`.
 */
#define MODE_WAITMODECHANGE 12      /* channel state 12 */
#define BYTE_0X26_VALUE 0x20   /* value stored in byte +0x26 of the channel record */

/* Channel record (0x78 bytes): only the fields used here are named. The word 0 bit field f12 is the port. */
struct Rec {
    unsigned int top : 16;
    unsigned int port : 4;
    unsigned int low : 12;
    unsigned char p04[0x0a];
    unsigned short h0e;
    unsigned char p10[0x0e];
    unsigned short start_x;             /* +0x1e: position field 12 of sys_api_set_channel_position_field */
    unsigned short start_y;             /* +0x20: position field 16 */
    unsigned char p22[4];
    unsigned char b26;
    unsigned char p27;
    unsigned short h28, h2a, h2c;
    unsigned char tail[0x4a];
};
/* Port record: +9 is the port type. */
struct Src { unsigned char p[9]; unsigned char type; unsigned char rest[0x20]; };
extern struct Rec channel_records[4];
extern struct Src port_records[];
extern int dbg_printf();
extern unsigned char sys_get_channel_state(unsigned char);
extern void sys_poll_events_stub_copy23(void);

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

/* True when the port of channel ch has type 5. A channel number outside 0..3 is reported and counts as 0. */
static unsigned char port_type_is_5(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { dbg_printf("SYS remapping channel OOR\r\n"); i = 0; }
    return port_records[channel_records[i].port].type == 5;
}

/*
 * Mode 1 reloads three halfwords of the records of channels in state 12 from the halfwords at +0x28, +0x2a and
 * +0x2c.
 *
 *   mode  0: calls sys_poll_events_stub_copy23, an empty routine. 1: the reset below. Other values do nothing.
 *
 * Mode 1 looks at channels 0..3. A channel is changed when it is in state 12 (MODE_WAITMODECHANGE) and its port
 * is not of type 5. For such a channel +0x0e, start_x (+0x1e) and start_y (+0x20) are loaded from +0x28, +0x2a
 * and +0x2c, and byte +0x26 is set to 0x20.
 * Called by sys_vcp_reset_positions and ddc_handle_request.
 */
void sys_api_copy_channel_position_fields(unsigned char mode)
{
    unsigned char i;

    switch (mode) {
    case 0:
        sys_poll_events_stub_copy23();
        break;
    case 1:
        for (i = 0; i < 4; i++) {
            if (sys_get_channel_state(i) == MODE_WAITMODECHANGE && !port_type_is_5(i)) {
                channel_records[i].h0e = channel_records[i].h28;
                channel_records[i].start_x = channel_records[i].h2a;
                channel_records[i].start_y = channel_records[i].h2c;
                channel_records[i].b26 = BYTE_0X26_VALUE;
            }
        }
        break;
    }
}
