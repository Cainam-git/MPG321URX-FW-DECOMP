/* drv_Set3DDEISC  (FUN_a0105e60)
 *
 * Find the table row for a width, height and rate and program picture block 5 with it.
 * Name basis: proven - original name printed: 'drv_Set3DDEISC no match timing'; same table as
 *   input_is_timing_supported, fallback row 2
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0105e60 @ 0xa0105e60-0xa01061c0 (216 words), flags -mcpu=v8 -O3 -g.
 * Source form: the two htotal reads index the table directly; the row pointer is taken again before the
 * BLK_VTOTAL write; row.reg62_value and row.reg66_value are read once into locals; width is copied to an
 * unsigned int (width_word) for the print and the BLK_REG_1A write, and to a separate halfword (path_width) for
 * the halving. The read of REG_CF01166C is volatile and its value is dropped.
 */

#define REG(a) (*(volatile unsigned int *)(a))
#define REG_CF01166C REG(0xcf01166c)    /* read once; the value is not used */

#define PQ_BLOCK_5 5

/* Registers of a picture block (names as in panel_output_setup_channel_timing where they appear there). */
#define BLK_REG_18         0x18         /* gets the height */
#define BLK_REG_1A         0x1a         /* gets the width */
#define BLK_REG_24         0x24
#define BLK_REG_25         0x25
#define BLK_REG_4B         0x4b
#define BLK_REG_50         0x50
#define BLK_BLANK_MODE     0x54         /* 0 = show */
#define BLK_REG_55         0x55
#define BLK_REG_59         0x59
#define BLK_VTOTAL         0x5b
#define BLK_HTOTAL         0x5e
#define BLK_REG_61         0x61
#define BLK_ROW_0X30_SUM   0x62
#define BLK_LINES          0x64
#define BLK_REG_66         0x66
#define BLK_REG_68         0x68
#define BLK_REG_6E         0x6e
#define BLK_ROW_0X30_SUM_2 0x6f
#define BLK_LINES_2        0x71
#define BLK_REG_73         0x73
#define BLK_REG_75         0x75
#define BLK_REG_79         0x79
#define BLK_REG_7D         0x7d
#define BLK_REG_86         0x86
#define BLK_REG_88         0x88
#define BLK_REG_8D         0x8d
#define BLK_REG_90         0x90
#define BLK_REG_95         0x95
#define BLK_REG_A0         0xa0
#define BLK_REG_A4         0xa4
#define BLK_REG_BE         0xbe

/*
 * A row of input_supported_timing_table (0x12 bytes). The eight rows are 720 x 480, 720 x 576, 1920 x 1080
 * (twice), 1440 x 480, 1440 x 576, 2880 x 480 and 2880 x 576, at rates 600 or 500 (tenths of a hertz).
 * Fields other than width, height and rate are named after the block register they are written to.
 */
struct supported_timing {
    unsigned short htotal;              /* +0x0: rounded up to a multiple of 8 for BLK_HTOTAL and BLK_REG_79 */
    unsigned short reg_a0_value;        /* +0x2 */
    unsigned short reg66_value;         /* +0x4: also BLK_REG_73 */
    unsigned short width;               /* +0x6 */
    unsigned short vtotal;              /* +0x8: BLK_VTOTAL */
    unsigned short reg_be_value;        /* +0xA */
    unsigned short reg62_value;         /* +0xC: BLK_ROW_0X30_SUM and BLK_ROW_0X30_SUM_2 */
    unsigned short height;              /* +0xE */
    unsigned short rate;                /* +0x10: tenths of a hertz */
};
#define SUPPORTED_TIMING_ROWS 8
#define FALLBACK_ROW          2         /* 1920 x 1080 at 600 */
#define WIDE_INPUT_WIDTH      0x780     /* 1920: wider inputs give half their width to registers 0x68 / 0x75 */

extern const struct supported_timing input_supported_timing_table[];
extern int dbg_printf(const char *fmt, ...);
extern void pq_block_write8(unsigned char block, unsigned char reg, unsigned char value);
extern void pq_block_write16(unsigned char block, unsigned char reg, unsigned short value);

/*
 * Pick the row of input_supported_timing_table that fits the input and program picture block 5 from it.
 *
 *   width, height  the size of the channel's picture
 *   rate           the channel's refresh rate, in tenths of a hertz
 *
 * A row fits when the given width is at most the row's width and more than nine tenths of it, the same for the
 * height, and the rate lies within 9 (0.9 Hz) of the row's rate: the same test as input_is_timing_supported.
 * The first fitting row is taken; with none, "drv_Set3DDEISC no match timing" is printed and row 2 is used.
 *
 * The block then gets the given size, the row's totals and the other row values, BLK_BLANK_MODE 0 (show) and a
 * fixed set of byte values. Called from sys_channel_apply_output_timing (phase 6, the picture block 5 path),
 * which then switches the selected path on.
 */
void drv_Set3DDEISC(unsigned short width, unsigned short height, unsigned short rate)
{
    unsigned char i;
    unsigned short htotal_8;
    unsigned int width_word;
    unsigned short path_width;
    const struct supported_timing *row;
    unsigned short reg62_value, reg66_value;

    REG_CF01166C;
    for (i = 0; i < SUPPORTED_TIMING_ROWS; i++) {
        row = &input_supported_timing_table[i];
        if ((unsigned short)(row->width - width) < row->width / 10 && (unsigned short)(row->height - height) < row->height / 10 &&
            (unsigned int)(row->rate - rate + 9) <= 18)
            break;
    }
    if (i == SUPPORTED_TIMING_ROWS) {
        dbg_printf("drv_Set3DDEISC no match timing\r\n");
        i = FALLBACK_ROW;
    }
    width_word = width;
    dbg_printf("index=%x %d %d\r\n", i, width_word, height);
    /* The row's horizontal total, rounded up to a multiple of 8. */
    htotal_8 = input_supported_timing_table[i].htotal >> 3;
    if (input_supported_timing_table[i].htotal & 7)
        htotal_8++;
    htotal_8 <<= 3;
    path_width = width;
    if (width_word > WIDE_INPUT_WIDTH)
        path_width >>= 1;
    pq_block_write8(PQ_BLOCK_5, BLK_REG_25, 0x1a);
    pq_block_write16(PQ_BLOCK_5, BLK_REG_18, height);
    pq_block_write16(PQ_BLOCK_5, BLK_REG_1A, width_word);
    pq_block_write8(PQ_BLOCK_5, BLK_REG_24, 0);
    pq_block_write8(PQ_BLOCK_5, BLK_BLANK_MODE, 0);
    row = &input_supported_timing_table[i];
    pq_block_write16(PQ_BLOCK_5, BLK_VTOTAL, row->vtotal);
    pq_block_write16(PQ_BLOCK_5, BLK_REG_BE, row->reg_be_value);
    pq_block_write16(PQ_BLOCK_5, BLK_HTOTAL, htotal_8);
    pq_block_write16(PQ_BLOCK_5, BLK_REG_A0, row->reg_a0_value);
    reg62_value = row->reg62_value;
    pq_block_write16(PQ_BLOCK_5, BLK_ROW_0X30_SUM, reg62_value);
    pq_block_write16(PQ_BLOCK_5, BLK_LINES, height);
    reg66_value = row->reg66_value;
    pq_block_write16(PQ_BLOCK_5, BLK_REG_66, reg66_value);
    pq_block_write16(PQ_BLOCK_5, BLK_REG_68, path_width);
    pq_block_write8(PQ_BLOCK_5, BLK_REG_6E, 7);
    /* Registers 0x6F..0x75 repeat the values of 0x62..0x68. */
    pq_block_write16(PQ_BLOCK_5, BLK_ROW_0X30_SUM_2, reg62_value);
    pq_block_write16(PQ_BLOCK_5, BLK_LINES_2, height);
    pq_block_write16(PQ_BLOCK_5, BLK_REG_73, reg66_value);
    pq_block_write16(PQ_BLOCK_5, BLK_REG_75, path_width);
    pq_block_write16(PQ_BLOCK_5, BLK_REG_79, htotal_8);
    /* Fixed settings. */
    pq_block_write8(PQ_BLOCK_5, BLK_REG_55, 0);
    pq_block_write8(PQ_BLOCK_5, BLK_REG_88, 2);
    pq_block_write8(PQ_BLOCK_5, BLK_REG_90, 0);
    pq_block_write8(PQ_BLOCK_5, BLK_REG_95, 0x40);
    pq_block_write8(PQ_BLOCK_5, BLK_REG_50, 0xc1);
    pq_block_write8(PQ_BLOCK_5, BLK_REG_7D, 200);
    pq_block_write8(PQ_BLOCK_5, BLK_REG_4B, 8);
    pq_block_write8(PQ_BLOCK_5, BLK_REG_61, 0x2e);
    pq_block_write8(PQ_BLOCK_5, BLK_REG_A4, 0);
    pq_block_write8(PQ_BLOCK_5, BLK_REG_86, 0x84);
    pq_block_write8(PQ_BLOCK_5, BLK_REG_8D, 0x20);
    pq_block_write8(PQ_BLOCK_5, BLK_REG_59, 0x83);
}
