/* osd_select_next_kvm  (FUN_a009db20)
 *
 * Move to the next allowed KVM choice (Auto, Upstream, Type C) (down key)
 * Name basis: derived - handler table 0xA802422C: down on states 0x3C..0x3E; texts 0x1909EC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009db20 @ 0xa009db20, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - (BASE - 1), taken modulo the count in a second statement;
 *  - the settings record is a byte array (KVM at +0x17C); osd_choice_row is copied into a block-scope local for the
 *    compare and the mark row;
 *  - the two input_api_* routines are declared but not used here.
 */

#define MENU_STATE_KVM_LIST     0x3c            /* + row: Auto, Upstream, Type C */
#define KVM_COUNT               3
#define USER_SETTINGS_KVM       0x17c           /* user_settings_kvm */
#define CHOICE_MARK_LIST        1               /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON          1
#define CHOICE_MARK_OFF         0
#define CHOICE_ROW_EDGED        1               /* highlight style of a choice row */

extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);

/*
 * Down key on the KVM choices (Auto, Upstream, Type C): move the highlight to the next row, wrapping from the
 * last row to the first. Rows that osd_is_choice_enabled rejects are skipped.
 *
 * The row number is stored as the KVM setting (+0x17C) at once. The mark is drawn at the row of osd_choice_row
 * (the value saved on entry); it is switched off while the highlight is on that row and on otherwise.
 */
void osd_select_next_kvm(void)
{
    int row;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_KVM_LIST);
    do {
        row = (unsigned short)osd_menu_state - (MENU_STATE_KVM_LIST - 1);
        row = row % KVM_COUNT;
        osd_menu_state = row + MENU_STATE_KVM_LIST;
    } while (osd_is_choice_enabled(row) != 1);
    user_settings[USER_SETTINGS_KVM] = osd_menu_state - MENU_STATE_KVM_LIST;
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_KVM_LIST, CHOICE_ROW_EDGED);
    {
        unsigned char saved = osd_choice_row;
        if (osd_menu_state - MENU_STATE_KVM_LIST == saved)
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_OFF);
        else
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_ON);
    }
}
