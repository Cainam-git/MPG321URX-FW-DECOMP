/* input_select_mode_row_by_id  (FUN_a013fe2c)
 *
 * Switch a port to the mode-table row with a given id and store it.
 * Name basis: descriptive - row whose halfword +0x22 equals the id; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013fe2c @ 0xa013fe2c-0xa013ffb0 (97 words), flags -mcpu=v8 -O3 -g.
 * Source form: row_index is initialised in its declaration; the search loop sets row_index = 0xff at the end row
 * and breaks, and the single 'row_index == 0xff' test after the loop covers both outcomes. input_load_mode_row is
 * a static copy of input_load_mode_row and is inlined here.
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
extern unsigned char nvram_load_saved_mode_row(void *m);

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
 * Move a port to the row of the mode table with a given id, then restore or store the saved adjustments of
 * that mode.
 *
 *   port     port number (looked up in the channel records)
 *   mode_id  id to look for: row word +0x22 of input_mode_table
 *
 * Does nothing when the type of the port (input_get_port_sync_mode) is 5, or when no row before the end row
 * (word +2 equal 0xffff) has that id. Otherwise the first row with that id is copied into the channel record
 * (input_load_mode_row). Then nvram_load_saved_mode_row(record + 6) tries to restore a saved row for the mode;
 * only when it finds none, nvram_store_mode_row(record + 6) stores the record. No result. No routine calls it
 * directly.
 */
void input_select_mode_row_by_id(unsigned char port, unsigned short mode_id)
{
    struct channel_record *record = sys_find_channel_by_port(port);
    unsigned char row_index = 0;

    if (input_get_port_sync_mode(port) == 5)
        return;
    for (; ; row_index++) {
        if (input_mode_table[row_index].word_2 == 0xffff) {
            row_index = 0xff;
            break;
        }
        if (input_mode_table[row_index].mode_id == mode_id)
            break;
    }
    if (row_index == 0xff)
        return;
    input_load_mode_row(port, row_index);
    if (nvram_load_saved_mode_row((unsigned char *)record + 6) == 0)
        nvram_store_mode_row((unsigned char *)record + 6);
}
