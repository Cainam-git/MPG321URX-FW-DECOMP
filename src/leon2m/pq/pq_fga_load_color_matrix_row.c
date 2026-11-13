/* pq_fga_load_color_matrix_row  (FUN_a012e6c0)
 *
 * Read a stored 18-byte row and program it as the colour matrix.
 * Name basis: derived - unpacked into three groups of four values for the matrix register write
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012e6c0 @ 0xa012e6c0-0xa012e82c (91 words), flags -mcpu=v8 -O3 -g.
 * Source form: the offset row * 18 is an unsigned short local; the stored row is declared before the matrix
 * array (frame layout); fga_off is a static copy of the one in FGA_Init.
 */

/* Where the FGA block lies in storage (device settings +0x34, as in FGA_Init). */
struct fga_location {
    unsigned char fga_selector;     /* +0x34: storage device of the FGA block */
    unsigned int address : 16;      /* +0x35: start address of the FGA block on that device */
    unsigned char byte_0x37;        /* +0x37: block layout */
};
struct device_settings_record {
    unsigned char bytes_0x00[0x34];
    struct fga_location fga;
    unsigned char rest[0x18];
};
extern struct device_settings_record device_settings;
extern void nvram_read(unsigned char, unsigned short, unsigned short, void *);
extern void pq_color_matrix_write(unsigned char, unsigned char, unsigned short *, int);

#define FGA_AREA_THREE_BLOCKS   0x120   /* marker area offset when byte_0x37 is 0 or 1 */
#define FGA_AREA_SIX_BLOCKS     0x240   /* when it is above 1 */
#define FGA_AREA_MASK           0x360
#define FGA_OFF_COLOR_ROWS      0x30    /* 54 bytes: 3 rows of 18 bytes */
#define FGA_ROW_KEYS            0x07    /* row bits 1 / 2 / 4 = rows 0 / 1 / 2 */
#define FGA_ROW_BYTES           0x12    /* three matrix rows of three 16-bit coefficients */
#define NO_ROW                  0xff

#define MATRIX_ROWS             3
#define MATRIX_OFFSET           0x80    /* offset written with each row */
#define COLOR_MATRIX_ON         1       /* enable argument of pq_color_matrix_write */
#define COLOR_MATRIX_MODE_SET   1       /* mode argument */
#define ALL_ROW_PARTS           0xff    /* which_rows: every coefficient row and offset */

/* Offset of a part of the marker area from the start of the FGA block. */
static unsigned short fga_off(unsigned short part)
{
    unsigned short area;
    if (device_settings.fga.byte_0x37 <= 1)
        area = FGA_AREA_THREE_BLOCKS;
    else
        area = FGA_AREA_SIX_BLOCKS;
    return (area & FGA_AREA_MASK) + part;
}

/*
 * Read one 18-byte colour row from the FGA block and write it as the colour matrix.
 *
 *   row_bit   1, 2 or 4 picks row 0, 1 or 2 of the colour rows (pq_fga_store_color_row writes them)
 *
 * The row number is the count of FGA_ROW_KEYS bits below the bit; a value with none of the bits 1, 2, 4 gives
 * row 0xFF (read from offset 0xFF * 18). The 18 bytes are three matrix rows of three little-endian 16-bit
 * coefficients; each row gets 0x80 as its offset. pq_color_matrix_write switches the matrix on with the mode
 * bit set and writes every row and offset.
 *
 * Called by pq_apply_picture_mode with sys_config matrix_row_bit, for picture modes 15..22 with FGA data in
 * use.
 */
void pq_fga_load_color_matrix_row(unsigned char row_bit)
{
    unsigned char stored[FGA_ROW_BYTES] = { 0 };
    unsigned short matrix[MATRIX_ROWS][4];
    unsigned char row, b, i;
    unsigned short row_offset;

    row = 0;
    if (!(row_bit & FGA_ROW_KEYS))
        row = NO_ROW;
    else {
        for (b = 0; (row_bit >> b) != 1; b++)
            if ((FGA_ROW_KEYS >> b) & 1)
                row++;
    }
    row_offset = row * FGA_ROW_BYTES;
    nvram_read(device_settings.fga.fga_selector, device_settings.fga.address + fga_off(FGA_OFF_COLOR_ROWS) + row_offset,
               FGA_ROW_BYTES, stored);
    for (i = 0; i < MATRIX_ROWS; i++) {
        matrix[i][0] = stored[i * 6] | (stored[i * 6 + 1] << 8);
        matrix[i][1] = stored[i * 6 + 2] | (stored[i * 6 + 3] << 8);
        matrix[i][2] = stored[i * 6 + 4] | (stored[i * 6 + 5] << 8);
        matrix[i][3] = MATRIX_OFFSET;
    }
    pq_color_matrix_write(COLOR_MATRIX_ON, COLOR_MATRIX_MODE_SET, matrix[0], ALL_ROW_PARTS);
}
