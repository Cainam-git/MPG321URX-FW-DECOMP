/* osd_redraw_settings_page  (FUN_a00ad460)
 *
 * Redraw the Settings page after the menu language changed.
 * Note: Redraws frames, items, header and key guide in the new language.
 * Name basis: derived - called by osd_cancel_language and osd_select_prev|next_language
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ad460 @ 0xa00ad460, flags -mcpu=v8 -O3 -g.
 * Source form: the row-5 and row-7 tests are two nested ifs (with '&&' the two tests are combined into one
 * flag test).
 */
#define TAB_SETTINGS 7
#define HIGHLIGHT_TAB_PARENT 2     /* tab drawn as the parent of the open item list */
#define KEY_TEXT_MOVE 0
#define KEY_TEXT_SELECT 4
#define KEY_GUIDE_REDRAW_ALL 0xff  /* stored pair that matches no text number: both guide texts are drawn */

/* user_settings_key_guide_shown is settings byte +0x189; osd_update_key_guide keeps the two key guide texts last
 * shown in it, one per nibble. */
extern unsigned char user_settings_key_guide_shown;
extern void panel_wait_sync_pulse(void);
extern void osd_draw_cell_run(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void osd_draw_tab_names(unsigned char);
extern void osd_highlight_tab(int, int);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_set_window_enable(int, int, int);
extern void osd_draw_settings_items(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_signal_info_header(void);
extern void osd_update_key_guide(unsigned int, unsigned int);

/* Redraw the whole Settings page after the menu language changed: the left column of cell runs
 * (row 6 with value 0x7c2 and length 10, rows 8..0x15 with 0x792 and length 0xb; row 7 is
 * skipped), the tab names, the Settings tab highlight, the cleared item area with page 0 of the
 * items, the first item highlighted, the signal info header and the key guide. Setting the stored
 * key guide byte to 0xff makes the last call draw both guide texts. No parameters; called by
 * the language list handlers (cancel and previous/next language). */
void osd_redraw_settings_page(void)
{
    unsigned char i;

    panel_wait_sync_pulse();
    for (i = 6; i <= 0x15; i++) {
        if (i != 5)
            if (i != 7) {
                if (i == 6)
                    osd_draw_cell_run(1, 0, 0x7c2, 7, 6, 10, 0);
                else
                    osd_draw_cell_run(1, 0, 0x792, 7, i, 0xb, 0);
            }
    }
    osd_draw_tab_names(1);
    osd_highlight_tab(TAB_SETTINGS, HIGHLIGHT_TAB_PARENT);
    panel_wait_sync_pulse();
    for (i = 5; i <= 0x14; i++) {
        osd_api_fill_cell_bytes(0, 0x13, i, 0x13, 0, 0);
        osd_api_fill_cells(0x13, i, 0x13, 0x792, 0);
    }
    osd_api_fill_cell_bytes(0, 0x1c, 0x15, 2, 0, 0);
    osd_api_set_window_enable(5, 0, 0);
    osd_draw_settings_items(0);
    osd_highlight_item_row(0, 2);
    osd_draw_signal_info_header();
    user_settings_key_guide_shown = KEY_GUIDE_REDRAW_ALL;
    osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_SELECT);
}
