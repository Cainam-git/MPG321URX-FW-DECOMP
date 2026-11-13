/* osd_cancel_night_vision  (FUN_a0095d5c)
 *
 * Restore the Night Vision level saved on entry and go back (left)
 * Note: Copies 0xA8025C56 back into settings byte +0x15B.
 * Name basis: derived - handler table 0xA802422C: left on states 0x4E..0x52
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095d5c @ 0xa0095d5c-0xa0095dd8 (124 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a byte array. osd_draw_choice_mark is declared with byte parameters, and
 * the last call is a tail call.
 */
extern unsigned char user_settings[];
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void sys_user_apply_dimming_mode(void);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_mark(unsigned char, unsigned char, unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_adaptive_sync_status(void);

#define MENU_STATE_NIGHT_VISION_ITEM 0xf        /* Night Vision item of the Gaming page */
#define MENU_STATE_NIGHT_VISION_LIST 0x4e       /* + level: the Night Vision list, one state per level */
#define USER_SETTINGS_NIGHT_VISION   0x15b      /* offset of the Night Vision byte in the settings record */
#define CHOICE_MARK_LIST             1          /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON               1
#define CHOICE_ROW_PLAIN             0          /* highlight style of a choice row while the list is left */
#define HIGHLIGHT_ITEM_ACTIVE        1          /* highlight style of an item row with the cursor in the item list */
#define NIGHT_VISION_ITEM_ROW        1          /* item row of the Night Vision item (state 0xF - 0xE) */

/*
 * Left key in the Night Vision list: put back the level that was saved when the list was opened (osd_choice_row).
 * When the stored level was changed meanwhile, the saved one is written back and applied through
 * sys_user_apply_dimming_mode. Then the highlight leaves the list, the level's mark is drawn, the menu state
 * returns to the Night Vision item, and the Adaptive-Sync status line is redrawn.
 */
void osd_cancel_night_vision(void)
{
    if (user_settings[USER_SETTINGS_NIGHT_VISION] != osd_choice_row) {
        user_settings[USER_SETTINGS_NIGHT_VISION] = osd_choice_row;
        sys_user_apply_dimming_mode();
    }
    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_NIGHT_VISION_LIST);
    osd_highlight_choice_row(user_settings[USER_SETTINGS_NIGHT_VISION], CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings[USER_SETTINGS_NIGHT_VISION], CHOICE_MARK_ON);
    osd_menu_state = MENU_STATE_NIGHT_VISION_ITEM;
    osd_highlight_item_row(NIGHT_VISION_ITEM_ROW, HIGHLIGHT_ITEM_ACTIVE);
    osd_draw_adaptive_sync_status();
}
