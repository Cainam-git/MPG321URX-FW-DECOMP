/* osd_close_change_notice  (FUN_a009b59c)
 *
 * Close the mode change notice and continue to the Game, Pro or Navi Key page.
 * Note: Notice state 0x116; the page to continue to is in byte 0xA802CFFE; also run when the notice times out.
 * Name basis: descriptive - handler table 0xA802422C: OK on state 0x116; called by osd_run_periodic_task;
 *   opens states 0x48.. (game) / 0x5C.. (pro) / 0xFB
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009b59c @ 0xa009b59c-0xa009b864 (178 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on (as in osd_enter_pro_mode_choices, osd_enter_pro_mode_choices):
 *  - the Pro bit of gaming_flags is cleared through a 1-bit bit-field of a union view, but tested and set
 *    through the whole word;
 *  - the game mode byte is read into a local first in the Game Mode case.
 */

/* The fields of the user settings record used here. */
struct user_settings_record {           /* user_settings, 0xA802D290 */
    unsigned char pad000[0x11];
    unsigned char color_temperature;                    /* +0x11 */
    unsigned char pad012[0xa8 - 0x12];
    union {                                             /* +0xA8 */
        unsigned int word;
        struct { unsigned int bits_31_12 : 20, pro_mode : 1, bits_10_0 : 11; } bits;   /* bit 11: Pro (1) / Game (0) */
    } gaming_flags;
    unsigned char pad0ac[0x181 - 0xac];
    unsigned char pro_mode, game_mode;                  /* +0x181, +0x182 */
    unsigned char pad183[0x18a - 0x183];
    unsigned char navi_key_up, navi_key_down, navi_key_left, navi_key_right;      /* +0x18A..+0x18D */
    unsigned char pad18e[0x1a9 - 0x18e];
    unsigned char byte_0x1a9;           /* +0x1A9: 1 = ask with the change notice before the mode switch */
    unsigned char byte_0x1aa;           /* +0x1AA: the highlighted notice button */
};
/* The application state record as far as it is used here. */
struct app_state_record_layout {        /* app_state_record, 0xA802CFF4 */
    unsigned short halfword_0x0;
    unsigned short halfword_0x2;
    unsigned short sleep_word;          /* +0x04 */
    unsigned char pad6[4];
    unsigned char notice_origin;        /* +0x0A: the page that opened the change notice */
};
extern struct user_settings_record user_settings;
extern struct app_state_record_layout app_state_record;
extern unsigned int osd_menu_state;
extern unsigned char osd_list_id;
extern unsigned char osd_saved_choice_value, osd_edit_value, osd_choice_row;
extern void input_rearm_port_event(int, int);
extern void osd_hide_menu(void);
extern void osd_mark_settings_changed(void);
extern void osd_redraw_page_after_notice(unsigned char a, unsigned char b);
extern void UserSetGameMode(void);
extern void osd_show_menu_layer(void);
extern void osd_draw_navi_quick_menu(unsigned char);
extern unsigned char osd_step_pro_mode_index(unsigned char, unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void UserSetProMode(void);

/* Who opened the notice (app_state_record.notice_origin). */
#define NOTICE_FROM_GAME_MODE 0         /* osd_enter_game_mode_choices */
#define NOTICE_FROM_PRO_MODE  2         /* osd_enter_pro_mode_choices */
#define NOTICE_FROM_NAVI_KEY  5         /* a Navi key whose function is Game Mode */
#define NOTICE_ORIGIN_DONE    9         /* stored once the switch is accepted */

#define NOTICE_BUTTON_YES     1         /* byte_0x1aa: Yes highlighted; 0 = No (the default and the time-out) */

#define GAMING_FLAG_PRO_MODE  0x800     /* gaming_flags bit 11 */
#define SLEEP_WORD_BIT15      0x8000
#define SLEEP_WORD_BIT10      0x400
#define ALL_PORTS             4         /* input_rearm_port_event: every port */

/* Menu states. */
#define MENU_STATE_CLOSED          0
#define MENU_STATE_GAME_MODE_ITEM  0x0e /* Gaming page, item Game Mode */
#define MENU_STATE_PRO_MODE_ITEM   0x15 /* Professional page, item Pro Mode */
#define MENU_STATE_GAME_MODE_LIST  0x48 /* + game mode: the Game Mode list */
#define MENU_STATE_PRO_MODE_LIST   0x5c /* + list index: the Pro Mode list */
#define MENU_STATE_NAVI_GAME_MODE  0xfb /* the Game Mode quick menu of the Navi keys */

#define NAVI_FUNCTION_GAME_MODE    2    /* Navi key function 2 opens state 0xFB */
#define LIST_ID_PRO_MODE           0x0c /* osd_list_id value set with the Pro Mode list */
#define PRO_MODE_LIST_ROWS         7

/*
 * Close the "Confirm Change !" notice (menu state 0x116) and go on to the page that opened it.
 *
 * Runs for OK while the notice is shown, and from osd_run_periodic_task when the notice has been shown longer
 * than the OSD Time out setting (that path selects No first). The notice was opened instead of a mode switch while
 * settings byte +0x1A9 was 1: from the Game Mode item, the Pro Mode item or a Navi key set to Game Mode.
 *
 *  1. If bit 15 of the application state halfword +4 is set, set its bit 10 and rearm the port events of all
 *     ports. Close the menu.
 *  2. Yes: make the switch the notice asked about, clear settings byte +0x1A9 and open the page:
 *     Game Mode: Game mode on (Pro bit cleared), the Game Mode list on the current game mode;
 *     Pro Mode: the Pro Mode list on the current pro mode, Pro mode switched on if it was off;
 *     Navi key: Game mode on and the Game Mode quick menu of the first Navi key set to it.
 *     No: back to the item that opened the notice, without a switch (nothing for a Navi key).
 *  3. Select No again and request that the settings are saved.
 */
void osd_close_change_notice(void)
{
    unsigned char list_row;             /* the game mode, or the Pro Mode list index */

    /* 1. */
    if ((short)(app_state_record.sleep_word & SLEEP_WORD_BIT15)) {
        app_state_record.sleep_word |= SLEEP_WORD_BIT10;
        input_rearm_port_event(ALL_PORTS, 0);
    }
    osd_menu_state = MENU_STATE_CLOSED;
    osd_hide_menu();

    /* 2. */
    if (user_settings.byte_0x1aa == NOTICE_BUTTON_YES) {
        switch (app_state_record.notice_origin) {
        case NOTICE_FROM_GAME_MODE:
            list_row = user_settings.game_mode;
            app_state_record.notice_origin = NOTICE_ORIGIN_DONE;
            osd_menu_state = list_row + MENU_STATE_GAME_MODE_LIST;
            user_settings.gaming_flags.bits.pro_mode = 0;
            user_settings.byte_0x1a9 = 0;
            UserSetGameMode();
            osd_redraw_page_after_notice(NOTICE_FROM_GAME_MODE, 1);
            osd_choice_row = user_settings.game_mode;
            osd_edit_value = (user_settings.gaming_flags.word >> 11) & 1;
            break;
        case NOTICE_FROM_PRO_MODE:
            app_state_record.notice_origin = NOTICE_ORIGIN_DONE;
            user_settings.byte_0x1a9 = 0;
            osd_menu_state = osd_step_pro_mode_index(user_settings.pro_mode, 0) + MENU_STATE_PRO_MODE_LIST;
            osd_redraw_page_after_notice(NOTICE_FROM_PRO_MODE, 1);
            osd_choice_row = user_settings.pro_mode;
            /* Values from before the switch: the Pro bit, and the colour temperature as the value to restore
               when the list is left. */
            osd_edit_value = (user_settings.gaming_flags.word >> 11) & 1;
            osd_saved_choice_value = user_settings.color_temperature;
            if (!(user_settings.gaming_flags.word & GAMING_FLAG_PRO_MODE)) {
                user_settings.gaming_flags.word |= GAMING_FLAG_PRO_MODE;
                UserSetProMode();
            }
            osd_list_id = LIST_ID_PRO_MODE;
            break;
        case NOTICE_FROM_NAVI_KEY:
            app_state_record.notice_origin = NOTICE_ORIGIN_DONE;
            osd_menu_state = MENU_STATE_NAVI_GAME_MODE;
            user_settings.gaming_flags.bits.pro_mode = 0;
            user_settings.byte_0x1a9 = 0;
            UserSetGameMode();
            /* Directions 0..3 = up, down, left, right. */
            if (user_settings.navi_key_up == NAVI_FUNCTION_GAME_MODE)
                osd_draw_navi_quick_menu(0);
            else if (user_settings.navi_key_down == NAVI_FUNCTION_GAME_MODE)
                osd_draw_navi_quick_menu(1);
            else if (user_settings.navi_key_left == NAVI_FUNCTION_GAME_MODE)
                osd_draw_navi_quick_menu(2);
            else if (user_settings.navi_key_right == NAVI_FUNCTION_GAME_MODE)
                osd_draw_navi_quick_menu(3);
            osd_show_menu_layer();
            break;
        }
    } else {
        switch (app_state_record.notice_origin) {
        case NOTICE_FROM_GAME_MODE:
            osd_menu_state = MENU_STATE_GAME_MODE_ITEM;
            osd_redraw_page_after_notice(NOTICE_FROM_GAME_MODE, 0);
            break;
        case NOTICE_FROM_PRO_MODE:
            osd_menu_state = MENU_STATE_PRO_MODE_ITEM;
            osd_redraw_page_after_notice(NOTICE_FROM_PRO_MODE, 0);
            osd_highlight_item_row(0, 1);
            list_row = osd_step_pro_mode_index(user_settings.pro_mode, 0);
            osd_highlight_choice_row(list_row % PRO_MODE_LIST_ROWS, 2);
            break;
        }
    }

    /* 3. */
    user_settings.byte_0x1aa = 0;
    osd_mark_settings_changed();
}
