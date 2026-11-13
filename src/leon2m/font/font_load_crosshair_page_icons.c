/* font_load_crosshair_page_icons  (FUN_a00a2afc)
 *
 * Load the icon glyph block shown on the Smart Crosshair page.
 * Note: Record 0xA8024170 (also part of the main menu layout set).
 * Name basis: descriptive - called by osd_draw_crosshair_icon_page, which draws
 *   'None|Icon|Color|Position|Reset' (0x18F984)
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O2 -g (the section default). Source form: the block is passed as an integer constant to an
 * undeclared-argument (K&R) prototype.
 */
extern int osd_api_write_packed_block();

/* Load the glyph block at 0xA8024170 into menu layer 0 for the crosshair icon page. The same record is also
 * loaded by layouts 0, 2, 3 and 5 (font_glyph_block_17).
 * The call sends (1 = run-length coded, block, menu layer). Called by osd_draw_crosshair_icon_page. */
void font_load_crosshair_page_icons(void)
{
  osd_api_write_packed_block(1,0xa8024170,0);
}
