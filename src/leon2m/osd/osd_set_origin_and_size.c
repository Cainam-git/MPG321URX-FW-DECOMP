/* osd_set_origin_and_size  (FUN_a011a060)
 *
 * Write the origin and the size in cells of a menu layer, then wait for a frame.
 * Name basis: derived - x to registers 0x81/0x82, columns - 1 to 0x83/0xD3, y to 0x84/0x85, rows - 1 to 0x86
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011a060, flags -mcpu=v8 -O3 -g.
 * osd_write_reg16, osd_write_columns_register and the byte-write helper are inlined static copies; the block clamp (a layer above 1
 * counts as 0) sits in each of them.
 */
/* Registers of a menu layer: word n at 0xCF000000 + 4 * n, with n = osd_layer_bases[layer] + register number. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

#define LAYER_REG_X            0x81     /* origin x: low byte; the high byte is in register 0x82 */
#define LAYER_REG_COLUMNS_LOW  0x83     /* columns - 1: low byte; bits 8..15 are in register 0xD3 */
#define LAYER_REG_COLUMNS_HIGH 0xd3
#define LAYER_REG_Y            0x84     /* origin y: low byte; the high byte is in register 0x85 */
#define LAYER_REG_ROWS         0x86     /* rows - 1 */

extern unsigned short osd_layer_bases[2];
extern unsigned short osd_layer_columns[];   /* columns of each layer, in cells */
extern unsigned char osd_layer_rows[];    /* rows of each layer, in cells */
extern void panel_wait_sync_pulse(void);

/* Write a 16-bit value to register reg (low byte) and reg + 1 (high byte). */
static void wr16(unsigned int a, unsigned short v) { R(a) = (unsigned char)v; R(a + 1) = (unsigned char)(v >> 8); }

static void osd_write_reg16(unsigned char layer, unsigned char reg, unsigned short v)
{
    if (layer > 1) layer = 0;
    wr16(osd_layer_bases[layer] + reg, v);
}

static void wr8(unsigned char layer, unsigned int reg, unsigned char v)
{
    if (layer > 1)
        layer = 0;
    R(osd_layer_bases[layer] + reg) = v;
}

static void osd_write_columns_register(unsigned int layer, int v)
{
    wr8(layer, LAYER_REG_COLUMNS_LOW, v & 0xff);
    wr8(layer, LAYER_REG_COLUMNS_HIGH, (v >> 8) & 0xff);
}

/* Put a menu layer at (x, y) and give it the size stored for it (columns and rows minus 1), then wait for the
 * sync pulse (panel_wait_sync_pulse).
 *   x, y:  origin of the layer
 *   layer: menu layer number
 * Called through osd_api_set_origin_and_size.
 */
void osd_set_origin_and_size(unsigned short x, unsigned short y, unsigned char layer)
{
    osd_write_reg16(layer, LAYER_REG_X, x);
    osd_write_columns_register(layer, osd_layer_columns[layer] - 1);
    osd_write_reg16(layer, LAYER_REG_Y, y);
    wr8(layer, LAYER_REG_ROWS, osd_layer_rows[layer] - 1);
    panel_wait_sync_pulse();
}
