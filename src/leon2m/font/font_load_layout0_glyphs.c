/* font_load_layout0_glyphs  (FUN_a00a28bc)
 *
 * Load the glyph blocks used by menu layer layout 0 (60 x 23 cells)
 * Note: Packed blocks from ROM via osd_api_write_packed_block; records at 0xA80240A4..0xA8024194.
 * Name basis: derived - osd_set_layout layout mode 0 tail call
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O3 -g. Source form: five calls in the order shown, each a separate call; the last is a tail call.
 */
extern unsigned short font_glyph_block_20[], font_glyph_block_17[], font_glyph_block_8[], font_glyph_block_6[], font_glyph_block_5[];
extern void osd_api_write_packed_block(int, unsigned short *, int);

/* Load the glyph blocks of layout 0 (the main menu, 60 x 23 cells) into menu layer 0.
 * Each call sends one glyph block record: (1 = run-length coded, block, menu layer).
 * Called by osd_set_layout, osd_setup_window_full, osd_draw_factory_info_page and osd_draw_factory_menu. */
void font_load_layout0_glyphs(void)
{
    osd_api_write_packed_block(1, font_glyph_block_20, 0);
    osd_api_write_packed_block(1, font_glyph_block_17, 0);
    osd_api_write_packed_block(1, font_glyph_block_8, 0);
    osd_api_write_packed_block(1, font_glyph_block_6, 0);
    osd_api_write_packed_block(1, font_glyph_block_5, 0);
}
