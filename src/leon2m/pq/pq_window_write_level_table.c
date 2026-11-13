/* pq_window_write_level_table  (FUN_a00f643c)
 *
 * Write the first 24-entry level table of the selected window, or zeros.
 * Name basis: descriptive - masked byte table through the 0xCF00EF38 / 0xCF00EF3C index and data pair
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f643c @ 0xa00f643c (-mcpu=v8 -O3 -g)
 * Source form: one loop with the table test inside it (GCC unswitches it into the two firmware loops).
 */
/* Hardware register access macro: read/write a 32-bit volatile register. */
#define R(a) (*(volatile unsigned int *)(a))

/* Level table control/select/index/data registers. */
#define LEVEL_TABLE_CTRL_REG   0xcf00ef30
#define LEVEL_TABLE_SELECT_REG 0xcf00ef34
#define LEVEL_TABLE_INDEX_REG  0xcf00ef38
#define LEVEL_TABLE_DATA_REG   0xcf00ef3c
#define LEVEL_TABLE_CTRL_BIT1  2        /* bit 1 of the control register: cleared before the writes, set after */
#define LEVEL_TABLE_SELECT_CMD 1        /* value written to the select register for this table */
#define LEVEL_TABLE_LAST_INDEX 0x17     /* last entry index (24 entries total) */

/* A 24-entry level table: valid_mask has one bit per entry, values holds the data. */
struct level_table {
    unsigned int valid_mask;
    unsigned char values[24];
};

/*
 * Write the first 24-entry level table of the selected window, or zeros.
 *
 * The table is written through an index/data register pair. The control register
 * bit 1 is cleared before the write and set after. The select register is set to 1.
 * For each index i from 0 to 23, the index register is set to i and the data register
 * receives table->values[i] if bit i of table->valid_mask is set; otherwise that entry
 * is skipped. If table is null, all entries are written as 0.
 *
 * Callers: pq_api_load_level_table, pq_set_scaled_level_table; pq_ace_init has its own inlined copy.
 */
void pq_window_write_level_table(struct level_table *table)
{
    unsigned char i;

    R(LEVEL_TABLE_CTRL_REG) &= ~LEVEL_TABLE_CTRL_BIT1;
    R(LEVEL_TABLE_SELECT_REG) = LEVEL_TABLE_SELECT_CMD;
    for (i = 0; i <= LEVEL_TABLE_LAST_INDEX; i++) {
        if (table) {
            /* Only write entries whose bit is set in the valid mask. */
            if ((table->valid_mask >> i) & 1) {
                R(LEVEL_TABLE_INDEX_REG) = i;
                R(LEVEL_TABLE_DATA_REG) = table->values[i];
            }
        } else {
            /* Null table: write zeros for every entry. */
            R(LEVEL_TABLE_INDEX_REG) = i;
            R(LEVEL_TABLE_DATA_REG) = 0;
        }
    }
    R(LEVEL_TABLE_CTRL_REG) |= LEVEL_TABLE_CTRL_BIT1;
}
