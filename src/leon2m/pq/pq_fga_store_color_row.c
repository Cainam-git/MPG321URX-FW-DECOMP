/* pq_fga_store_color_row  (FUN_a012e928)
 *
 * Copy an 18-byte colour row into a slot of the stored block and save it.
 * Note: Writes the EEPROM.
 * Name basis: derived - 0x36-byte block of the device read and written through nvram_read / nvram_write
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012e928 @ 0xa012e928-0xa012eb4c (137 words), -mcpu=v8 -O3 -g.
 * Source form: mode_bit is the switch of pq_mode_to_color_row_bit, inlined here as a static copy; in it the
 * default arm comes first and value 0x12 has no case of its own (it takes the default 1); with an explicit case
 * 0x12 the result gets its own register.
 */

/* The FGA block in storage; fields and helper as in FGA_Init (FGA_Init). */
#define FGA_OFF_MARKER        0x00    /* one marker byte at the start of the marker area */
#define FGA_OFF_COLOR_ROWS    0x30    /* 54 bytes: 3 rows of 18 bytes */
#define FGA_AREA_THREE_BLOCKS 0x120
#define FGA_AREA_SIX_BLOCKS   0x240
#define FGA_AREA_MASK         0x360
#define FGA_ROW_KEYS          0x07    /* the three 18-byte rows of the colour table */
#define FGA_COLOR_ROWS_SIZE   0x36    /* all three rows together */
#define FGA_COLOR_ROW_SIZE    18      /* one row */
#define NVRAM_NO_COMMIT       0       /* last argument of nvram_write */
#define NVRAM_COMMIT          1
#define FGA_MARKER_COLOR_ROWS 0x79    /* marker byte for stored colour rows (within 0x77..0x7A) */

struct fga_location {
    unsigned char fga_selector;         /* +0x34: storage device of the FGA block (nvram_read / nvram_write) */
    unsigned int address : 16;          /* +0x35: start address of the FGA block on that device */
    unsigned char byte_0x37;            /* +0x37: block layout, see FGA_Init */
};
struct device_settings_record {
    unsigned char bytes_0x00[0x34];
    struct fga_location fga;
    unsigned char rest[0x18];
};
extern struct device_settings_record device_settings;
extern unsigned char pq_fga_color_rows[FGA_COLOR_ROWS_SIZE];
extern void nvram_read(unsigned char, unsigned short, unsigned short, void *);
extern void nvram_write(unsigned char, unsigned short, unsigned short, void *, unsigned char);
extern void nvram_flash_advance_row(unsigned char);

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

/* Static copy of pq_mode_to_color_row_bit: picture modes 0x10, 0x11, 0x13..0x16 give bits 1, 2, 4..7;
   every other value (0x12 too) gives bit 0. */
static int mode_bit(unsigned char v)
{
    unsigned char result;

    switch (v) {
    default:
        result = 1;
        break;
    case 0x10:
        result = 0x2;
        break;
    case 0x11:
        result = 0x4;
        break;
    case 0x13:
        result = 0x10;
        break;
    case 0x14:
        result = 0x20;
        break;
    case 0x15:
        result = 0x40;
        break;
    case 0x16:
        result = 0x80;
        break;
    }
    return result;
}

/*
 * Copy an 18-byte colour row into one slot of the stored block and save the block.
 *
 *   mode    picture mode; picks the slot: 0x10 -> slot 1, 0x11 -> slot 2, 0x13..0x16 -> no slot (nothing is
 *           copied), any other value -> slot 0
 *   src     the 18 bytes of the row to store
 *   flags   bit 0 (1): read the three stored colour rows into pq_fga_color_rows first;
 *           bit 2 (4): write them back to storage
 *
 * The slot is the number of FGA_ROW_KEYS bits below the mode's bit. The row is copied into the working copy
 * pq_fga_color_rows at that slot; the other rows are kept. With bit 2 set the 0x36 bytes are written back
 * (committed), the marker FGA_MARKER_COLOR_ROWS is written at the start of the marker area (not committed),
 * and nvram_flash_advance_row is called for the device.
 *
 * The only caller is pq_api_store_color_row, which itself has no caller found in the image.
 */
void pq_fga_store_color_row(unsigned char mode, unsigned char *src, unsigned char flags)
{
    unsigned char bit, slot, j, k;
    unsigned char mark;

    bit = mode_bit(mode);
    if (flags & 1)
        nvram_read(device_settings.fga.fga_selector, device_settings.fga.address + fga_off(FGA_OFF_COLOR_ROWS), FGA_COLOR_ROWS_SIZE, pq_fga_color_rows);
    slot = 0;
    if (!(bit & FGA_ROW_KEYS))
        slot = 0xff;
    else {
        for (j = 0; (bit >> j) != 1; j++)
            if ((FGA_ROW_KEYS >> j) & 1)
                slot++;
    }
    if (slot != 0xff)
        for (k = 0; k < FGA_COLOR_ROW_SIZE; k++)
            pq_fga_color_rows[slot * FGA_COLOR_ROW_SIZE + k] = src[k];
    if (flags & 4) {
        mark = FGA_MARKER_COLOR_ROWS;
        nvram_write(device_settings.fga.fga_selector, device_settings.fga.address + fga_off(FGA_OFF_COLOR_ROWS), FGA_COLOR_ROWS_SIZE, pq_fga_color_rows, NVRAM_COMMIT);
        nvram_write(device_settings.fga.fga_selector, device_settings.fga.address + fga_off(FGA_OFF_MARKER), 1, &mark, NVRAM_NO_COMMIT);
        nvram_flash_advance_row(device_settings.fga.fga_selector);
    }
}
