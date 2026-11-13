/* input_match_port_mode  (FUN_a013f370)
 *
 * Match a port's measured timing against the known modes and store the result.
 * Name basis: derived - per-port mode match; uses the saved-mode table; called from the bring-up state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013f370 @ 0xa013f370, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: 'if (sync mode != 5) {search} else {sync mode 5}' in this order (the block order before layout
 *   decides the register choice of -frename-registers). 'if (found == 1)' (gcc predicts a compare with a constant
 *   as false, so the fall-back arm is the fall-through) with the nvram_load_saved_mode_row check written in BOTH
 *   arms. The port status bits are bit-fields (lets gcc move the input_port_status_bit10_mask store after the next load). In the
 *   search loop the rows are read as input_mode_table[i].field, in the sync-mode-5 loop through 'row'. abs() is
 *   the builtin. The order of the local declarations matters (register spill of best_score).
 */

/* The channel record (0x78 bytes), the fields this routine reads and writes. Offsets are from the start of the
   record; the input timing begins at +6. */
struct channel_record {
    unsigned char pad0[6];
    unsigned short line_rate, refresh_rate;     /* +6: 100 Hz units; +8: tenths of a hertz */
    unsigned char pixel_repeat, pad0b;          /* +0xA */
    unsigned char register_0x23, pad0d;         /* +0xC: copy of port record +0x23 */
    unsigned short half_0x0e, half_0x10, half_0x12, half_0x14, half_0x16;
    unsigned short active_lines;                /* +0x18: timing field 10 */
    unsigned short half_0x1a;
    unsigned short capture_width;               /* +0x1C */
    unsigned short half_0x1e, half_0x20;
    unsigned char pad22[4];
    unsigned char byte_0x26, pad27;             /* +0x26 */
    unsigned short half_0x28, half_0x2a, half_0x2c;
    unsigned char pad2e[12];
    unsigned char byte_0x3a, pad3b;             /* +0x3A */
    unsigned short mode_id;                     /* +0x3C: id of the matched row */
};

/* One row of the mode table in ROM (0x24 bytes). The table ends at a row whose line_rate is MODE_TABLE_END. */
struct mode_row {
    unsigned char scale, pad1;                  /* +0: when not 0, five copied fields are multiplied by it */
    unsigned short line_rate, refresh_rate;     /* +2, +4: compared with the channel's */
    unsigned char pixel_repeat_mask, pad7;      /* +6: tested against the pixel repeat for sync mode 2 */
    unsigned char register_0x23, pad9;          /* +8: compared with the channel's register 0x23 copy */
    unsigned short half_0x0a, half_0x0c, half_0x0e, half_0x10, half_0x12;
    unsigned short active_lines;                /* +0x14: copied to the channel's active_lines */
    unsigned short half_0x16;
    unsigned short capture_width;               /* +0x18: copied to the channel's capture_width */
    unsigned short half_0x1a, half_0x1c;
    unsigned char line_rate_tolerance;          /* +0x1E */
    unsigned char refresh_rate_tolerance;       /* +0x1F */
    unsigned short half_0x20;
    unsigned short id;                          /* +0x22: bit 0 = the interlace flag the row is for */
};

/* One entry of input_short_mode_list (13 entries of 4 bytes). */
struct short_mode_entry { unsigned char kind, pad; unsigned short mode_id; };

/* The port record (0x2A bytes), the parts read here. */
struct port_record {
    unsigned short bit15:1, bit14:1, bit13:1, bit12:1, bit11:1, status_bit10:1, bit9:1, bit8:1, status_bit7:1,
                   bit6:1, bit5:1, low_bits:5;  /* +0: status halfword */
    unsigned char pad2[0x14];
    unsigned short half_0x16, half_0x18;        /* +0x16, +0x18: set by input_port_sync_task */
    unsigned char pad1a[0x10];
};
extern struct port_record port_records[];
extern struct mode_row input_mode_table[];
extern struct short_mode_entry input_short_mode_list[];
extern unsigned char input_port_status_bit7_mask, input_port_status_bit10_mask;
extern struct channel_record *sys_find_channel_by_port(unsigned char);
extern void input_block_check_signal(unsigned char);
extern unsigned char input_get_port_sync_mode(unsigned int);
extern unsigned char input_block_get_status_bit2(unsigned char);
extern unsigned char nvram_load_saved_mode_row(void *);
extern void nvram_store_mode_row(void *);

#define MODE_TABLE_END       0xffff     /* line_rate of the row after the last */
#define SHORT_LIST_ENTRIES   13
#define KIND_EXCLUDED_ID     12         /* short-list entries of this kind name mode ids the search skips */
#define SYNC_MODE_2          2          /* sync modes of the port (input_get_port_sync_mode) */
#define SYNC_MODE_5          5
#define BYTE_0X26_ON_COPY    0x20       /* stored in byte +0x26 of the channel record with every copied row */
#define NO_ROW_ID            0xff00     /* high byte of the mode id when no row matched */

/* 1 when the id is named by a kind-12 entry of the short list. */
static unsigned char is_excluded_mode(unsigned short id)
{
    unsigned char j;
    for (j = 0; j < SHORT_LIST_ENTRIES; j++)
        if (input_short_mode_list[j].kind == KIND_EXCLUDED_ID && input_short_mode_list[j].mode_id == id)
            return 1;
    return 0;
}

extern int abs(int);
#define ABS(x) abs(x)

/*
 * Copy row k of the mode table into the port's channel record. Row +0x0A, +0x16 and +0x18 each go to two places
 * (channel +0x0E / +0x28, +0x1A / +0x2A, capture_width / +0x2C). With a scale in the row, channel +0x16, +0x0E,
 * +0x1E, +0x28 and +0x2A are multiplied by it.
 */
static void apply_mode_row(unsigned char port, unsigned char k)
{
    struct channel_record *dest;

    dest = sys_find_channel_by_port(port);
    dest->half_0x12 = input_mode_table[k].half_0x0e;
    dest->half_0x14 = input_mode_table[k].half_0x10;
    dest->half_0x16 = input_mode_table[k].half_0x12;
    dest->active_lines = input_mode_table[k].active_lines;
    dest->half_0x0e = input_mode_table[k].half_0x0a;
    dest->half_0x1e = input_mode_table[k].half_0x1a;
    dest->half_0x20 = input_mode_table[k].half_0x1c;
    dest->half_0x1a = input_mode_table[k].half_0x16;
    dest->capture_width = input_mode_table[k].capture_width;
    dest->half_0x28 = input_mode_table[k].half_0x0a;
    dest->half_0x2a = input_mode_table[k].half_0x16;
    dest->half_0x2c = input_mode_table[k].capture_width;
    dest->byte_0x26 = BYTE_0X26_ON_COPY;
    dest->byte_0x3a = 0;
    dest->mode_id = input_mode_table[k].id;
    if (input_mode_table[k].scale) {
        dest->half_0x16 = dest->half_0x16 * input_mode_table[k].scale;
        dest->half_0x0e = dest->half_0x0e * input_mode_table[k].scale;
        dest->half_0x1e = dest->half_0x1e * input_mode_table[k].scale;
        dest->half_0x28 = dest->half_0x28 * input_mode_table[k].scale;
        dest->half_0x2a = dest->half_0x2a * input_mode_table[k].scale;
    }
}

/*
 * Find the mode table row that fits the measured timing of a port and store it in the port's channel record.
 *
 *   port  the port; its channel record is the one sys_find_channel_by_port returns
 *
 * Called once per bring-up, in MODE_MODESEARCH step 1 of input_channel_bring_up_task (the only caller), after
 * step 0 has copied the port's timing into the channel record.
 *
 * 1. Status bits 10 and 7 of the port record go into the port's bit of input_port_status_bit10_mask and input_port_status_bit7_mask (read back
 *    by input_get_port_mask_bit and input_get_port_mask_bit_alt).
 * 2. input_block_check_signal prepares the capture registers and writes the interlace flag into bit 2 of capture
 *    register 0; input_block_get_status_bit2 reads it back below ("interlaced").
 * 3. Sync mode other than 5: a search over the whole mode table. A row is passed over when its id is excluded
 *    (is_excluded_mode) or bit 0 of its id differs from the interlace flag. Of the rest, the row whose +0x0C is
 *    nearest to channel +0x10, among those whose +0x10 is below channel +0x10, is kept as the fall-back. A row is a
 *    candidate when line rate and refresh rate are within the row's tolerances, for sync mode 2 when the pixel
 *    repeat has a bit of the row's mask, and when the row's +0x10 is below channel +0x10 (doubled when
 *    interlaced). The candidate with the lowest score wins:
 *        (|line rate diff| + |refresh rate diff| + 4 * |channel +0x10 - row +0x0C|) * 100 + |register 0x23 diff|
 *    Without a candidate the fall-back row (row 0 when there is none) is copied and the mode id becomes
 *    0xFF00 | (row id >> 8). Either way nvram_load_saved_mode_row then restores the saved row for this timing,
 *    and when there is none nvram_store_mode_row stores this one.
 * 4. Sync mode 5: two values come from the port record, +0x16 and +0x18 (doubled when interlaced). They and
 *    defaults are stored first (mode id 0xFF00, 0x1E0 in capture_width, +0x20 and +0x2C). The first row whose
 *    +0x12 is within 5 of port +0x16, whose active_lines is within 6 of port +0x18, and whose line rate and
 *    refresh rate are within 9 of the channel's then sets channel +0x12, +0x14 and the mode id. The saved-mode
 *    table is not used on this path.
 */
void input_match_port_mode(unsigned char port)
{
    struct mode_row *row;
    unsigned short port_0x16;
    unsigned short channel_0x10;
    unsigned char i;
    unsigned char nearest_row;
    unsigned char best_row;
    unsigned short nearest_distance;
    struct channel_record *channel;
    unsigned char found;
    unsigned char channel_reg23;
    int diff;
    unsigned int best_score;
    unsigned short port_lines;
    unsigned int score;

    channel = sys_find_channel_by_port(port);
    if (port_records[port].status_bit10)
        input_port_status_bit10_mask |= 1 << port;
    else
        input_port_status_bit10_mask &= ~(1 << port);
    if (port_records[port].status_bit7)
        input_port_status_bit7_mask |= 1 << port;
    else
        input_port_status_bit7_mask &= ~(1 << port);
    input_block_check_signal(port);
    if (input_get_port_sync_mode(port) != SYNC_MODE_5) {
        best_score = 0xffffffff;
        nearest_row = 0;
        best_row = 0;
        nearest_distance = 0xffff;
        channel_reg23 = channel->register_0x23;
        found = 0;
        for (i = 0; input_mode_table[i].line_rate != MODE_TABLE_END; i++) {
            if (is_excluded_mode(input_mode_table[i].id))
                continue;
            if (input_block_get_status_bit2(port) != (input_mode_table[i].id & 1))
                continue;
            /* Fall-back: nearest row by +0x0C. */
            if (channel->half_0x10 > input_mode_table[i].half_0x10) {
                diff = channel->half_0x10 - input_mode_table[i].half_0x0c;
                if (ABS(diff) < nearest_distance) {
                    nearest_distance = ABS(diff);
                    nearest_row = i;
                }
            }
            diff = channel->line_rate - input_mode_table[i].line_rate;
            if (ABS(diff) > input_mode_table[i].line_rate_tolerance)
                continue;
            diff = channel->refresh_rate - input_mode_table[i].refresh_rate;
            if (ABS(diff) > input_mode_table[i].refresh_rate_tolerance)
                continue;
            if (input_get_port_sync_mode(port) == SYNC_MODE_2 && !(channel->pixel_repeat & input_mode_table[i].pixel_repeat_mask))
                continue;
            channel_0x10 = channel->half_0x10;
            if (input_block_get_status_bit2(port) == 1)
                channel_0x10 += channel_0x10;
            if (input_mode_table[i].half_0x10 >= channel_0x10)
                continue;
            score = (ABS(channel->line_rate - input_mode_table[i].line_rate) + ABS(channel->refresh_rate - input_mode_table[i].refresh_rate) + ABS(channel->half_0x10 - input_mode_table[i].half_0x0c) * 4) * 100 + ABS(channel_reg23 - input_mode_table[i].register_0x23);
            found = 1;
            if (score < best_score) {
                best_score = score;
                best_row = i;
            }
        }
        if (found == 1) {
            apply_mode_row(port, best_row);
            if (!nvram_load_saved_mode_row(&channel->line_rate))
                nvram_store_mode_row(&channel->line_rate);
        } else {
            apply_mode_row(port, nearest_row);
            channel->mode_id = (channel->mode_id >> 8) | NO_ROW_ID;
            if (!nvram_load_saved_mode_row(&channel->line_rate))
                nvram_store_mode_row(&channel->line_rate);
        }
    } else {
        port_lines = port_records[port].half_0x18;
        if (input_block_get_status_bit2(port))
            port_lines *= 2;
        port_0x16 = port_records[port].half_0x16;
        channel->capture_width = 0x1e0;
        channel->half_0x20 = 0x1e0;
        channel->mode_id = NO_ROW_ID;
        channel->half_0x16 = port_0x16;
        channel->half_0x14 = port_lines;
        channel->half_0x12 = port_0x16;
        channel->active_lines = port_lines;
        channel->half_0x1a = 0;
        channel->half_0x1e = 0;
        channel->half_0x2a = 0;
        channel->half_0x2c = 0x1e0;
        for (i = 0; input_mode_table[i].line_rate != MODE_TABLE_END; i++) {
            row = &input_mode_table[i];
            /* Each test is 'difference within +-n', written as one unsigned compare. */
            if ((unsigned int)(port_0x16 - row->half_0x12 + 5) <= 10 && (unsigned int)(port_lines - row->active_lines + 6) <= 12 &&
                (unsigned int)(channel->line_rate - row->line_rate + 9) <= 18 && (unsigned int)(channel->refresh_rate - row->refresh_rate + 9) <= 18) {
                channel->half_0x12 = row->half_0x0e;
                channel->half_0x14 = row->half_0x10;
                channel->mode_id = row->id;
                return;
            }
        }
    }
}
