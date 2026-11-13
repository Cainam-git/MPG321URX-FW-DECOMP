/* osd_clear_pip_pbp_marks  (FUN_a00976a8)
 *
 * Clear the PIP/PBP list marks of the saved and the current layout, highlight the parent item.
 * Note: Nothing calls it directly.
 * Name basis: descriptive - two osd_draw_choice_mark calls with 'off' for 0xA8025C56 and settings byte +0x1F,
 *   then the item row of state - 0x23
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00976a8 @ 0xa00976a8, flags -mcpu=v8 -O3 -g.
 * Source form: the routine declares six parameters and passes the last four on to osd_highlight_item_row
 * (declared without a prototype), which reads only two arguments; the pass-through of the four registers is part
 * of the exact build.
 */

#define MENU_STATE_PIP_PBP_OFF  0x23    /* first of the three layout items; item = state - 0x23 */
#define LIST_KIND_ITEMS         0       /* osd_draw_choice_mark: the item list (kinds 1 and 2 are choice lists) */
#define HIGHLIGHT_PARENT        2       /* osd_highlight_item_row: parent of an open choice list */

extern unsigned char osd_choice_row;
extern unsigned char user_settings_pip_pbp_mode;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark();
extern int osd_clear_item_highlight();
extern int osd_highlight_item_row();

/*
 * Redraw the marks of the PIP/PBP item list: the item row saved in osd_choice_row is drawn back in normal
 * colours, its mark and the mark of the current layout (settings +0x1F) are cleared, and the item row of the
 * open item (menu state - 0x23) is highlighted as the parent of an open list.
 *
 * The first two parameters are not used; parameters 3 to 6 are passed on unchanged to
 * osd_highlight_item_row, which uses two arguments. No call to this routine and no table entry for it was found
 * in this firmware.
 */
void osd_clear_pip_pbp_marks(unsigned int ignored_1, unsigned int ignored_2, unsigned int forwarded_3,
                              unsigned int forwarded_4, unsigned int forwarded_5, unsigned int forwarded_6)
{
    osd_clear_item_highlight(osd_choice_row);
    osd_draw_choice_mark(LIST_KIND_ITEMS, osd_choice_row, 0);
    osd_draw_choice_mark(LIST_KIND_ITEMS, user_settings_pip_pbp_mode, 0);
    osd_highlight_item_row(osd_menu_state - MENU_STATE_PIP_PBP_OFF & 0xff, HIGHLIGHT_PARENT, forwarded_3, forwarded_4, forwarded_5, forwarded_6);
}
