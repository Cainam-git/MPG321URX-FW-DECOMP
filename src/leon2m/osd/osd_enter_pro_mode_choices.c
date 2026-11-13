/* osd_enter_pro_mode_choices  (FUN_a00a01fc)
 *
 * Switch to Pro mode and open the Pro mode list (OK/right on 'Pro Mode')
 * Note: Shows the change notice instead when settings byte +0x1A9 is 1; saves the current values for cancel.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x15 (Professional: Pro Mode); list states
 *   0x5C..0x63; UserSetProMode
 *
 * Matching notes
 * --------------
 * leon2m, flags -mcpu=v8 -O3 -g.
 * Source form: the gaming-flag part goes through a block-local pointer to the settings record. Bit 15 of the
 * halfword at +4 is tested as '(short)(half_0x4 & 0x8000)'. Same form as osd_enter_game_mode_choices.
 */

#define MENU_STATE_PRO_MODE_ITEM 0x15   /* the Pro Mode item of the Professional tab */
#define MENU_STATE_PRO_MODE_LIST 0x5c   /* list rows are the menu states 0x5C..0x63 */
#define MENU_STATE_CHANGE_NOTICE 0x116
#define CHOICES_PER_PAGE         7
#define GAMING_FLAG_PRO_MODE     0x800  /* bit 11 of gaming_flags: Pro (1) / Game (0) */
#define NOTICE_FROM_PRO_MODE     2      /* value of app_state_record notice_origin */
#define HIGHLIGHT_ITEM_LIST_OPEN 2      /* item row is the parent of an open list */
#define CHOICE_MARK_LIST         1
#define LIST_ID_PRO_MODE         0xc    /* osd_list_id while the Pro mode list is open */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02

/* Settings (user_settings record): the fields used here. */
struct settings_fields {
    unsigned char p000[0x11];
    unsigned char color_temperature;
    unsigned char p012[0xa8 - 0x12];
    unsigned int gaming_flags;
    unsigned char p0ac[0x180 - 0xac];
    union { unsigned int w; unsigned char b[4]; } modes;   /* b[1] = pro_mode (+0x181), b[2] = game_mode (+0x182) */
    unsigned char b181_pad[0x1a9 - 0x184];
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
extern unsigned char osd_request_bits, osd_list_id;
extern unsigned char osd_saved_choice_value, osd_edit_value, osd_choice_row;
extern unsigned short osd_message_ticks;
extern void input_rearm_port_event(int, int);
extern void osd_hide_menu(void);
extern void osd_show_change_notice(void);
extern unsigned short timer_get_ticks16(void);
extern unsigned char osd_step_pro_mode_index(unsigned char, unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void UserSetProMode(void);
extern void osd_draw_item_row_state(int, int);

/*
 * OK / right key on the Pro Mode item: switch to Pro mode and open the Pro mode list.
 * Two paths:
 *   - settings byte_0x1a9 is 1: the list is not opened. The menu is closed (state 0), the change notice is shown
 *     with notice_origin = NOTICE_FROM_PRO_MODE, the menu state becomes the change notice state, a settings save is
 *     requested, the notice button byte is cleared and the tick count is stored in osd_message_ticks.
 *   - otherwise: osd_edit_value, osd_choice_row and osd_saved_choice_value keep the Pro-selected flag, the Pro mode
 *     and the colour temperature as they were, for Cancel. The menu state moves to the list row of the current Pro
 *     mode and the item row is marked as the parent of the open list. If Pro mode was not selected, the flag is set
 *     and, unless pro_mode is 1 and game_mode is 0, the mode is applied with UserSetProMode; the item row is then
 *     redrawn. Last, the mark of the row is drawn, the row highlighted and osd_list_id set to the Pro mode list.
 */
void osd_enter_pro_mode_choices(void)
{
    unsigned char m;

    /* Byte 0x1a9 is 1: ask with the change notice first; the list is not opened. */
    if (user_settings.byte_0x1a9 == 1) {
        /* Bit 15 of the halfword at +4 set: set its bit 10 and re-arm the ports. */
        if ((short)(app_state_record.half_0x4 & 0x8000)) {
            app_state_record.half_0x4 |= 0x400;
            input_rearm_port_event(4, 0);
        }
        osd_menu_state = 0;
        osd_hide_menu();
        app_state_record.notice_origin = NOTICE_FROM_PRO_MODE;
        osd_show_change_notice();
        osd_menu_state = MENU_STATE_CHANGE_NOTICE;
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
        user_settings.byte_0x1aa = 0;
        osd_message_ticks = timer_get_ticks16();
        return;
    }
    /* Save what Cancel must put back: the Pro-selected flag, the Pro mode and the colour temperature. */
    osd_edit_value = (user_settings.gaming_flags >> 11) & 1;
    osd_choice_row = user_settings.modes.b[1];
    osd_saved_choice_value = user_settings.color_temperature;
    /* Open the list on the row of the current Pro mode. */
    m = osd_step_pro_mode_index(user_settings.modes.b[1], 0);
    osd_highlight_item_row(osd_menu_state - MENU_STATE_PRO_MODE_ITEM, HIGHLIGHT_ITEM_LIST_OPEN);
    osd_menu_state = m + MENU_STATE_PRO_MODE_LIST;
    {
        struct settings_fields *p = &user_settings;

        /* Pro was not selected yet: select it. Unless pro_mode is 1 and game_mode 0, apply the Pro mode (modes 4..6 set
         * the colour temperature to 1 first). */
        if (!(p->gaming_flags & GAMING_FLAG_PRO_MODE)) {
            p->gaming_flags |= GAMING_FLAG_PRO_MODE;
            if ((p->modes.w & 0xffff00) != 0x100) {
                if ((unsigned char)(p->modes.b[1] - 4) <= 2)
                    p->color_temperature = 1;
                UserSetProMode();
            }
            osd_draw_item_row_state(2, 1);
        }
    }
    osd_draw_choice_mark(CHOICE_MARK_LIST, m % CHOICES_PER_PAGE, 0);
    osd_highlight_choice_row((osd_menu_state - MENU_STATE_PRO_MODE_LIST) % CHOICES_PER_PAGE, 1);
    osd_list_id = LIST_ID_PRO_MODE;
}
