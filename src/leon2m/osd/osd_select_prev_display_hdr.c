/* osd_select_prev_display_hdr  (FUN_a009c67c)
 *
 * Move to the previous allowed DisplayHDR mode (up key) and store it.
 * Note: Wraps inside the states 0x77..0x79; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: up on states 0x77..0x79; writes bits 18..19 of settings word
 *   +0xAC; texts 0x190CEC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009c67c @ 0xa009c67c, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - BASE + (COUNT - 1), taken modulo the count in a second statement;
 *  - the mode is a 2-bit field of the settings record (bits 18..19 of the word at +0xAC), assigned from an
 *    unsigned int; the mark is drawn before the highlight.
 */

#define MENU_STATE_DISPLAY_HDR_LIST 0x77        /* + row: the three DisplayHDR modes */
#define DISPLAY_HDR_COUNT           3
#define CHOICE_MARK_LIST            1           /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON              1
#define CHOICE_MARK_OFF             0
#define CHOICE_ROW_EDGED            1           /* highlight style of a choice row */

/* Fields of the user settings record (docs/RECORDS.md) up to the word at +0xAC. */
struct user_settings_record {
    unsigned char p000[0xac];
    unsigned int p_0xac_hi : 12;
    unsigned int display_hdr_mode : 2;          /* +0xAC bits 18..19: the DisplayHDR mode */
    unsigned int p_0xac_lo : 18;
};
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);

/*
 * Up key in the DisplayHDR list: move the highlight to the previous row, wrapping from the first row to the last.
 * Rows that osd_is_choice_enabled rejects are skipped.
 *
 * The row number is stored as the DisplayHDR mode at once. The mark is drawn at the row of the mode saved on
 * entry (osd_choice_row); it is switched off while the highlight is on that row and on otherwise.
 */
void osd_select_prev_display_hdr(void)
{
    int row;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_DISPLAY_HDR_LIST);
    do {
        row = (unsigned short)osd_menu_state - MENU_STATE_DISPLAY_HDR_LIST + (DISPLAY_HDR_COUNT - 1);
        row = row % DISPLAY_HDR_COUNT;
        osd_menu_state = row + MENU_STATE_DISPLAY_HDR_LIST;
    } while (osd_is_choice_enabled(row) != 1);
    user_settings.display_hdr_mode = osd_menu_state - MENU_STATE_DISPLAY_HDR_LIST;
    if (osd_menu_state - MENU_STATE_DISPLAY_HDR_LIST == osd_choice_row)
        osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, CHOICE_MARK_OFF);
    else
        osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, CHOICE_MARK_ON);
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_DISPLAY_HDR_LIST, CHOICE_ROW_EDGED);
}
