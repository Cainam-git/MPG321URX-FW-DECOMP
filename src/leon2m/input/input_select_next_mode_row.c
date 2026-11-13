/* input_select_next_mode_row  (FUN_a013fbe8)
 *
 * Switch a port to the next mode-table row of the same group and store it.
 * Name basis: descriptive - input_load_mode_row, then nvram_store_mode_row; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013fbe8 @ 0xa013fbe8-0xa013fe2c (145 words), flags -mcpu=v8 -O3 -g.
 * Source form: the selected row is an unsigned int compared through an unsigned char cast; the found flag is
 * tested 'found == 1' (block order); the comparisons put the record value first. input_load_mode_row is a
 * static copy of input_load_mode_row and is inlined here.
 */
/* One row of input_mode_table (0x24 bytes). Only the fields used here are named. */
struct mode_row {
    unsigned char multiplier;           /* +0: when not 0, five of the copied fields are multiplied by it */
    unsigned char pad_1;
    unsigned short word_2;              /* +2: 0xffff in the end row of the table */
    unsigned char pad_4[6];
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
extern unsigned char input_get_port_sync_mode(unsigned int);
extern void nvram_store_mode_row(void *m);

/* Copy of input_load_mode_row (input_load_mode_row): copy row 'row_index' of the mode table into the port's channel record. */
static void input_load_mode_row(unsigned char port, unsigned char row_index)
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

/*
 * Move a port to the next row of the mode table that belongs to the same group as its current row, and store the
 * result. The rows of a group are the rows whose mode id (row word +0x22) has the same high byte.
 *
 *   port   port number (looked up in the channel records)
 *
 * Does nothing when the type of the port (input_get_port_sync_mode) is 5. Otherwise it finds the first row whose mode id
 * equals the channel record's mode id (+0x3c); with no such row it does nothing. From the row after it, walking
 * forward and wrapping from the end row (word +2 equal 0xffff) to row 0, the first row met is taken whose mode
 * id has the same high byte as the record's; but if a row with the record's whole mode id comes first, nothing is
 * selected. A selected row is copied into the channel record (input_load_mode_row) and stored with
 * nvram_store_mode_row(record + 6). No result. No routine calls it directly.
 */
void input_select_next_mode_row(unsigned char port)
{
    struct channel_record *record = sys_find_channel_by_port(port);
    struct channel_record *current;
    unsigned char first_match, next_row, found;
    unsigned int selected;

    if (input_get_port_sync_mode(port) == 5)
        return;
    current = sys_find_channel_by_port(port);
    found = 0;
    for (first_match = 0; input_mode_table[first_match].word_2 != 0xffff; first_match++)
        if (current->mode_id == input_mode_table[first_match].mode_id) {
            found = 1;
            break;
        }
    if (found == 1) {
        for (next_row = first_match + 1; ; next_row++) {
            if (input_mode_table[next_row].word_2 == 0xffff)
                next_row = 0;
            if (current->mode_id == input_mode_table[next_row].mode_id) {
                selected = 0xff;                /* came round to a row with the same whole id: none */
                break;
            }
            if (current->mode_id >> 8 == input_mode_table[next_row].mode_id >> 8) {
                selected = next_row;
                break;
            }
        }
    } else
        selected = 0xff;
    if ((unsigned char)selected == 0xff)
        return;
    input_load_mode_row(port, selected);
    nvram_store_mode_row((unsigned char *)record + 6);
}
