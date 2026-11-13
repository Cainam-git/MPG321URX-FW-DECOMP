/* font_load_layout5_glyphs  (FUN_a00a2a38)
 *
 * Load the glyph blocks used by menu layer layout 5 (56 x 27 cells)
 * Note: Packed blocks from ROM via osd_api_write_packed_block; records at 0xA80240A4..0xA8024194.
 * Name basis: derived - osd_set_layout layout mode 5 tail call
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O3 -g. Source form: eight calls in the order shown, each a separate call; the last is a tail call.
 */
extern unsigned short font_glyph_block_19[], font_glyph_block_18[], font_glyph_block_17[], font_glyph_block_16[], font_glyph_block_0[],
    font_glyph_block_2[], font_glyph_block_1[];
extern void osd_api_write_packed_block(int, unsigned short *, int);

/* Load the glyph blocks of layout 5 (the panel protect prompt, 56 x 27 cells) into menu layers 0 and 1; block 17 goes to both.
 * Each call sends one glyph block record: (1 = run-length coded, block, menu layer).
 * Called by osd_set_layout. Layout 3 loads the same blocks without block 1. */
void font_load_layout5_glyphs(void)
{
    osd_api_write_packed_block(1, font_glyph_block_19, 0);
    osd_api_write_packed_block(1, font_glyph_block_18, 0);
    osd_api_write_packed_block(1, font_glyph_block_17, 0);
    osd_api_write_packed_block(1, font_glyph_block_17, 1);
    osd_api_write_packed_block(1, font_glyph_block_16, 0);
    osd_api_write_packed_block(1, font_glyph_block_0, 0);
    osd_api_write_packed_block(1, font_glyph_block_2, 0);
    osd_api_write_packed_block(1, font_glyph_block_1, 0);
}
