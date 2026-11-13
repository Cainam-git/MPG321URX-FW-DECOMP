/* osd_draw_panel_protect_prompt  (FUN_a00b1700)
 *
 * Draw the OLED panel protect prompt with its text and buttons.
 *   step_code: prompt kind
 *   variant
 * Name basis: derived - texts 0x190184 'Execute|Cancel|Later|More Info'; called by
 *   osd_check_panel_protect_prompt
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b1700 @ 0xa00b1700-0xa00b1ba4 (297 words), flags -mcpu=v8 -O3 -g.
 * Source form: text_row from the comparison value (cmp 3; subx), the width icon_width = 0x37 in a variable
 * (smul by 0x37, cmp 0x37; bcc), the column test with continue, '+ 0x3f' in each arm of the row choice (ldub to
 * %g1 at 0xa00b1a60 and 0xa00b1a68); GCC unswitches the column loop on row > 2.
 */
/* Fields of the settings record used here. */
struct user_settings_record { unsigned char pad[8]; unsigned char language; };

/* Protect step codes (from oled_get_protect_step_code) that have a prompt of their own; each selects one text
 * of osd_panel_protect_prompt_texts (text_row 0, 1, 2). Step code 0 is drawn with text_row 3 or 4. */
#define PROTECT_STEP_1 0x1e
#define PROTECT_STEP_2 0x32
#define PROTECT_STEP_3 0x37

#define ICON_WIDTH            0x37    /* cells per row of osd_protect_icon_cells */
#define ICON_GLYPH_BASE       0x3f    /* glyph = table byte + 0x3f */
#define ICON_GLYPH_SKIP       0x54    /* a cell with this glyph is not written */
#define TEXTS_PER_ITEM        29      /* a text table holds one text per menu language for every item */
#define BUTTON_TEXT_STEP_2    (1 * TEXTS_PER_ITEM)    /* 0x1d: 2nd button text */
#define BUTTON_TEXT_STEP_3    (2 * TEXTS_PER_ITEM)    /* 0x3a */
#define BUTTON_TEXT_STEP_4    (3 * TEXTS_PER_ITEM)    /* 0x57 */
#define LAYER_TEXT_ATTR       0x792   /* third argument of osd_setup_layer_window and the cell runs */

extern struct user_settings_record user_settings;
extern unsigned char osd_dialog_button_index;
extern unsigned char osd_protect_icon_cells[];
extern unsigned int osd_panel_protect_prompt_texts[], osd_protect_button_texts[];
extern void osd_close_menu(void);
extern void osd_set_layout(unsigned int);
extern void osd_setup_layer_window(int, int, int);
extern void osd_api_write_reg_cc(int, int);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_api_set_glyph_write_address(int, int);
extern void osd_api_set_text_mode(int, int);
extern void osd_draw_cell_run(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, unsigned short, unsigned short, int, unsigned int, int);
extern void osd_highlight_dialog_button(unsigned char, unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned short panel_api_get_active_size(int);
extern void osd_api_set_origin_and_size(int, int, int);
extern void osd_api_enable(int, int);

/* Draw the panel protect prompt: a picture of 0x37 cells per row, a text line, and for text_row 3 and 4
 * the button texts.
 *   step_code: 0x1e, 0x32 or 0x37 (the protect step reached; 8 picture rows, text_row 0, 1 or 2) or 0 (the
 *              Panel Protect request; 11 picture rows). Any other value draws no picture and text_row 0.
 *   variant:   used only with step_code 0: 3 or more selects text_row 4, below 3 text_row 3. The value 3 also
 *              calls osd_api_fill_cells at the column of the second button.
 * Order: close the menu and switch to layout 5, set up the layer window and draw the picture from
 * osd_protect_icon_cells (rows from the fourth on are taken from the table three rows further on when the
 * picture has 8 rows, so rows 3..7 of a step prompt are table rows 6..10), draw two cell runs, the prompt
 * text, then (text_row 3 and 4 only) the button texts, and finally set the layer origin to
 * x = (panel width - 1320) / 2, y = panel height - icon_rows * 36 - 144 and switch it on. Called by
 * osd_check_panel_protect_prompt (step_code 0, variant 3 or settings byte +0x1E2) and osd_run_periodic_task
 * (step_code of a new protect step, variant 3). */
void osd_draw_panel_protect_prompt(unsigned char step_code, unsigned char variant)
{
    unsigned char text_row, icon_rows, row, col, glyph, icon_width;

    osd_close_menu();
    osd_set_layout(5);
    text_row = 0;
    icon_rows = 0;
    if (step_code == PROTECT_STEP_1 || step_code == PROTECT_STEP_2 || step_code == PROTECT_STEP_3) {
        icon_rows = 8;
        if (step_code == PROTECT_STEP_1)
            text_row = 0;
        else if (step_code == PROTECT_STEP_2)
            text_row = 1;
        else if (step_code == PROTECT_STEP_3)
            text_row = 2;
    } else if (step_code == 0) {
        text_row = 3 + (variant >= 3);
        icon_rows = 0xb;
    }
    icon_width = ICON_WIDTH;
    osd_setup_layer_window(icon_width, icon_rows, LAYER_TEXT_ATTR);
    osd_api_write_reg_cc(0x91ae, 0);
    for (row = 0; row < icon_rows; row++) {
        for (col = 0; col < icon_width; col++) {
            /* Step prompts (8 rows) skip table rows 3..5 of the picture. */
            if (row > 2 && icon_rows == 8)
                glyph = osd_protect_icon_cells[(row + 3) * icon_width + col] + ICON_GLYPH_BASE;
            else
                glyph = osd_protect_icon_cells[row * icon_width + col] + ICON_GLYPH_BASE;
            if (glyph == ICON_GLYPH_SKIP)
                continue;
            osd_api_fill_cell_bytes(1, col, row, 1, glyph, 0);
        }
    }
    osd_api_set_glyph_write_address(0x60, 0);
    osd_api_set_text_mode(2, 0);
    osd_draw_cell_run(1, 1, LAYER_TEXT_ATTR, 0x14, 1, 0xf, 0x40);
    osd_draw_cell_run(1, 1, LAYER_TEXT_ATTR, 0x14, 2, 0xf, 0x4f);
    osd_draw_text(0, 1, 4, 0x35, osd_get_text(osd_panel_protect_prompt_texts, text_row), 0);
    /* Text rows 3 and 4 have buttons. The text index is the menu language (settings byte +8) plus 0, 1, 2,
     * 3 times TEXTS_PER_ITEM for the 1st to 4th text of osd_protect_button_texts ('Execute', 'Cancel', 'Later', 'More
     * Info'); osd_dialog_button_index 2 draws three buttons, without the 3rd text. */
    if (text_row == 3 || text_row == 4) {
        if (osd_dialog_button_index == 2) {
            osd_highlight_dialog_button(3, 0);
            osd_draw_text(0, 0xb, 8, 8, osd_get_text(osd_protect_button_texts, user_settings.language), 0);
            osd_draw_text(0, 0x18, 8, 8, osd_get_text(osd_protect_button_texts, user_settings.language + BUTTON_TEXT_STEP_2), 0);
            osd_draw_text(0, 0x25, 8, 8, osd_get_text(osd_protect_button_texts, user_settings.language + BUTTON_TEXT_STEP_4), 0);
            if (variant == 3)
                osd_api_fill_cells(0x18, 8, 8, 0x2c2, 0);
        } else {
            osd_highlight_dialog_button(3, 0);
            osd_draw_text(0, 5, 8, 8, osd_get_text(osd_protect_button_texts, user_settings.language), 0);
            osd_draw_text(0, 0x11, 8, 8, osd_get_text(osd_protect_button_texts, user_settings.language + BUTTON_TEXT_STEP_2), 0);
            osd_draw_text(0, 0x1d, 8, 8, osd_get_text(osd_protect_button_texts, user_settings.language + BUTTON_TEXT_STEP_3), 0);
            osd_draw_text(0, 0x29, 8, 8, osd_get_text(osd_protect_button_texts, user_settings.language + BUTTON_TEXT_STEP_4), 0);
            if (variant == 3)
                osd_api_fill_cells(0x11, 8, 8, 0x2c2, 0);
        }
    }
    osd_api_set_origin_and_size((unsigned short)((panel_api_get_active_size(0) - 1320) / 2), (unsigned short)(panel_api_get_active_size(1) - icon_rows * 36 - 144), 0);
    osd_api_enable(1, 0);
}
