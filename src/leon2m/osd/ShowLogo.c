/* ShowLogo  (FUN_a008ef48)
 *
 * Draw the MSI power-on logo and switch the panel on.
 * Note: Waits without a time limit until the panel reports on, keeping the 8051 alive signal going.
 * Name basis: proven - prints 'ShowLogo !!' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008ef48 @ 0xA008EF48..0xA008F354 (259 words), flags -mcpu=v8 -O3 -g (-msoft-float gives the same
 * code).
 * Source forms the exact build depends on:
 *  - the glyph upload is a static inline helper load_logo_glyphs(count) called with LOGO_GLYPH_WORDS (the firmware
 *    compares the counter with 0xBE8 by an unsigned test); each arm reads the high byte into its own local first;
 *  - the panel-on call sits in both arms of the sleep-state test, and the sleep state is a 2-bit bit-field of the
 *    halfword (bits 14..13, the same field as sys_run_app_timer_task uses);
 *  - user_settings is a byte array here; the brightness byte is index 9.
 */
extern unsigned char user_settings[];
#define SETTINGS_BRIGHTNESS 9           /* byte +9 of the user settings: Brightness */

/* Application state halfword +4: the sleep state is bits 14..13. */
struct app_state_sleep_word { unsigned short bit_15 : 1; unsigned short sleep_state : 2; unsigned short bits_12_0 : 13; };
extern struct app_state_sleep_word app_state_record_sleep_word;

#define LAYER_0             0           /* the layer osd_show_menu_layer switches on */
#define LAYER_1             1           /* the layer the logo cells are drawn on */
#define PLANE_1             1           /* byte plane 1 (first argument of osd_api_fill_cell_bytes) */
#define ALL_WINDOWS         8           /* osd_api_set_window_enable: all eight windows */
#define RAM_PUT_BYTE_AND_WORD 1         /* osd_api_ram_put_data: send a byte and a word */

#define LOGO_GLYPH_WORDS    0xbe8       /* entries of osd_logo_glyph_words / osd_logo_glyph_high_bytes */
#define LOGO_GLYPH_FLAGGED_LAST 0x673   /* entries 0..0x673 get bit 3 set in the word they send */
#define LOGO_COLUMNS        63          /* cells of the logo map: 63 x 10 */
#define LOGO_ROWS           10
#define LOGO_CLEAR_COLUMNS  26          /* then cells 0..25 of the same ten rows are cleared */

#define PANEL_ON  1                     /* SYSAPI_PanelOnOffControl arguments */
#define WAIT_DONE 1

extern unsigned short osd_logo_layer0_block[], osd_logo_layer0_packed_first[], osd_logo_layer0_packed_second[], osd_logo_layer1_block[], osd_logo_layer1_packed[];
extern const unsigned short osd_logo_glyph_words[];
extern const unsigned char osd_logo_glyph_high_bytes[];
extern const unsigned short osd_logo_cell_map[];
extern int dbg_printf(const char *, ...);
extern void pq_api_set_fill_color(int, int, int, int, int);
extern void pq_api_set_color_triple(int, int, int);
extern void pq_color_matrix_rebuild(int);
extern void sys_user_apply_brightness(void);
extern void osd_close_menu(void);
extern void osd_api_set_cell_size_mode(int, int);
extern void osd_api_write_block(unsigned short *, int);
extern void osd_setup_layer_window(int, int, int);
extern unsigned short osd_api_cell_count_plus_one(int, int);
extern void osd_api_write_reg24_group(int, int, int);
extern void osd_api_write_packed_block(int, unsigned short *, int);
extern void osd_api_set_origin_and_size(int, int, int);
extern void osd_api_ram_seek(int, int, int);
extern void osd_api_ram_put_data(int, unsigned char, unsigned short, int);
extern void osd_api_set_reg_c8_ranges(int, int, int, int, int);
extern void osd_api_enable(int, int);
extern void osd_api_set_window_enable(int, int, int);
extern void osd_api_set_size_in_cells(int, int, int);
extern void osd_api_write_reg_cc(int, int);
extern void osd_api_reset_layer(int);
extern void osd_api_fill_cells(unsigned short, unsigned short, int, int, int);
extern void osd_api_fill_cell_bytes(int, unsigned short, unsigned short, int, unsigned char, int);
extern void SYSAPI_PanelOnOffControl(int, int);
extern void ResetVx1(void);
extern void osd_show_menu_layer(void);

/* Send the logo glyph data to the memory port: per entry the low byte of the glyph word and the high byte
   moved up by 8, with bit 3 added for the entries up to LOGO_GLYPH_FLAGGED_LAST. */
static inline void load_logo_glyphs(unsigned short count)
{
    unsigned short i;

    for (i = 0; i < count; i++) {
        if (i > LOGO_GLYPH_FLAGGED_LAST) {
            unsigned char high = osd_logo_glyph_high_bytes[i];
            osd_api_ram_put_data(RAM_PUT_BYTE_AND_WORD, osd_logo_glyph_words[i], high << 8, 0);
        } else {
            unsigned char high = osd_logo_glyph_high_bytes[i];
            osd_api_ram_put_data(RAM_PUT_BYTE_AND_WORD, osd_logo_glyph_words[i], high << 8 | 8, 0);
        }
    }
}

/*
 * Draw the MSI logo shown at power-on, then switch the panel on and wait until it is on.
 *
 * Called by osd_show_logo_on_power_on and from two places in power_enter_app_state; all three call it only when
 * settings word +0 has bit 12 set and bit 14 (factory mode) clear and the factory marker (settings +0x1F6) is not
 * 0x55AA.
 *
 *  1. Picture: colour-fill call, colour triple 0x100 / 0x100 / 0x100, colour matrix rebuilt; the brightness is
 *     applied as 100 and the stored setting put back unchanged; the on-screen menu is closed.
 *  2. Layer 0: 127 x 24 cells, its blocks and register groups, then the logo glyph data (0xBE8 entries) sent to
 *     the layer memory.
 *  3. Layer 1: 63 x 10 cells, each cell set from osd_logo_cell_map; cells 0..25 of the same rows set to 0 again.
 *  4. Panel on through SYSAPI_PanelOnOffControl with waiting. That call has no time limit: it repeats the panel
 *     power sequencer step, oled_frc_task and ipc_signal_alive until the panel reports on. In sleep state 1 the
 *     V-by-One link is reset afterwards (ResetVx1).
 *  5. Both layers switched on.
 */
void ShowLogo(void)
{
    unsigned char saved_brightness, col, row;
    unsigned short clear_col, clear_row;

    /* 1. Picture set-up. */
    saved_brightness = user_settings[SETTINGS_BRIGHTNESS];
    dbg_printf("ShowLogo !!\r\n");
    pq_api_set_fill_color(0, 0, 0, 0, 1);
    pq_api_set_color_triple(0x100, 0x100, 0x100);
    pq_color_matrix_rebuild(0x80);
    /* Apply full brightness for the logo without changing the stored setting. */
    user_settings[SETTINGS_BRIGHTNESS] = 100;
    sys_user_apply_brightness();
    user_settings[SETTINGS_BRIGHTNESS] = saved_brightness;
    osd_close_menu();

    /* 2. Layer 0 and the glyph data. */
    osd_api_set_cell_size_mode(3, LAYER_0);
    osd_api_write_block(osd_logo_layer0_block, LAYER_0);
    osd_setup_layer_window(0x7f, 0x18, 2);
    osd_api_set_cell_size_mode(3, LAYER_0);
    osd_api_write_reg24_group(0, osd_api_cell_count_plus_one(0x7f, 0x18), LAYER_0);
    osd_api_write_reg24_group(1, osd_api_cell_count_plus_one(0x7f, 0x18) + 0x8f0, LAYER_0);
    osd_api_write_packed_block(1, osd_logo_layer0_packed_first, LAYER_0);
    osd_api_write_packed_block(1, osd_logo_layer0_packed_second, LAYER_0);
    osd_api_set_origin_and_size(0x10f, 0xcf, LAYER_0);
    osd_api_ram_seek(1, 0, LAYER_0);
    load_logo_glyphs(LOGO_GLYPH_WORDS);
    osd_api_set_reg_c8_ranges(0x1f, 0x56, 6, 0x4a, LAYER_0);

    /* 3. Layer 1 and the logo cells. */
    osd_api_set_cell_size_mode(3, LAYER_1);
    osd_api_write_block(osd_logo_layer1_block, LAYER_1);
    osd_api_enable(0, LAYER_1);
    osd_api_set_window_enable(ALL_WINDOWS, 0, LAYER_1);
    osd_api_set_size_in_cells(LOGO_COLUMNS, LOGO_ROWS, LAYER_1);
    osd_api_write_reg_cc(2, LAYER_1);
    osd_api_reset_layer(LAYER_1);
    osd_api_set_origin_and_size(0x136, 0x6e5, LAYER_1);
    osd_api_set_cell_size_mode(3, LAYER_1);
    osd_api_write_reg24_group(0, osd_api_cell_count_plus_one(LOGO_COLUMNS, LOGO_ROWS), LAYER_1);
    osd_api_write_packed_block(1, osd_logo_layer1_packed, LAYER_1);
    for (row = 0; row <= LOGO_ROWS - 1; row++)
        for (col = 0; col <= LOGO_COLUMNS - 1; col++) {
            osd_api_fill_cells(col, row, 1, 0, LAYER_1);
            osd_api_fill_cell_bytes(PLANE_1, col, row, 1, osd_logo_cell_map[row * LOGO_COLUMNS + col], LAYER_1);
        }
    osd_api_write_reg_cc(2, LAYER_1);
    for (clear_row = 0; clear_row <= LOGO_ROWS - 1; clear_row++)
        for (clear_col = 0; clear_col <= LOGO_CLEAR_COLUMNS - 1; clear_col++) {
            osd_api_fill_cells(clear_col, clear_row, 1, 0, LAYER_1);
            osd_api_fill_cell_bytes(PLANE_1, clear_col, clear_row, 1, 0, LAYER_1);
        }
    osd_api_set_reg_c8_ranges(0x1b, 0x138, 0, 0, LAYER_1);

    /* 4. Panel on; waits until the panel power sequencer is done. */
    if (app_state_record_sleep_word.sleep_state == 1) {
        SYSAPI_PanelOnOffControl(PANEL_ON, WAIT_DONE);
        ResetVx1();
    } else
        SYSAPI_PanelOnOffControl(PANEL_ON, WAIT_DONE);

    /* 5. */
    osd_api_enable(1, LAYER_1);
    osd_show_menu_layer();
}
