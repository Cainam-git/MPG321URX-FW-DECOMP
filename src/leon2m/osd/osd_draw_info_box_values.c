/* osd_draw_info_box_values  (FUN_a00b9750)
 *
 * Draw the Info. On Screen box: input, resolutions, rate, mode, HDR and bit depth.
 *   x: column
 *   y: row
 * Name basis: proven - texts 0x191b30 'Input Source|Native Resolution|...|Bit Depth', 'nHDR'/'nSDR', 'n8
 *   Bit'...; caller osd_draw_info_box
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b9750 @ 0xa00b9750-0xa00b9c68 (1304 bytes), flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the bit 11 test is written with the clear-bit arm first; u is an int
 * set to (unsigned char)(v + 1) in the last arm and narrowed again at its use; the format strings are the
 * symbols s_001981e0 / s_001981d8; the strings are copied with strcpy (GCC stores them as words); the length
 * loops run to 16, not 15.
 */
#define LANGUAGE_COUNT        29        /* text index = entry * 29 + language byte */
#define PANEL_SIZE_WIDTH      0         /* panel_api_get_active_size selector */
#define PANEL_LINES           0x870     /* 2160 */
#define TIMING_WIDTH          7         /* input_api_get_timing_field: width and height of the input */
#define TIMING_HEIGHT         8
#define GAMING_FLAG_PRO_MODE  0x800     /* settings word +0xA8 bit 11: Pro (1) / Game (0) mode */
#define LABEL_COLUMN          4         /* labels and the HDR/SDR text: column x + 4, 14 cells wide */
#define LABEL_WIDTH           0xe
#define VALUE_COLUMN          3         /* the other values: column x + 3, 16 cells wide */
#define VALUE_WIDTH           0x10
#define ROW_STEP              3         /* a label and its value take three rows */
#define PORT_CODE_LINK_FIRST  5         /* port codes 5 and 6: the bit depth comes from the link state */

/* Rows of the box below y. */
#define ROW_INPUT_SOURCE      2
#define ROW_NATIVE            5
#define ROW_PHYSICAL          8
#define ROW_REFRESH_RATE      0xb
#define ROW_SELECT_MODE       0xe
#define ROW_CONTENT_TYPE      0x11
#define ROW_BIT_DEPTH         0x14

/* The user settings fields used here. */
struct user_settings_record {
    unsigned char p000[8];
    unsigned char language;                     /* +0x08 */
    unsigned char p009[0x1e - 9];
    unsigned char input_source;                 /* +0x1E: menu index of the Input Source */
    unsigned char p01f[0xa8 - 0x1f];
    unsigned int gaming_flags;                  /* +0xA8 */
    unsigned char p0ac[0x181 - 0xac];
    unsigned char pro_mode;                     /* +0x181 */
    unsigned char game_mode;                    /* +0x182 */
};
extern struct user_settings_record user_settings;
extern unsigned char app_main_link_state;
extern unsigned int osd_info_box_texts[], osd_input_name_texts[], osd_pro_mode_texts[], osd_game_mode_texts[];
extern unsigned char input_api_get_channel_port_code(unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, unsigned short, unsigned short, int, unsigned char *, int);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern unsigned short panel_api_get_active_size(int);
extern unsigned short input_api_get_timing_field(unsigned char, unsigned int);
extern unsigned short input_user_get_rounded_refresh_rate(void);
extern int sys_user_get_picture_state(void);
extern int input_api_get_channel_port_byte5(int);
extern unsigned char sys_api_get_channel_port_flag11(int);
extern void sprintf(unsigned char *, const char *, ...);
extern char *strcpy(char *, const char *);

/*
 * Draw the texts of the Info. On Screen box with its top-left cell at column x, row y. Called by
 * osd_draw_info_box.
 *
 * First the seven labels (Input Source, Native Resolution, Physical Resolution, Refresh Rate, Select Mode,
 * Content Type, Bit Depth: table osd_info_box_texts) are drawn three rows apart, their cells being cleared
 * first. Then each value goes under its label:
 *   Input Source          name of the stored Input Source (menu index -> source id -> name);
 *   Native Resolution     "<active panel width>X2160";
 *   Physical Resolution   "<input width>X<input height>" (timing fields 7 and 8 of channel 0);
 *   Refresh Rate          "<rounded refresh rate> HZ";
 *   Select Mode           the Pro mode name when settings bit 11 of +0xA8 is set, else the Game Mode name;
 *   Content Type          "HDR" when the picture state is non-zero, else "SDR";
 *   Bit Depth             "6", "8", "10", "12" or "16" Bit, from byte 5 of the port entry of channel 0; when
 *                         flag 7 of that port is set and the port code of channel 0 is 5 or 6, from
 *                         app_main_link_state instead. For any other number the text stays "HDR"/"SDR".
 *
 * Formatted values are built as menu texts: the placeholder 'n' in front is replaced by the length of the
 * characters after it.
 */
void osd_draw_info_box_values(unsigned short x, unsigned short y)
{
    unsigned char text[16];                     /* [0] = length byte, then the characters */
    unsigned char i, port_code, bit_depth, pro_mode;

    port_code = input_api_get_channel_port_code(0);
    for (i = 0; i <= 6; i++) {
        osd_api_fill_cells(x + LABEL_COLUMN, i * ROW_STEP + y + 1, LABEL_WIDTH, 0x596, 0);
        osd_draw_text(0, x + LABEL_COLUMN, i * ROW_STEP + y + 1, LABEL_WIDTH,
                     (unsigned char *)osd_get_text(osd_info_box_texts, i * LANGUAGE_COUNT + user_settings.language), 0);
    }
    osd_draw_text(0, x + LABEL_COLUMN, y + ROW_INPUT_SOURCE, LABEL_WIDTH,
                  (unsigned char *)osd_get_text(osd_input_name_texts, input_api_source_id_to_menu_index(user_settings.input_source)), 0);
    sprintf(text, "n%4dX%4d", panel_api_get_active_size(PANEL_SIZE_WIDTH), PANEL_LINES);
    for (i = 0; i < 16; i++)
        if (text[i] == 0)
            break;
    text[0] = i - 1;
    osd_draw_text(0, x + VALUE_COLUMN, y + ROW_NATIVE, VALUE_WIDTH, text, 0);
    sprintf(text, "n%4dX%4d", input_api_get_timing_field(0, TIMING_WIDTH), input_api_get_timing_field(0, TIMING_HEIGHT));
    for (i = 0; i < 16; i++)
        if (text[i] == 0)
            break;
    text[0] = i - 1;
    osd_draw_text(0, x + VALUE_COLUMN, y + ROW_PHYSICAL, VALUE_WIDTH, text, 0);
    sprintf(text, "n%d HZ", input_user_get_rounded_refresh_rate());
    for (i = 0; i < 16; i++)
        if (text[i] == 0)
            break;
    text[0] = i - 1;
    osd_draw_text(0, x + VALUE_COLUMN, y + ROW_REFRESH_RATE, VALUE_WIDTH, text, 0);
    if (!(user_settings.gaming_flags & GAMING_FLAG_PRO_MODE)) {
        osd_draw_text(0, x + VALUE_COLUMN, y + ROW_SELECT_MODE, VALUE_WIDTH,
                     (unsigned char *)osd_get_text(osd_game_mode_texts, user_settings.game_mode * LANGUAGE_COUNT + user_settings.language), 0);
    } else {
        pro_mode = user_settings.pro_mode;
        {
            int entry;      /* index into osd_pro_mode_texts: Pro mode 7 shows entry 0, 8 and above itself, 0..6 one higher */

            if (pro_mode == 7)
                entry = 0;
            else if (pro_mode > 6)
                entry = pro_mode;
            else
                entry = (unsigned char)(pro_mode + 1);
            osd_draw_text(0, x + VALUE_COLUMN, y + ROW_SELECT_MODE, VALUE_WIDTH, (unsigned char *)osd_get_text(osd_pro_mode_texts, (unsigned char)entry * LANGUAGE_COUNT + user_settings.language), 0);
        }
    }
    if (sys_user_get_picture_state() != 0)
        strcpy((char *)text, "nHDR");
    else
        strcpy((char *)text, "nSDR");
    for (i = 0; i < 16; i++)
        if (text[i] == 0)
            break;
    text[0] = i - 1;
    osd_draw_text(0, x + LABEL_COLUMN, y + ROW_CONTENT_TYPE, LABEL_WIDTH, text, 0);
    bit_depth = input_api_get_channel_port_byte5(0);
    if (sys_api_get_channel_port_flag11(0) && (unsigned char)(port_code - PORT_CODE_LINK_FIRST) <= 1)
        bit_depth = app_main_link_state;
    if (bit_depth == 8)
        strcpy((char *)text, "n8 Bit");
    else if (bit_depth == 10)
        strcpy((char *)text, "n10 Bit");
    else if (bit_depth == 12)
        strcpy((char *)text, "n12 Bit");
    else if (bit_depth == 16)
        strcpy((char *)text, "n16 Bit");
    else if (bit_depth == 6)
        strcpy((char *)text, "n6 Bit");
    for (i = 0; i < 16; i++)
        if (text[i] == 0)
            break;
    text[0] = i - 1;
    osd_draw_text(0, x + VALUE_COLUMN, y + ROW_BIT_DEPTH, VALUE_WIDTH, text, 0);
}
