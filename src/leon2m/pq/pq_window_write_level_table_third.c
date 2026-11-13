/* pq_window_write_level_table_third  (FUN_a00f65d8)
 *
 * Write a 17-entry level table of the selected window, or the neutral value 0x80.
 * Name basis: descriptive - same index and data pair; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f65d8 @ 0xa00f65d8-0xa00f66a4 (-mcpu=v8 -O3 -g).
 * Source form: one loop with the table pointer test inside it (GCC unswitches it into the two firmware loops);
 * same form as pq_window_write_level_table_second (24 entries, writes 2 to 0xCF00EF34).
 */
#define R(a) (*(volatile unsigned int *)(a))

#define REG_CF00EF30      0xcf00ef30
#define REG_CF00EF34      0xcf00ef34
#define REG_CF00EF38      0xcf00ef38
#define REG_CF00EF3C      0xcf00ef3c
#define REG_CF00EF30_BIT1 2
#define LAST_INDEX        0x10
#define NEUTRAL_LEVEL     0x80

struct level_table {
    unsigned int mask;
    unsigned char values[24];
};

/*
 * Write the 17-entry level table for the selected window.
 * If table is non-null, for each bit i set in table->mask, write table->values[i] to the data register;
 * entries with clear bits are skipped. If table is null, write the neutral value 0x80 for every entry.
 * The index/data register pair is used: bit 1 of REG_CF00EF30 is cleared, REG_CF00EF34 is set to 0,
 * then for i=0..16 the index register REG_CF00EF38 is set to i and the data register REG_CF00EF3C is written.
 * Finally bit 1 of REG_CF00EF30 is set.
 * No direct call to it was found in the image; pq_ace_init has its own inlined copy.
 */
void pq_window_write_level_table_third(struct level_table *table)
{
    unsigned char i;

    R(REG_CF00EF30) &= ~REG_CF00EF30_BIT1;
    R(REG_CF00EF34) = 0;
    for (i = 0; i <= LAST_INDEX; i++) {
        if (table) {
            /* Only entries with the corresponding bit set are written. */
            if ((table->mask >> i) & 1) {
                R(REG_CF00EF38) = i;
                R(REG_CF00EF3C) = table->values[i];
            }
        } else {
            /* Null table: write the neutral value for every entry. */
            R(REG_CF00EF38) = i;
            R(REG_CF00EF3C) = NEUTRAL_LEVEL;
        }
    }
    R(REG_CF00EF30) |= REG_CF00EF30_BIT1;
}
