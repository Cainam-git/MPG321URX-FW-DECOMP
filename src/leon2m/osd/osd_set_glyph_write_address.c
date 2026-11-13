/* osd_set_glyph_write_address  (FUN_a011b3a0)
 *
 * Store the memory address at which the next glyph data of a menu layer is written.
 * Name basis: derived - halfword per layer at 0xA802C9A2; osd_ram_write_words24 writes there and advances it
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011b3a0 @ 0xa011b3a0 (-mcpu=v8 -O2 -g)
 * Source form: the table is declared as a byte and indexed as layer * 2 bytes through a halfword pointer cast.
 */

/* Start of a table of one halfword per menu layer: the address in the layer's memory where the next glyph data
   goes. osd_ram_write_words24 writes there and advances it. */
extern unsigned char osd_glyph_write_address;

/*
 * Set where the next glyph data of a menu layer is written.
 *
 *   address  address in the layer's memory
 *   layer    menu layer (only the low 8 bits count)
 *
 * Called through osd_api_set_glyph_write_address.
 */
void osd_set_glyph_write_address(unsigned short address, unsigned int layer)
{
    *(unsigned short *)(&osd_glyph_write_address + (layer & 0xff) * 2) = address;
    return;
}
