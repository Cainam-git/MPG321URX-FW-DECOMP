/* input_find_next_mode_row  (FUN_a013faa0)
 *
 * Return the next mode-table row of the same group as the port's current mode.
 * Returns: row index or 0xFF
 * Name basis: descriptive - rows grouped by the high byte of halfword +0x22; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013faa0 @ 0xa013faa0-0xa013fbe8, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the first search sets a found flag and breaks; the second loop is
 * "for (i++; ; i++)" with the wrap test first; both comparisons are written with the channel record's halfword on
 * the left. No caller refers to it directly.
 */

/* The channel record, up to the field used here. */
struct channel_record_mode {
    unsigned char pad[0x3c];
    unsigned short mode_id;             /* +0x3C: the id of the matched mode-table row */
};
/* A row of the mode table (0x24 bytes), up to the fields used here. */
struct mode_row {
    unsigned char byte_0, pad1;
    unsigned short end_marker;          /* +2: 0xFFFF in the row that ends the table */
    unsigned char pad4[0x22 - 4];
    unsigned short mode_id;             /* +0x22 */
};
extern struct mode_row input_mode_table[];
extern struct channel_record_mode *sys_find_channel_by_port(unsigned char port);

#define MODE_TABLE_END 0xffff
#define NO_ROW         0xff

/*
 * Find the next mode-table row of the same group as the current mode of a port. The group is the high byte of
 * the mode id.
 *
 *   port  the port whose channel record holds the current mode id
 *
 * First the row with the current mode id is found; when there is none the answer is 0xFF. Then the rows after it
 * are walked, going back to row 0 after the last row, and the first row with another mode id but the same high
 * byte is returned. When the walk arrives at a row with the current mode id again, the answer is 0xFF.
 */
unsigned char input_find_next_mode_row(unsigned char port)
{
    struct channel_record_mode *record = sys_find_channel_by_port(port);
    unsigned char found = 0;
    unsigned char i;

    for (i = 0; input_mode_table[i].end_marker != MODE_TABLE_END; i++)
        if (record->mode_id == input_mode_table[i].mode_id) {
            found = 1;
            break;
        }
    if (found) {
        for (i++; ; i++) {
            if (input_mode_table[i].end_marker == MODE_TABLE_END)
                i = 0;
            if (record->mode_id == input_mode_table[i].mode_id)
                return NO_ROW;
            if ((record->mode_id >> 8) == (input_mode_table[i].mode_id >> 8))
                return i;
        }
    }
    return NO_ROW;
}
