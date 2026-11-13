/* osd_accept_kvm  (FUN_a0099524)
 *
 * Keep the highlighted KVM choice, apply it and go back (OK)
 * Note: Returns to state 0x0B.
 * Name basis: derived - handler table 0xA802422C: OK on states 0x3C..0x3E; texts 0x1909EC: Auto, Upstream,
 *   Type C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099524 @ 0xa0099524, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a byte array; the KVM byte is user_settings[0x17c].
 */
extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];

extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(int, int);
extern void osd_highlight_item_row(int, int);

#define USER_SETTINGS_KVM        0x17c  /* KVM_AUTO 0, KVM_UPSTREAM 1, KVM_TYPE_C 2 */
#define MENU_STATE_KVM_ITEM      0x0b   /* KVM item of the G.I. page (item row 0) */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define MARK_DRAW                1
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */
#define CHOICE_ROW_PLAIN         0      /* osd_highlight_choice_row style: plain */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK in the KVM list (states 0x3C..0x3E): go back to the KVM item.
 *
 * Only the display is updated here, the setting is not written. The row saved on entry (osd_choice_row) loses
 * its highlight and mark; the row of the KVM setting (settings byte +0x17C) gets the plain highlight and the mark.
 */
void osd_accept_kvm(void)
{
    osd_clear_choice_highlight(osd_choice_row);
    osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, MARK_CLEAR);
    osd_highlight_choice_row(user_settings[USER_SETTINGS_KVM], CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings[USER_SETTINGS_KVM], MARK_DRAW);
    osd_menu_state = MENU_STATE_KVM_ITEM;
    osd_highlight_item_row(0, ITEM_ROW_ACTIVE);
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
