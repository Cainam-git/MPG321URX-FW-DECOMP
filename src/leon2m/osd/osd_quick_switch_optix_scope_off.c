/* osd_quick_switch_optix_scope_off  (FUN_a00a50c4)
 *
 * Turn Optix Scope off in its quick menu (left key)
 * Note: Clears settings byte +0x4A and applies it with sys_user_apply_second_picture_enable(0); redraws the
 *   switch.
 * Name basis: derived - handler table 0xA802422C: left on state 0x103 (Navi Key quick menu 'Optix Scope')
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a50c4 @ 0xa00a50c4, flags -mcpu=v8 -O3 -g.
 * Source form: same code as the Refresh Rate switch handlers but on a byte (optix_scope, user_settings +0x4A);
 * the arms test !v first.
 */
extern unsigned char user_settings[];
extern unsigned char osd_request_bits;
extern void sys_user_apply_second_picture_enable(unsigned char);
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned short count, unsigned short value, unsigned char layer);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);

#define SETTING_OPTIX_SCOPE 0x4a   /* byte offset in user_settings */
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

/* Left key in the Optix Scope quick menu: if Optix Scope is 1 (on), set it to 0,
 * apply it with sys_user_apply_second_picture_enable(0) and redraw the switch
 * in its off position. Nothing changes when it is not 1. The settings-changed
 * request is raised in every case. */
void osd_quick_switch_optix_scope_off(void)
{
    unsigned char v, i;
    if (user_settings[SETTING_OPTIX_SCOPE] == 1) {
        user_settings[SETTING_OPTIX_SCOPE] = 0;
        sys_user_apply_second_picture_enable(0);
        v = user_settings[SETTING_OPTIX_SCOPE];
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
