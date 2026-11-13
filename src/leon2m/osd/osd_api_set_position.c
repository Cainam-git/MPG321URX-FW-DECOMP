/* osd_api_set_position  (FUN_a0146518)
 *
 * Place a menu layer on the screen for the active panel size.
 * Name basis: derived - forwards to osd_set_position; passes the two size fields of the active panel timing
 *   row
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146518, flags -mcpu=v8 -O3 -g -msoft-float.
 * Tail call osd_set_position(a, b, active row +0x08, active row +0x0A, layer); the active panel timing row at
 * 0xA802E378 is 0x58 bytes, +0x08 and +0x0A are 16-bit fields.
 */
struct RawRow { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short width, lines; };
extern struct RawRow panel_active_row;
extern void osd_set_position(unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);

/* Place a menu layer on the screen for the active panel mode: calls osd_set_position with the two position
 * percentages and the two size fields (+0x08 and +0x0A) of the active panel timing row.
 *   percent_a, percent_b: position values, passed on unchanged
 *   layer:                menu layer number
 * Callers pass user_settings.menu_position_a / _b or fixed pairs such as 1 / 0x62 (osd_setup_window_full, osd_draw_factory_info_page).
 */
void osd_api_set_position(unsigned short percent_a, unsigned short percent_b, unsigned char layer)
{
    osd_set_position(percent_a, percent_b, panel_active_row.width, panel_active_row.lines, layer);
}
