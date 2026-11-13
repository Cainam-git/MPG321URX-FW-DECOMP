/* pq_set_scaled_level_table  (FUN_a0150a98)
 *
 * Scale a level by 48/255 and pass a four-entry table to the picture block.
 * Name basis: descriptive - table handed to pq_window_write_level_table; meaning of the entries not shown
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0150a98, flags -mcpu=v8 -O3 -g.
 * Source form: the scaled level is an unsigned short computed at its declaration; the entries are assigned in
 * the order 0, 2, 1, 3.
 */

/* The argument of pq_window_write_level_table: entry i is written only when bit i of valid_mask is set. */
struct level_table {
    unsigned int valid_mask;
    unsigned char values[24];
};

extern void pq_window_write_level_table(struct level_table *table);

#define LEVEL_SCALE_MAX 48              /* a value of 255 becomes 48 */

/*
 * Write entries 0..3 of the first level table of the selected window, from one value: with
 * scaled = value * 48 / 255, the entries are scaled / 2, scaled * 3 / 4, scaled and scaled * 3 / 4.
 * The other 20 entries are not written.
 * The only caller, pq_api_set_window_item, does this for its item 9 (PQ_ITEM_SCALED_LEVEL_TABLE) after
 * selecting the window.
 */
void pq_set_scaled_level_table(unsigned char value)
{
    struct level_table table;
    unsigned short scaled = value * LEVEL_SCALE_MAX / 255;

    table.valid_mask = 0xf;
    table.values[0] = scaled / 2;
    table.values[2] = scaled;
    table.values[1] = scaled * 3 / 4;
    table.values[3] = scaled * 3 / 4;
    pq_window_write_level_table(&table);
}
