/* osd_cancel_game_mode  (FUN_a0093334)
 *
 * Restore the mode saved on entry, re-apply it if it changed, and go back (left key)
 * Note: Re-applies with UserSetGameMode or UserSetProMode by bit 11 of the settings word +0xA8.
 * Name basis: derived - left in the game mode list states 0x48..0x4D (texts 0x195F24: Premium Color .. RPG);
 *   handler table
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0093334 @ 0xa0093334-0xa0093464 (76 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the "mode changed" flag is set by an if/else (an && expression gives subx flag arithmetic);
 *  - the game mode byte is copied back before the Pro bit;
 *  - the arm for a clear Pro bit (UserSetGameMode) is written first;
 *  - osd_draw_mode_status_header is the last call (a tail call).
 */

#define MENU_STATE_GAME_MODE_ITEM  0x0e /* Gaming page, item Game Mode */
#define MENU_STATE_GAME_MODE_LIST  0x48 /* + game mode: the Game Mode list */

/* The part of the user settings record used here (user_settings, 0xA802D290). */
struct user_settings_record {
    unsigned char pad000[0xa8];
    struct { unsigned int bits_31_12:20, pro_mode:1, bits_10_0:11; } gaming_flags;     /* +0xA8: bit 11 Pro (1) / Game (0) */
    unsigned char pad0ac[0x180 - 0xac];
    union {                                                             /* +0x180 */
        unsigned int word;
        struct { unsigned char byte_0x180, pro_mode, game_mode, byte_0x183; } modes;   /* +0x181 Pro mode, +0x182 Game mode */
    } word_0x180;
};

extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_edit_value;
extern unsigned char osd_choice_row;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void UserSetGameMode(void);
extern void UserSetProMode(void);
extern void osd_draw_mode_status_header(void);

/* Left key in the Game Mode list: put back the game mode (osd_choice_row) and the Pro/Game bit
 * (osd_edit_value) that were stored when the list was opened, and return to the Game Mode item of the Gaming
 * page (menu state 0xE). No parameters, no result.
 * The picture mode is applied again (UserSetGameMode when the restored bit says Game, UserSetProMode when it
 * says Pro) only when something differs from the stored values: the game mode byte or the bit. The exception is
 * the case where the Pro mode byte (+0x181) is 0 and the game mode byte (+0x182) is 1 at that moment and the bit
 * differs: then the mode is not applied again.
 * After restoring, the highlight of the list row is cleared, the restored row is highlighted and marked, the
 * item row of the Game Mode item is highlighted and the mode status header is redrawn.
 */
void osd_cancel_game_mode(void)
{
    unsigned char mode_changed;

    if (user_settings.word_0x180.modes.game_mode != osd_choice_row || osd_edit_value != user_settings.gaming_flags.pro_mode) {
        if ((user_settings.word_0x180.word & 0xffff00) == 0x100 && osd_edit_value != user_settings.gaming_flags.pro_mode)
            mode_changed = 0;
        else
            mode_changed = 1;
    } else
        mode_changed = 0;
    user_settings.word_0x180.modes.game_mode = osd_choice_row;
    user_settings.gaming_flags.pro_mode = osd_edit_value;
    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_GAME_MODE_LIST);
    osd_highlight_choice_row(user_settings.word_0x180.modes.game_mode, 0);
    osd_draw_choice_mark(1, user_settings.word_0x180.modes.game_mode, 1);
    osd_menu_state = MENU_STATE_GAME_MODE_ITEM;
    osd_highlight_item_row(0, 1);
    if (mode_changed) {
        if (!user_settings.gaming_flags.pro_mode)
            UserSetGameMode();
        else
            UserSetProMode();
    }
    osd_draw_mode_status_header();
}
