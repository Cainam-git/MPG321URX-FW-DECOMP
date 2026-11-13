/* osd_draw_signal_message  (FUN_a00b7f9c)
 *
 * Draw one signal message window (no signal, out of range, input banner, HDR icon)
 *   page: message kind 0x11..0x1e
 * Note: Page 0x11 small icon layout, 0x17/0x18 'Out Of Range!', 0x19 input + 'No Signal', 0x1b 'No Signal',
 *   0x1e input banner.
 * Name basis: proven - texts 0x192d8c 'Out Of Range!', 0x193008 'No Signal', 0x196b24 input names
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b7f9c @ 0xa00b7f9c-0xa00b83e4 (1096 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the start is written out in full (the steps of osd_hide_menu and osd_setup_layer_window, not calls);
 *  - in case SIGNAL_MESSAGE_NO_SIGNAL each arm has its own complete calls (the firmware keeps three copies of
 *    the row-1 call; a shared call or a ?: argument gives another argument order).
 */
/* The application state fields used here. */
struct app_state_record {
    unsigned char p00;
    unsigned char byte_0x1;                     /* +0x01: with PIP/PBP on, non-zero selects the second source's name */
    unsigned char p02[0x3e - 2];
    struct { unsigned short bit15 : 1, rest : 15; } flags_0x3e; /* +0x3E: bit 15 cleared when the menu is hidden */
};
/* The user settings fields read here. */
struct user_settings_record {
    unsigned char p000[8];
    unsigned char language;                     /* +0x08: menu language */
    unsigned char p009[0x0d - 0x09];
    unsigned char byte_0x0d, byte_0x0e;         /* +0x0D, +0x0E: the arguments of osd_api_set_position */
    unsigned char p00f[0x1e - 0x0f];
    unsigned char input_source;                 /* +0x1E: selected Input Source */
    unsigned char pip_pbp_mode;                 /* +0x1F: PIP/PBP mode (0 off, 1 PIP, 2 PBP) */
    unsigned char second_source;                /* +0x20: source of the second picture */
    unsigned char p021[0xac - 0x21];
    unsigned int settings_page_flags;           /* +0xAC: bit 20 HDMI CEC */
};
extern struct app_state_record app_state_record;
extern struct user_settings_record user_settings;
extern unsigned char osd_list_id;
extern unsigned int osd_out_of_range_texts[], osd_no_signal_texts[], osd_input_name_texts[], osd_cec_console_texts[];

extern void osd_api_enable(int, int);
extern void osd_api_set_window_enable(int, int, int);
extern void panel_wait_sync_pulse(void);
extern void osd_set_layout(unsigned int);
extern void osd_api_set_reg_c8_ranges(int, int, int, int, int);
extern void osd_api_set_size_in_cells(int, int, int);
extern void osd_api_set_position(unsigned short, unsigned short, unsigned char);
extern void osd_api_write_reg_cc(int, int);
extern void osd_api_reset_layer(int);
extern void osd_draw_message_frame(int, int);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_origin_and_size(int, int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern unsigned char input_api_get_channel_port_code(int);
extern unsigned char APPCECGetSourceType(void);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

/* Message kinds (the `page` argument), named by their callers and the texts drawn. The kind is also stored in
   osd_list_id. */
#define SIGNAL_MESSAGE_HDR_ICON         0x11    /* osd_draw_hdr_icon, osd_draw_input_info_banner: 8 x 3 glyph block */
#define SIGNAL_MESSAGE_EMPTY            0x15    /* osd_clear_signal_message, osd_draw_input_info_banner: frame only */
#define SIGNAL_MESSAGE_OUT_OF_RANGE_17  0x17    /* 'Out Of Range!' */
#define SIGNAL_MESSAGE_OUT_OF_RANGE     0x18    /* osd_draw_out_of_range_message: 'Out Of Range!' */
#define SIGNAL_MESSAGE_NO_SIGNAL        0x19    /* osd_draw_no_signal_with_input: input name and 'No Signal' */
#define SIGNAL_MESSAGE_NO_SIGNAL_ONLY   0x1b    /* osd_draw_no_signal_message: 'No Signal' */
#define SIGNAL_MESSAGE_INPUT_BANNER     0x1e    /* osd_draw_input_info_banner: input name, with CEC the console */

#define MENU_LAYER_MAIN         0       /* the layer osd_show_menu_layer switches on */
#define ALL_WINDOWS             8       /* window number that means all eight windows */
#define CELL_BLANK              0x792   /* cell value of an empty menu cell (the layer background) */
#define SETTINGS_HDMI_CEC_ON    0x100000    /* settings_page_flags bit 20: the HDMI CEC menu switch */
#define CEC_SOURCE_NONE         0xff    /* APPCECGetSourceType: no console recognised */
#define MAIN_CHANNEL            0       /* channel 0: the main picture */

/* Text rows of the message window (column 1, 0xC cells wide). */
#define TEXT_FIRST_ROW          1
#define TEXT_MIDDLE_ROW         2
#define TEXT_LAST_ROW           3

/*
 * Draw one signal message window on menu layer 0 and switch the layer on.
 *
 *   page  SIGNAL_MESSAGE_HDR_ICON .. SIGNAL_MESSAGE_INPUT_BANNER; kinds 0x12..0x14, 0x16, 0x1A, 0x1C and 0x1D
 *         get the empty window
 *
 * Phases:
 *   1. Hide the menu (as osd_hide_menu) and wait for a sync pulse.
 *   2. Set up layer 0 (as osd_setup_layer_window): SIGNAL_MESSAGE_HDR_ICON uses layout 4 and 8 x 3 cells,
 *      every other kind layout 3, 0xE x 5 cells and a message frame (osd_draw_message_frame). Then the layer is
 *      placed with (0x63, 0x62) or (0x32, 0x32), glyph write address 100, text mode 2 and the blank cell value
 *      are set, and the kind is stored in osd_list_id.
 *   3. The content of the kind:
 *        HDR icon:       glyphs 0..23 in rows 0..2, eight per row (cell value 0x970A), then layer origin and
 *                        size 0xE10, 0x48;
 *        empty:          only a second placing of the layer;
 *        out of range:   'Out Of Range!' in the middle row;
 *        no signal with input: the input name in the first row ('No Signal' in the last row); with PIP/PBP on
 *                        and application state byte +1 non-zero, the name of the second source;
 *        no signal:      'No Signal' in the middle row;
 *        input banner:   the input name of entry input_api_source_id_to_menu_index(port code of the main
 *                        picture). With HDMI CEC on, PIP/PBP off, that entry 0 and a console recognised over
 *                        CEC, the name goes to the first row and text n of osd_cec_console_texts (n = the
 *                        APPCECGetSourceType result) to the last row; else the name alone in the middle row.
 *   4. Switch the layer on.
 */
void osd_draw_signal_message(unsigned char page)
{
    int position_a, position_b;         /* the two arguments of osd_api_set_position */
    unsigned char row, column;

    /* Phase 1: hide the menu. */
    osd_api_enable(0, MENU_LAYER_MAIN);
    osd_api_set_window_enable(ALL_WINDOWS, 0, 0);
    osd_list_id = 0x24;
    osd_api_enable(0, 1);
    app_state_record.flags_0x3e.bit15 = 0;
    panel_wait_sync_pulse();

    /* Phase 2: the layer for this kind. */
    if (page == SIGNAL_MESSAGE_HDR_ICON) {
        osd_set_layout(4);
        osd_api_enable(0, MENU_LAYER_MAIN);
        osd_api_set_window_enable(ALL_WINDOWS, 0, 0);
        osd_api_set_reg_c8_ranges(0, 0, 0, 0, 0);
        osd_api_set_size_in_cells(8, 3, 0);
        osd_api_set_position(user_settings.byte_0x0d, user_settings.byte_0x0e, 0);
        osd_api_write_reg_cc(CELL_BLANK, 0);
        osd_api_reset_layer(0);
        position_a = 0x63;
        position_b = 0x62;
    } else {
        osd_set_layout(3);
        osd_api_enable(0, MENU_LAYER_MAIN);
        osd_api_set_window_enable(ALL_WINDOWS, 0, 0);
        osd_api_set_reg_c8_ranges(0, 0, 0, 0, 0);
        osd_api_set_size_in_cells(0xe, 5, 0);
        osd_api_set_position(user_settings.byte_0x0d, user_settings.byte_0x0e, 0);
        osd_api_write_reg_cc(CELL_BLANK, 0);
        osd_api_reset_layer(0);
        osd_draw_message_frame(0, 0);
        position_a = 0x32;
        position_b = 0x32;
    }
    osd_api_set_position(position_a, position_b, 0);
    osd_api_set_glyph_write_address(100, 0);
    osd_api_set_text_mode(2, 0);
    osd_api_write_reg_cc(CELL_BLANK, 0);
    osd_list_id = page;

    /* Phase 3: the content. */
    switch (page) {
    case SIGNAL_MESSAGE_HDR_ICON:
        osd_api_write_reg_cc(0x970a, 0);
        for (row = 0; row <= 2; row++)
            for (column = 0; column <= 7; column++)
                osd_api_fill_cell_bytes(1, column, row, 1, row * 8 + column, 0);
        osd_api_set_origin_and_size(0xe10, 0x48, 0);
        break;
    case SIGNAL_MESSAGE_EMPTY:
        osd_api_set_position(0x32, 0x32, 0);
        break;
    case SIGNAL_MESSAGE_OUT_OF_RANGE_17:
    case SIGNAL_MESSAGE_OUT_OF_RANGE:
        osd_draw_text(1, 1, TEXT_MIDDLE_ROW, 0xc, osd_get_text(osd_out_of_range_texts, user_settings.language), 0);
        break;
    case SIGNAL_MESSAGE_NO_SIGNAL:
        if (user_settings.pip_pbp_mode == 0) {
            osd_draw_text(1, 1, TEXT_FIRST_ROW, 0xc, osd_get_text(osd_input_name_texts, input_api_source_id_to_menu_index(user_settings.input_source)), 0);
            osd_draw_text(1, 1, TEXT_LAST_ROW, 0xc, osd_get_text(osd_no_signal_texts, user_settings.language), 0);
        } else {
            /* PIP/PBP on: application state byte +1 chooses which of the two sources is named. */
            if (app_state_record.byte_0x1 == 0)
                osd_draw_text(1, 1, TEXT_FIRST_ROW, 0xc, osd_get_text(osd_input_name_texts, input_api_source_id_to_menu_index(user_settings.input_source)), 0);
            else
                osd_draw_text(1, 1, TEXT_FIRST_ROW, 0xc, osd_get_text(osd_input_name_texts, input_api_source_id_to_menu_index(user_settings.second_source)), 0);
            osd_draw_text(1, 1, TEXT_LAST_ROW, 0xc, osd_get_text(osd_no_signal_texts, user_settings.language), 0);
        }
        break;
    case SIGNAL_MESSAGE_NO_SIGNAL_ONLY:
        osd_draw_text(1, 1, TEXT_MIDDLE_ROW, 0xc, osd_get_text(osd_no_signal_texts, user_settings.language), 0);
        break;
    case SIGNAL_MESSAGE_INPUT_BANNER:
        if ((user_settings.settings_page_flags & SETTINGS_HDMI_CEC_ON) && user_settings.pip_pbp_mode == 0 && input_api_source_id_to_menu_index(input_api_get_channel_port_code(MAIN_CHANNEL)) == 0 && APPCECGetSourceType() != CEC_SOURCE_NONE) {
            /* Input name and the console recognised over CEC. */
            osd_draw_text(1, 1, TEXT_FIRST_ROW, 0xc, osd_get_text(osd_input_name_texts, input_api_source_id_to_menu_index(input_api_get_channel_port_code(MAIN_CHANNEL))), 0);
            osd_draw_text(1, 1, TEXT_LAST_ROW, 0xc, osd_get_text(osd_cec_console_texts, APPCECGetSourceType()), 0);
        } else {
            osd_draw_text(1, 1, TEXT_MIDDLE_ROW, 0xc, osd_get_text(osd_input_name_texts, input_api_source_id_to_menu_index(input_api_get_channel_port_code(MAIN_CHANNEL))), 0);
        }
        break;
    }

    /* Phase 4. */
    osd_api_enable(1, MENU_LAYER_MAIN);
}
