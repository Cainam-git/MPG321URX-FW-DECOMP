/* pq_set_three_entry_table  (FUN_a0150b08)
 *
 * Fill three entries of the table chosen by sel and pass it to the picture block.
 * Name basis: descriptive - table handed to pq_window_write_level_table_second
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0150b08, flags -mcpu=v8 -O3 -g.
 * Source form: the neighbour value is computed at its declaration; within each case the mask comes first, then
 * the centre entry, the lower and the upper neighbour (case 0: entries 0, 23, 1). For any other group the table
 * is passed on without being filled, as in the firmware.
 */

/* The argument of pq_window_write_level_table_second: entry i is written only when bit i of valid_mask is set. */
struct level_table {
    unsigned int valid_mask;
    unsigned char values[24];
};

extern void pq_window_write_level_table_second(struct level_table *table);

/*
 * Write three entries of the second level table of the selected window: the centre entry of a group gets the
 * low byte of value, its two neighbours get ((value >> 1) & 0x7F) + 0x40.
 *
 *   group  0: entries 23, 0, 1 (centre 0); 1: entries 7, 8, 9; 2: entries 15, 16, 17; any other value passes
 *          a table that was never filled
 *   value  the centre value
 *
 * The only caller, pq_api_set_window_item, does this for its items 10..12 (groups 0..2) after selecting the
 * window.
 */
void pq_set_three_entry_table(unsigned int group, unsigned int value)
{
    struct level_table table;
    unsigned char neighbour = ((value >> 1) & 0x7f) + 0x40;

    switch (group) {
    case 0:
        table.valid_mask = 0x800003;
        table.values[0] = value;
        table.values[23] = neighbour;
        table.values[1] = neighbour;
        break;
    case 1:
        table.valid_mask = 0x380;
        table.values[8] = value;
        table.values[7] = neighbour;
        table.values[9] = neighbour;
        break;
    case 2:
        table.valid_mask = 0x38000;
        table.values[16] = value;
        table.values[15] = neighbour;
        table.values[17] = neighbour;
        break;
    }
    pq_window_write_level_table_second(&table);
}
