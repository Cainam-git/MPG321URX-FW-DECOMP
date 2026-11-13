/* font_load_crosshair_icon2  (FUN_a00a2b3c)
 *
 * Load the glyphs of Smart Crosshair icon 2 into menu layer 1.
 * Note: Run-length coded block to layer 1; chosen when (crosshair icon setting - 1) % 6 is 1; the icon is 4 x
 *   3 cells.
 * Name basis: derived - osd_show_screen_overlays and osd_draw_overlay_position_preview pick it by
 *   (crosshair_icon - 1) % 6 == 1 and show 4 columns x 3 rows on layer 1
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O2 -g (the section default). Source form: the block is passed as an integer constant to an
 * undeclared-argument (K&R) prototype.
 */
extern int osd_api_write_packed_block();

/* Load the glyphs of Smart Crosshair icon 2 into menu layer 1 (the crosshair layer).
 * The call sends the block record at 0xa802414c: (1 = run-length coded, block, menu layer).
 * osd_show_screen_overlays and osd_draw_overlay_position_preview call it when (crosshair_icon - 1) % 6 == 1. */
void font_load_crosshair_icon2(void)
{
  osd_api_write_packed_block(1,0xa802414c,1);
}
