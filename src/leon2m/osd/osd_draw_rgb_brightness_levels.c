/* osd_draw_rgb_brightness_levels  (FUN_a00ac0c4)
 *
 * Draw the five RGB Brightness level texts.
 * Name basis: derived - texts 0x18A758 ('40%', ...); called by osd_open_rgb_brightness_slider
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ac0c4 @ 0xa00ac0c4, flags -mcpu=v8 -O2 -g (section default).
 */
extern unsigned char osd_rgb_brightness_level_texts[];
extern void osd_clear_choice_column(void);
extern void osd_api_set_glyph_write_address(unsigned short address, unsigned char layer);
extern void osd_api_set_text_mode(unsigned short mode, unsigned char layer);
extern unsigned int osd_get_text(int table, unsigned short index);
extern void osd_draw_text(int plane, int column, int row, int width, unsigned int text, int layer);

#define PLANE_0                    0
#define MENU_LAYER_MAIN            0
#define TEXT_ALIGN_LEFT            0
#define CHOICE_TEXT_COLUMN         0x2a    /* column of the choice texts */
#define CHOICE_FIRST_ROW           6       /* row of the first choice; the choices are two rows apart */
#define CHOICE_GLYPH_ADDRESS       0x111   /* glyph memory address given before choice texts are drawn */
#define RGB_BRIGHTNESS_LEVELS      5       /* levels 0..4 */

/* Draw the five RGB Brightness level texts as the choice list: the choice column is cleared and
 * level i (text i of osd_rgb_brightness_level_texts) is drawn left-aligned on row 2 * i + 6. */
void osd_draw_rgb_brightness_levels(void)
{
    unsigned char level;

    osd_clear_choice_column();
    osd_api_set_glyph_write_address(CHOICE_GLYPH_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);

    for (level = 0; level < RGB_BRIGHTNESS_LEVELS; level++) {
        unsigned int text = osd_get_text(osd_rgb_brightness_level_texts, level);
        osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, (level * 2) + CHOICE_FIRST_ROW, 1, text, MENU_LAYER_MAIN);
    }
}
