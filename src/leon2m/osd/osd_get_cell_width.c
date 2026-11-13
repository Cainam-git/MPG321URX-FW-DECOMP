/* osd_get_cell_width  (FUN_a01198a0)
 *
 * Return the character cell width of a menu layer in pixels.
 * Returns: 10, 12 or 24
 * Name basis: derived - byte per layer at 0xA802C9C0; columns times it is compared with the panel width
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01198a0 @ 0xa01198a0 (-mcpu=v8 -O2 -g)
 * Source form: the layer parameter is an unsigned int masked with 0xff at the index.
 */
extern unsigned char osd_cell_widths[];   /* cell height code of each menu layer */

/* Return the cell height code of a menu layer (byte table indexed by layer). The rounding routines test the
   code for 0x18. */
unsigned char osd_get_cell_width(unsigned int layer)

{
  return osd_cell_widths[(layer & 0xff)];
}
