/* osd_draw_panel_protect_dialog  (FUN_a00b1ba4)
 *
 * Draw the panel protect dialog page with its explanation rows and buttons.
 *   long_time: page
 *   mode: variant
 * Name basis: derived - texts 0x190184; called by osd_open_panel_protect_dialog and
 *   osd_accept_panel_protect_prompt
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b1ba4 @ 0xa00b1ba4-0xa00b27fc (790 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - row_count is set in each arm of the long_time test by a full mode if-chain;
 *  - the text loop reuses `column`, the variable that held the button column before the loop;
 *  - flags_0xe is read as a plain halfword (>> 15), flags_0x18 is written as a 1-bit field;
 *  - the bytes +0x1E4..+0x1E7 are a union with the word, which is tested as one word.
 */
/* The application state fields used here. */
struct app_state_record {
    unsigned char p00[0x0e];
    unsigned short flags_0xe;                   /* +0x0E: bit 15 = button highlighted first: 1 Execute, 0 Cancel */
    unsigned short half_0x10, half_0x12;        /* +0x10 / +0x12: compared with settings +0x1E2 / +0x1E3 */
    unsigned char p14[0x18 - 0x14];
    struct { unsigned short bit15 : 1, rest : 15; } flags_0x18; /* +0x18: bit 15 set here while the Later button is shown */
};
/* The user settings fields read here. Bytes +0x1E2, +0x1E4 and +0x1E6 are read for the Panel Protect page,
   +0x1E3, +0x1E5 and +0x1E7 for the Long Time page. */
struct user_settings_record {
    unsigned char p000[8];
    unsigned char language;                     /* +0x08: menu language */
    unsigned char p009[0x1e2 - 0x09];
    unsigned char byte_0x1e2, byte_0x1e3;       /* +0x1E2, +0x1E3 */
    union {
        unsigned int word;                      /* the four bytes below as one word */
        unsigned char byte[4];                  /* +0x1E4, +0x1E5, +0x1E6, +0x1E7 */
    } word_0x1e4;
    unsigned char p1e8[6];
    unsigned char protect_notice;               /* +0x1EE: Protect Notice */
};
extern struct app_state_record app_state_record;
extern struct user_settings_record user_settings;
extern unsigned char osd_edit_value;
extern unsigned int osd_protect_button_texts[], osd_protect_incomplete_texts[], osd_protect_execute_texts[], osd_protect_retry_texts[], osd_protect_auto_texts[],
    osd_protect_title_texts[], osd_protect_long_incomplete_texts[], osd_protect_long_execute_texts[], osd_protect_long_retry_texts[], osd_protect_long_auto_texts[], osd_protect_long_title_texts[];

extern void panel_wait_sync_pulse(void);
extern void osd_set_layout(unsigned int);
extern void osd_setup_layer_window(int, int, int);
extern void osd_draw_cell_run(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char,
                         unsigned char);
extern void osd_highlight_dialog_button(unsigned char, unsigned char);
extern void osd_api_set_glyph_write_address(int, int);
extern void osd_api_set_text_mode(int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_api_set_position(unsigned short, unsigned short, unsigned char);
extern void osd_api_enable(int, int);

/* The `mode` argument: which body text the page gets. */
#define DIALOG_MODE_AUTO        3       /* "panel protect function will automatically activate" */
#define DIALOG_MODE_EXECUTE     4       /* "press 'Execute' ...", or "did not complete" */

/* osd_highlight_dialog_button kinds used here. */
#define DIALOG_TWO_BUTTONS      1       /* Execute, Cancel */
#define DIALOG_THREE_BUTTONS    2       /* Execute, Cancel, Later */

#define TEXTS_PER_ITEM          29      /* a text table holds one text per menu language for every item */
#define BUTTON_ROW              0x17    /* cell row of the button texts */
#define BUTTON_WIDTH            8       /* cells per button text */
#define BUTTON_SPACING          0xc     /* columns from one button text to the next */
#define LATER_BUTTON_COLUMN     0x24
#define CELL_BLANK              0x792   /* cell value of an empty menu cell (the layer background) */
#define MENU_LAYER_MAIN         0       /* the layer osd_show_menu_layer switches on */

/*
 * Draw the Panel Protect dialog: a full menu layer with a frame, up to 13 rows of explanation and the buttons.
 *
 *   long_time  0: the 'MSI OLED Care - Panel Protect' texts; else the 'Panel Protect (Long Time)' texts
 *   mode       DIALOG_MODE_AUTO, DIALOG_MODE_EXECUTE, or 0..2: the title page, or the "did not complete"
 *              page (see the table choice in phase 4)
 *
 * Callers: osd_open_panel_protect_dialog (long_time = osd_choice_row, mode 4), osd_check_panel_protect_prompt
 * (mode 4, or settings byte +0x1E2 - 1) and osd_accept_panel_protect_prompt (mode 3, or byte +0x1E2).
 *
 * Phases:
 *   1. Set up the menu layer (layout 3, 0x37 x 0x1A cells) and draw the frame from fixed glyph runs.
 *   2. Buttons, only while settings bytes +0x1E4 and +0x1E5 are both 0: three buttons (Execute, Cancel,
 *      Later) when mode is neither 3 nor 4 and Protect Notice is 0, else two (Execute, Cancel). The button
 *      highlighted first comes from bit 15 of app_state_record +0x0E; bit 15 of +0x18 records whether Later is
 *      shown.
 *   3. Two runs of 15 rising glyphs at column 0x14, rows 1 and 2.
 *   4. The body: 9 or 13 rows from one text table, chosen by long_time, mode and the settings bytes
 *      +0x1E2..+0x1E7 (see the table choice in the loop). Rows 0 and 1 use text mode 2, the others text mode 0;
 *      rows 3, 4, 5, 7, 9 and 11 get the mark cell at column 4.
 *   5. Place the layer, copy the first-highlighted button into osd_edit_value and switch the layer on.
 */
void osd_draw_panel_protect_dialog(unsigned char long_time, unsigned char mode)
{
    unsigned char column, row_count, row, cell_row, width;

    /* Phase 1: layer and frame. */
    panel_wait_sync_pulse();
    osd_set_layout(3);
    osd_setup_layer_window(0x37, 0x1a, CELL_BLANK);
    osd_draw_cell_run(1, 1, 0x8a2, 0, 0, 1, 1);
    osd_draw_cell_run(1, 1, 0x8a2, 0x36, 0x19, 1, 4);
    osd_draw_cell_run(1, 0, 0x8a2, 1, 0, 7, 5);
    osd_draw_cell_run(1, 0, 0x8a2, 5, 0x19, 0x31, 6);
    osd_draw_cell_run(0, 0, 0x8a2, 0, 1, 0x17, 7);
    osd_draw_cell_run(0, 0, 0x8a2, 0x36, 3, 0x16, 8);
    osd_draw_cell_run(1, 1, 0x12aa, 6, 0, 1, 0x72);
    osd_draw_cell_run(1, 1, 0xa89a, 0x2f, 1, 1, 0x73);
    osd_draw_cell_run(1, 1, 0xa89a, 1, 0x17, 1, 0x74);
    osd_draw_cell_run(1, 1, 0x592, 3, 1, 2, 0x26);
    osd_draw_cell_run(1, 1, 0x592, 6, 0x18, 1, 0x2a);
    osd_draw_cell_run(1, 1, 0x592, 0x33, 0x18, 1, 0x2b);
    osd_draw_cell_run(1, 1, 0x592, 0x34, 0x17, 2, 0x2c);
    osd_draw_cell_run(1, 1, 0x592, 0x34, 0x18, 2, 0x2e);
    osd_draw_cell_run(1, 1, 0x9aae, 8, 0, 3, 0x20);
    osd_draw_cell_run(1, 0, 0x9aae, 0xb, 0, 0x21, 0x23);
    osd_draw_cell_run(1, 1, 0x9aae, 0x2c, 0, 2, 0x35);
    osd_draw_cell_run(1, 1, 0x9aae, 0x2e, 0, 1, 0x38);
    osd_draw_cell_run(1, 1, 0xd6aa, 0x2f, 0, 4, 0x88);
    osd_draw_cell_run(1, 1, 0xd79a, 0x30, 1, 2, 0x8c);
    osd_draw_cell_run(1, 1, 0xa29a, 0x33, 0, 3, 0x7a);
    osd_draw_cell_run(1, 1, 0xaaaa, 0x36, 0, 1, 0x7d);
    osd_draw_cell_run(1, 1, 0x9aaa, 0x32, 1, 5, 0x7e);
    osd_draw_cell_run(1, 1, 0x9aaa, 0x32, 2, 5, 0x83);
    osd_draw_cell_run(1, 1, 0x9faa, 0, 0x18, 1, 0x8e);
    osd_draw_cell_run(1, 1, 0x9faa, 2, 0x18, 2, 0x8f);
    osd_draw_cell_run(1, 1, 0x9faa, 0, 0x19, 5, 0x91);
    osd_draw_cell_run(1, 1, 0x3392, 2, 0x17, 2, 0x30);
    osd_draw_cell_run(1, 1, 0x3392, 1, 0x18, 1, 0x32);
    osd_draw_cell_run(1, 1, 0x3092, 4, 0x17, 3, 0x33);
    osd_draw_cell_run(1, 1, 0x3092, 4, 0x18, 2, 0x36);

    /* Phase 2a: button highlight; `column` becomes the column of the first button text. */
    column = 0;
    if (!(user_settings.word_0x1e4.word & 0xffff0000)) {
        if ((unsigned char)(mode - 3) > 1 && user_settings.protect_notice == 0) {
            osd_highlight_dialog_button(DIALOG_THREE_BUTTONS, app_state_record.flags_0xe >> 15);
            app_state_record.flags_0x18.bit15 = 1;
            column = 0xb;
        } else {
            osd_highlight_dialog_button(DIALOG_TWO_BUTTONS, app_state_record.flags_0xe >> 15);
            app_state_record.flags_0x18.bit15 = 0;
            column = 0x11;
        }
    }

    /* Phase 3. */
    osd_api_set_glyph_write_address(0x5e, 0);
    osd_api_set_text_mode(2, 0);
    osd_draw_cell_run(1, 1, 0x792, 0x14, 1, 0xf, 0x40);
    osd_draw_cell_run(1, 1, 0x792, 0x14, 2, 0xf, 0x4f);

    /* Phase 2b: button texts Execute, Cancel and (three-button dialog) Later. */
    if (!(user_settings.word_0x1e4.word & 0xffff0000)) {
        osd_draw_text(0, column, BUTTON_ROW, BUTTON_WIDTH, osd_get_text(osd_protect_button_texts, user_settings.language), 0);
        osd_draw_text(0, column + BUTTON_SPACING, BUTTON_ROW, BUTTON_WIDTH, osd_get_text(osd_protect_button_texts, user_settings.language + TEXTS_PER_ITEM), 0);
        if ((unsigned char)(mode - 3) > 1 && user_settings.protect_notice == 0)
            osd_draw_text(0, LATER_BUTTON_COLUMN, BUTTON_ROW, BUTTON_WIDTH, osd_get_text(osd_protect_button_texts, user_settings.language + 2 * TEXTS_PER_ITEM), 0);
    }
    /* In the 'automatically activate' page, 8 cells of the button row from column 0x1D get the value 0x2C2. */
    if (mode == DIALOG_MODE_AUTO)
        osd_api_fill_cells(0x1d, BUTTON_ROW, 8, 0x2c2, 0);
    osd_api_fill_cells(4, 7, 0x32, 0x592, 0);

    /* Phase 4: the body text. Rows of the table: 9 for the 'automatically activate' page and for the
       short 'Execute' page, 13 otherwise. */
    if (long_time == 0) {
        if (mode == DIALOG_MODE_EXECUTE)
            row_count = 9;
        else if (mode == DIALOG_MODE_AUTO)
            row_count = 9;
        else
            row_count = 13;
    } else {
        if (mode == DIALOG_MODE_EXECUTE)
            row_count = 13;
        else if (mode == DIALOG_MODE_AUTO)
            row_count = 9;
        else
            row_count = 13;
    }
    for (row = 0; row < row_count; row++) {
        /* Cell row on the layer: rows 0, 1 at 4, 5; row 2 at 7; rows 3, 4 at 9, 11; the rest from 13 on. */
        if (row <= 1) {
            osd_api_set_text_mode(2, 0);
            cell_row = row + 4;
        } else {
            if (row == 2)
                cell_row = 7;
            else if ((unsigned char)(row - 3) <= 1)
                cell_row = row * 2 + 3;
            else
                cell_row = row + 8;
            osd_api_set_text_mode(0, 0);
        }
        /* Rows 0 and 1 start at column 3 and are 0x30 cells wide, row 2 at column 4, the rest at column 5;
           those are 0x2B cells wide. */
        width = 0x2b;
        if (row <= 1) {
            column = 3;
            width = 0x30;
        } else
            column = (row == 2) ? 4 : 5;
        /* Mark cell at column 4 in front of rows 3, 4, 5, 7, 9 and 11 (row 11 without its byte plane value
           when Protect Notice is 1). */
        if ((unsigned char)(row - 3) < 3 || row == 7 || row == 9 || row == 11) {
            osd_api_fill_cells(4, cell_row, 1, 0xe96, 0);
            if (row != 11 || user_settings.protect_notice != 1)
                osd_api_fill_cell_bytes(0, 4, cell_row, 1, 1, 0);
        }
        if (row > 3) {
            if (row == 4)
                osd_api_set_glyph_write_address(0x10d, 0);
            osd_api_fill_cells(5, cell_row, 0x2b, 0x796, 0);
        }
        if (long_time == 0) {
            if (mode == DIALOG_MODE_EXECUTE) {
                /* Byte +0x1E4 = 1: "did not complete ... select this item later"; else "press Execute". */
                if (user_settings.word_0x1e4.byte[0] == 1)
                    osd_draw_text(0, column, cell_row, width, osd_get_text(osd_protect_incomplete_texts, row * TEXTS_PER_ITEM + user_settings.language), 0);
                else
                    osd_draw_text(0, column, cell_row, width, osd_get_text(osd_protect_execute_texts, row * TEXTS_PER_ITEM + user_settings.language), 0);
            } else if (user_settings.byte_0x1e2 == app_state_record.half_0x10 && user_settings.word_0x1e4.byte[2] == 1) {
                /* "did not complete. Please press execute": with Protect Notice 0, rows 9..12 take texts
                   11..14 (the paragraphs about Cancel or Later); else only rows 0..10 are drawn. */
                if (user_settings.protect_notice == 0 && row > 8) {
                    if (row == 9)
                        osd_api_set_glyph_write_address(0x201, 0);
                    osd_api_fill_cells(column, cell_row, width, 0x793, 0);
                    osd_draw_text(0, column, cell_row, width, osd_get_text(osd_protect_retry_texts, row * TEXTS_PER_ITEM + user_settings.language + 2 * TEXTS_PER_ITEM), 0);
                } else if (row <= 10)
                    osd_draw_text(0, column, cell_row, width, osd_get_text(osd_protect_retry_texts, row * TEXTS_PER_ITEM + user_settings.language), 0);
            } else if (mode == DIALOG_MODE_AUTO)
                osd_draw_text(0, column, cell_row, width, osd_get_text(osd_protect_auto_texts, row * TEXTS_PER_ITEM + user_settings.language), 0);
            else {
                /* The title page: texts from the second on (the first is the title line). */
                if (row > 8) {
                    if (row == 9)
                        osd_api_set_glyph_write_address(0x201, 0);
                    osd_api_fill_cells(column, cell_row, width, 0x793, 0);
                }
                osd_draw_text(0, column, cell_row, width, osd_get_text(osd_protect_title_texts, row * TEXTS_PER_ITEM + user_settings.language + TEXTS_PER_ITEM), 0);
            }
        } else {
            if (mode == DIALOG_MODE_EXECUTE) {
                if (user_settings.word_0x1e4.byte[1] == 1)
                    osd_draw_text(0, column, cell_row, width, osd_get_text(osd_protect_long_incomplete_texts, row * TEXTS_PER_ITEM + user_settings.language), 0);
                else
                    osd_draw_text(0, column, cell_row, width, osd_get_text(osd_protect_long_execute_texts, row * TEXTS_PER_ITEM + user_settings.language), 0);
            } else if (user_settings.byte_0x1e3 == app_state_record.half_0x12 && user_settings.word_0x1e4.byte[3] == 1)
                osd_draw_text(0, column, cell_row, width, osd_get_text(osd_protect_long_retry_texts, row * TEXTS_PER_ITEM + user_settings.language), 0);
            else if (mode == DIALOG_MODE_AUTO)
                osd_draw_text(0, column, cell_row, width, osd_get_text(osd_protect_long_auto_texts, row * TEXTS_PER_ITEM + user_settings.language), 0);
            else
                osd_draw_text(0, column, cell_row, width, osd_get_text(osd_protect_long_title_texts, row * TEXTS_PER_ITEM + user_settings.language + TEXTS_PER_ITEM), 0);
        }
    }

    /* Phase 5: show the dialog. */
    osd_api_set_text_mode(2, 0);
    osd_api_set_position(0x32, 0x32, 0);
    osd_edit_value = app_state_record.flags_0xe >> 15;
    osd_api_enable(1, MENU_LAYER_MAIN);
}
