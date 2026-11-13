/* osd_api_write_cells  (FUN_a0146acc)
 *
 * Write a row of 16-bit cell values at a cell position.
 * Name basis: derived - forwards to osd_ram_write_cells; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146acc @ 0xa0146acc-0xa0146af4 (10 words), flags -mcpu=v8 -O2 -g.
 * Tail call: the callee returns straight to this routine's caller, and the last word is the nop the compiler
 * places behind such a call sequence.
 * Source form: column and row are unsigned short parameters (sll/srl 16 in the firmware) although the callee takes
 * them as unsigned int; count and layer are cut to 8 bits, the pointer is passed unchanged.
 */
extern void osd_ram_write_cells(unsigned int column, unsigned int row, unsigned char count, unsigned short *values,
                                unsigned char layer);

/* Pass the cell position (column, row), the number of values, the values and the menu layer (0 or 1) on to
 * osd_ram_write_cells. Nothing calls this routine and no stored address points at it. */
void osd_api_write_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short *values,
                         unsigned char layer)
{
    osd_ram_write_cells(column, row, count, values, layer);
}
