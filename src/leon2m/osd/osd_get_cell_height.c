/* osd_get_cell_height  (FUN_a01198b4)
 *
 * Return the character cell height of a menu layer in lines.
 * Returns: 16, 18 or 36
 * Name basis: derived - byte per layer at 0xA802C9B8; rows times it is compared with the panel lines
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01198b4, flags -mcpu=v8 -O2 -g (section default).
 * The table is declared as an array and indexed with a plain subscript, which gives the operand order [%g1 + %o0].
 */
extern unsigned char osd_cell_heights[]; /* 0xa802c9b8 */

/* Return the cell width code stored for a menu layer.
 *   layer: menu layer number (only the low byte is used)
 */
unsigned char osd_get_cell_height(unsigned int layer)
{
    return osd_cell_heights[layer & 0xff];
}
