/* osd_draw_factory_number  (FUN_a008a568)
 *
 * Draw a number as 1 or 3 digits in factory menu field id.
 *   id: field number in the ROM layout table 0x100242
 *   value
 * Note: Digits are converted to font codes (character - 47).
 * Name basis: derived - callers include the factory menu osd_factory_increase_value; sprintf '%1d' / '%3d'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008a568 @ 0xa008a568-0xa008a778 (132 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the position bytes (x, y) are read before the sprintf call;
 *  - the last branch uses its own loop counter j (with the shared counter i the delay slot of the loop entry
 *    jump holds a different instruction).
 */

/* Items of the factory menu that are drawn with a fixed layout here (see osd_factory_menu_layout). */
#define FACTORY_ITEM_FIRST_COLOUR_VALUE 1       /* items 1..12: the R, G and B values of the four colour rows */
#define FACTORY_ITEM_COLOUR_VALUE_COUNT 12
#define FACTORY_ITEM_SSC_FREQ           15      /* "SSC" line, "Freq": one digit */
#define FACTORY_ITEM_SSC_RATIO          16      /* "SSC" line, "Ratio": one digit */

/* The font code of a digit is its character code minus 47 ('0' = 1); a blank is code 0. */
#define FONT_CODE_BLANK     0
#define FONT_CODE_OFFSET    47

/* One entry of osd_factory_menu_layout: where the label of a menu item sits, in character cells. The value
   is drawn to the right of the label, at col + len. */
struct factory_item_position { unsigned char col, row, len; };

extern const struct factory_item_position osd_factory_menu_layout[];

extern void sprintf(unsigned char *, const char *, unsigned short);
extern void osd_api_write_cell_bytes(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char);

/* Draw the value of one factory menu item as decimal digits, in font codes, next to its label.
 *   id    item number, the index into osd_factory_menu_layout
 *   value the number to show
 * Three kinds of item: the colour values (items 1..12) are drawn as 3 digits one cell right of the label column;
 * the two SSC items (15, 16) as one digit at the end of the label; every other item as 3 digits at the end of
 * the label. Leading blanks of the 3-digit form stay blank. */
void osd_draw_factory_number(unsigned char id, unsigned short value)
{
  unsigned char i, x, y, j;


  if ((unsigned char)(id - FACTORY_ITEM_FIRST_COLOUR_VALUE) < FACTORY_ITEM_COLOUR_VALUE_COUNT) {
    unsigned char digits[8];

    x = osd_factory_menu_layout[id].col + 1;
    y = osd_factory_menu_layout[id].row;
    sprintf(digits, "%3d", value);
    for (i = 0; i < 3; i++) {
      if (digits[i] == ' ')
        digits[i] = FONT_CODE_BLANK;
      else
        digits[i] -= FONT_CODE_OFFSET;
    }
    osd_api_write_cell_bytes(0, x, y, 3, digits, 0);
  } else if ((unsigned char)(id - FACTORY_ITEM_SSC_FREQ) < 2) {
    unsigned char digit[1];

    x = osd_factory_menu_layout[id].col + osd_factory_menu_layout[id].len;
    y = osd_factory_menu_layout[id].row;
    sprintf(digit, "%1d", value);
    for (i = 0; i < 1; i++) {
      if (digit[i] == ' ')
        digit[i] = FONT_CODE_BLANK;
      else
        digit[i] -= FONT_CODE_OFFSET;
    }
    osd_api_write_cell_bytes(0, x, y, 1, digit, 0);
  } else {
    unsigned char digits[8];

    x = osd_factory_menu_layout[id].col + osd_factory_menu_layout[id].len;
    y = osd_factory_menu_layout[id].row;
    sprintf(digits, "%3d", value);
    for (j = 0; j < 3; j++) {
      if (digits[j] == ' ')
        digits[j] = FONT_CODE_BLANK;
      else
        digits[j] -= FONT_CODE_OFFSET;
    }
    osd_api_write_cell_bytes(0, x, y, 3, digits, 0);
  }
}
