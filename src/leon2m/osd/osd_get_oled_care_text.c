/* osd_get_oled_care_text  (FUN_a00ac138)
 *
 * Return the text of row i for an OLED Care choice list.
 *   id: list
 *   i: row
 * Returns: text pointer
 * Note: Lists: Pixel Shift speeds, Protect Notice, Static Screen rows and times, OFF/ON.
 * Name basis: derived - tables 0x185BC0, 0x18A794, 0x18A7EC, 0x18B29C, 0x18B5E0, 0x18B94C, 0x193248; called by
 *   osd_draw_oled_care_choices
 *
 * Matching notes
 * --------------
 * FUN_a00ac138 (leon2m 0xa00ac138-0xa00ac388, 592 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: one call per case into a result preset to 0 (the calls are merged into one call site); cases in
 * the order 0x37, 0x3b, 0x38..0x3a, 0x34, 0xba, 0xbd, 0xbf, 0xbe, 0x36, with 0x34 and 0xba as two identical
 * case bodies.
 */

/* Texts are word tables with 29 languages per entry: the text of entry n in the menu
 * language is table[n * 29 + language] (language 1 = English). */
#define LANGUAGE_COUNT 29

/* Settings record (user_settings): only the menu language is used here. */
struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;  /* +8 */
};
extern struct user_settings_record user_settings;
extern unsigned char user_settings_static_screen_level;
extern unsigned int osd_oled_care_choice_texts[], osd_oled_care_function_texts[], osd_oled_care_level_texts[], osd_oled_care_seconds_texts[], osd_oled_care_usage_texts[];
extern unsigned int osd_oled_care_speed_texts[], osd_oled_care_status_texts[], osd_off_on_texts[];
extern unsigned int osd_get_text(unsigned int *, unsigned short);

/* Return the text (in the menu language) of row i of the OLED Care choice list id, or 0 for an
 * id that has no list. id is a menu state: 0x34 and 0xba use the Pixel Shift speed texts, 0x36
 * the Protect Notice texts, 0x37 the OFF/ON texts for rows 0..1 and the Static Screen texts for
 * the rest (the table starts at row 2), 0x38..0x3a the common choice texts, 0x3b the function
 * texts, 0xbd the seconds texts (0xbe reads 58 entries further into the same table) and 0xbf
 * the level texts. Called by osd_draw_oled_care_choices. */
unsigned int osd_get_oled_care_text(unsigned short id, unsigned char i)
{
    unsigned int r = 0;

    switch (id) {
    case 0x37:
        if (i <= 1)
            r = osd_get_text(osd_off_on_texts, i * LANGUAGE_COUNT + user_settings.language);
        else
            r = osd_get_text(osd_oled_care_status_texts, i * LANGUAGE_COUNT + user_settings.language - 58);
        break;
    case 0x3b:
        r = osd_get_text(osd_oled_care_function_texts, i * LANGUAGE_COUNT + user_settings.language);
        break;
    case 0x38:
    case 0x39:
    case 0x3a:
        r = osd_get_text(osd_oled_care_choice_texts, i * LANGUAGE_COUNT + user_settings.language);
        break;
    case 0x34:
        r = osd_get_text(osd_oled_care_speed_texts, i * LANGUAGE_COUNT + user_settings.language);
        break;
    case 0xba:
        r = osd_get_text(osd_oled_care_speed_texts, i * LANGUAGE_COUNT + user_settings.language);
        break;
    case 0xbd:
        r = osd_get_text(osd_oled_care_seconds_texts, i * LANGUAGE_COUNT + user_settings.language);
        break;
    case 0xbf:
        /* A static screen level above 6 reads the level texts from row 7 on. */
        if (user_settings_static_screen_level <= 6)
            r = osd_get_text(osd_oled_care_level_texts, i);
        else
            r = osd_get_text(osd_oled_care_level_texts, i + 7);
        break;
    case 0xbe:
        r = osd_get_text(osd_oled_care_seconds_texts, i * LANGUAGE_COUNT + user_settings.language + 0x3a);
        break;
    case 0x36:
        r = osd_get_text(osd_oled_care_usage_texts, i * LANGUAGE_COUNT + user_settings.language);
        break;
    }
    return r;
}
