/* osd_draw_professional_item_state  (FUN_a00aa258)
 *
 * Draw the switch state of a Professional item and set the key guide.
 *   item: item row
 *   mode: highlight style
 * Note: Only row 1 (Low Blue Light, bit 4 of +0x11C) has a switch.
 * Name basis: derived - called by the Professional item handlers and osd_toggle_low_blue_light
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00aa258 @ 0xa00aa258, flags -mcpu=v8 -O3 -g.
 * Source form: the osd_draw_cell_run call is written once per glyph value in an if / else on the cell value (the
 * compiler merges the two calls by cross-jumping into one call after a branch that selects the glyph). The same
 * form as osd_draw_input_item_state.
 */
extern unsigned int user_settings_professional_flags;
extern void osd_draw_cell_run(unsigned char across, unsigned char rising, unsigned short attribute, unsigned short column, unsigned char row, unsigned char count, unsigned char first_glyph);
extern void osd_draw_key_guide(unsigned int group, unsigned int mode);
extern void osd_update_key_guide(unsigned int first_text, unsigned int second_text);

#define LOW_BLUE_LIGHT_BIT    0x10    /* bit 4 of settings word +0x11C */
#define HIGHLIGHT_ITEM_ACTIVE 1
#define SWITCH_COLUMN         0x22
#define SWITCH_OFF_GLYPHS     0x34    /* first of three glyph bytes, off */
#define SWITCH_ON_GLYPHS      0x37    /* first of three glyph bytes, on */
#define KEY_TEXT_MOVE         0       /* key guide texts: Move, Enter, Switch, ..., Select */
#define KEY_TEXT_ENTER        1
#define KEY_TEXT_SWITCH       2

/* Draw the switch of a Professional item and update the key guide. Only item
 * 1 (Low Blue Light, bit 4 of settings word +0x11C) has a switch. Its three
 * cells at column 0x22, row 2 * item + 6, get the selected-item cell value
 * (0x742 on, 0x542 off) when mode is HIGHLIGHT_ITEM_ACTIVE, else the normal one
 * (0x792 on, 0x592 off), with glyphs 0x37.. for on and 0x34.. for off. Then
 * the key guide cells are drawn with osd_draw_key_guide(1, 3) and the texts are
 * Move and Switch. Any other item gets osd_draw_key_guide(1, 2) and the texts
 * Move and Enter. Called by the Professional item handlers and
 * osd_toggle_low_blue_light. */
void osd_draw_professional_item_state(unsigned char item, unsigned char mode)
{
    unsigned char row;
    unsigned char on = 0xff;
    unsigned short cell;
    row = item * 2 + 6;
    if (item == 1) {
        on = 1;
        if (!(user_settings_professional_flags & LOW_BLUE_LIGHT_BIT))
            on = 0;
    }
    if (item == 1) {
        if (mode == HIGHLIGHT_ITEM_ACTIVE)
            cell = on == 1 ? 0x742 : 0x542;
        else
            cell = on == 1 ? 0x792 : 0x592;
        if (cell == 0x742 || cell == 0x792)
            osd_draw_cell_run(1, 1, cell, SWITCH_COLUMN, row, 3, SWITCH_ON_GLYPHS);
        else
            osd_draw_cell_run(1, 1, cell, SWITCH_COLUMN, row, 3, SWITCH_OFF_GLYPHS);
        osd_draw_key_guide(1, 3);
        osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_SWITCH);
    } else {
        osd_draw_key_guide(1, 2);
        osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
    }
}
