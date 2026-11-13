/* osd_draw_input_item_state  (FUN_a00aa01c)
 *
 * Draw the switch state of the Input Source auto item and set the key guide.
 *   item: item row
 *   mode: highlight style
 * Note: Only row 4 has a switch (bit 9 of settings word 0).
 * Name basis: descriptive - called by the Input Source item handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00aa01c @ 0xa00aa01c, flags -mcpu=v8 -O3 -g.
 * Source form: the osd_draw_cell_run call is written once per glyph value in an if / else on the cell value (the
 * compiler merges the two calls by cross-jumping into one call after a branch that selects the glyph). The last
 * call of each arm is a tail call. user_settings is read as an unsigned int (word 0).
 */
extern unsigned int user_settings;
extern void osd_draw_cell_run(unsigned char across, unsigned char rising, unsigned short attribute, unsigned short column, unsigned char row, unsigned char count, unsigned char first_glyph);
extern void osd_update_key_guide(unsigned int first_text, unsigned int second_text);

#define SETTINGS_WORD0_BIT9   0x200
#define HIGHLIGHT_ITEM_ACTIVE 1
#define SWITCH_COLUMN         0x22
#define SWITCH_OFF_GLYPHS     0x34    /* first of three glyph bytes, off */
#define SWITCH_ON_GLYPHS      0x37    /* first of three glyph bytes, on */
#define KEY_TEXT_MOVE         0       /* key guide texts: Move, Enter, Switch, ..., Select */
#define KEY_TEXT_SWITCH       2
#define KEY_TEXT_SELECT       4

/* Draw the switch of an Input Source item and update the key guide. Only
 * item 4 has a switch: bit 9 of settings word 0 (on / off). Its three cells at
 * column 0x22, row 2 * item + 6, get the selected-item cell value
 * (0x742 on, 0x542 off) when mode is HIGHLIGHT_ITEM_ACTIVE, else the normal one
 * (0x792 on, 0x592 off), with glyphs 0x37.. for on and 0x34.. for off; the key
 * guide then shows Move and Switch. Any other item only gets the key guide with
 * Move and Select. Called by the Input Source item handlers. */
void osd_draw_input_item_state(unsigned char item, unsigned char mode)
{
    unsigned char row;
    unsigned char on = 0xff;
    unsigned short cell;
    row = item * 2 + 6;
    if (item == 4) {
        on = 1;
        if (!(user_settings & SETTINGS_WORD0_BIT9))
            on = 0;
    }
    if (item == 4) {
        if (mode == HIGHLIGHT_ITEM_ACTIVE)
            cell = on == 1 ? 0x742 : 0x542;
        else
            cell = on == 1 ? 0x792 : 0x592;
        if (cell == 0x742 || cell == 0x792)
            osd_draw_cell_run(1, 1, cell, SWITCH_COLUMN, row, 3, SWITCH_ON_GLYPHS);
        else
            osd_draw_cell_run(1, 1, cell, SWITCH_COLUMN, row, 3, SWITCH_OFF_GLYPHS);
        osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_SWITCH);
    } else
        osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_SELECT);
}
