/* osd_open_transparency_slider  (FUN_a0098d4c)
 *
 * Open the menu Transparency slider (OK or right key)
 * Note: Menu state 0xAF; value = settings byte +0x0F, saved in 0xA8025C56.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x2B = 'Transparency' (Settings texts
 *   0x1874F8)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0098d4c @ 0xa0098d4c, flags -mcpu=v8 -O3 -g.
 * Source form: the routine declares two parameters and passes the second on to osd_draw_transparency_slider
 * (declared without a prototype), which reads only one argument; the pass-through is part of the exact build.
 */

#define MENU_STATE_SETTINGS_ITEMS   0x2a    /* item row of the Settings page = menu state - 0x2A (state 0x2B = Transparency) */
#define MENU_STATE_TRANSPARENCY     0xaf    /* the Transparency slider is open */
#define HIGHLIGHT_PARENT            2       /* osd_highlight_item_row: parent of an open list */
#define CHOICE_ROW_PLAIN            0       /* osd_highlight_choice_row: style 0 */
#define SLIDER_EDITING              1       /* osd_draw_*_slider: the slider is being edited (highlighted) */

extern unsigned char osd_choice_row;
extern unsigned char user_settings_transparency;
extern unsigned int osd_menu_state;
extern void osd_highlight_item_row();
extern int osd_highlight_choice_row();
extern int osd_draw_transparency_slider();

/*
 * OK or right key on the 'Transparency' item (menu state 0x2B): open its slider.
 *
 * The current value (settings +0x0F) is saved in osd_choice_row, the item row is shown as the parent of an open
 * list, the menu state becomes 0xAF and the slider is drawn in its editing look.
 *
 * Parameters: the key handler's two arguments. The first is not used; the second is passed on unchanged to
 * osd_draw_transparency_slider, which does not read it.
 */
void osd_open_transparency_slider(unsigned int unused, unsigned int forwarded)
{
    osd_choice_row = user_settings_transparency;
    osd_highlight_item_row(osd_menu_state - MENU_STATE_SETTINGS_ITEMS & 0xff, HIGHLIGHT_PARENT);
    osd_menu_state = MENU_STATE_TRANSPARENCY;
    osd_highlight_choice_row(0, 1);
    osd_draw_transparency_slider(SLIDER_EDITING, forwarded);
}
