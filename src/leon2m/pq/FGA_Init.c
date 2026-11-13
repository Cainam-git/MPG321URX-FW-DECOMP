/* FGA_Init  (FUN_a012cfac)
 *
 * Write the default calibration tables to storage when the stored marker is missing.
 * Note: May write the EEPROM.
 * Name basis: proven - prints 'FGA_Init' (original name); called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012cfac @ 0xa012cfac..0xa012d4f8 (339 words), flags -mcpu=v8 -O3 -g -msoft-float. Without
 * -msoft-float it does not match (item 3).
 * Source forms the exact build depends on:
 *  (1) the row offset in color_block is the static helper row_off(row, width) ('row * width', inlined), and the
 *      store is color_block[column + row_off(k, 9) + j]: this gives the firmware's 'smul k, 9' (a literal 9 is
 *      built as sll 3 + add), and 'column + ...' first lets the loop pass hoist fp-8 + column as the firmware does;
 *  (2) the row loop's switch has an arm for every bit 0x01..0x80 (five of them the same as the default): this
 *      gives the firmware's compare tree (root 8, 'cmp 2; ble', right root 0x20); fewer arms drop tree nodes, seven
 *      arms below 0x80 give a jump table;
 *  (3) -msoft-float: in the -dL loop dump the sethi of pq_fga_default_row_bit2 / _bit4 are then 'not desirable'
 *      and only the sethi of pq_fga_default_row_bit1 (seven uses) is hoisted, as in the firmware; with hard float
 *      all three are hoisted (loop.c's threshold counts non-fixed registers, and -msoft-float makes the FP
 *      registers fixed);
 *  (4) block loop: the 'layout <= 1 && !(key_bit & 0x200)' arm is written FIRST (the arm order decides block
 *      order and registers), and 'offset += 0x60' follows each of the two tables (gives the firmware's
 *      (offset + 0x60) + address and the merged offset += 0xC0);
 *  (5) 'keys = .., key_bit = 1' in the for-init (keys set first, as in the firmware); the row loop uses
 *      unsigned char keys / bit (firmware btst 0xff);
 *  (6) frame 208 with color[3], color_block, color_rows declared first and the scalar marker after them;
 *      fga_off() is a static helper with if/else so that the '& 0x360' survives; address + fga_off(sub) keeps the
 *      firmware's (base + sub) + address order.
 * FW.012 has the same routine; it differs only in the %lo parts of moved string and RAM addresses.
 */

/*
 * The FGA block in storage. Its place comes from three fields of the device settings record. Seen from its start
 * address it holds the default blocks of 0x60 bytes first, then the marker area: 0x120 bytes in (three blocks)
 * when byte_0x37 is 0 or 1, 0x240 bytes in (six blocks) when it is above 1. The stored defaults (ROM 0x20170 +
 * 0x34) are device 0, address 0x500, byte_0x37 = 1.
 */
struct fga_location {
    unsigned char fga_selector;     /* +0x34: storage device of the FGA block (nvram_read / nvram_write) */
    unsigned int address : 16;      /* +0x35: start address of the FGA block on that device */
    unsigned char byte_0x37;        /* +0x37: block layout, see above */
};
struct device_settings_record {
    unsigned char bytes_0x00[0x34];
    struct fga_location fga;
    unsigned char rest[0x18];
};

/* Offsets inside the marker area (from fga_off()). */
#define FGA_OFF_MARKER          0x00    /* one marker byte */
#define FGA_OFF_COLOR_BLOCK     0x10    /* 27 bytes: 3 rows of 3 colour triples */
#define FGA_OFF_COLOR_ROWS      0x30    /* 54 bytes: 3 rows of 18 bytes */

#define FGA_AREA_THREE_BLOCKS   0x120
#define FGA_AREA_SIX_BLOCKS     0x240
#define FGA_AREA_MASK           0x360
#define FGA_BLOCK_SIZE          0x60
#define FGA_COLOR_BLOCK_SIZE    0x1b
#define FGA_COLOR_ROWS_SIZE     0x36
#define FGA_COLOR_ROW_SIZE      18

/* The marker: FGA_Init writes FGA_MARKER_DEFAULTS; any value FGA_MARKER_DEFAULTS .. + FGA_MARKER_RANGE counts as
   written and skips the default load. */
#define FGA_MARKER_DEFAULTS     0x77
#define FGA_MARKER_RANGE        3

/* Key bits. Each set bit gives one entry in the order of the bits:
   - FGA_COLOR_KEYS: bits of the colour-temperature key table (pq_fga_key_table_second): 0x02 = key 50,
     0x10 = key 65, 0x80 = key 93, the factory menu rows Warm 50, Normal 65 and Cool 93;
   - FGA_ROW_KEYS: the three 18-byte rows;
   - FGA_BLOCK_KEYS: bits of the first key table (pq_fga_key_table_first): 0x008 = key 0x16, 0x100 = key 0x20,
     0x400 = key 0x24. */
#define FGA_COLOR_KEYS          0x92
#define FGA_ROW_KEYS            0x07
#define FGA_BLOCK_KEYS          0x508

/* Colour triples of the part record (red, green, blue). */
#define PART_WARM50             0x06
#define PART_NORMAL65           0x09
#define PART_ENTRY_0C           0x0c
#define PART_ENTRY_0F           0x0f
#define PART_COOL93             0x12
#define PART_ENTRY_15           0x15

#define RETENTION_BIT4          0x10    /* set in the retention registers' value after a default load */
#define NVRAM_NO_COMMIT         0       /* last argument of nvram_write */

extern struct device_settings_record device_settings;
extern unsigned char part_record[];
extern const unsigned char pq_fga_default_row_bit4[], pq_fga_default_row_bit2[], pq_fga_default_row_bit1[];
extern const unsigned char pq_fga_default_block_second[], pq_fga_default_block_first[], pq_fga_default_block_key400[], pq_fga_default_block_key100[], pq_fga_default_block_key8[];
extern unsigned short oled_flag_registers_read(void);
extern void oled_flag_registers_write(unsigned short);
extern void pq_gamma_disable_secondary_lut(void);
extern int dbg_printf(const char *, ...);
extern void nvram_read(unsigned char, unsigned short, unsigned short, void *);
extern void nvram_write(unsigned char, unsigned short, unsigned short, void *, unsigned char);
extern void nvram_flash_advance_row(unsigned char);

/* Offset of a part of the marker area from the start of the FGA block. */
static unsigned short fga_off(unsigned short sub)
{
    unsigned short area;
    if (device_settings.fga.byte_0x37 <= 1)
        area = FGA_AREA_THREE_BLOCKS;
    else
        area = FGA_AREA_SIX_BLOCKS;
    return (area & FGA_AREA_MASK) + sub;
}

static int row_off(int row, int width)
{
    return row * width;
}

/*
 * Start-up step: write the default FGA data to storage once.
 *
 * Called from startup_bring_up_system at every power-on. When the marker byte of the FGA block already holds
 * 0x77..0x7A it returns without writing. Otherwise it writes the defaults and, last of all, the marker 0x77, so an
 * interrupted load is done again at the next power-on.
 *
 * Phases:
 *   1. Read the retention registers' value, print "FGA_Init", read the marker byte; return when it is 0x77..0x7A.
 *   2. Colour block (27 bytes at FGA_OFF_COLOR_BLOCK): three rows of three colour triples. Triple n of every row
 *      is the part record's triple for the n-th bit of FGA_COLOR_KEYS (Warm 50, Normal 65, Cool 93).
 *   3. Colour rows (54 bytes at FGA_OFF_COLOR_ROWS): one 18-byte ROM row per bit of FGA_ROW_KEYS.
 *   4. Default blocks from the start of the FGA block, 0x60 bytes each: with byte_0x37 0 or 1 one block per bit
 *      of FGA_BLOCK_KEYS; with byte_0x37 above 1 the two blocks 0x4fe8 and 0x4f88 per bit.
 *   5. Write the retention value back with RETENTION_BIT4 set, switch the secondary gamma table off, write the
 *      marker 0x77, and let nvram_flash_advance_row finish the area (it does nothing for an EEPROM device).
 *
 * The waits are in the storage routines: nvram_write waits for each chunk until the chip answers, without a
 * limit. A failed write is not reported.
 */
void FGA_Init(void)
{
    unsigned char color[3];
    unsigned char color_block[27];
    unsigned char color_rows[3][18];
    unsigned char marker = 0;
    unsigned char row;
    unsigned short column;
    unsigned char k;
    unsigned short retention_value, marker_offset, keys, key_bit, offset;
    unsigned char row_keys, row_bit;
    const unsigned char *default_row;

    /* Phase 1: is the FGA block already written? */
    retention_value = oled_flag_registers_read();
    dbg_printf("FGA_Init\r\n");
    marker_offset = fga_off(FGA_OFF_MARKER);
    nvram_read(device_settings.fga.fga_selector, device_settings.fga.address + marker_offset, 1, &marker);
    if ((unsigned char)(marker - FGA_MARKER_DEFAULTS) <= FGA_MARKER_RANGE)
        return;
    dbg_printf("\nLoad Default FGA %02X\r\n", marker);

    /* Phase 2: the colour block. Walk the set bits of the key mask from the lowest up; each one fills the
       next column (0, 3, 6) of all three rows. */
    column = 0;
    row = 0;
    for (keys = FGA_COLOR_KEYS, key_bit = 1; keys != 0; keys &= ~key_bit) {
        while (!(keys & key_bit))
            key_bit <<= 1;
        switch (key_bit) {
        case 0x02: color[0] = part_record[PART_WARM50 + 0]; color[1] = part_record[PART_WARM50 + 1]; color[2] = part_record[PART_WARM50 + 2]; break;
        case 0x10: color[0] = part_record[PART_NORMAL65 + 0]; color[1] = part_record[PART_NORMAL65 + 1]; color[2] = part_record[PART_NORMAL65 + 2]; break;
        case 0x20: color[0] = part_record[PART_ENTRY_0C + 0]; color[1] = part_record[PART_ENTRY_0C + 1]; color[2] = part_record[PART_ENTRY_0C + 2]; break;
        case 0x40: color[0] = part_record[PART_ENTRY_0F + 0]; color[1] = part_record[PART_ENTRY_0F + 1]; color[2] = part_record[PART_ENTRY_0F + 2]; break;
        case 0x80: color[0] = part_record[PART_COOL93 + 0]; color[1] = part_record[PART_COOL93 + 1]; color[2] = part_record[PART_COOL93 + 2]; break;
        case 0x100: color[0] = part_record[PART_ENTRY_15 + 0]; color[1] = part_record[PART_ENTRY_15 + 1]; color[2] = part_record[PART_ENTRY_15 + 2]; break;
        default: color[0] = 0xff; color[1] = 0xff; color[2] = 0xff; break;
        }
        for (k = 0; k < 3; k++) {
            color_block[column + row_off(k, 9) + 0] = color[0];
            color_block[column + row_off(k, 9) + 1] = color[1];
            color_block[column + row_off(k, 9) + 2] = color[2];
        }
        column += 3;
    }
    nvram_write(device_settings.fga.fga_selector, device_settings.fga.address + fga_off(FGA_OFF_COLOR_BLOCK), FGA_COLOR_BLOCK_SIZE, color_block, NVRAM_NO_COMMIT);


    /* Phase 3: the colour rows, one ROM row per key bit. */
    for (row_keys = FGA_ROW_KEYS, row_bit = 1; row_keys != 0; row_keys &= ~row_bit) {
        while (!(row_keys & row_bit))
            row_bit <<= 1;
        switch (row_bit) {
        case 0x01: default_row = pq_fga_default_row_bit1; break;
        case 0x02: default_row = pq_fga_default_row_bit2; break;
        case 0x04: default_row = pq_fga_default_row_bit4; break;
        case 0x08: default_row = pq_fga_default_row_bit1; break;
        case 0x10: default_row = pq_fga_default_row_bit1; break;
        case 0x20: default_row = pq_fga_default_row_bit1; break;
        case 0x40: default_row = pq_fga_default_row_bit1; break;
        case 0x80: default_row = pq_fga_default_row_bit1; break;
        default: default_row = pq_fga_default_row_bit1; break;
        }
        for (k = 0; k < FGA_COLOR_ROW_SIZE; k++)
            color_rows[row][k] = default_row[k];
        row++;
    }
    nvram_write(device_settings.fga.fga_selector, device_settings.fga.address + fga_off(FGA_OFF_COLOR_ROWS), FGA_COLOR_ROWS_SIZE, color_rows, NVRAM_NO_COMMIT);

    /* Phase 4: the default blocks, packed from the start of the FGA block. */
    offset = 0;
    for (keys = FGA_BLOCK_KEYS, key_bit = 1; keys != 0; keys &= ~key_bit) {
        while (!(keys & key_bit))
            key_bit <<= 1;
        if (device_settings.fga.byte_0x37 <= 1 && !(key_bit & 0x200)) {
            if (key_bit & 0x008) {
                nvram_write(device_settings.fga.fga_selector, device_settings.fga.address + offset, FGA_BLOCK_SIZE, (void *)pq_fga_default_block_key8, NVRAM_NO_COMMIT);
                offset += FGA_BLOCK_SIZE;
            } else if (key_bit & 0x100) {
                nvram_write(device_settings.fga.fga_selector, device_settings.fga.address + offset, FGA_BLOCK_SIZE, (void *)pq_fga_default_block_key100, NVRAM_NO_COMMIT);
                offset += FGA_BLOCK_SIZE;
            } else if (key_bit & 0x400) {
                nvram_write(device_settings.fga.fga_selector, device_settings.fga.address + offset, FGA_BLOCK_SIZE, (void *)pq_fga_default_block_key400, NVRAM_NO_COMMIT);
                offset += FGA_BLOCK_SIZE;
            }
        } else {
            nvram_write(device_settings.fga.fga_selector, device_settings.fga.address + offset, FGA_BLOCK_SIZE, (void *)pq_fga_default_block_first, NVRAM_NO_COMMIT);
            offset += FGA_BLOCK_SIZE;
            nvram_write(device_settings.fga.fga_selector, device_settings.fga.address + offset, FGA_BLOCK_SIZE, (void *)pq_fga_default_block_second, NVRAM_NO_COMMIT);
            offset += FGA_BLOCK_SIZE;
        }
    }

    /* Phase 5: finish; the marker goes last. */
    oled_flag_registers_write(retention_value | RETENTION_BIT4);
    pq_gamma_disable_secondary_lut();
    marker = FGA_MARKER_DEFAULTS;
    nvram_write(device_settings.fga.fga_selector, device_settings.fga.address + marker_offset, 1, &marker, NVRAM_NO_COMMIT);
    nvram_flash_advance_row(device_settings.fga.fga_selector);
}
