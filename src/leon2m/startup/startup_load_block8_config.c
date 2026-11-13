/* startup_load_block8_config  (FUN_a01410a4)
 *
 * Load the start configuration of picture block 8.
 * Name basis: descriptive - passes a record with the two ROM tables to pq_load_block8_config; called from
 *   System_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01410a4 @ 0xa01410a4, flags -mcpu=v8 -O3 -g.
 * Source form: the first word is a struct of three 1-bit fields and a 29-bit rest, set in the order bit 31,
 * bit 29, bit 30 (the other 29 bits are never written, so they keep whatever the stack slot held); the record
 * is passed by value.
 */
struct pq_block8_config_table_row { unsigned char b[0x1e]; };      /* 15 halfwords */
struct pq_block8_value_table_row { unsigned char e[16][2]; };      /* 16 byte pairs */
extern struct pq_block8_config_table_row pq_block8_config_tables[];
extern struct pq_block8_value_table_row pq_block8_value_tables[];

#define PQ_BLOCK8_START_MODE 2      /* mode value of the start configuration (modes are 1..4, as for pq_block8_set_mode) */

/* The record pq_load_block8_config copies into pq_block8_config (16 bytes). */
struct pq_block8_config_record {
    unsigned int load_tables:1, bit_30:1, bit_29:1, rest:29;    /* +0: flag bits; bit 31 = load_tables */
    unsigned int mode;                                          /* +4 */
    struct pq_block8_config_table_row *config_table;            /* +8 */
    struct pq_block8_value_table_row *value_table;              /* +0xC */
};
extern void pq_load_block8_config(struct pq_block8_config_record config);

/*
 * Load the start configuration of picture block 8: mode 2, with the first row of each of the two ROM tables
 * and all three flag bits clear (so, as the flag load_tables says, the tables are not written to the block).
 * Called once by System_Initialize (System_Initialize).
 */
void startup_load_block8_config(void)
{
    struct pq_block8_config_record config;

    config.load_tables = 0;
    config.bit_29 = 0;
    config.bit_30 = 0;
    config.mode = PQ_BLOCK8_START_MODE;
    config.config_table = pq_block8_config_tables;
    config.value_table = pq_block8_value_tables;
    pq_load_block8_config(config);
}
