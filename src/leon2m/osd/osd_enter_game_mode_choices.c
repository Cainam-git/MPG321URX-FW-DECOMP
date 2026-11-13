/* osd_enter_game_mode_choices  (FUN_a00a03e8)
 *
 * Switch to Game mode and open the game mode list (OK/right on 'Game Mode')
 * Note: Shows the change notice instead when settings byte +0x1A9 is 1; saves the current values for cancel.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x0E (Gaming: Game Mode); list states
 *   0x48..0x4D; UserSetGameMode
 *
 * Matching notes
 * --------------
 * leon2m, flags -mcpu=v8 -O3 -g.
 * Source form: bit 15 of the halfword at +4 is tested as '(short)(half_0x4 & 0x8000)' (same as
 * osd_enter_pro_mode_choices). UserSetGameMode is the last call of the routine.
 */

#define MENU_STATE_GAME_MODE_ITEM 0x0e   /* the Game Mode item of the Gaming tab */
#define MENU_STATE_GAME_MODE_LIST 0x48   /* list rows are the menu states 0x48..0x4D */
#define MENU_STATE_CHANGE_NOTICE  0x116
#define GAMING_FLAG_PRO_MODE      0x800  /* bit 11 of gaming_flags: Pro (1) / Game (0) */
#define NOTICE_FROM_GAME_MODE     0      /* value of app_state_record notice_origin */
#define HIGHLIGHT_ITEM_LIST_OPEN  2      /* item row is the parent of an open list */
#define CHOICE_MARK_LIST          1
#define OSD_REQUEST_SETTINGS_CHANGED 0x02

/* Settings (user_settings record): the fields used here. */
struct settings_fields {
    unsigned char p000[0xa8];
    unsigned int gaming_flags;
    unsigned char p0ac[0x180 - 0xac];
    union { unsigned int w; unsigned char b[4]; } modes;   /* b[1] = pro_mode (+0x181), b[2] = game_mode (+0x182) */
    unsigned char p184[0x1a9 - 0x184];
    unsigned char byte_0x1a9;   /* 1 = ask with the change notice before switching */
    unsigned char byte_0x1aa;   /* the button highlighted in the change notice */
};
struct app_state_fields {
    unsigned short h0;
    unsigned short h2;
    unsigned short half_0x4;
    unsigned char p6[4];
    unsigned char notice_origin;   /* +0xA: which menu opened the change notice */
};
extern struct settings_fields user_settings;
extern struct app_state_fields app_state_record;
extern unsigned int osd_menu_state;
extern unsigned char osd_request_bits;
extern unsigned char osd_edit_value;
extern unsigned char osd_choice_row;
extern unsigned short osd_message_ticks;
extern void input_rearm_port_event(int, int);
extern void osd_hide_menu(void);
extern void osd_show_change_notice(void);
extern unsigned short timer_get_ticks16(void);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void UserSetGameMode(void);

/*
 * OK / right key on the Game Mode item: switch to Game mode and open the Game mode list.
 * Two paths:
 *   - settings byte_0x1a9 is 1: the list is not opened. The menu is closed (state 0), the change notice is shown
 *     with notice_origin = NOTICE_FROM_GAME_MODE, the menu state becomes the change notice state, a settings save is
 *     requested, the notice button byte is cleared and the tick count is stored in osd_message_ticks.
 *   - otherwise: the mark of the current Game mode row is drawn, the item row is marked as the parent of the open
 *     list, the menu state moves to the list row of the current Game mode and that row is highlighted. The row and
 *     the Pro-selected flag are kept in osd_choice_row and osd_edit_value for Cancel. If Pro was selected, the flag
 *     is cleared and, unless pro_mode is 1 and game_mode is 0, UserSetGameMode applies the Game mode.
 */
void osd_enter_game_mode_choices(void)
{
    /* Byte 0x1a9 is 1: ask with the change notice first; the list is not opened. */
    if (user_settings.byte_0x1a9 == 1) {
        /* Bit 15 of the halfword at +4 set: set its bit 10 and re-arm the ports. */
        if ((short)(app_state_record.half_0x4 & 0x8000)) {
            app_state_record.half_0x4 |= 0x400;
            input_rearm_port_event(4, 0);
        }
        osd_menu_state = 0;
        osd_hide_menu();
        app_state_record.notice_origin = NOTICE_FROM_GAME_MODE;
        osd_show_change_notice();
        osd_menu_state = MENU_STATE_CHANGE_NOTICE;
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
        user_settings.byte_0x1aa = 0;
        osd_message_ticks = timer_get_ticks16();
        return;
    }
    /* Open the list on the row of the current Game mode (modes.b[2]) and keep it as the value for Cancel. */
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.modes.b[2], 0);
    osd_highlight_item_row(osd_menu_state - MENU_STATE_GAME_MODE_ITEM, HIGHLIGHT_ITEM_LIST_OPEN);
    osd_menu_state = user_settings.modes.b[2] + MENU_STATE_GAME_MODE_LIST;
    osd_highlight_choice_row(user_settings.modes.b[2], 1);
    osd_choice_row = user_settings.modes.b[2];
    /* Keep the Pro-selected flag for Cancel; if Pro was selected, clear it and apply the Game mode, unless
     * pro_mode is 1 and game_mode is 0. */
    osd_edit_value = (user_settings.gaming_flags >> 11) & 1;
    if (user_settings.gaming_flags & GAMING_FLAG_PRO_MODE) {
        user_settings.gaming_flags &= ~GAMING_FLAG_PRO_MODE;
        if ((user_settings.modes.w & 0xffff00) != 0x100)
            UserSetGameMode();
    }
}
