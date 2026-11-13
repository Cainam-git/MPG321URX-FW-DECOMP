/* osd_draw_power_button_choices  (FUN_a00b789c)
 *
 * Draw the Power Button choices (OFF, Standby) and mark the current one.
 * Note: Current choice = bit 15 of settings word +0xA8.
 * Name basis: proven - texts 0x19336c 'OFF|Standby'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b789c @ 0xa00b789c-0xa00b7944 (42 words), flags -mcpu=v8 -O3 -g.
 * Source form: the loop has the same form as the one in osd_draw_response_time_choices.
 */
#define GLYPH_WRITE_ADDRESS   0x111
#define TEXT_MODE_NORMAL      0
#define CHOICE_TEXT_COLUMN    0x2A              /* column of the choice texts */
#define LANGUAGE_COUNT        29                /* text index = entry * 29 + language byte of the settings */
#define POWER_BUTTON_CHOICES  2                 /* OFF, Standby */
#define LIST_KIND_CHOICES     1                 /* first argument of osd_draw_choice_mark */
#define POWER_BUTTON_STANDBY_BIT 15             /* bit of settings word +0xA8 */

struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;                     /* +8: selects the text of the menu language */
    unsigned char pad09[0x9f];
    unsigned int  word_0xa8;                    /* +0xA8: bit 15 is the Power Button choice */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_power_button_texts[];
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, int, unsigned int, int, unsigned int, int);
extern void osd_draw_choice_mark(int, unsigned char, int);

/* Draw the two Power Button choices (OFF, Standby) at rows 6 and 8 and mark the one saved in bit 15 of
   settings word +0xA8. */
void osd_draw_power_button_choices(void)
{
    unsigned char i;

    osd_api_set_glyph_write_address(GLYPH_WRITE_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_MODE_NORMAL, 0);
    for (i = 0; i <= POWER_BUTTON_CHOICES - 1; i++)
        osd_draw_text(0, CHOICE_TEXT_COLUMN, i * 2 + 6, 1, osd_get_text(osd_power_button_texts, i * LANGUAGE_COUNT + user_settings.language), 0);
    osd_draw_choice_mark(LIST_KIND_CHOICES, (user_settings.word_0xa8 >> POWER_BUTTON_STANDBY_BIT) & 1, 1);
}
