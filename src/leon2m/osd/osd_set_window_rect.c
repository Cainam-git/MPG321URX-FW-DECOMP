/* osd_set_window_rect  (FUN_a002ed14)
 *
 * Write the rectangle of the selected window of a menu layer (registers 3..10 of its block).
 *   x: left cell
 *   y: top cell
 *   last_x: last cell of the window to the right
 *   last_y: last cell of the window at the bottom
 *   block: register block of the menu layer, 0 or 1
 * Note: Same code as osd_set_window_rect_wait without the wait at the end; nothing calls it.
 * Name basis: derived - same code as osd_set_window_rect_wait minus the wait; the registers are reached
 *   through osd_layer_bases; no reference in the image
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002ed14 @ 0xa002ed14-0xa002ef0c (504 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: wr is a static helper inlined eight times, its value parameter unsigned short with the low-byte
 * arguments cast to unsigned char; x and y are unsigned short; the products are computed in the order
 * left, right, top, bottom.
 */

/* Register of a menu layer's register block, by word address (the register block sits at 0xCF000000). */
#define OSD_REG(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

/* Registers of the selected window that hold its rectangle. */
#define REG_LEFT_LOW     3              /* left edge, bits 0..7 */
#define REG_RIGHT_LOW    4              /* right edge, bits 0..7 */
#define REG_X_HIGH       5              /* left bits 8..11 | right bits 8..11 << 4 */
#define REG_TOP_LOW      6              /* top edge, bits 0..7 */
#define REG_BOTTOM_LOW   7              /* bottom edge, bits 0..7 */
#define REG_Y_HIGH       8              /* top bits 8..11 | bottom bits 8..11 << 4 */
#define REG_X_EXTRA      9              /* left bits 12..13 | right bits 12..13 << 4 */
#define REG_Y_EXTRA      10             /* top bits 12..13 | bottom bits 12..13 << 4 */

extern unsigned short osd_layer_bases[2];
extern unsigned char osd_layer_x_scales[];
extern unsigned char osd_layer_y_scales[];

/* Write register reg of block (0 or 1; any other value counts as 0). */
static void wr(unsigned char block, unsigned char reg, unsigned short val)
{
    if (block >= 2) block = 0;
    OSD_REG(osd_layer_bases[block] + reg) = val;
}

/*
 * Write the rectangle of the selected window of a menu layer. The same code as osd_set_window_rect_wait
 * without the wait for a sync pulse at the end; no call to this copy is found in the firmware.
 * The cell coordinates are multiplied by the layer's scale (osd_layer_x_scales / osd_layer_y_scales) and
 * written as 14-bit values: low bytes in their own registers, the upper bits packed in pairs.
 *   x, y:             left and top cell
 *   last_x, last_y:   last cell of the window (the right and bottom edge written are one more)
 *   block:            register block of the menu layer, 0 or 1
 */
void osd_set_window_rect(unsigned short x, unsigned short y, unsigned short last_x, unsigned short last_y, unsigned char block)
{
    unsigned short left, right, top, bottom;

    left = x * osd_layer_x_scales[block];
    right = (last_x + 1) * osd_layer_x_scales[block];
    top = y * osd_layer_y_scales[block];
    bottom = (last_y + 1) * osd_layer_y_scales[block];
    wr(block, REG_LEFT_LOW, (unsigned char)left);
    wr(block, REG_RIGHT_LOW, (unsigned char)right);
    wr(block, REG_X_HIGH, ((left >> 8) & 0xf) | ((right >> 4) & 0xf0));
    wr(block, REG_X_EXTRA, ((left >> 12) & 3) | ((right >> 8) & 0x30));
    wr(block, REG_TOP_LOW, (unsigned char)top);
    wr(block, REG_BOTTOM_LOW, (unsigned char)bottom);
    wr(block, REG_Y_HIGH, ((top >> 8) & 0xf) | ((bottom >> 4) & 0xf0));
    wr(block, REG_Y_EXTRA, ((top >> 12) & 3) | ((bottom >> 8) & 0x30));
}
