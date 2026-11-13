/* osd_set_position  (FUN_a01199ac)
 *
 * Place a menu layer on the screen from percentage values and its size in cells.
 * Name basis: derived - computes the position for the active panel size and writes registers 0x81..0x86 and
 *   0xD3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01199ac @ 0xa01199ac-0xa011a060 (1716 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - K&R definition;
 *  - osd_update_reg_bits, osd_write_reg16, osd_write_columns_register, osd_is_enabled and the byte-write helper
 *    wr8 are static copies of the bodies of those routines, inlined by the compiler;
 *  - offset is an unsigned short.
 */
/* Register n of the menu layers is the word at 0xCF000000 + 4 * n; a layer's registers start at its base
 * (osd_layer_bases). */
#define OSD_REG(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short osd_layer_bases[2];
extern unsigned char osd_option_byte;
extern unsigned char osd_cell_heights[];
extern unsigned char osd_cell_widths[];
extern unsigned char osd_layer_rows[];            /* rows of each layer (osd_set_rows / osd_get_rows) */
extern unsigned short osd_layer_columns[];           /* columns of each layer (osd_set_columns / osd_get_columns) */
extern void panel_wait_sync_pulse(void);

/* Registers of a menu layer (offsets from its base). */
#define LAYER_REG_FIRST         0       /* bit 7 is cleared here, as by osd_reset_layer and osd_ram_write_block */
#define LAYER_REG_FIRST_BIT7    0x80
#define LAYER_REG_ON            0x80    /* bit 0: the layer is switched on (osd_is_enabled) */
#define LAYER_REG_X             0x81    /* 16 bits, low byte first; osd_set_origin_and_size writes it as x */
#define LAYER_REG_COLUMNS       0x83    /* columns - 1: low byte here, high byte in LAYER_REG_COLUMNS_HIGH */
#define LAYER_REG_COLUMNS_HIGH  0xd3
#define LAYER_REG_Y             0x84    /* 16 bits, low byte first; osd_set_origin_and_size writes it as y */
#define LAYER_REG_ROWS          0x86    /* rows - 1 */

/* The orientation of a layer: a 2-bit field of osd_option_byte. */
#define ORIENT_SHIFT_BLOCK0     2       /* layer 0: bits 2..3 */
#define ORIENT_SHIFT_BLOCK1     4       /* the other layer: bits 4..5 */
enum {
    ORIENT_0   = 0,                     /* the names of osd_set_layer_window_oriented */
    ORIENT_90  = 1,
    ORIENT_180 = 2,
    ORIENT_270 = 3
};
#define PERCENT                 100

static void wr16(unsigned int reg, unsigned short value)
{
    OSD_REG(reg) = (unsigned char)value;
    OSD_REG(reg + 1) = (unsigned char)(value >> 8);
}

static void osd_write_reg16(unsigned char layer, unsigned char reg, unsigned short value)
{
    if (layer > 1) layer = 0;
    wr16(osd_layer_bases[layer] + reg, value);
}

static void wr8(unsigned char layer, unsigned int reg, unsigned char value)
{
    if (layer > 1) layer = 0;
    OSD_REG(osd_layer_bases[layer] + reg) = value;
}

static void osd_update_reg_bits(unsigned char layer, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int value = OSD_REG(osd_layer_bases[layer] + reg);
    if (set == 1) value |= mask; else value &= ~mask;
    OSD_REG(osd_layer_bases[layer] + reg) = (unsigned char)value;
}

static void osd_write_columns_register(unsigned int layer, int value)
{
    wr8(layer, LAYER_REG_COLUMNS, value & 0xff);
    wr8(layer, LAYER_REG_COLUMNS_HIGH, (value >> 8) & 0xff);
}

static unsigned int osd_is_enabled(unsigned char layer)
{
    if (layer > 1) layer = 0;
    return OSD_REG(osd_layer_bases[layer] + LAYER_REG_ON) & 1;
}

/*
 * Place a menu layer on the panel: the free space left beside the layer, times a percentage, becomes the
 * layer's x and y offset.
 *
 *   percent_a, percent_b: the two position percentages, passed on by osd_api_set_position (its callers give
 *                         user_settings.menu_position_a / _b, or fixed pairs such as 50 / 50 and 1 / 98)
 *   panel_width, panel_lines: the size of the active panel mode (fields +8 and +0xA of the active panel timing
 *                         row, passed by osd_api_set_position, the only caller)
 *   layer: menu layer 0 or 1 (the register helpers use layer 0 for any value above 1)
 *
 * Phases:
 *   1. Clear bit 7 of the layer's first register.
 *   2. Read the layer's columns and rows, its two cell size codes and its orientation.
 *   3. Compute the two offsets for that orientation and write them, with columns - 1 and rows - 1, to the
 *      layer's position and size registers. "cols" is the layer's extent columns * osd_cell_widths,
 *      "rows" its extent rows * osd_cell_heights; an offset is 0 when the extent is larger than the panel
 *      size it is taken from:
 *        orientation   LAYER_REG_X                                  LAYER_REG_Y
 *        ORIENT_0      (width - cols) * a / 100                     (lines - rows) * (100 - b) / 100
 *        ORIENT_90     (width - rows) * b / 100                     (lines - cols) * a / 100
 *        ORIENT_180    (width - cols) * (100 - a) / 100             (lines - rows) * b / 100
 *        ORIENT_270    (width - rows) * (100 - b) / 100             (lines - cols) * (100 - a) / 100
 *      In ORIENT_0 the columns product is measured against the panel width; osd_set_layer_window_oriented
 *      also mirrors x coordinates against that product.
 *   4. Wait for three sync pulses of the panel when the layer is switched on, otherwise for one.
 */
void osd_set_position(percent_a, percent_b, panel_width, panel_lines, layer)
    unsigned short percent_a, percent_b, panel_width, panel_lines;
    unsigned char layer;
{
    unsigned short columns;
    unsigned char cell_code_h, cell_code_w, rows;
    int orient;
    unsigned short offset;

    /* 1. */
    osd_update_reg_bits(layer, LAYER_REG_FIRST, LAYER_REG_FIRST_BIT7, 0);

    /* 2. Size, cell codes and orientation of the layer. */
    columns = osd_layer_columns[layer];
    cell_code_h = osd_cell_widths[layer];
    cell_code_w = osd_cell_heights[layer];
    rows = osd_layer_rows[layer];
    if (layer == 0)
        orient = (osd_option_byte & (3 << ORIENT_SHIFT_BLOCK0)) >> ORIENT_SHIFT_BLOCK0;
    else
        orient = (osd_option_byte & (3 << ORIENT_SHIFT_BLOCK1)) >> ORIENT_SHIFT_BLOCK1;

    /* 3. Offsets, position and size registers. */
    switch (orient) {
    case ORIENT_90:
        if (panel_width >= cell_code_w * rows)
            offset = (unsigned int)((panel_width - cell_code_w * rows) * percent_b) / PERCENT;
        else
            offset = 0;
        osd_write_reg16(layer, LAYER_REG_X, offset);
        osd_write_columns_register(layer, columns - 1);
        if (panel_lines >= cell_code_h * columns)
            offset = (unsigned int)((panel_lines - cell_code_h * columns) * percent_a) / PERCENT;
        else
            offset = 0;
        osd_write_reg16(layer, LAYER_REG_Y, offset);
        wr8(layer, LAYER_REG_ROWS, rows - 1);
        break;
    case ORIENT_180:
        if (panel_width >= cell_code_h * columns)
            offset = (unsigned int)((panel_width - cell_code_h * columns) * (PERCENT - percent_a)) / PERCENT;
        else
            offset = 0;
        osd_write_reg16(layer, LAYER_REG_X, offset);
        osd_write_columns_register(layer, columns - 1);
        if (panel_lines >= cell_code_w * rows)
            offset = (unsigned int)((panel_lines - cell_code_w * rows) * percent_b) / PERCENT;
        else
            offset = 0;
        osd_write_reg16(layer, LAYER_REG_Y, offset);
        wr8(layer, LAYER_REG_ROWS, rows - 1);
        break;
    case ORIENT_270:
        if (panel_width >= cell_code_w * rows)
            offset = (unsigned int)((panel_width - cell_code_w * rows) * (PERCENT - percent_b)) / PERCENT;
        else
            offset = 0;
        osd_write_reg16(layer, LAYER_REG_X, offset);
        osd_write_columns_register(layer, columns - 1);
        if (panel_lines >= cell_code_h * columns)
            offset = (unsigned int)((panel_lines - cell_code_h * columns) * (PERCENT - percent_a)) / PERCENT;
        else
            offset = 0;
        osd_write_reg16(layer, LAYER_REG_Y, offset);
        wr8(layer, LAYER_REG_ROWS, rows - 1);
        break;
    default:                            /* ORIENT_0 */
        if (panel_width >= cell_code_h * columns)
            offset = (unsigned int)((panel_width - cell_code_h * columns) * percent_a) / PERCENT;
        else
            offset = 0;
        osd_write_reg16(layer, LAYER_REG_X, offset);
        osd_write_columns_register(layer, columns - 1);
        if (panel_lines >= cell_code_w * rows)
            offset = (unsigned int)((panel_lines - cell_code_w * rows) * (PERCENT - percent_b)) / PERCENT;
        else
            offset = 0;
        osd_write_reg16(layer, LAYER_REG_Y, offset);
        wr8(layer, LAYER_REG_ROWS, rows - 1);
        break;
    }

    /* 4. */
    if (osd_is_enabled(layer)) {
        panel_wait_sync_pulse();
        panel_wait_sync_pulse();
    }
    panel_wait_sync_pulse();
}
