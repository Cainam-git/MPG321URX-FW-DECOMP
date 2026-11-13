/* osd_select_prev_kvm  (FUN_a009da6c)
 *
 * Move to the previous allowed KVM choice (Auto, Upstream, Type C) (up key)
 * Name basis: derived - handler table 0xA802422C: up on states 0x3C..0x3E; texts 0x1909EC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009da6c @ 0xa009da6c, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - one expression for the walk back, ((u16)state - 58) % 3 in an int, with the base written as the decimal 60;
 *  - the setting is written through the separate label user_settings_kvm (a byte); osd_choice_row is read again
 *    for the compare and the mark row.
 */

#define MENU_STATE_KVM_LIST     60              /* + row: Auto, Upstream, Type C */
#define KVM_COUNT               3
#define CHOICE_MARK_LIST        1               /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON          1
#define CHOICE_MARK_OFF         0
#define CHOICE_ROW_EDGED        1               /* highlight style of a choice row */

extern unsigned int osd_menu_state;
extern unsigned char user_settings_kvm;         /* settings byte +0x17C: the KVM setting */
extern unsigned char osd_choice_row;
extern void osd_clear_choice_highlight(unsigned char);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_mark(int, unsigned char, int);

/*
 * Up key on the KVM choices (Auto, Upstream, Type C): move the highlight to the previous row, wrapping from the
 * first row to the last. Rows that osd_is_choice_enabled rejects are skipped.
 *
 * The row number is stored as the KVM setting (+0x17C) at once. The mark is drawn at the row of osd_choice_row
 * (the value saved on entry); it is switched off while the highlight is on that row and on otherwise.
 */
void osd_select_prev_kvm(void)
{
    int row;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_KVM_LIST);
    do {
        row = ((unsigned short)osd_menu_state - (MENU_STATE_KVM_LIST - (KVM_COUNT - 1))) % KVM_COUNT;
        osd_menu_state = row + MENU_STATE_KVM_LIST;
    } while (osd_is_choice_enabled(row) != 1);
    user_settings_kvm = osd_menu_state - MENU_STATE_KVM_LIST;
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_KVM_LIST, CHOICE_ROW_EDGED);
    if (osd_menu_state - MENU_STATE_KVM_LIST == osd_choice_row)
        osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, CHOICE_MARK_OFF);
    else
        osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, CHOICE_MARK_ON);
}
