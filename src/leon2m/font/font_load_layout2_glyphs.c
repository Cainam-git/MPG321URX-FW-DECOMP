/* font_load_layout2_glyphs  (FUN_a00a2928)
 *
 * Load the glyph blocks used by menu layer layout 2 (22 x 17 cells)
 * Note: Packed blocks from ROM via osd_api_write_packed_block; records at 0xA80240A4..0xA8024194.
 * Name basis: derived - osd_set_layout layout mode 2 tail call
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O3 -g. Source form: six calls in the order shown, each a separate call; the last is a tail call.
 */
extern unsigned short font_glyph_block_19[], font_glyph_block_17[], font_glyph_block_9[], font_glyph_block_0[], font_glyph_block_3[], font_glyph_block_2[];
extern void osd_api_write_packed_block(int, unsigned short *, int);

/* Load the glyph blocks of layout 2 (the input quick menu, 22 x 17 cells) into menu layer 0.
 * Each call sends one glyph block record: (1 = run-length coded, block, menu layer).
 * Called by osd_set_layout. */
void font_load_layout2_glyphs(void)
{
    osd_api_write_packed_block(1, font_glyph_block_19, 0);
    osd_api_write_packed_block(1, font_glyph_block_17, 0);
    osd_api_write_packed_block(1, font_glyph_block_9, 0);
    osd_api_write_packed_block(1, font_glyph_block_0, 0);
    osd_api_write_packed_block(1, font_glyph_block_3, 0);
    osd_api_write_packed_block(1, font_glyph_block_2, 0);
}
