/* osd_cancel_kvm  (FUN_a0099598)
 *
 * Restore the KVM choice saved on entry and go back (left)
 * Note: Writes 0xA8025C56 back into settings byte +0x17C.
 * Name basis: derived - handler table 0xA802422C: left on states 0x3C..0x3E
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099598 @ 0xa0099598, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a byte array; the KVM byte is user_settings[0x17c].
 */
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];

extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(int, int);
extern void osd_highlight_item_row(int, int);

#define USER_SETTINGS_KVM        0x17c  /* KVM_AUTO 0, KVM_UPSTREAM 1, KVM_TYPE_C 2 */
#define MENU_STATE_KVM_ITEM      0x0b   /* KVM item of the G.I. page (item row 0) */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_DRAW                1
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */
#define CHOICE_ROW_PLAIN         0      /* osd_highlight_choice_row style: plain */

/*
 * Left key in the KVM list (states 0x3C..0x3E): put back the setting saved on entry and go back to the KVM item.
 *
 * The row of the setting now stored loses its highlight, settings byte +0x17C gets the value that osd_choice_row
 * saved on entry, and that row gets the plain highlight and the mark.
 */
void osd_cancel_kvm(void)
{
    osd_clear_choice_highlight(user_settings[USER_SETTINGS_KVM]);
    user_settings[USER_SETTINGS_KVM] = osd_choice_row;
    osd_highlight_choice_row(osd_choice_row, CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings[USER_SETTINGS_KVM], MARK_DRAW);
    osd_menu_state = MENU_STATE_KVM_ITEM;
    osd_highlight_item_row(0, ITEM_ROW_ACTIVE);
}
