/* font_load_layout4_glyphs  (FUN_a00a2adc)
 *
 * Load the glyph blocks used by menu layer layout 4 (8 x 3 cells)
 * Note: Packed blocks from ROM via osd_api_write_packed_block; records at 0xA80240A4..0xA8024194.
 * Name basis: derived - osd_set_layout layout mode 4 tail call
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O2 -g (the section default). Source form: the block is passed as an integer constant to an
 * undeclared-argument (K&R) prototype.
 */
extern int osd_api_write_packed_block();

/* Load the glyph block of layout 4 (8 x 3 cells) into menu layer 0.
 * The call sends the block record at 0xA80240D4: (1 = run-length coded, block, menu layer).
 * Called by osd_set_layout. */
void font_load_layout4_glyphs(void)
{
  osd_api_write_packed_block(1,0xa80240d4,0);
}
