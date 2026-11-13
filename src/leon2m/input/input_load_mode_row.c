/* input_load_mode_row  (FUN_a013f284)
 *
 * Copy a row of the ROM mode table into a port's timing record.
 * Name basis: derived - 36-byte rows at 0x1A5A16; five fields scaled by the row's first byte; unused directly
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013f284 @ 0xa013f284-0xa013f370 (59 words), flags -mcpu=v8 -O3 -g.
 * Source form: the table is read through a local pointer 'table'; the row is 'row = table + row_index', but
 * the multiplier is read as table[row_index].multiplier (ldub [table + offset] operand order) and record->word_0x2c is
 * written before record->byte_0x26.
 */
/* One row of input_mode_table (0x24 bytes). Only the fields used here are named. */
struct mode_row {
    unsigned char multiplier;           /* +0: when not 0, five of the copied fields are multiplied by it */
    unsigned char pad_1[9];
    unsigned short word_0xa, word_0xc, word_0xe, word_0x10, word_0x12, word_0x14, word_0x16, word_0x18, word_0x1a,
                   word_0x1c, word_0x1e, word_0x20;
    unsigned short mode_id;             /* +0x22 */
};
/* The channel record, up to the fields written here. */
struct channel_record {
    unsigned char pad_0[0xe];
    unsigned short word_0xe, word_0x10, word_0x12, word_0x14, word_0x16, word_0x18, word_0x1a, word_0x1c, word_0x1e,
                   word_0x20;
    unsigned char pad_0x22[4];
    unsigned char byte_0x26, byte_0x27;
    unsigned short word_0x28, word_0x2a, word_0x2c;
    unsigned char pad_0x2e[0xc];
    unsigned char byte_0x3a, byte_0x3b;
    unsigned short mode_id;             /* +0x3c */
};
extern const struct mode_row input_mode_table[];
extern struct channel_record *sys_find_channel_by_port(unsigned char port);

/*
 * Copy row 'row_index' of the ROM mode table into the channel record of a port.
 *
 *   port       port number (looked up in the channel records)
 *   row_index  row of input_mode_table
 *
 * Row words +0xe..+0x14 go to record words +0x12..+0x18, row word +0xa to record words +0xe and +0x28, row word
 * +0x16 to +0x1a and +0x2a, row word +0x18 to +0x1c and +0x2c, row words +0x1a and +0x1c to +0x1e and +0x20.
 * Record byte +0x26 is set to 0x20, byte +0x3a to 0 and the mode id (+0x3c) to row word +0x22. When the row's
 * first byte (multiplier) is not 0, the record words +0x16, +0xe, +0x1e, +0x28 and +0x2a are then multiplied by it.
 * No result. No routine calls it directly; input_select_next_mode_row and input_select_mode_row_by_id contain
 * the same copy.
 */
void input_load_mode_row(unsigned char port, unsigned char row_index)
{
    struct channel_record *record = sys_find_channel_by_port(port);
    const struct mode_row *table = input_mode_table;
    const struct mode_row *row = table + row_index;

    record->word_0x12 = row->word_0xe;
    record->word_0x14 = row->word_0x10;
    record->word_0x16 = row->word_0x12;
    record->word_0x18 = row->word_0x14;
    record->word_0xe = row->word_0xa;
    record->word_0x1e = row->word_0x1a;
    record->word_0x20 = row->word_0x1c;
    record->word_0x1a = row->word_0x16;
    record->word_0x1c = row->word_0x18;
    record->word_0x28 = row->word_0xa;
    record->word_0x2a = row->word_0x16;
    record->word_0x2c = row->word_0x18;
    record->byte_0x26 = 0x20;
    record->byte_0x3a = 0;
    record->mode_id = row->mode_id;
    if (table[row_index].multiplier) {
        record->word_0x16 *= table[row_index].multiplier;
        record->word_0xe *= table[row_index].multiplier;
        record->word_0x1e *= table[row_index].multiplier;
        record->word_0x28 *= table[row_index].multiplier;
        record->word_0x2a *= table[row_index].multiplier;
    }
}
