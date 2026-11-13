/* osd_cancel_display_hdr  (FUN_a0096e14)
 *
 * Restore the DisplayHDR mode saved on entry and go back (left)
 * Note: Returns to state 0x1D.
 * Name basis: derived - handler table 0xA802422C: left on states 0x77..0x79
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0096e14 @ 0xa0096e14 (-mcpu=v8 -O3 -g)
 * Source form: the DisplayHDR mode is a 2-bit bit-field (bits 18-19 of the word at +0xAC, between a 12-bit and
 * an 18-bit field); the firmware reads it again for every use. The last call is a tail call.
 */
struct user_settings_record {
    unsigned char pad0[0xac];
    unsigned int other_bits_hi : 12, display_hdr_mode : 2, other_bits_lo : 18;    /* +0xAC: bits 18-19 = DisplayHDR mode */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);

#define MENU_STATE_DISPLAY_HDR_ITEM  0x1d       /* DisplayHDR item of the Image page (item row 5) */
#define MENU_STATE_DISPLAY_HDR_LIST  0x77       /* + mode: the DisplayHDR list (states 0x77..0x79) */
#define DISPLAY_HDR_ITEM_ROW         5          /* item row of the DisplayHDR item */
#define CHOICE_MARK_LIST             1          /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON               1
#define CHOICE_ROW_PLAIN             0          /* highlight style of a choice row while the list is left */
#define HIGHLIGHT_ITEM_ACTIVE        1          /* highlight style of an item row with the cursor in the item list */

/*
 * Left key in the DisplayHDR list: put back the mode that was saved when the list was opened (osd_choice_row).
 * The highlight leaves the list row of the present state, the restored mode is highlighted and marked, and the
 * menu state returns to the DisplayHDR item with its row highlighted.
 */
void osd_cancel_display_hdr(void)
{
    user_settings.display_hdr_mode = osd_choice_row;
    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_DISPLAY_HDR_LIST);
    osd_highlight_choice_row(user_settings.display_hdr_mode, CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.display_hdr_mode, CHOICE_MARK_ON);
    osd_menu_state = MENU_STATE_DISPLAY_HDR_ITEM;
    osd_highlight_item_row(DISPLAY_HDR_ITEM_ROW, HIGHLIGHT_ITEM_ACTIVE);
}
