/* osd_draw_factory_ssc_ratio  (FUN_a008b5e0)
 *
 * Draw the spread-spectrum ratio (x.xx %) and its register value in the factory menu.
 * Note: Inputs are the bytes 0xA802AFB8 (frequency step) and 0xA802AFB9 (ratio step).
 * Name basis: derived - texts 'nS%d.%2dP' ('$'/'%' substituted) and 'nReg 0x%2x'; field 16 = 'Ratio'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008b5e0 @ 0xa008b5e0-0xa008b83c (151 words), flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the shift by the frequency step is written in each arm of the
 * ratio < 4 test (one shared shift after the if changes the block order).
 */

/* Items of the factory menu drawn here (positions in osd_factory_menu_layout). */
#define FACTORY_ITEM_SSC_FREQ    15     /* "SSC" line, "Freq": the register line is drawn on its row */
#define FACTORY_ITEM_SSC_RATIO   16     /* "SSC" line, "Ratio": the percentage is drawn on its row */

/* Base value of the ratio table: the ratio step shifts it left (step >= 4) or right (step < 4) around
   step 4, and the frequency step shifts the result right. */
#define SSC_RATIO_BASE      0x4e
#define SSC_RATIO_STEP_PIVOT 4

/* The register value shown is (frequency step << 5) | (ratio step * 2) | 1. */
#define SSC_REG_FREQ_SHIFT  5

#define SSC_TEXT_CELLS      9           /* the length byte and up to 8 characters */
#define PERCENT_GLYPH_FIRST 'S'         /* in the format texts: replaced by '$' before drawing */
#define PERCENT_GLYPH_LAST  'P'         /* in the format texts: replaced by '%' before drawing */

/* One entry of osd_factory_menu_layout: where the label of an item sits, in character cells. */
struct factory_item_position { unsigned char col, row, len; };

extern unsigned char osd_factory_ssc_freq, osd_factory_ssc_ratio;
extern const struct factory_item_position osd_factory_menu_layout[];

extern void sprintf(unsigned char *, const char *, ...);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);

/* Draw the two lines of the spread-spectrum item of the factory menu from the two selected steps,
 * osd_factory_ssc_freq (frequency step) and osd_factory_ssc_ratio (ratio step). No parameters, no result.
 *  1. The ratio: a number v is taken from the base value 0x4e, shifted by the ratio step and then by the
 *     frequency step, and written as "whole.hundredths" followed by a percent sign (v / 100 and v % 100; the
 *     fraction gets a leading 0 below 11). The text is drawn on the row of the Ratio item, column 0x10, 9 cells.
 *  2. The register value (frequency step << 5 | ratio step * 2 | 1) is written as "Reg 0x" and two hex digits
 *     and drawn on the row of the Freq item, column 0xf.
 * Both texts are built with a placeholder byte first that is then replaced by the length of the text, which is
 * the form osd_draw_text takes. In the first text the 'S' and 'P' of the format are replaced by '$' and '%'.
 */
void osd_draw_factory_ssc_ratio(void)
{
  unsigned char digits[2];              /* whole part, hundredths */
  unsigned char buf[16];
  unsigned short ratio_value, reg_value;
  unsigned char i, c, len;

  if (osd_factory_ssc_ratio < SSC_RATIO_STEP_PIVOT)
    ratio_value = (SSC_RATIO_BASE >> (SSC_RATIO_STEP_PIVOT - osd_factory_ssc_ratio)) >> osd_factory_ssc_freq;
  else
    ratio_value = (SSC_RATIO_BASE << (osd_factory_ssc_ratio - SSC_RATIO_STEP_PIVOT)) >> osd_factory_ssc_freq;

  digits[0] = ratio_value / 100;
  digits[1] = ratio_value % 100;
  for (i = 0; i < SSC_TEXT_CELLS; i++)
    buf[i] = 0;
  if (digits[0] > 10)
    sprintf(buf, "nS%2d.%2dP", digits[0], digits[1]);
  else if (digits[1] > 10)
    sprintf(buf, "nS%d.%2dP", digits[0], digits[1]);
  else
    sprintf(buf, "nS%d.0%dP", digits[0], digits[1]);
  for (i = 0; i < SSC_TEXT_CELLS; i++) {
    c = buf[i];
    if (c == PERCENT_GLYPH_FIRST)
      buf[i] = '$';
    else if (c == PERCENT_GLYPH_LAST)
      buf[i] = '%';
    else if (c == 0)
      break;
  }
  buf[0] = i - 1;                       /* length byte: the characters after the first byte */
  osd_api_set_text_mode(0, 0);
  osd_api_set_glyph_write_address(0xdf, 0);
  osd_draw_text(0, 0x10, osd_factory_menu_layout[FACTORY_ITEM_SSC_RATIO].row, 9, buf, 0);

  reg_value = (osd_factory_ssc_freq << SSC_REG_FREQ_SHIFT) | (osd_factory_ssc_ratio * 2) | 1;
  for (i = 0; i < SSC_TEXT_CELLS; i++)
    buf[i] = 0;
  if (reg_value <= 15)
    sprintf(buf, "nReg 0x0%x", reg_value);
  else
    sprintf(buf, "nReg 0x%2x", reg_value);
  for (i = 0; i < SSC_TEXT_CELLS; i++)
    if (buf[i] == 0)
      break;
  len = i - 1;
  buf[0] = len;
  osd_draw_text(0, 0xf, osd_factory_menu_layout[FACTORY_ITEM_SSC_FREQ].row, len, buf, 0);
}
