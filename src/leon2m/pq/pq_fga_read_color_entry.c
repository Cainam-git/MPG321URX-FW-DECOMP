/* pq_fga_read_color_entry  (FUN_a012e550)
 *
 * Read one stored 3-byte colour entry and report whether it is valid.
 * Returns: 1 when valid
 * Name basis: derived - row bit of 0x508 and column bit of 0x92 in settings storage
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012e550 @ 0xa012e550-0xa012e6c0 (92 words), flags -mcpu=v8 -O3 without -g (no nop after the final
 * call).
 * Source form: both counts are written out in place and use the same variable index (the first is then copied to
 * row_index; the static helper bit_index is not called); the validity test is two int flags combined with '&'
 * into an unsigned char ok; the offset row_index * 9 + index * 3 is an unsigned short local inside the if.
 */

/* The FGA block in storage; fields and helper as in FGA_Init (FGA_Init). */
#define FGA_OFF_COLOR_BLOCK 0x10    /* 27 bytes: 3 rows of 3 colour triples */
#define FGA_AREA_THREE_BLOCKS 0x120
#define FGA_AREA_SIX_BLOCKS   0x240
#define FGA_AREA_MASK         0x360
#define FGA_BLOCK_KEYS        0x508   /* bit 0x008 = key 0x16, 0x100 = key 0x20, 0x400 = key 0x24 */
#define FGA_COLOR_KEYS        0x92    /* 0x02 = key 50, 0x10 = key 65, 0x80 = key 93 */
#define FGA_ROW_BYTES         9       /* bytes of one colour row: 3 triples */
#define FGA_TRIPLE_BYTES      3

struct fga_location {
    unsigned char fga_selector;         /* +0x34: storage device of the FGA block (nvram_read) */
    unsigned int address : 16;          /* +0x35: start address of the FGA block on that device */
    unsigned char byte_0x37;            /* +0x37: block layout, see FGA_Init */
};
struct device_settings_record {
    unsigned char bytes_0x00[0x34];
    struct fga_location fga;
    unsigned char rest[0x18];
};
extern struct device_settings_record device_settings;
extern void nvram_read(unsigned char, unsigned short, unsigned short, void *);

/* Offset of a part of the FGA block, from its start address. */
static unsigned short fga_off(unsigned short sub)
{
    unsigned short area;
    if (device_settings.fga.byte_0x37 <= 1)
        area = FGA_AREA_THREE_BLOCKS;
    else
        area = FGA_AREA_SIX_BLOCKS;
    return (area & FGA_AREA_MASK) + sub;
}

/* Number of bits of 'set' below the single bit 'bit', 0xFF when bit is not in set. Not called: the routine below
   has the same loop written out twice. */
static unsigned char bit_index(unsigned short bit, unsigned short set)
{
    unsigned char j;
    unsigned char index = 0;

    if (!(bit & set))
        index = 0xff;
    else {
        for (j = 0; (bit >> j) != 1; j++)
            if ((set >> j) & 1)
                index++;
    }
    return index;
}

/*
 * Read one 3-byte colour entry of the FGA colour table.
 *
 *   row  a single key bit of FGA_BLOCK_KEYS (0x008, 0x100, 0x400 -> row 0, 1, 2)
 *   col  a single key bit of FGA_COLOR_KEYS (0x02, 0x10, 0x80 -> column 0, 1, 2)
 *   rgb  receives the three colour bytes
 *   Returns 1 when the entry was read, 0 when row or col shares no bit with its key set (nothing is read).
 *
 * The entry lies at row * 9 + column * 3 in the colour block (FGA_OFF_COLOR_BLOCK) of the FGA area, read with
 * nvram_read from the device and address in device settings +0x34 / +0x35.
 *
 * Callers: pq_apply_picture_mode, pq_load_fga_color_entries.
 */
unsigned char pq_fga_read_color_entry(unsigned short row, unsigned short col, unsigned char *rgb)
{
    unsigned char row_index, index, ok, j;
    int row_ok, col_ok;
    unsigned short pos;

    ok = 0;
    index = 0;
    if (!(row & FGA_BLOCK_KEYS))
        index = 0xff;
    else {
        for (j = 0; (row >> j) != 1; j++)
            if ((FGA_BLOCK_KEYS >> j) & 1)
                index++;
    }
    row_index = index;
    index = 0;
    if (!(col & FGA_COLOR_KEYS))
        index = 0xff;
    else {
        for (j = 0; (col >> j) != 1; j++)
            if ((FGA_COLOR_KEYS >> j) & 1)
                index++;
    }
    row_ok = row_index != 0xff;
    col_ok = index != 0xff;
    if (row_ok & col_ok)
        ok = 1;
    if (ok == 1) {
        pos = row_index * FGA_ROW_BYTES + index * FGA_TRIPLE_BYTES;
        nvram_read(device_settings.fga.fga_selector, device_settings.fga.address + fga_off(FGA_OFF_COLOR_BLOCK) + pos, FGA_TRIPLE_BYTES, rgb);
    }
    return ok;
}
