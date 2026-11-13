/* pq_window_write_level_table_second  (FUN_a00f6508)
 *
 * Write the second 24-entry level table of the selected window, or the neutral value 0x80.
 * Name basis: descriptive - same index and data pair
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6508 @ 0xa00f6508 (-mcpu=v8 -O3 -g)
 * Source form: one loop with the table test inside it (GCC unswitches it into the two firmware loops);
 * same form as pq_window_write_level_table (pq_window_write_level_table), which writes 1 to 0xCF00EF34 and fills 0.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define CONTROL_REG        0xcf00ef30   /* bit 1 cleared before the writes, set after */
#define TABLE_SELECT_REG   0xcf00ef34   /* selects which table to write */
#define INDEX_REG          0xcf00ef38   /* entry index */
#define DATA_REG           0xcf00ef3c   /* entry value */
#define CONTROL_BIT1       2            /* bit 1 of CONTROL_REG */
#define SECOND_TABLE       2            /* value for the second level table */
#define NEUTRAL_VALUE      0x80         /* written to every entry when there is no table */
#define LAST_ENTRY_INDEX   0x17         /* 23, the last of 24 entries */

struct level_table {
    unsigned int mask;
    unsigned char values[24];
};

/*
 * Write the second 24-entry level table of the selected window through the index / data registers.
 * For each entry i, if the table's mask has bit i set, write table->values[i];
 * otherwise skip that entry. If table is NULL, write the neutral value 0x80 for every entry.
 * The control register bit 1 is cleared before the transfer and set after.
 * Callers: pq_api_load_level_table_second, pq_set_three_entry_table; pq_ace_init has its own inlined copy.
 */
void pq_window_write_level_table_second(struct level_table *table)
{
    unsigned char entry_index;

    /* Clear bit 1 of the control register before the transfer. */
    R(CONTROL_REG) &= ~CONTROL_BIT1;
    /* Select the second table. */
    R(TABLE_SELECT_REG) = SECOND_TABLE;
    for (entry_index = 0; entry_index <= LAST_ENTRY_INDEX; entry_index++) {
        if (table) {
            if ((table->mask >> entry_index) & 1) {
                R(INDEX_REG) = entry_index;
                R(DATA_REG) = table->values[entry_index];
            }
        } else {
            R(INDEX_REG) = entry_index;
            R(DATA_REG) = NEUTRAL_VALUE;
        }
    }
    /* Set bit 1 of the control register after the transfer. */
    R(CONTROL_REG) |= CONTROL_BIT1;
}
