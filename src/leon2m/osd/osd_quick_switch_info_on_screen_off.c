/* osd_quick_switch_info_on_screen_off  (FUN_a00a4e08)
 *
 * Turn Info. On Screen off in its quick menu (left key)
 * Note: Clears bit 22 of settings word +0xAC and redraws the switch.
 * Name basis: derived - handler table 0xA802422C: left on state 0x101 (Navi Key quick menu 'Info. On Screen')
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a4e08 @ 0xa00a4e08, flags -mcpu=v8 -O3 -g.
 * Source form: the settings word is a union of a plain word (tested with the mask 0x400000) and a bit-field view
 * (written and read back as a 1-bit field); the arms test !v first. The record is declared with only the
 * fields this routine uses.
 */
struct user_settings_record {
    unsigned char pad0[0xac];
    union {
        unsigned int word;
        struct {
            unsigned int high_9_bits : 9;
            unsigned int info_on_screen : 1;
            unsigned int low_22_bits : 22;
        } bits;
    } settings_page_flags;
};
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned short count, unsigned short value, unsigned char layer);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);

#define MENU_LAYER_MAIN     0
#define PLANE_0             0
#define SWITCH_ROW          8
#define SWITCH_GLYPH_COLUMN 9      /* four glyph cells, columns 9..12 */
#define SWITCH_GLYPHS_ON    0x1e
#define SWITCH_GLYPHS_OFF   0x22
#define SWITCH_LEFT_COLUMN  3
#define SWITCH_RIGHT_COLUMN 0xe
#define CELL_BLANK          0x792
#define CELL_SWITCH_HALF    0x992
#define OSD_REQUEST_SETTINGS_CHANGED 0x02

/* Left key in the Info. On Screen quick menu: if Info. On Screen (bit 22 of the settings page flags
 * word, +0xAC) is on, switch it off and redraw the switch in its off position.
 * Nothing changes when the bit already has the wanted value. The settings-changed
 * request is raised in every case. */
void osd_quick_switch_info_on_screen_off(void)
{
    unsigned char v, i;
    if (user_settings.settings_page_flags.word & 0x400000) {
        user_settings.settings_page_flags.bits.info_on_screen = 0;
        v = user_settings.settings_page_flags.bits.info_on_screen;
        osd_api_fill_cells(5, SWITCH_ROW, 4, CELL_BLANK, MENU_LAYER_MAIN);
        for (i = 0; i <= 3; i++) {
            if (!v)
                osd_api_fill_cell_bytes(PLANE_0, i + SWITCH_GLYPH_COLUMN, SWITCH_ROW, 1, i + SWITCH_GLYPHS_OFF, MENU_LAYER_MAIN);
            else
                osd_api_fill_cell_bytes(PLANE_0, i + SWITCH_GLYPH_COLUMN, SWITCH_ROW, 1, i + SWITCH_GLYPHS_ON, MENU_LAYER_MAIN);
        }
        if (!v) {
            osd_api_fill_cells(SWITCH_LEFT_COLUMN, SWITCH_ROW, 5, CELL_BLANK, MENU_LAYER_MAIN);
            osd_api_fill_cells(SWITCH_RIGHT_COLUMN, SWITCH_ROW, 5, CELL_SWITCH_HALF, MENU_LAYER_MAIN);
        } else {
            osd_api_fill_cells(SWITCH_LEFT_COLUMN, SWITCH_ROW, 5, CELL_SWITCH_HALF, MENU_LAYER_MAIN);
            osd_api_fill_cells(SWITCH_RIGHT_COLUMN, SWITCH_ROW, 5, CELL_BLANK, MENU_LAYER_MAIN);
        }
    }
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
