/* osd_select_next_game_mode  (FUN_a009a6c0)
 *
 * Move to the next allowed game mode (down key) and preview it.
 * Note: Wraps inside the states 0x48..0x4D; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: down on states 0x48..0x4D; applies with UserSetGameMode;
 *   texts 0x195F24
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009a6c0 @ 0xa009a6c0-0xa009a784 (49 words), flags -mcpu=v8 -O3 -g.
 * Same loop as the Pro Mode list routine osd_select_next_night_vision. Source form: the next row is computed from the low
 * halfword of the menu state ('(unsigned short)state - 0x47') and reduced with '% 6' in a separate statement;
 * the last test is an if/else with the two osd_draw_choice_mark calls.
 */
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void UserSetGameMode(void);

#define USER_SETTINGS_GAME_MODE  0x182  /* the Game Mode (a row of the Game Mode list) */
#define MENU_STATE_GAME_MODE_LIST 0x48  /* + game mode: the Game Mode list (states 0x48..0x4D) */
#define GAME_MODE_COUNT          6      /* Premium Color, User, FPS, Racing, RTS, RPG */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define MARK_DRAW                1
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * Down key in the Game Mode list (states 0x48..0x4D): move the cursor to the next game mode that can be
 * selected, set it as the Game Mode and apply it.
 *
 * The highlight of the cursor row is removed. The row steps forward by one, wrapping from the last row to the
 * first, until osd_is_choice_enabled accepts it. The row is stored in settings byte +0x182 (the Game Mode),
 * UserSetGameMode applies it and the row is highlighted with edge glyphs. The mark of the row saved on entry
 * (osd_choice_row) is cleared when the cursor is on that row and drawn otherwise.
 */
void osd_select_next_game_mode(void)
{
    int row;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_GAME_MODE_LIST);
    do {
        row = (unsigned short)osd_menu_state - 0x47;
        row = row % GAME_MODE_COUNT;
        osd_menu_state = row + MENU_STATE_GAME_MODE_LIST;
    } while (osd_is_choice_enabled(row) != 1);
    user_settings[USER_SETTINGS_GAME_MODE] = osd_menu_state - MENU_STATE_GAME_MODE_LIST;
    UserSetGameMode();
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_GAME_MODE_LIST, CHOICE_ROW_EDGED);
    {
        unsigned char saved_row = osd_choice_row;
        if (osd_menu_state - MENU_STATE_GAME_MODE_LIST == saved_row)
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved_row, MARK_CLEAR);
        else
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved_row, MARK_DRAW);
    }
}
