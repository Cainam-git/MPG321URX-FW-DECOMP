/* osd_accept_power_button  (FUN_a00990e4)
 *
 * Keep the highlighted Power Button behaviour and go back (OK)
 * Note: Returns to state 0x2E.
 * Name basis: derived - handler table 0xA802422C: OK on states 0xB4/0xB5
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00990e4 @ 0xa00990e4, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is an array of words; word index 42 is +0xA8.
 */
extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern unsigned int osd_menu_state;
extern unsigned int user_settings[];

extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(int, int);
extern void osd_highlight_item_row(int, int);

#define SETTINGS_FLAGS_WORD      42     /* word index of settings +0xA8 */
#define SETTINGS_POWER_BUTTON_STANDBY_SHIFT 0xf /* bit 15 of +0xA8: 0 = OFF, 1 = Standby */
#define MENU_STATE_POWER_BUTTON_ITEM 0x2e /* Power Button item of the Settings page (item row 4) */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define MARK_DRAW                1
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */
#define CHOICE_ROW_PLAIN         0      /* osd_highlight_choice_row style: plain */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK in the Power Button list (states 0xB4, 0xB5): go back to the Power Button item.
 *
 * Only the display is updated here, the stored bit is not written. The row saved on entry (osd_choice_row)
 * loses its highlight and mark; the row of the choice stored in bit 15 of settings word +0xA8 gets the plain
 * highlight and the mark.
 */
void osd_accept_power_button(void)
{
    osd_clear_choice_highlight(osd_choice_row);
    osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, MARK_CLEAR);
    osd_highlight_choice_row((user_settings[SETTINGS_FLAGS_WORD] >> SETTINGS_POWER_BUTTON_STANDBY_SHIFT) & 1, CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, (user_settings[SETTINGS_FLAGS_WORD] >> SETTINGS_POWER_BUTTON_STANDBY_SHIFT) & 1, MARK_DRAW);
    osd_menu_state = MENU_STATE_POWER_BUTTON_ITEM;
    osd_highlight_item_row(4, ITEM_ROW_ACTIVE);
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
