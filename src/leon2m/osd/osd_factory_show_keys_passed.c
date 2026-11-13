/* osd_factory_show_keys_passed  (FUN_a008b2bc)
 *
 * Show "All Key Pass" in the factory key test.
 * Name basis: proven - draws ROM texts 'All', 'Key', 'Pass' on one row
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008b2bc, flags -mcpu=v8 -O3 -g.
 * The three texts are string literals; the last osd_draw_text call is a tail call.
 */

extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);

#define KEY_TEST_ROW 10

/* Draw the words "All", "Key" and "Pass" side by side in row 10 (each text starts with its length byte). */
void osd_factory_show_keys_passed(void)
{
  osd_api_set_glyph_write_address(0xdc, 0);
  osd_draw_text(0, 1, KEY_TEST_ROW, 3, "\003" "All", 0);
  osd_draw_text(0, 3, KEY_TEST_ROW, 3, "\003" "Key", 0);
  osd_draw_text(0, 6, KEY_TEST_ROW, 4, "\004" "Pass", 0);
}
