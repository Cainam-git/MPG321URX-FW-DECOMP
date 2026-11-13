/* pq_load_block8_config  (FUN_a0118e04)
 *
 * Store the 16-byte configuration record and load the register tables it selects.
 * Name basis: descriptive - record kept at 0xA8027A98; registers 0x1A, 0x1B and bit 0 of 0x10 of all four port
 *   blocks; the tables at 0xCF012FD0..
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0118e04 @ 0xa0118e04-0xa011909c (166 words), flags -mcpu=v8 -O3 -g.
 * Source forms:
 *  - pq_port_set_reg10_bit0 (pq_port_set_reg10_bit0) is compiled here as a static copy and inlined; its 'on != 0' test
 *    folds away and leaves the second forming of the high part of the pq_block8_config address ('mov %l0,%i0'
 *    at 0xa0118e7c, used at 0xa0118f20 and 0xa0119034);
 *  - the table loading is the static function load_tables() that pq_block8_load_tables (pq_block8_load_tables) also
 *    contains: the firmware code from 0xa0118e7c on is that routine's code without its two stores to the
 *    record. Inferred: that this shared part is its own function in the source; with pq_block8_load_tables
 *    itself inlined (both pointers passed and stored back) the copy words at 0xa0118e20..0xa0118e2c take other
 *    registers.
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
#define ALL_PORT_BLOCKS      8              /* port block number that pq_port_write8 takes as "all four blocks" */
#define PORT_REG_10          0x10
#define PORT_REG_1A          0x1a
#define PORT_REG_1B          0x1b

extern struct pq_block8_config_record pq_block8_config;
extern void *memcpy(void *dst, const void *src, unsigned int n) __asm__("FUN_a013c910");
extern unsigned char input_measure_read8(unsigned char block, unsigned char reg);
extern void pq_port_write8(unsigned char block, unsigned char reg, unsigned char value);
extern unsigned char pq_port_read8(unsigned char block, unsigned char reg);

/* Set (on != 0) or clear bit 0 of register 0x10 of a port block; the register is read through pq_port_read8. */
static void pq_port_set_reg10_bit0(unsigned char block, unsigned char on)
{
    unsigned char reg10;

    if (on != 0) {
        reg10 = pq_port_read8(block, PORT_REG_10);
        pq_port_write8(block, PORT_REG_10, reg10 | 1);
    } else {
        reg10 = pq_port_read8(block, PORT_REG_10);
        pq_port_write8(block, PORT_REG_10, reg10 & 0xfe);
    }
}

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
 * Make config the configuration record of picture block 8 (pq_block8_config) and prepare the port blocks.
 *
 *   config  the record, passed by value: flags (bit 31 load_tables, bit 29), mode, config_table, value_table
 *
 * Registers 0x1A and 0x1B of all four port blocks get 0 and bit 0 of their register 0x10 is set (the value
 * written to all four is read from port block 0, since pq_port_read8 takes block 8 as block 0). The two tables
 * are written into the block only when load_tables is set.
 *
 * Only caller: startup_load_block8_config, with all flags clear, mode 2 and the first rows of
 * pq_block8_config_tables and pq_block8_value_tables, so at start-up the tables are stored but not written.
 */
void pq_load_block8_config(struct pq_block8_config_record config)
{
    pq_block8_config = config;
    pq_port_write8(ALL_PORT_BLOCKS, PORT_REG_1A, 0);
    pq_port_write8(ALL_PORT_BLOCKS, PORT_REG_1B, 0);
    pq_port_set_reg10_bit0(ALL_PORT_BLOCKS, 1);
    if (pq_block8_config.flags.bits.load_tables)
        load_tables();
}
