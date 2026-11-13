/* sys_api_set_channel_position_field  (FUN_a0145808)
 *
 * Store one position value of a channel and apply it.
 * Name basis: descriptive - halfword 0x16, 0x18, 0x1E or 0x20 of the channel record by id; then a write or a
 *   channel restart
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0145808 @ 0xa0145808-0xa0145920, flags -mcpu=v8 -O3 -g.
 * Source form: the record pointer is taken once before the switch; the calls for fields 12 and 16 sit inside
 * the switch arms (not in tail position, so they are plain calls). The channel number is not range-checked:
 * a number above 3 gives 0xff through remap() and indexes past the four records.
 */
/* Position fields, as the callers number them. Each is one halfword of the channel record. */
enum {
    POSITION_WIDTH   = 9,       /* +0x16 */
    POSITION_HEIGHT  = 10,      /* +0x18 */
    POSITION_START_X = 12,      /* +0x1e */
    POSITION_START_Y = 16       /* +0x20 */
};

#define RESTART_STATE 2         /* second argument of sys_restart_channel */

/* Channel record (0x78 bytes): only the halfwords written here are named. Word 0: port = bits 12..15. */
struct Chan {
    unsigned int w0;
    unsigned char p04[0x16 - 0x04];
    unsigned short width, height;
    unsigned char p1a[0x1e - 0x1a];
    unsigned short start_x, start_y;
    unsigned char p22[0x78 - 0x22];
};
extern struct Chan channel_records[4];
extern void input_block_set_capture_reg12(unsigned char, unsigned short);
extern void input_block_set_capture_reg0e(unsigned char, unsigned short);
extern void sys_restart_channel(unsigned char ch, unsigned char m);

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

/*
 * Store one position value in the record of channel ch and apply it.
 *
 *   ch     channel number 0..3
 *   field  POSITION_WIDTH, POSITION_HEIGHT, POSITION_START_X or POSITION_START_Y; any other number stores nothing
 *   value  the new value
 *   restart  0: for START_X and START_Y the value is also written to the channel's input block
 *               (input_block_set_capture_reg12 for START_X, input_block_set_capture_reg0e for START_Y).
 *            non-zero: only the record is changed, then the channel is sent back with sys_restart_channel(ch, 2)
 *               so that it is brought up again with the new value.
 * WIDTH and HEIGHT never write a register here.
 * Called by the sys_vcp_* position handlers, by pq_update_input_window and by pq_update_input_window.
 */
void sys_api_set_channel_position_field(unsigned char ch, unsigned int field, unsigned short value, unsigned char restart)
{
    unsigned char i = remap(ch);
    struct Chan *c = &channel_records[i];

    switch (field) {
    case POSITION_WIDTH:
        c->width = value;
        break;
    case POSITION_HEIGHT:
        c->height = value;
        break;
    case POSITION_START_X:
        c->start_x = value;
        if (!restart)
            input_block_set_capture_reg12((c->w0 >> 12) & 0xf, value);
        break;
    case POSITION_START_Y:
        c->start_y = value;
        if (!restart)
            input_block_set_capture_reg0e((c->w0 >> 12) & 0xf, value);
        break;
    }
    if (restart)
        sys_restart_channel(i, RESTART_STATE);
}
