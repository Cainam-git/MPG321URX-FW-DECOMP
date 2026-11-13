/* osd_draw_mode_status_header  (FUN_a00acc40)
 *
 * Draw the top status lines: HDR on/off and the current game or Pro mode.
 * Note: Pro (bit 11 of settings +0xA8) or Game mode decides which mode name is shown.
 * Name basis: derived - texts 0x18A6AC 'HDR', 0x193248, 0x188634 / 0x1951DC (Pro), 0x188DA0 / 0x195F24 (Game)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00acc40 @ 0xa00acc40-0xa00acef4 (173 words), flags -mcpu=v8 -O3 -g.
 * Source form: both arms of the picture-state test clear their cells with their own osd_api_fill_cells call
 * (the call is not merged), and the tail call to osd_api_set_text_mode is the last statement.
 */
#define LANGUAGE_COUNT 29  /* languages per text entry */

/* Header cell positions: the HDR pair sits in column 0x22 (width 6), the mode pair in column 0x17
 * (width 10); each pair is two rows, row 1 (name) and row 2 (value). */
#define HEADER_STATUS_COLUMN 0x22
#define HEADER_MODE_COLUMN   0x17

/* Settings record (user_settings): the fields used here. */
struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;           /* +8 */
    unsigned char pad9[0xa8 - 9];
    unsigned int gaming_flags;        /* +0xa8: bit 11 (0x800) = Pro mode, else Game mode */
    unsigned char padac[0x181 - 0xac];
    unsigned char pro_mode;           /* +0x181 */
    unsigned char game_mode;          /* +0x182 */
};
#define GAMING_FLAG_PRO_MODE 0x800
extern struct user_settings_record user_settings;
extern unsigned int osd_status_header_texts[], osd_off_on_texts[], osd_professional_item_texts[], osd_pro_mode_texts[], osd_gaming_item_texts[];
extern unsigned int osd_game_mode_texts[];
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, int, unsigned short, int, unsigned int, int);
extern int sys_user_get_picture_state(void);
extern unsigned char osd_step_pro_mode_index(unsigned char, unsigned char);

/* Draw the two header pairs of the menu: the text "HDR" over OFF or its next entry (shown when
 * sys_user_get_picture_state() returns non-zero), and the name of the active mode family
 * (Pro Mode when settings gaming_flags bit 11 is set, otherwise Game Mode) over the name of the
 * mode in use (pro_mode through osd_step_pro_mode_index, or game_mode).
 * No parameters. The texts are taken in the menu language; the OFF/ON entry is read at the
 * language number itself when that is 0, 6, 7 or 10, and at 1 for every other language. */
void osd_draw_mode_status_header(void)
{
    unsigned char m;

    if (user_settings.language == 0 || user_settings.language == 6 || user_settings.language == 7 || user_settings.language == 10)
        m = user_settings.language;
    else
        m = 1;
    osd_api_set_glyph_write_address(0x177, 0);
    osd_api_set_text_mode(2, 0);
    osd_api_fill_cells(HEADER_STATUS_COLUMN, 1, 6, 0x596, 0);
    osd_draw_text(0, HEADER_STATUS_COLUMN, 1, 6, osd_get_text(osd_status_header_texts, 1), 0);
    if (sys_user_get_picture_state()) {
        /* Non-zero state: the entry 29 words on. */
        osd_api_fill_cells(HEADER_STATUS_COLUMN, 2, 6, 0x596, 0);
        osd_draw_text(0, HEADER_STATUS_COLUMN, 2, 6, osd_get_text(osd_off_on_texts, m + LANGUAGE_COUNT), 0);
    } else {
        osd_api_fill_cells(HEADER_STATUS_COLUMN, 2, 6, 0x596, 0);
        osd_draw_text(0, HEADER_STATUS_COLUMN, 2, 6, osd_get_text(osd_off_on_texts, m), 0);
    }
    osd_api_fill_cells(HEADER_MODE_COLUMN, 1, 0xa, 0x596, 0);
    osd_api_fill_cells(HEADER_MODE_COLUMN, 2, 0xa, 0x596, 0);
    osd_api_fill_cell_bytes(0, HEADER_MODE_COLUMN, 1, 0xa, 0, 0);
    osd_api_fill_cell_bytes(0, HEADER_MODE_COLUMN, 2, 0xa, 0, 0);
    if (!(user_settings.gaming_flags & GAMING_FLAG_PRO_MODE)) {
        /* Game Mode: the item name, then the name of the chosen game mode. */
        osd_draw_text(0, HEADER_MODE_COLUMN, 1, 0xa, osd_get_text(osd_gaming_item_texts, user_settings.language), 0);
        osd_draw_text(0, HEADER_MODE_COLUMN, 2, 0xa, osd_get_text(osd_game_mode_texts, user_settings.game_mode * LANGUAGE_COUNT + user_settings.language), 0);
    } else {
        osd_draw_text(0, HEADER_MODE_COLUMN, 1, 0xa, osd_get_text(osd_professional_item_texts, user_settings.language), 0);
        osd_draw_text(0, HEADER_MODE_COLUMN, 2, 0xa,
                     osd_get_text(osd_pro_mode_texts, osd_step_pro_mode_index(user_settings.pro_mode, 0) * LANGUAGE_COUNT + user_settings.language), 0);
    }
    osd_api_set_text_mode(0, 0);
}
