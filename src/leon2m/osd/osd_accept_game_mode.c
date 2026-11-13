/* osd_accept_game_mode  (FUN_a00932a8)
 *
 * Keep the highlighted game mode, switch to Game (not Pro) mode and go back (OK key)
 * Note: Clears bit 11 (Pro mode) of the settings word +0xA8 and returns to the Game Mode item.
 * Name basis: derived - OK in the game mode list states 0x48..0x4D (texts 0x195F24: Premium Color .. RPG);
 *   handler table
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00932a8, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a struct with the word at +0xA8 and the byte at +0x182 as fields.
 */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit of osd_request_bits */
#define SETTINGS_PRO_MODE_SELECTED   0x800      /* settings word +0xA8, bit 11: Pro Mode (clear = Game Mode) */
#define MENU_STATE_GAME_MODE_ITEM    0x0e       /* Gaming page, item Game Mode */
#define MENU_STATE_GAME_MODE_LIST    0x48       /* + game mode: the Game Mode list */

/* The two fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0xa8];
    unsigned int gaming_flags;                  /* +0xA8 */
    unsigned char padac[0x182 - 0xac];
    unsigned char game_mode;                    /* +0x182: the selected Game Mode */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row, osd_request_bits;
extern unsigned int osd_menu_state;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(unsigned char mode, unsigned char sel, unsigned char on);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_mode_status_header(void);

/*
 * OK key in the Game Mode list: the highlighted entry stays as the game mode. The choice row saved on entry
 * (osd_choice_row) loses its highlight and mark, the highlighted entry (menu state - 0x48) is un-highlighted,
 * and the mark is drawn at the row of settings byte +0x182. Pro Mode is switched off (bit 11 of settings word
 * +0xA8), the menu state goes back to the Game Mode item with its row highlighted, the status header is
 * redrawn and the settings-changed request is made.
 */
void osd_accept_game_mode(void)
{
    osd_clear_choice_highlight(osd_choice_row);
    osd_draw_choice_mark(1, osd_choice_row, 0);
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_GAME_MODE_LIST, 0);
    osd_draw_choice_mark(1, user_settings.game_mode, 1);
    osd_menu_state = MENU_STATE_GAME_MODE_ITEM;
    osd_highlight_item_row(0, 1);
    user_settings.gaming_flags &= ~(unsigned int)SETTINGS_PRO_MODE_SELECTED;
    osd_draw_mode_status_header();
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
