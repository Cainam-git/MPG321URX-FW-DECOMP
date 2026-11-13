/* osd_accept_scope_ratio  (FUN_a00955a0)
 *
 * Keep the highlighted Optix Scope ratio and go back (OK)
 * Note: States 0xEA..0xEC; returns to 'Scope Ratio' (0x45).
 * Name basis: derived - handler table 0xA802422C: OK on states 0xEA..0xEC; texts 0x18D578
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00955a0, flags -mcpu=v8 -O3 -g.
 * Source form: the (unsigned char) casts on osd_choice_row + 2 produce the 'and 0xff' instructions;
 * 'osd_request_bits = osd_request_bits | 2' is written as an assignment.
 */
#define MENU_STATE_SCOPE_RATIO_ITEM   0x45      /* Optix Scope items, Scope Ratio row (item row 1) */
#define OSD_REQUEST_SETTINGS_CHANGED  0x02      /* bit of osd_request_bits */

extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern unsigned int osd_menu_state;

extern void osd_clear_choice_column(void);
extern void osd_draw_optix_scope_items(void);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_mark(int, unsigned char, int);

/*
 * OK key in the Scope Ratio choices: back to the Optix Scope items. The choice column is cleared, the items are
 * drawn, the menu state becomes the Scope Ratio item, the choice row osd_choice_row + 2 is highlighted (style 2)
 * and marked, the Scope Ratio item row is highlighted, and the settings-changed request is made.
 */
void osd_accept_scope_ratio(void)
{
    osd_clear_choice_column();
    osd_draw_optix_scope_items();
    osd_menu_state = MENU_STATE_SCOPE_RATIO_ITEM;
    osd_highlight_choice_row((unsigned char)(osd_choice_row + 2), 2);
    osd_highlight_choice_row(1, 1);
    osd_draw_choice_mark(1, (unsigned char)(osd_choice_row + 2), 1);
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
