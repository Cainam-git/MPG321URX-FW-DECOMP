/* osd_draw_rgb_led_choices  (FUN_a00b77b4)
 *
 * Draw the RGB LED choices and mark the current one.
 * Note: Current choice from bits 6 and 5 of settings word +0xA8.
 * Name basis: derived - texts 0x193248 'OFF|ON|RGB Brightness' (Settings item RGB LED)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b77b4 @ 0xa00b77b4 (-mcpu=v8 -O3 -g).
 * Source form: the tables at 0x193248 and 0x193330 are extern array symbols; the choice is a local unsigned
 * char set to 0 before the bit test; osd_highlight_choice_row and osd_draw_choice_mark are declared with
 * unsigned char arguments.
 */
#define GLYPH_WRITE_ADDRESS   0x111
#define TEXT_MODE_NORMAL      0
#define CHOICE_TEXT_COLUMN    0x2A              /* column of the choice texts */
#define CHOICE_FIRST_ROW      6                 /* rows 6, 8, 10 and 12 */
#define LIST_KIND_CHOICES     1                 /* first argument of osd_draw_choice_mark */
#define RGB_LED_ON_BIT        0x40              /* bit 6 of settings word +0xA8 */
#define RGB_LED_BRIGHTNESS_BIT 5                /* bit 5 of settings word +0xA8 */

struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;                     /* +8: selects the text of the menu language */
    unsigned char pad9[0xa8 - 9];
    unsigned int  word_0xa8;                    /* +0xA8: bits 6 and 5 give the RGB LED choice */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_off_on_texts[];
extern unsigned int osd_rgb_led_texts[];
extern void osd_api_set_glyph_write_address(int, int);
extern void osd_api_set_text_mode(int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, int, unsigned int, int, unsigned int, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_mark(unsigned char, unsigned char, unsigned char);

/*
 * Draw the four choices of the RGB LED item (rows 6, 8, 10 and 12 of the choice column) and mark the saved one.
 *
 * The first text comes from the OFF/ON table (entry 0 of the language in user_settings byte +8); the other
 * three are the entries 0..2 of the RGB LED table, read without a language offset.
 *
 * The saved choice is 0 while bit 6 of settings word +0xA8 is clear, else 1 plus bit 5 of that word. That row
 * is highlighted and carries the mark. Called by osd_draw_item_choices (osd_draw_item_choices).
 */
void osd_draw_rgb_led_choices(void)
{
    unsigned char i;
    unsigned char choice;

    osd_api_set_glyph_write_address(GLYPH_WRITE_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_MODE_NORMAL, 0);
    osd_draw_text(0, CHOICE_TEXT_COLUMN, CHOICE_FIRST_ROW, 1, osd_get_text(osd_off_on_texts, user_settings.language), 0);
    for (i = 1; i <= 3; i++)
        osd_draw_text(0, CHOICE_TEXT_COLUMN, i * 2 + CHOICE_FIRST_ROW, 1, osd_get_text(osd_rgb_led_texts, i - 1), 0);
    choice = 0;
    if (user_settings.word_0xa8 & RGB_LED_ON_BIT)
        choice = ((user_settings.word_0xa8 >> RGB_LED_BRIGHTNESS_BIT) & 1) + 1;
    osd_highlight_choice_row(choice, 0);
    osd_draw_choice_mark(LIST_KIND_CHOICES, choice, 1);
}
