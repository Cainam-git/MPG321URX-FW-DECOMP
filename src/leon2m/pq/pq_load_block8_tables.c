/* pq_load_block8_tables  (FUN_a014118c)
 *
 * Load the pair of ROM tables with a given index into picture block 8.
 * Name basis: descriptive - 30-byte and 32-byte tables at 0x1A3668 / 0x1A3648; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014118c @ 0xa014118c-0xa01411c4 (14 words), flags -mcpu=v8 -O3 -g.
 * Source form: the two tables are symbols declared as arrays of row structs (each gets its own sethi of the same
 * high part; constant addresses would share one). The word after the range is the usual padding nop.
 */

/* One row of each ROM table. */
struct pq_block8_config_row { unsigned char bytes[0x1e]; };    /* 15 halfwords */
struct pq_block8_value_row { unsigned char bytes[0x20]; };     /* 16 byte pairs */
extern const struct pq_block8_config_row pq_block8_config_tables[];
extern const struct pq_block8_value_row pq_block8_value_tables[];
extern void pq_block8_load_tables(const struct pq_block8_config_row *, const struct pq_block8_value_row *);

/*
 * Write row 'row' of both ROM tables into picture block 8 (through pq_block8_load_tables, which also keeps
 * the two row addresses in pq_block8_config). Nothing in the firmware calls this routine.
 */
void pq_load_block8_tables(unsigned char row)
{
    pq_block8_load_tables(&pq_block8_config_tables[row], &pq_block8_value_tables[row]);
}
