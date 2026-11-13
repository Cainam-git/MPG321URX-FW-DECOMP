/* pq_set_block8_table_value  (FUN_a014122c)
 *
 * Store a value in a block-8 table entry and load the tables again.
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014122c @ 0xa014122c-0xa0141290 (25 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - pq_get_block8_variant is called once for each of the two stores, not once into a local;
 *  - the data word at 0xa0141290 that follows is not part of the routine.
 */

/* One configuration table of picture block 8 (0x1e bytes); the layout is read by pq_block8_load_tables. */
struct pq_block8_config_table { unsigned char bytes[0x1e]; };

/* One value table of picture block 8: a pair of bytes for each of the 16 variants. */
struct pq_block8_value_table { unsigned char pair[16][2]; };

extern struct pq_block8_config_table pq_block8_config_tables[];
extern struct pq_block8_value_table pq_block8_value_tables[];
extern unsigned char pq_get_block8_variant(void);
extern void pq_block8_load_tables(struct pq_block8_config_table *, struct pq_block8_value_table *);

/*
 * Put one value into both bytes of the current variant's pair in value table `table`, then load that table and
 * the configuration table of the same number into picture block 8.
 *
 *   table  number of the table pair (config table and value table share the number)
 *   value  the byte stored twice
 *
 * The variant is the 4-bit field of the block's register 0xCF012FDC (pq_get_block8_variant).
 * Nothing in the firmware calls this routine.
 */
void pq_set_block8_table_value(unsigned char table, unsigned char value)
{
    pq_block8_value_tables[table].pair[pq_get_block8_variant()][0] = value;
    pq_block8_value_tables[table].pair[pq_get_block8_variant()][1] = value;
    pq_block8_load_tables(&pq_block8_config_tables[table], &pq_block8_value_tables[table]);
}
