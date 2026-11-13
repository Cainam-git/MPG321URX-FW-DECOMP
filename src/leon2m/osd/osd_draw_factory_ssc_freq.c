/* osd_draw_factory_ssc_freq  (FUN_a008b380)
 *
 * Draw the selected spread-spectrum clock frequency (kHz/MHz) in the factory menu.
 * Note: Byte 0xA802AFB8 (0..7) picks 23.4 kHz .. 3 MHz from a local table.
 * Name basis: derived - texts 'n%2d.%dKHz' / 'n%d.%dMHz', field 15 = 'Freq' under ROM label 'SSC'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008b380, flags -mcpu=v8 -O3 -g.
 * Called by osd_factory_decrease_value, osd_factory_increase_value and osd_draw_factory_menu.
 * Source form: the v < 1000 test first, then v > 10000 (the other two orders change the block layout).
 */

#define FACTORY_ITEM_SSC_FREQ   15              /* factory menu item 15 */

/* One entry of osd_factory_menu_layout: where the label of an item sits, in character cells. Its value field
   starts at col + len. */
struct factory_item_position { unsigned char col, row, len; };

extern unsigned char osd_factory_ssc_freq;
extern const struct factory_item_position osd_factory_menu_layout[];

extern void sprintf(unsigned char *, const char *, unsigned short, unsigned short);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);

/*
 * Draw the spread-spectrum frequency chosen in the factory menu (osd_factory_ssc_freq, 0..7) in the value field
 * of item 15. The frequency comes from a table of eight values in tenths of a kHz and is written as
 * "nn.nKHz", "nnn.nKHz" (below 1000, or up to 10000) or "n.nMHz" (above 10000). The text is built after a
 * placeholder first character, which is then replaced by the length byte (number of characters that follow).
 */
void osd_draw_factory_ssc_freq(void)
{
  unsigned short freq_table[8] = { 234, 468, 937, 1875, 3750, 7500, 15000, 30000 };
  unsigned char text[16];
  unsigned short freq;
  unsigned char i;

  freq = freq_table[osd_factory_ssc_freq];
  for (i = 0; i < 9; i++)
    text[i] = 0;
  if (freq < 1000)
    sprintf(text, "n%2d.%dKHz", freq / 10, freq % 10);
  else if (freq > 10000)
    sprintf(text, "n%d.%dMHz", freq / 10000, (freq % 10000) / 1000);
  else
    sprintf(text, "n%3d.%dKHz", freq / 10, freq % 10);
  for (i = 0; i < 9; i++)
    if (text[i] == 0)
      break;
  text[0] = i - 1;
  osd_api_set_text_mode(0, 0);
  osd_api_set_glyph_write_address(0xd9, 0);
  osd_draw_text(0, osd_factory_menu_layout[FACTORY_ITEM_SSC_FREQ].col + osd_factory_menu_layout[FACTORY_ITEM_SSC_FREQ].len, osd_factory_menu_layout[FACTORY_ITEM_SSC_FREQ].row, text[0], text, 0);
}
