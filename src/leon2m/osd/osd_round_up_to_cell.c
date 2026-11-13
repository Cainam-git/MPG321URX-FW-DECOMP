/* osd_round_up_to_cell  (FUN_a011926c)
 *
 * Round a size up to a multiple of 36 when the layer's cells are 24 pixels wide, else of 9.
 * Returns: rounded value
 * Name basis: descriptive - multiple of 36 when osd_cell_widths of the layer is 24 (0x18), else of 9; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011926c @ 0xa011926c-0xa01192d0 (100 bytes, leaf), flags -mcpu=v8 -O3 -g.
 */
#define CELL_WIDTH_24       0x18                /* layers with 24-pixel cells round to 36 */
#define CELL_SIZE_36        36
#define CELL_SIZE_9         9

extern unsigned char osd_cell_widths[];   /* cell width of each menu layer, in pixels */

/*
 * Round a size up: to a multiple of 36 when the cells of the layer are 24 pixels wide (0x18), otherwise to
 * a multiple of 9. Nothing in the firmware calls this routine.
 *
 *   size   the size to round
 *   layer  index into osd_cell_widths
 */
unsigned int osd_round_up_to_cell(unsigned int size, unsigned char layer)
{
    if (osd_cell_widths[layer] == CELL_WIDTH_24)
        return (size + 0x23) / CELL_SIZE_36 * CELL_SIZE_36;
    return (size + 8) / CELL_SIZE_9 * CELL_SIZE_9;
}
