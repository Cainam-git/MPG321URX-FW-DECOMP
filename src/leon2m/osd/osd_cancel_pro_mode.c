/* osd_cancel_pro_mode  (FUN_a0095fb0)
 *
 * Restore the mode saved on entry, re-apply it if it changed, and go back (left)
 * Note: Re-applies with UserSetProMode or UserSetGameMode.
 * Name basis: derived - handler table 0xA802422C: left on states 0x5C..0x63
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095fb0 @ 0xa0095fb0-0xa00961a4 (125 words), flags -mcpu=v8 -O3 -g. Counterpart of
 * osd_enter_pro_mode_choices (osd_enter_pro_mode_choices). Source form: the page test (menu state - 0x5C) / 7 is written
 * inline in the if, without a variable; the nested conditions of needs_apply are written as shown.
 */
struct user_settings_record {
    unsigned char p000[0x11];
    unsigned char color_temperature;            /* +0x11 */
    unsigned char p012[0xa8 - 0x12];
    union {                                     /* +0xA8: gaming flags */
        unsigned int w;
        struct {
            unsigned int hi : 20;
            unsigned int pro_mode : 1;          /* bit 11, GAMING_FLAG_PRO_MODE: the Pro mode list is the one in use */
            unsigned int lo : 11;
        } f;
    } gaming_flags;
    unsigned char p0ac[0x180 - 0xac];
    union { unsigned int w; unsigned char b[4]; } modes;    /* +0x180: b[1] = pro_mode (+0x181), b[2] = game_mode (+0x182) */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_saved_choice_value, osd_edit_value, osd_choice_row;
extern unsigned char osd_step_pro_mode_index(unsigned char, unsigned char);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_pro_mode_choices(unsigned char page);
extern void osd_draw_choice_mark(unsigned char, unsigned char, unsigned char);
extern void osd_highlight_choice_row(unsigned char, unsigned char);
extern void osd_highlight_item_row(unsigned char, unsigned char);
extern void UserSetProMode(void);
extern void UserSetGameMode(void);
extern void osd_draw_item_row_state(unsigned char, unsigned char);
extern void osd_draw_mode_status_header(void);

#define MENU_STATE_PRO_MODE_LIST     0x5c       /* + list position: the Pro Mode list (states 0x5C..0x63) */
#define MENU_STATE_PRO_MODE_ITEM     0x15       /* Professional page, item Pro Mode */
#define PRO_MODE_ROWS_PER_PAGE       7          /* rows of one page of the Pro Mode list */
#define GAMING_FLAG_PRO_MODE         0x800      /* bit 11 of the gaming flags */

/*
 * Left key in the Pro Mode list (menu states 0x5C..0x63, reached through the handler table): give up the change
 * and go back to the Pro Mode item. osd_enter_pro_mode_choices saved three values when the list was opened;
 * this routine writes them back:
 *   osd_edit_value         -> the Pro bit (bit 11) of the gaming flags
 *   osd_saved_choice_value -> color_temperature
 *   osd_choice_row         -> the Pro mode (byte +0x181)
 * The picture mode is applied again (UserSetGameMode when the Pro bit is clear, else UserSetProMode) only when
 * something differs from the saved values. The exception is a Pro mode of 0 with Game mode 1 and a differing Pro
 * bit: that case is not re-applied.
 *
 * The list is then redrawn for the restored mode: osd_step_pro_mode_index(pro mode, 0) gives its list position;
 * the highlight of the row of the present state is removed, the page is redrawn when the restored position lies
 * on another page (7 rows per page), and that position is highlighted and marked. The menu state becomes
 * 0x15 with item row 0 highlighted, and the item row state and the mode status header are redrawn.
 */
void osd_cancel_pro_mode(void)
{
    unsigned char needs_apply;
    unsigned char list_index;

    if (user_settings.modes.b[1] != osd_choice_row || osd_edit_value != ((user_settings.gaming_flags.w >> 11) & 1)) {
        if ((user_settings.modes.w & 0xffff00) == 0x100 && osd_edit_value != ((user_settings.gaming_flags.w >> 11) & 1))
            needs_apply = 0;
        else
            needs_apply = 1;
    } else
        needs_apply = 0;
    user_settings.gaming_flags.f.pro_mode = osd_edit_value;
    user_settings.color_temperature = osd_saved_choice_value;
    user_settings.modes.b[1] = osd_choice_row;
    list_index = osd_step_pro_mode_index(osd_choice_row, 0);
    osd_clear_choice_highlight((osd_menu_state - MENU_STATE_PRO_MODE_LIST) % PRO_MODE_ROWS_PER_PAGE);
    if ((osd_menu_state - MENU_STATE_PRO_MODE_LIST) / PRO_MODE_ROWS_PER_PAGE != (unsigned char)(list_index / PRO_MODE_ROWS_PER_PAGE))
        osd_draw_pro_mode_choices(list_index / PRO_MODE_ROWS_PER_PAGE);
    osd_highlight_choice_row(list_index % PRO_MODE_ROWS_PER_PAGE, 0);
    osd_draw_choice_mark(1, list_index % PRO_MODE_ROWS_PER_PAGE, 1);
    osd_menu_state = MENU_STATE_PRO_MODE_ITEM;
    osd_highlight_item_row(0, 1);
    if (needs_apply) {
        if (!(user_settings.gaming_flags.w & GAMING_FLAG_PRO_MODE))
            UserSetGameMode();
        else
            UserSetProMode();
    }
    osd_draw_item_row_state(2, 1);
    osd_draw_mode_status_header();
}
