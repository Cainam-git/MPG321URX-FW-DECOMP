/* osd_set_layer_window_oriented  (FUN_a002e960)
 *
 * Program window registers 3..10 of a menu layer after turning the corners by the layer's orientation.
 *   x0: left
 *   y0: top
 *   x1: right
 *   y1: bottom
 *   blk: register block 0 or 1
 * Note: Orientation = bits 2..3 (block 0) or 4..5 of byte 0xA802C9B0; nothing calls it directly.
 * Name basis: descriptive - code: corner transforms against the block width/height
 *
 * Matching notes
 * --------------
 * FUN_a002e960 (leon2m 0xa002e960-0xa002ed14, 948 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the four size factors are read into unsigned int locals before the pad
 * and orientation tests and multiplied in each case; the parameters are updated in place, with the old values that
 * are still needed kept in two temporaries (in ORIENT_180 the y0 copy is taken after the x pair is done); the write
 * helper takes an unsigned short value with the low-byte arguments cast to unsigned char.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short osd_layer_bases[2];
extern unsigned char osd_option_byte;
extern unsigned char osd_cell_heights[], osd_cell_widths[], osd_layer_rows[];  /* osd_layer_rows: rows */
extern unsigned short osd_layer_columns[];                                                   /* columns */

/* Positions of the two 2-bit orientation fields in osd_option_byte. */
#define ORIENT_SHIFT_BLOCK0 2       /* block 0: bits 2..3 */
#define ORIENT_SHIFT_BLOCK1 4       /* other blocks: bits 4..5 */

/* The orientation (rotation) of a menu layer's window, in screen coordinates. */
enum {
    ORIENT_0   = 0,   /* axes as given */
    ORIENT_90  = 1,   /* 90 degrees: new x = height - old y, new y = old x */
    ORIENT_180 = 2,   /* 180 degrees: mirror both axes */
    ORIENT_270 = 3    /* 270 degrees: new x = old y, new y = width - old x */
};

/* The window coordinates x0/x1 and y0/y1 are packed into registers 3..10 (14 bits each). */
enum {
    WIN_REG_X0_LO = 3,   /* x0 low byte */
    WIN_REG_X1_LO = 4,   /* x1 low byte */
    WIN_REG_X_HI  = 5,   /* x0/x1 bits 8..11 */
    WIN_REG_Y0_LO = 6,   /* y0 low byte */
    WIN_REG_Y1_LO = 7,   /* y1 low byte */
    WIN_REG_Y_HI  = 8,   /* y0/y1 bits 8..11 */
    WIN_REG_X_EXT = 9,   /* x0/x1 bits 12..13 */
    WIN_REG_Y_EXT = 10   /* y0/y1 bits 12..13 */
};

/* Registers that decide the pad subtracted from each mirrored coordinate. */
#define WIN_PAD_CTRL_REG 0xaa       /* bit 7 set: a border pad is subtracted */
#define WIN_PAD_SIZE_REG 0xad       /* bits 0..2: pad = value + 1 */

static unsigned char rd(unsigned char blk, unsigned char reg)
{
    if (blk >= 2) blk = 0;
    return R(osd_layer_bases[blk] + reg);
}

static void wr(unsigned char blk, unsigned char reg, unsigned short val)
{
    if (blk >= 2) blk = 0;
    R(osd_layer_bases[blk] + reg) = val;
}

/*
 * Write the window (x0, y0) .. (x1, y1) into registers 3..10 of menu layer blk (0 or 1; 2 and above use layer 0),
 * after turning it by the layer's orientation in osd_option_byte (bits 2..3 for layer 0, bits 4..5 otherwise).
 *
 * The layer is W = width_code * columns wide and H = height_code * rows high. width_code is the layer's entry of
 * osd_cell_widths and height_code its entry of osd_cell_heights: the same pairing with columns and rows
 * as in osd_set_position. pad = (bits 0..2 of register 0xAD) + 1 when bit 7 of register 0xAA is set, else 0.
 *
 *   ORIENT_0    the window is written as given;
 *   ORIENT_90   x0 = H - y1 - pad, x1 = H - y0 - pad, y0 = old x0, y1 = old x1;
 *   ORIENT_180  x0 = W - x1 - pad, x1 = W - old x0 - pad, y0 = H - y1 - pad, y1 = H - old y0 - pad;
 *   ORIENT_270  x0 = old y0, x1 = old y1, y0 = W - old x1 - pad, y1 = W - old x0 - pad.
 * The new x0 (ORIENT_90, ORIENT_180) and new y0 (ORIENT_180, ORIENT_270) lose the pad only when they are at
 * least pad; the other values always lose it.
 *
 * No direct call to it was found in the image.
 */
void osd_set_layer_window_oriented(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1, unsigned char blk)
{
    unsigned int width_code, columns, height_code, rows;
    unsigned short old_x0, old_other;    /* old_other: old x1 (ORIENT_90 / 270) or old y0 (ORIENT_180) */
    unsigned char pad;
    int orient;

    width_code = osd_cell_widths[blk];
    columns = osd_layer_columns[blk];
    height_code = osd_cell_heights[blk];
    rows = osd_layer_rows[blk];
    pad = 0;
    if (rd(blk, WIN_PAD_CTRL_REG) & 0x80)
        pad = (rd(blk, WIN_PAD_SIZE_REG) & 7) + 1;
    if (blk == 0)
        orient = (osd_option_byte & (3 << ORIENT_SHIFT_BLOCK0)) >> ORIENT_SHIFT_BLOCK0;
    else
        orient = (osd_option_byte & (3 << ORIENT_SHIFT_BLOCK1)) >> ORIENT_SHIFT_BLOCK1;
    switch (orient) {
    case ORIENT_90:
        old_x0 = x0;
        old_other = x1;
        x0 = height_code * rows - y1;
        if (x0 >= pad)
            x0 -= pad;
        x1 = height_code * rows - y0 - pad;
        y0 = old_x0;
        y1 = old_other;
        break;
    case ORIENT_180:
        old_x0 = x0;
        x0 = width_code * columns - x1;
        if (x0 >= pad)
            x0 -= pad;
        x1 = width_code * columns - old_x0 - pad;
        old_other = y0;
        y0 = height_code * rows - y1;
        if (y0 >= pad)
            y0 -= pad;
        y1 = height_code * rows - old_other - pad;
        break;
    case ORIENT_270:
        old_x0 = x0;
        old_other = x1;
        x0 = y0;
        x1 = y1;
        y0 = width_code * columns - old_other;
        if (y0 >= pad)
            y0 -= pad;
        y1 = width_code * columns - old_x0 - pad;
        break;
    }
    wr(blk, WIN_REG_X0_LO, (unsigned char)x0);
    wr(blk, WIN_REG_X1_LO, (unsigned char)x1);
    wr(blk, WIN_REG_X_HI, ((x0 >> 8) & 0xf) | ((x1 >> 4) & 0xf0));
    wr(blk, WIN_REG_X_EXT, ((x0 >> 12) & 3) | ((x1 >> 8) & 0x30));
    wr(blk, WIN_REG_Y0_LO, (unsigned char)y0);
    wr(blk, WIN_REG_Y1_LO, (unsigned char)y1);
    wr(blk, WIN_REG_Y_HI, ((y0 >> 8) & 0xf) | ((y1 >> 4) & 0xf0));
    wr(blk, WIN_REG_Y_EXT, ((y0 >> 12) & 3) | ((y1 >> 8) & 0x30));
}
