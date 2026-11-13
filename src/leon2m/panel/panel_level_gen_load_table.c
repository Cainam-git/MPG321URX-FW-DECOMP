/* panel_level_gen_load_table  (FUN_a0101704)
 *
 * Load the 128-byte table of the level generator.
 * Name basis: derived - data register 0xCF0160FC between two writes of the index register
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101704 @ 0xa0101704-0xa010178c (34 words), flags -mcpu=v8 -O3 -g.
 * Source form: two loops of 0x40 with an unsigned short counter; the first reads through an unsigned int copy of
 * the counter, which gives the firmware's load operand order [table + j].
 */

/* Table port of the level generator. */
#define LEVEL_GEN_REG_F8 (*(volatile unsigned int *)0xcf0160f8)    /* 0x10 while the table is written, else 0 */
#define LEVEL_GEN_REG_FC (*(volatile unsigned int *)0xcf0160fc)    /* table data, one byte per write */

#define LEVEL_GEN_TABLE_OPEN 0x10
#define LEVEL_GEN_TABLE_HALF 0x40                                  /* the table has 2 x 0x40 = 128 bytes */

/*
 * Load the 128-byte table of the level generator.
 *
 *   table  128 bytes; startup_init_level_generator passes the rising level steps in ROM
 *          (panel_level_gen_levels)
 *
 * The bytes go one by one to the data register, in two runs of 64, between a write of 0x10 and a write of 0 to
 * register 0xCF0160F8.
 */
void panel_level_gen_load_table(unsigned char *table)
{
    unsigned short i;
    unsigned int j;

    LEVEL_GEN_REG_F8 = LEVEL_GEN_TABLE_OPEN;
    for (i = 0; i < LEVEL_GEN_TABLE_HALF; i++) {
        j = i;
        LEVEL_GEN_REG_FC = table[j];
    }
    for (i = 0; i < LEVEL_GEN_TABLE_HALF; i++)
        LEVEL_GEN_REG_FC = table[i + LEVEL_GEN_TABLE_HALF];
    LEVEL_GEN_REG_F8 = 0;
}
