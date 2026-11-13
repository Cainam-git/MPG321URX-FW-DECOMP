/* osd_accept_scope_size  (FUN_a00954a0)
 *
 * Keep the highlighted Optix Scope size and go back (OK)
 * Note: States 0xE7..0xE9; returns to 'Scope Size' (0x44).
 * Name basis: derived - handler table 0xA802422C: OK on states 0xE7..0xE9; texts 0x18D578 (Scope Size, Scope
 *   Ratio)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00954a0, flags -mcpu=v8 -O3 -g.
 * Source form: 'osd_request_bits = osd_request_bits | 2' is written as an assignment; the routine sets no
 * return value.
 */
#define MENU_STATE_SCOPE_SIZE_ITEM    0x44      /* Optix Scope items, Scope Size row (item row 0) */
#define OSD_REQUEST_SETTINGS_CHANGED  0x02      /* bit of osd_request_bits */

extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char osd_request_bits;

extern void osd_clear_choice_column(void);
extern void osd_draw_optix_scope_items(void);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_mark(int, unsigned char, int);

/*
 * OK key in the Scope Size choices: back to the Optix Scope items. The choice column is cleared, the items are
 * drawn, the menu state becomes the Scope Size item with its row highlighted, the choice row osd_choice_row + 2
 * is highlighted (style 2) and marked, and the settings-changed request is made.
 */
void osd_accept_scope_size(void)
{
    osd_clear_choice_column();
    osd_draw_optix_scope_items();
    osd_menu_state = MENU_STATE_SCOPE_SIZE_ITEM;
    osd_highlight_choice_row(0, 1);
    osd_highlight_choice_row(osd_choice_row + 2, 2);
    osd_draw_choice_mark(1, osd_choice_row + 2, 1);
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
