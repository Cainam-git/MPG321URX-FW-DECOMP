/* osd_draw_signal_info_header  (FUN_a00b3860)
 *
 * Draw the menu header: input, resolution, refresh rate, firmware and model.
 * Name basis: proven - formats 'n%4dX%4d', 'n%d HZ', firmware 'FW.021' text; input names 0x196B24
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b3860 @ 0xa00b3860-0xa00b3ac8 (616 bytes), flags -mcpu=v8 -O3 -g. Callers: osd_redraw_settings_page,
 * osd_draw_main_menu_frame.
 * Source form: the results of input_api_get_timing_field are passed as (unsigned short) casts of int returns
 * directly in the sprintf call (16-bit extension right after each call).
 */
/* Fields of the settings record used here. */
struct user_settings_record { unsigned char pad[0x1e]; unsigned char input_source; };   /* +0x1E */
extern struct user_settings_record user_settings;
extern unsigned int osd_input_name_texts[];
extern const unsigned char osd_firmware_version_text[], osd_model_name_text[];   /* length-prefixed "\x06FW.021" and "\x10MPG 321U QD-OLED" */
extern void osd_draw_mode_status_header(void);
extern void osd_draw_adaptive_sync_status(void);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern int input_api_get_timing_field(unsigned int, unsigned int);
extern int input_user_get_rounded_refresh_rate(void);
extern void sprintf(unsigned char *, const char *, ...);

/* Draw the header lines of the menu: the HDR / mode status and the Adaptive-Sync status (two routines), then
 * the name of the selected input (settings byte +0x1E, through the menu-index-to-source table), the
 * resolution as "n%4dX%4d" from timing fields 7 and 8 of channel 0, the refresh rate as "n%d HZ"
 * (rounded, input_user_get_rounded_refresh_rate), the firmware version text and the model name. Each text is
 * drawn by clearing its cells with osd_api_fill_cells (x, row, width, attribute) and then osd_draw_text with
 * the same x, row and width; the layer is not enabled here. The two formatted texts are made length-prefixed:
 * the first byte, which holds the placeholder 'n', is replaced by the index of the first zero byte minus 1
 * (15 when none is found in the 16 bytes). Called by osd_redraw_settings_page and osd_draw_main_menu_frame. */
void osd_draw_signal_info_header(void)
{
    unsigned char resolution_text[16];
    unsigned char refresh_text[16];
    unsigned char n;

    osd_draw_mode_status_header();
    osd_draw_adaptive_sync_status();
    osd_api_set_text_mode(2, 0);
    osd_api_set_glyph_write_address(0x1a6, 0);
    osd_api_fill_cells(0x36, 1, 5, 0x596, 0);
    osd_draw_text(0, 0x36, 1, 5, osd_get_text(osd_input_name_texts, input_api_source_id_to_menu_index(user_settings.input_source)), 0);
    sprintf(resolution_text, "n%4dX%4d", (unsigned short)input_api_get_timing_field(0, 7), (unsigned short)input_api_get_timing_field(0, 8));
    for (n = 0; n < 16; n++)
        if (resolution_text[n] == 0)
            break;
    resolution_text[0] = n - 1;
    osd_api_fill_cells(0xe, 1, 8, 0x596, 0);
    osd_draw_text(0, 0xe, 1, 8, (unsigned int)resolution_text, 0);
    sprintf(refresh_text, "n%d HZ", (unsigned short)input_user_get_rounded_refresh_rate());
    for (n = 0; n < 16; n++)
        if (refresh_text[n] == 0)
            break;
    refresh_text[0] = n - 1;
    osd_api_set_text_mode(2, 0);
    osd_api_set_glyph_write_address(0x1b5, 0);
    osd_api_fill_cells(0xe, 2, 8, 0x596, 0);
    osd_draw_text(0, 0xe, 2, 8, (unsigned int)refresh_text, 0);
    osd_api_set_glyph_write_address(0x1bc, 0);
    osd_api_set_text_mode(2, 0);
    osd_api_fill_cells(0x37, 0x15, 4, 0xa96, 0);
    osd_draw_text(0, 0x37, 0x15, 4, (unsigned int)osd_firmware_version_text, 0);
    osd_api_fill_cells(1, 4, 0xb, 0x996, 0);
    osd_draw_text(0, 1, 4, 0xb, (unsigned int)osd_model_name_text, 0);
}
