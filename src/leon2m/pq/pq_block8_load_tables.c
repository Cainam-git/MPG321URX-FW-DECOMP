/* pq_block8_load_tables  (FUN_a0118be4)
 *
 * Remember two table pointers and write the two byte tables to picture block 8.
 * Name basis: descriptive - 15 and 16 byte pairs to the registers at 0xCF012FD0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0118be4 @ 0xa0118be4-0xa0118e04 (136 words), flags -mcpu=v8 -O3 -g.
 * Source form: default_config and default_values are initialised const local arrays, each declared with its own
 * counter i in its own block; GCC copies their initialisers (firmware 0x1a2f2f and 0x1a2f4d) to the stack with a
 * memcpy call, and memcpy is declared with the link name memcpy (an __asm__ name, no code). The two table
 * loops are the static function load_tables(), inlined here and in pq_load_block8_config (pq_load_block8_config, whose
 * code from 0xa0118e7c on is the same without the two stores). The record words are read again for each test;
 * the divisions are signed (int).
 */
#define R(a) (*(volatile unsigned int *)(a))

/* The two table register sets of picture block 8: an index register and two data registers each. */
#define BLOCK8_TABLE1_INDEX  R(0xcf012fd0)   /* entry number << 4 */
#define BLOCK8_TABLE1_HIGH   R(0xcf012fd4)
#define BLOCK8_TABLE1_LOW    R(0xcf012fd8)
#define BLOCK8_TABLE2_INDEX  R(0xcf012fe0)   /* entry number */
#define BLOCK8_TABLE2_FIRST  R(0xcf012fe4)
#define BLOCK8_TABLE2_SECOND R(0xcf012fe8)
#define CONFIG_TABLE_ENTRIES 15
#define VALUE_TABLE_ENTRIES  16

#define MEASURE_REG_29       0x29           /* register of input measurement block 0; bit 2 picks the divider */
#define MEASURE_REG_29_BIT2  4

/* pq_block8_config: the configuration record of picture block 8 (pq_load_block8_config stores it). */
struct pq_block8_config_bits { unsigned int load_tables : 1, bit30 : 1, bit29 : 1, rest : 29; };
struct pq_block8_config_record {
    union { unsigned int word; struct pq_block8_config_bits bits; } flags;     /* +0x0 */
    unsigned int mode;                  /* +0x4: 1..4, as for pq_block8_set_mode */
    unsigned short *config_table;       /* +0x8: 15 halfwords (a row of pq_block8_config_tables) */
    unsigned char *value_table;         /* +0xC: 16 byte pairs (a row of pq_block8_value_tables) */
};
extern struct pq_block8_config_record pq_block8_config;
extern void *memcpy(void *dst, const void *src, unsigned int n) __asm__("FUN_a013c910");
extern unsigned char input_measure_read8(unsigned char block, unsigned char reg);

/*
 * Write the two tables of pq_block8_config into picture block 8.
 *
 * First table, 15 entries: with a configuration table, entry i is 12000000 / divider / config_table[i], high
 * byte first, where the divider is 0x20 when bit 2 of register 0x29 of input measurement block 0 is set, else
 * 0x100. Without one (null pointer) the 15 byte pairs of default_config are written instead.
 * Second table, 16 entries: the byte pairs of the value table, or of default_values without one.
 * Both defaults are chosen by the config_table pointer alone.
 */
static void load_tables(void)
{
    unsigned short divider;

    {
        unsigned char i;
        const unsigned char default_config[30] = {
            0x3a, 0x98, 0x28, 0xda, 0x29, 0x8d, 0x1a, 0xa2, 0x16, 0x89, 0x13, 0x88, 0x11, 0x3b, 0x0f, 0x6b,
            0x0d, 0xf3, 0x0c, 0xbc, 0x0b, 0xb8, 0x0a, 0xd9, 0x0a, 0x1a, 0x09, 0x73, 0x08, 0xe0
        };

        divider = 0x20;
        if (!(input_measure_read8(0, MEASURE_REG_29) & MEASURE_REG_29_BIT2))
            divider = 0x100;
        if (pq_block8_config.config_table == 0) {
            for (i = 0; i < CONFIG_TABLE_ENTRIES; i++) {
                BLOCK8_TABLE1_INDEX = i << 4;
                BLOCK8_TABLE1_HIGH = default_config[i * 2];
                BLOCK8_TABLE1_LOW = default_config[i * 2 + 1];
            }
        } else {
            for (i = 0; i < CONFIG_TABLE_ENTRIES; i++) {
                int entry = 12000000 / divider / pq_block8_config.config_table[i];
                BLOCK8_TABLE1_INDEX = i << 4;
                BLOCK8_TABLE1_HIGH = (unsigned short)entry >> 8;
                BLOCK8_TABLE1_LOW = entry & 0xff;
            }
        }
    }
    {
        unsigned char i;
        const unsigned char default_values[32] = {
            0x4a, 0x20, 0x49, 0x24, 0x48, 0x28, 0x47, 0x2c, 0x46, 0x30, 0x45, 0x34, 0x44, 0x38, 0x43, 0x3c,
            0x42, 0x3c, 0x41, 0x3e, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40
        };

        /* The test is on config_table, not on value_table. */
        if (pq_block8_config.config_table == 0) {
            for (i = 0; i < VALUE_TABLE_ENTRIES; i++) {
                BLOCK8_TABLE2_INDEX = i;
                BLOCK8_TABLE2_FIRST = default_values[i * 2];
                BLOCK8_TABLE2_SECOND = default_values[i * 2 + 1];
            }
        } else {
            for (i = 0; i < VALUE_TABLE_ENTRIES; i++) {
                BLOCK8_TABLE2_INDEX = i;
                BLOCK8_TABLE2_FIRST = pq_block8_config.value_table[i * 2];
                BLOCK8_TABLE2_SECOND = pq_block8_config.value_table[i * 2 + 1];
            }
        }
    }
}

/*
 * Make config_table and value_table the tables of picture block 8 (stored in pq_block8_config) and write both
 * into the block (load_tables).
 *
 * Called by pq_load_block8_tables with row n of pq_block8_config_tables and of pq_block8_value_tables, and by
 * pq_set_block8_table_value after it has changed one pair of a value table.
 */
void pq_block8_load_tables(unsigned short *config_table, unsigned char *value_table)
{
    pq_block8_config.config_table = config_table;
    pq_block8_config.value_table = value_table;
    load_tables();
}
