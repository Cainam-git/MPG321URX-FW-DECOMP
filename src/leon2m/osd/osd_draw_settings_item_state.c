/* osd_draw_settings_item_state  (FUN_a00aa33c)
 *
 * Draw the switch state of a Settings item (rows 5..8) and set the key guide.
 *   item: item row
 *   mode: highlight style
 * Note: Rows Info. On Screen, HDMI CEC, Type C PD Charge, Power LED.
 * Name basis: derived - called by the Settings item handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00aa33c @ 0xa00aa33c, flags -mcpu=v8 -O3 -g.
 * Source form: the osd_draw_cell_run call is written once per glyph value in an if/else on the attribute test
 * (the two calls are merged by cross-jumping into one call after a branch that selects the glyph).
 */
extern unsigned int user_settings_settings_page_flags;
extern unsigned int user_settings_boundary_detection;
extern unsigned int user_settings_word_0x1f4;
extern void osd_draw_cell_run(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_update_key_guide(unsigned int, unsigned int);

#define SETTINGS_ITEM_INFO_ON_SCREEN  5   /* switch: bit 22 of settings word +0xAC */
#define SETTINGS_ITEM_HDMI_CEC        6   /* switch: bit 20 of settings word +0xAC */
#define SETTINGS_ITEM_TYPE_C_PD       7   /* switch: bit 7 of the word at +0x1EC */
#define SETTINGS_ITEM_POWER_LED       8   /* switch: bit 30 of the word at +0x1F4 */
#define SWITCH_COLUMN                 0x22
#define SWITCH_GLYPH_ON               0x37
#define SWITCH_GLYPH_OFF              0x34
#define HIGHLIGHT_ITEM_ACTIVE         1
#define KEY_TEXT_MOVE                 0
#define KEY_TEXT_ENTER                1
#define KEY_TEXT_SWITCH               2

/*
 * Draw the on/off switch of a Settings item and set the key guide for it.
 *
 *   item  Settings item row (7 rows per page, so items 5..8 are on the first and second page)
 *   mode  1: the item is the active (highlighted) row; anything else: not
 *
 * The four items with a switch are Info. On Screen (5), HDMI CEC (6), Type C PD Charge (7) and Power LED (8).
 * Their switch is three cells at column 0x22 of the item's middle row (row = (item % 7) * 2 + 6), glyphs 0x37..
 * when on, 0x34.. when off; the attribute is 0x742 (active row) or 0x792 when on and 0x200 less when off. The
 * key guide then shows icon set 3 with 'Move' / 'Switch'. Every other item only gets icon set 2 with 'Move' /
 * 'Enter'.
 *
 * Called by the Settings item handlers after they move or toggle.
 */
void osd_draw_settings_item_state(unsigned char item, unsigned char mode)
{
    unsigned char row;
    unsigned char on = 0xff;
    unsigned short attr;

    row = (item % 7) * 2 + 6;
    if (item == SETTINGS_ITEM_INFO_ON_SCREEN) {
        on = 1;
        if (!(user_settings_settings_page_flags & 0x400000))
            on = 0;
    } else if (item == SETTINGS_ITEM_HDMI_CEC) {
        on = 1;
        if (!(user_settings_settings_page_flags & 0x100000))
            on = 0;
    } else if (item == SETTINGS_ITEM_TYPE_C_PD) {
        on = 1;
        if (!(user_settings_boundary_detection & 0x80))
            on = 0;
    } else if (item == SETTINGS_ITEM_POWER_LED) {
        on = (user_settings_word_0x1f4 >> 30) & 1;
    }
    if (item >= SETTINGS_ITEM_INFO_ON_SCREEN && item <= SETTINGS_ITEM_POWER_LED) {
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
