/* osd_draw_game_mode_choices  (FUN_a00b617c)
 *
 * Draw the game mode choices and mark the current one.
 * Note: Choices Premium Color, User, FPS, Racing, RTS, RPG; current = settings byte +0x182.
 * Name basis: proven - texts 0x195F24
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b617c @ 0xa00b617c, flags -mcpu=v8 -O3 -g.
 * Source form: user_settings is read as {u8 at +8; u8 at +0x182}; the loop is a do-while over i = 0..5, and
 * osd_draw_choice_mark is the last call (a tail call).
 */
struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;                 /* +8 */
    unsigned char pad2[0x182 - 9];
    unsigned char game_mode;                /* +0x182 */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_game_mode_texts[];
extern void osd_api_set_glyph_write_address(int address, int layer);
extern void osd_api_set_text_mode(int mode, int layer);
extern unsigned int osd_get_text(unsigned int *table, unsigned short index);
extern void osd_draw_text(int plane, int column, unsigned int row, int width, unsigned int text, int layer);
extern void osd_draw_choice_mark(int list_kind, unsigned char row, int on);

#define PLANE_0              0
#define MENU_LAYER_MAIN      0
#define TEXT_ALIGN_LEFT      0
#define LANGUAGE_COUNT       29      /* texts of one entry for every language, in language order */
#define CHOICE_TEXT_COLUMN   0x2a    /* column of the choice texts */
#define CHOICE_FIRST_ROW     6       /* row of the first choice; the choices are two rows apart */
#define CHOICE_GLYPH_ADDRESS 0x111   /* glyph memory address given before choice texts are drawn */
#define GAME_MODE_CHOICES    6       /* Premium Color, User, FPS, Racing, RTS, RPG */
#define CHOICE_MARK_LIST     1       /* osd_draw_choice_mark list kind of choice lists */
#define CHOICE_MARK_ON       1

/* Draw the six Game Mode choices (Premium Color, User, FPS, Racing, RTS, RPG): entry i of osd_game_mode_texts
 * in the menu language, left-aligned on row 2 * i + 6, then the mark of the stored choice (user_settings byte
 * +0x182, the Game Mode). The choice column is not cleared here. */
void osd_draw_game_mode_choices(void)
{
    unsigned char i;

    osd_api_set_glyph_write_address(CHOICE_GLYPH_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    i = 0;
    do {
        osd_draw_text(PLANE_0, CHOICE_TEXT_COLUMN, i * 2 + CHOICE_FIRST_ROW, 1, osd_get_text(osd_game_mode_texts, (unsigned short)(i * LANGUAGE_COUNT + user_settings.language)), MENU_LAYER_MAIN);
        i++;
    } while (i < GAME_MODE_CHOICES);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.game_mode, CHOICE_MARK_ON);
}
