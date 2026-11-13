/* osd_get_last_text_width  (FUN_a00a3838)
 *
 * Return the pixel width of the text drawn last.
 * Returns: width in pixels
 * Note: Halfword 0xA802B088, summed by osd_draw_text.
 * Name basis: derived - osd_draw_text pass 1 sums the glyph widths into 0xA802B088
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a3838, flags -mcpu=v8 -O2 -g.
 * A leaf routine without a register window.
 */
extern unsigned short osd_last_text_width;

/*
 * Return the width, in pixels, of the text that osd_draw_text drew last. osd_draw_text sums the glyph widths
 * of its text into osd_last_text_width.
 */
unsigned short osd_get_last_text_width(void)

{
  return osd_last_text_width;
}
