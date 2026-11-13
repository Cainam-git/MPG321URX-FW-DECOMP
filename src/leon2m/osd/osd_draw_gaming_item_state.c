/* osd_draw_gaming_item_state  (FUN_a00aa0e8)
 *
 * Draw the switch state of a Gaming item and set the key guide.
 *   item: item row
 *   mode: highlight style
 * Note: Rows 2, 5, 6 have switches (bit 15 of +0x174, bit 7 of +0xA8, bit 31 of +0x1F4).
 * Name basis: derived - called by the Gaming item handlers and osd_toggle_adaptive_sync / _dsc / _ai_vision
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00aa0e8 @ 0xa00aa0e8, flags -mcpu=v8 -O3 -g.
 * Source form: the AI Vision and Adaptive-Sync flags are set to 1 first and cleared when the bit is clear (the
 * two tests stay branches); the DSC mask is held in a local variable (and + addx instead of a sign shift); the
 * osd_draw_cell_run call is written once per glyph value in an if/else on the attribute test (the two calls are
 * merged by cross-jumping into one call after a branch that selects the glyph).
 */
extern unsigned int user_settings_word_0x174;
extern unsigned int user_settings_gaming_flags;
extern unsigned int user_settings_word_0x1f4;
extern void osd_draw_cell_run(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_update_key_guide(unsigned int, unsigned int);

#define GAMING_ITEM_AI_VISION     2     /* switch: bit 15 of user_settings word +0x174 */
#define GAMING_ITEM_ADAPTIVE_SYNC 5     /* switch: bit 7 of the gaming flags (+0xA8) */
#define GAMING_ITEM_DSC           6     /* switch: bit 31 of user_settings word +0x1F4 */
#define SWITCH_COLUMN             0x22  /* column of the three switch cells */
#define SWITCH_GLYPH_ON           0x37  /* first glyph of the three switch cells when the switch is on */
#define SWITCH_GLYPH_OFF          0x34  /* ... when it is off */
#define HIGHLIGHT_ITEM_ACTIVE     1     /* mode: same value as osd_highlight_item_row */
#define KEY_TEXT_MOVE             0     /* key guide texts (osd_update_key_guide) */
#define KEY_TEXT_ENTER            1
#define KEY_TEXT_SWITCH           2

/*
 * Draw the on/off switch of a Gaming item and set the key guide for it.
 *
 *   item  Gaming item row (7 rows per page)
 *   mode  1: the item is the active (highlighted) row; anything else: not
 *
 * The three items with a switch are AI Vision (2), Adaptive-Sync (5) and DSC (6). For them the three switch
 * cells at column 0x22 of the item's middle row (row = 2 * item + 6, 2 * item - 8 above item 6) get the
 * glyphs 0x37.. when the setting is on, 0x34.. when it is off; the attribute is 0x742 (active row) or 0x792 when
 * on, and 0x200 less when off. The key guide then shows icon set 3 with 'Move' / 'Switch'. Every other item
 * only gets icon set 2 with 'Move' / 'Enter'.
 *
 * Called by the Gaming item handlers after they move or toggle, and by the three toggle handlers.
 */
void osd_draw_gaming_item_state(unsigned char item, unsigned char mode)
{
    unsigned char row;
    unsigned char on = 0xff;
    unsigned short attr;
    unsigned int dsc_mask;

    if (item > 6)
        row = item * 2 - 8;
    else
        row = item * 2 + 6;
    if (item == GAMING_ITEM_AI_VISION) {
        on = 1;
        if (!(user_settings_word_0x174 & 0x8000))
            on = 0;
    } else if (item == GAMING_ITEM_ADAPTIVE_SYNC) {
        on = 1;
        if (!(user_settings_gaming_flags & 0x80))
            on = 0;
    } else if (item == GAMING_ITEM_DSC) {
        dsc_mask = 0x80000000;
        on = (user_settings_word_0x1f4 & dsc_mask) != 0;
    }
    if (item == GAMING_ITEM_ADAPTIVE_SYNC || item == GAMING_ITEM_AI_VISION || item == GAMING_ITEM_DSC) {
        if (mode == HIGHLIGHT_ITEM_ACTIVE)
            attr = on == 1 ? 0x742 : 0x542;
        else
            attr = on == 1 ? 0x792 : 0x592;
        if (attr == 0x742 || attr == 0x792)
            osd_draw_cell_run(1, 1, attr, SWITCH_COLUMN, row, 3, SWITCH_GLYPH_ON);
        else
            osd_draw_cell_run(1, 1, attr, SWITCH_COLUMN, row, 3, SWITCH_GLYPH_OFF);
        osd_draw_key_guide(1, 3);
        osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_SWITCH);
    } else {
        osd_draw_key_guide(1, 2);
        osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
    }
}
