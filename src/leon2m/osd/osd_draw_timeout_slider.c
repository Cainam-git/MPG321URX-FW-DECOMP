/* osd_draw_timeout_slider  (FUN_a00b7674)
 *
 * Draw the OSD Time out slider with its value and key guide.
 *   editing: 1 = slider is being edited (highlighted)
 * Note: Value = settings byte +0xC (seconds); drawn highlighted while being edited.
 * Name basis: proven - callers osd_open_timeout_slider, osd_increase_osd_timeout ...
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b7674 @ 0xa00b7674-0xa00b77b4 (80 words), flags -mcpu=v8 -O3 -g.
 * Source form: the first read of the setting goes through a local base pointer and the second through the byte
 * array itself (the firmware loads the kept high part of the address again); the cell value is set in both arms
 * of the if (a default before it puts the first value in a delay slot).
 */
#define SETTING_OSD_TIMEOUT     0xc             /* user_settings byte: OSD Time out */
#define SLIDER_COLUMN           0x2c
#define SLIDER_ROW              6
#define SLIDER_KIND_WITH_GUIDE  6               /* kind argument of osd_draw_value_slider */
#define NUMBER_GLYPH_ADDRESS    0xe6            /* glyph memory address given before the number is drawn */
#define CELL_SLIDER_ACTIVE      0x742           /* cell value of the row while its slider is being adjusted */
#define CELL_BLANK              0x792           /* cell value of the row when it is not adjusted */
#define CELL_ATTRIBUTE_MASK     0x7d2
#define KEY_GUIDE_GROUP         1
#define KEY_GUIDE_ADJUSTING     3
#define KEY_GUIDE_IDLE          2
#define TEXT_MODE_NUMBER        2

extern unsigned char user_settings[];
extern void osd_api_set_glyph_write_address(unsigned int, unsigned char);
extern void osd_draw_value_slider(unsigned int, unsigned int, unsigned char, unsigned int, unsigned int);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_api_fill_cells(unsigned int, unsigned int, unsigned char, unsigned int, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned int, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);
extern void sprintf(unsigned char *, unsigned int, unsigned char);
extern void osd_api_set_text_mode(unsigned int, unsigned int);
extern void osd_draw_text(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *, unsigned int);

/*
 * Draw the OSD Time out row: the slider bar, the value as three digits at column 0x28, and the
 * key guide.
 *
 *   editing  non-zero while the slider is being adjusted: the cells take the active value and the key guide
 *            shows its adjusting mode
 *
 * The number shown is the OSD Time out setting (user_settings byte +0xC, in seconds); the slider bar is given
 * the setting times 4 minus 20, masked with 0xfc.
 */
void osd_draw_timeout_slider(unsigned char editing)
{
  unsigned short cell_value;
  unsigned char text[8];
  unsigned char *rec = user_settings;

  osd_draw_value_slider(SLIDER_COLUMN, SLIDER_ROW, (rec[SETTING_OSD_TIMEOUT] * 4 - 20) & 0xfc, SLIDER_KIND_WITH_GUIDE, editing);
  if (editing != 0) {
    cell_value = CELL_SLIDER_ACTIVE;
    osd_draw_key_guide(KEY_GUIDE_GROUP, KEY_GUIDE_ADJUSTING);
  } else {
    cell_value = CELL_BLANK;
    osd_draw_key_guide(KEY_GUIDE_GROUP, KEY_GUIDE_IDLE);
  }
  cell_value &= CELL_ATTRIBUTE_MASK;
  /* The number's three cells and the cells at columns 0x2b and 0x32 (where the two byte-plane values
     0x3f and 0x40 are set). */
  osd_api_fill_cells(0x28, SLIDER_ROW, 3, cell_value, 0);
  osd_api_fill_cells(0x2b, SLIDER_ROW, 1, cell_value, 0);
  osd_api_fill_cell_bytes(0, 0x2b, SLIDER_ROW, 1, 0x3f, 0);
  osd_api_fill_cells(0x32, SLIDER_ROW, 1, cell_value, 0);
  osd_api_fill_cell_bytes(0, 0x32, SLIDER_ROW, 1, 0x40, 0);
  osd_api_set_glyph_write_address(NUMBER_GLYPH_ADDRESS, 0);
  /* The value as a length-prefixed text of three characters. */
  sprintf(text, "n%3d", user_settings[SETTING_OSD_TIMEOUT]);
  text[0] = 3;
  osd_api_set_text_mode(TEXT_MODE_NUMBER, 0);
  osd_draw_text(0, 0x28, SLIDER_ROW, 2, text, 0);
}
