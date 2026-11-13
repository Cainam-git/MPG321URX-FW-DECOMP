/* osd_cancel_power_button  (FUN_a0099168)
 *
 * Leave the Power Button list with the saved behaviour and go back (left)
 * Note: Returns to state 0x2E.
 * Name basis: derived - handler table 0xA802422C: left on states 0xB4/0xB5
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099168 @ 0xa0099168-0xa00991ec (33 words), flags -mcpu=v8 -O3 -g.
 * Source form: bit 15 of word +0xA8 is a 1-bit bit-field (big-endian numbering: 16 high bits, the bit, 15 low
 * bits) reached through a struct pointer; the bit is read again for each use.
 */
/* Settings word +0xA8; bit 15 is the Power Button choice. */
struct user_settings_record { unsigned char pad[0xa8]; struct { unsigned int hi : 16, standby : 1, lo : 15; } flags; };
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);

#define MENU_STATE_POWER_BUTTON_ITEM 0x2e /* Power Button item of the Settings page (item row 4) */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_DRAW                1
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */
#define CHOICE_ROW_PLAIN         0      /* osd_highlight_choice_row style: plain */

/*
 * Left key in the Power Button list (states 0xB4, 0xB5): put back the choice saved on entry and go back to the
 * Power Button item.
 *
 * The row of the choice now stored loses its highlight, bit 15 of settings word +0xA8 gets the choice that
 * osd_choice_row saved on entry (only its lowest bit is kept), and that row gets the plain highlight and the mark.
 */
void osd_cancel_power_button(void)
{
    struct user_settings_record *p = &user_settings;

    osd_clear_choice_highlight(p->flags.standby);
    p->flags.standby = osd_choice_row;
    osd_highlight_choice_row(p->flags.standby, CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, p->flags.standby, MARK_DRAW);
    osd_menu_state = MENU_STATE_POWER_BUTTON_ITEM;
    osd_highlight_item_row(4, ITEM_ROW_ACTIVE);
}
