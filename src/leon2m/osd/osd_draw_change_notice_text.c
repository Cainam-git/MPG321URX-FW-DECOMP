/* osd_draw_change_notice_text  (FUN_a00b05d8)
 *
 * Draw the 'Confirm Change !' notice text with its Yes and No buttons.
 * Note: Text explains that the change affects the power consumption of the monitor.
 * Name basis: proven - texts 0x1819CC 'Confirm Change !', 0x181058 '...the power consumption of this
 *   monitor.', 0x190748 Yes/No
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b05d8 @ 0xa00b05d8, flags -mcpu=v8 -O3 -g.
 * Source form: each text table is addressed by its own symbol (the firmware builds each address with a
 * high-part/low-part pair), and the settings record is reached through one local pointer (kept in a
 * callee-saved register). Callee prototypes as in osd_draw_pip_pbp_items.
 */
struct user_settings_record { unsigned char pad[8]; unsigned char language; };
extern struct user_settings_record user_settings;
extern unsigned int osd_change_notice_title_texts[], osd_change_notice_line1_texts[], osd_change_notice_line2_texts[], osd_change_notice_line3_texts[], osd_yes_no_texts[];
extern void osd_api_set_glyph_write_address(unsigned short address, unsigned char layer);
extern void osd_api_set_text_mode(int mode, int layer);
extern unsigned int osd_get_text(unsigned int *table, unsigned short index);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);

#define PLANE_0                  0
#define MENU_LAYER_MAIN          0
#define TEXT_ALIGN_CENTRE        2
#define LANGUAGE_COUNT           29    /* texts of one entry for every language, in language order */
#define NOTICE_GLYPH_ADDRESS     0x4e  /* glyph memory address given before the texts are drawn */
#define NOTICE_TITLE_COLUMN      9
#define NOTICE_TITLE_ROW         1
#define NOTICE_TITLE_WIDTH       0x16
#define NOTICE_LINE_COLUMN       2
#define NOTICE_LINE_WIDTH        0x24
#define NOTICE_YES_COLUMN        0xa
#define NOTICE_NO_COLUMN         0x16
#define NOTICE_BUTTON_ROW        8
#define NOTICE_BUTTON_WIDTH      8

/* Draw the texts of the 'Confirm Change !' notice, all centred and in the menu language: the title on
 * row 1, three lines of explanation on rows 3 to 5 (the second one ends with the firmware's text about the
 * power consumption of the monitor) and the button texts Yes (column 0xA) and No (column 0x16) on row 8.
 * The Yes and No texts are entries 0 and 1 of osd_yes_no_texts (No is 29 texts further on). The text mode
 * stays centred afterwards. */
void osd_draw_change_notice_text(void)
{
    struct user_settings_record *settings;

    osd_api_set_glyph_write_address(NOTICE_GLYPH_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_ALIGN_CENTRE, MENU_LAYER_MAIN);
    settings = &user_settings;
    osd_draw_text(PLANE_0, NOTICE_TITLE_COLUMN, NOTICE_TITLE_ROW, NOTICE_TITLE_WIDTH, osd_get_text(osd_change_notice_title_texts, settings->language), MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, NOTICE_LINE_COLUMN, 3, NOTICE_LINE_WIDTH, osd_get_text(osd_change_notice_line1_texts, settings->language), MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, NOTICE_LINE_COLUMN, 4, NOTICE_LINE_WIDTH, osd_get_text(osd_change_notice_line2_texts, settings->language), MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, NOTICE_LINE_COLUMN, 5, NOTICE_LINE_WIDTH, osd_get_text(osd_change_notice_line3_texts, settings->language), MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, NOTICE_YES_COLUMN, NOTICE_BUTTON_ROW, NOTICE_BUTTON_WIDTH, osd_get_text(osd_yes_no_texts, settings->language), MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, NOTICE_NO_COLUMN, NOTICE_BUTTON_ROW, NOTICE_BUTTON_WIDTH, osd_get_text(osd_yes_no_texts, settings->language + LANGUAGE_COUNT), MENU_LAYER_MAIN);
}
