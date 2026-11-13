/* osd_draw_custom_color_page  (FUN_a00b7474)
 *
 * Draw the custom colour page with the red, green and blue gain bars.
 * Note: Ends with the key guide (Move/Enter/... texts 0x1928b0).
 * Name basis: derived - calls osd_draw_red_gain / osd_draw_green_gain / osd_draw_blue_gain; only caller
 *   osd_open_custom_color_gains
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b7474 @ 0xa00b7474 (-mcpu=v8 -O2 -g).
 * Source form: the six parameters are declared and passed on unchanged to osd_update_key_guide (its last four
 * arguments are the caller's registers); the callees without prototypes are declared with empty parentheses.
 */
#define GLYPH_WRITE_ADDRESS   0x1e5
#define TEXT_MODE_NUMBER      2
#define KEY_GUIDE_TEXT_COLUMN 0x37              /* column of the key guide text (KEY_GUIDE_COLUMN) */
#define KEY_GUIDE_TEXT_ROW    9
#define CELL_KEY_GUIDE        0x596

extern unsigned char osd_key_guide_texts[];
extern unsigned char user_settings_language;
extern int osd_draw_text();
extern int osd_get_text();
extern int osd_clear_choice_column();
extern void osd_draw_key_guide();
extern int osd_draw_blue_gain();
extern int osd_draw_green_gain();
extern int osd_draw_red_gain();
extern int osd_update_key_guide();
extern int osd_draw_color_gain_labels();
extern void osd_api_fill_cells();
extern void osd_api_set_glyph_write_address();
extern void osd_api_set_text_mode();

/*
 * Draw the custom colour page: the red gain row highlighted, the green and blue rows plain, the R, G, B
 * labels, the key guide icons, and the key guide text in the key guide table.
 * Only caller: osd_open_custom_color_gains. The parameters are not used here; the last four are passed on to
 * osd_update_key_guide together with the guide numbers 3 and 5.
 */
void osd_draw_custom_color_page(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
{
    osd_clear_choice_column();
    osd_draw_red_gain(1);
    osd_draw_green_gain(0);
    osd_draw_blue_gain(0);
    osd_draw_color_gain_labels();
    osd_draw_key_guide(2,0);
    osd_draw_key_guide(0,1);
    osd_draw_key_guide(1,3);
    osd_api_set_glyph_write_address(GLYPH_WRITE_ADDRESS,0);
    osd_api_set_text_mode(TEXT_MODE_NUMBER,0);
    osd_api_fill_cells(KEY_GUIDE_TEXT_COLUMN,KEY_GUIDE_TEXT_ROW,4,CELL_KEY_GUIDE,0);
    osd_draw_text(0,KEY_GUIDE_TEXT_COLUMN,KEY_GUIDE_TEXT_ROW,4, osd_get_text(osd_key_guide_texts, user_settings_language), 0);
    osd_update_key_guide(3,5,param_3,param_4,param_5,param_6);
}
