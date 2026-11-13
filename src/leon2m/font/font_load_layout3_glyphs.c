/* font_load_layout3_glyphs  (FUN_a00a29a8)
 *
 * Load the glyph blocks used by menu layer layout 3 (full width x 61 cells)
 * Note: Packed blocks from ROM via osd_api_write_packed_block; records at 0xA80240A4..0xA8024194.
 * Name basis: derived - osd_set_layout layout mode 3 tail call
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O3 -g. Source form: seven calls in the order shown, each a separate call; the last is a tail call.
 */
extern unsigned short font_glyph_block_19[], font_glyph_block_18[], font_glyph_block_17[], font_glyph_block_16[], font_glyph_block_0[],
    font_glyph_block_2[];
extern void osd_api_write_packed_block(int, unsigned short *, int);

/* Load the glyph blocks of layout 3 (screen overlays and messages) into menu layers 0 and 1; block 17 goes to both.
 * Each call sends one glyph block record: (1 = run-length coded, block, menu layer).
 * Called by osd_set_layout. Layout 5 loads the same blocks and one more. */
void font_load_layout3_glyphs(void)
{
    osd_api_write_packed_block(1, font_glyph_block_19, 0);
    osd_api_write_packed_block(1, font_glyph_block_18, 0);
    osd_api_write_packed_block(1, font_glyph_block_17, 0);
    osd_api_write_packed_block(1, font_glyph_block_17, 1);
    osd_api_write_packed_block(1, font_glyph_block_16, 0);
    osd_api_write_packed_block(1, font_glyph_block_0, 0);
    osd_api_write_packed_block(1, font_glyph_block_2, 0);
}
