/* osd_close_timeout_slider  (FUN_a0098e28)
 *
 * Close the OSD Time out slider and go back to the item (OK)
 * Note: Returns to state 0x2C.
 * Name basis: derived - handler table 0xA802422C: OK on state 0xB0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0098e28 @ 0xa0098e28, flags -mcpu=v8 -O3 -g.
 */
extern int osd_clear_choice_highlight(int);
extern unsigned int osd_menu_state;
extern void osd_highlight_item_row(int, int);
extern int osd_draw_timeout_slider(int);
extern unsigned char osd_request_bits;

#define MENU_STATE_OSD_TIMEOUT_ITEM 0x2c /* OSD Time out item of the Settings page (item row 2) */
#define SLIDER_DRAWN_PLAIN       0      /* osd_draw_timeout_slider argument: not being edited */
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK on the OSD Time out slider (menu state 0xB0): keep the value and go back to the OSD Time out item.
 * The slider is redrawn as not being edited.
 */
void osd_close_timeout_slider(void)
{
    osd_clear_choice_highlight(0);
    osd_menu_state = MENU_STATE_OSD_TIMEOUT_ITEM;
    osd_highlight_item_row(2, ITEM_ROW_ACTIVE);
    osd_draw_timeout_slider(SLIDER_DRAWN_PLAIN);
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
