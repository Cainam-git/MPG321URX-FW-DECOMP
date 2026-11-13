/* osd_highlight_tab  (FUN_a00b4144)
 *
 * Highlight a tab of the left column and show the tab key guide.
 *   tab: tab index
 *   style: highlight style
 * Note: Mode 1 = cursor on the tabs (stores the tab in 0xA802B08F), other modes = parent of the open item
 *   list.
 * Name basis: derived - called at 46 sites by the tab and item handlers; key guide texts 0x1928B0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b4144 @ 0xa00b4144-0xa00b5014 (3792 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - draw_cell_run is a static copy of osd_draw_cell_run, inlined at every use;
 *  - the bottom-row test is written 'tab != 5' with the glyph-run arm first;
 *  - user_settings is an extern byte array here (language read as element 8).
 */
extern unsigned char user_settings[];
extern unsigned char osd_list_id;
extern unsigned int osd_key_guide_texts[];
extern void panel_wait_sync_pulse(void);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_api_write_reg_cc(unsigned short, unsigned char);
extern void osd_api_set_window_enable(int, int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern unsigned short osd_get_menu_state(void);
extern void osd_set_highlight_window(unsigned char, unsigned char, unsigned int, unsigned int);

#define SETTINGS_LANGUAGE       8       /* user settings byte +0x08: menu language */
#define TEXTS_PER_ITEM          29      /* a text table holds one text per menu language for every item */

/* Highlight styles (the `style` argument). */
#define TAB_STYLE_CURSOR        1       /* the cursor is on the tabs */
#define TAB_STYLE_PARENT        2       /* the tab whose item list is open */

/* Texts 6 and 7 of the key guide table: 'Exit' and 'Back'. */
#define KEY_GUIDE_EXIT          (6 * TEXTS_PER_ITEM)
#define KEY_GUIDE_BACK          (7 * TEXTS_PER_ITEM)
#define KEY_GUIDE_COLUMN        0x37    /* the key guide column */
#define KEY_GUIDE_ROW           9

/* Layout of a tab box: three rows from `top`. Border glyphs in columns 1 and 0x11 on all three rows and in
   column 0x10 on the top and bottom rows; columns 2..4 hold the icon; the middle row is filled on columns
   5..0x10. */
#define TAB_LAST_ON_FIRST_PAGE  6       /* tabs 7 and 8 are on the second page of the tab column */

/* A copy of osd_draw_cell_run: set the cell value (osd_api_write_reg_cc), then write `count` glyph cells from
   (column, row) across (across 1) or down, with the same glyph or rising glyphs (rising 1). */
static void draw_cell_run(unsigned char across, unsigned char rising, unsigned short cell_value, unsigned short column,
                          unsigned char row, unsigned char count, unsigned char glyph)
{
    unsigned char k;

    osd_api_write_reg_cc(cell_value, 0);
    if (across == 1) {
        for (k = 0; k < count; k++) {
            if (rising)
                osd_api_fill_cell_bytes(1, column + k, row, 1, glyph + k, 0);
            else
                osd_api_fill_cell_bytes(1, column + k, row, 1, glyph, 0);
        }
    } else {
        for (k = 0; k < count; k++) {
            if (rising)
                osd_api_fill_cell_bytes(1, column, row + k, 1, glyph + k, 0);
            else
                osd_api_fill_cell_bytes(1, column, row + k, 1, glyph, 0);
        }
    }
}

/*
 * Draw the box of one tab in the left column of the main menu in one of two styles, and set the key guide.
 *
 *   tab    tab number 0..8 (G.I. .. MSI OLED Care)
 *   style  TAB_STYLE_CURSOR: the cursor is on this tab; the tab number is stored in osd_list_id and the
 *          highlight window is placed over the box. Any other value (TAB_STYLE_PARENT is used): the box
 *          is drawn in the second set of cell values and glyphs; the highlight window is switched off unless
 *          the menu state is 0x92..0xAE.
 *
 * Called by the tab and item handlers (osd_select_prev|next_tab, osd_leave_<tab>_items, osd_draw_tab_page,
 * osd_redraw_page_after_notice and others).
 *
 * Phases:
 *   1. Key guide: 'Back' for style 2, 'Exit' otherwise, at column 0x37 row 9.
 *   2. Box position: tabs 0..6 from row 5 down in steps of two, tabs 7 and 8 on the second page from row 5.
 *      Pick the five cell values of the style.
 *   3. Wait two sync pulses, then the highlight window (style 1) or switch it off.
 *   4. The icon part (columns 2..4) and the middle row: tabs 0, 6 and 7 have a three-row icon; tabs 1, 5 and 8
 *      have one icon row (tab 5 at the bottom row); the others plain glyph runs.
 *   5. The border glyphs 0x9A..0xA3 around the box, with the top and bottom runs at columns 5..0xF.
 */
void osd_highlight_tab(unsigned char tab, unsigned char style)
{
    unsigned char top;
    unsigned short cells_middle_left, cells_icon, cells_edge, cells_middle, cells_border;

    /* Phase 1: key guide. */
    panel_wait_sync_pulse();
    if (style == TAB_STYLE_PARENT) {
        osd_api_set_glyph_write_address(0x1e5, 0);
        osd_api_set_text_mode(2, 0);
        osd_api_fill_cells(KEY_GUIDE_COLUMN, KEY_GUIDE_ROW, 4, 0x596, 0);
        osd_draw_text(0, KEY_GUIDE_COLUMN, KEY_GUIDE_ROW, 4, osd_get_text(osd_key_guide_texts, user_settings[SETTINGS_LANGUAGE] + KEY_GUIDE_BACK), 0);
    } else {
        osd_api_set_glyph_write_address(0x1e5, 0);
        osd_api_set_text_mode(2, 0);
        osd_api_fill_cells(KEY_GUIDE_COLUMN, KEY_GUIDE_ROW, 4, 0x596, 0);
        osd_draw_text(0, KEY_GUIDE_COLUMN, KEY_GUIDE_ROW, 4, osd_get_text(osd_key_guide_texts, user_settings[SETTINGS_LANGUAGE] + KEY_GUIDE_EXIT), 0);
    }

    /* Phase 2: top row of the box and the cell values of the style. */
    if (tab > TAB_LAST_ON_FIRST_PAGE)
        top = tab * 2 - 9;
    else
        top = tab * 2 + 5;
    if (style == TAB_STYLE_CURSOR) {
        osd_list_id = tab;
        cells_middle_left = 0x714a;
        cells_icon = 0x799a;
        cells_edge = 0x392;
        cells_middle = 0x742;
        if ((unsigned char)(tab - 6) > 1)
            cells_icon = 0x699a;        /* tabs other than 6 and 7 */
        cells_border = 0x589a;
    } else {
        cells_middle_left = 0x75ca;
        cells_icon = 0x7d9a;
        cells_edge = 0xb92;
        cells_middle = 0x7c2;
        if ((unsigned char)(tab - 6) > 1)
            cells_icon = 0x6d9a;        /* tabs other than 6 and 7 */
        cells_border = 0x5b9a;
    }

    /* Phase 3: highlight window. */
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    if (style == TAB_STYLE_CURSOR) {
        osd_set_highlight_window(1, 1, top, 0x11);
        osd_api_set_window_enable(1, 1, 0);
        osd_api_set_window_enable(2, 1, 0);
    } else if (osd_get_menu_state() <= 0x91 || osd_get_menu_state() > 0xae)
        osd_set_highlight_window(0, 0, 0, 0);

    /* Phase 4: icon part and middle row. */
    if ((unsigned char)(tab - 6) < 2 || tab == 0) {
        /* Tabs 0, 6, 7: an icon three rows high. */
        osd_api_fill_cells(2, top, 3, cells_icon, 0);
        osd_api_fill_cells(2, top + 1, 3, cells_icon, 0);
        osd_api_fill_cells(5, top + 1, 0xc, cells_middle, 0);
        osd_api_fill_cells(2, top + 2, 3, cells_icon, 0);
        if (tab == 0) {
            if (style == TAB_STYLE_CURSOR) {
                draw_cell_run(1, 1, cells_icon, 2, top, 3, 0x49);
                draw_cell_run(1, 1, cells_icon, 2, top + 2, 3, 0x4f);
            } else {
                draw_cell_run(1, 1, cells_icon, 2, top, 3, 0x7f);
                draw_cell_run(1, 1, cells_icon, 2, top + 2, 3, 0x82);
            }
        } else if (tab == 6) {
            if (style == TAB_STYLE_CURSOR) {
                draw_cell_run(1, 1, cells_icon, 2, top, 3, 0x64);
                draw_cell_run(1, 1, cells_icon, 2, top + 2, 3, 0x6a);
            } else {
                draw_cell_run(1, 1, cells_icon, 2, top, 3, 0x88);
                draw_cell_run(1, 1, cells_icon, 2, top + 2, 3, 0x8b);
            }
        } else if (tab == 7) {
            if (style == TAB_STYLE_CURSOR) {
                draw_cell_run(1, 1, cells_icon, 2, top, 3, 0x70);
                draw_cell_run(1, 1, cells_icon, 2, top + 2, 3, 0x76);
            } else {
                draw_cell_run(1, 1, cells_icon, 2, top, 3, 0x91);
                draw_cell_run(1, 1, cells_icon, 2, top + 2, 3, 0x94);
            }
        }
    } else {
        /* Top row: tabs 1 and 8 have an icon row here, the others a run of one glyph. */
        if (tab != 1 && tab != 8) {
            if (style == TAB_STYLE_CURSOR)
                draw_cell_run(1, 0, cells_edge, 2, top, 3, 0x30);
            else
                draw_cell_run(1, 0, cells_edge, 2, top, 3, 0x32);
        } else if (tab == 8) {
            if (style == TAB_STYLE_CURSOR)
                draw_cell_run(1, 1, cells_icon, 2, top, 3, 0x79);
            else
                draw_cell_run(1, 1, cells_icon, 2, top, 3, 0x97);
        } else if (tab == 1) {
            if (style == TAB_STYLE_CURSOR)
                draw_cell_run(1, 1, cells_icon, 2, top, 3, 0x52);
            else
                draw_cell_run(1, 1, cells_icon, 2, top, 3, 0x85);
        }
        osd_api_fill_cells(2, top + 1, 3, cells_middle_left, 0);
        osd_api_fill_cells(5, top + 1, 0xc, cells_middle, 0);
        /* Bottom row: tab 5 has an icon row here, the others a run of one glyph. */
        if (tab != 5) {
            if (style == TAB_STYLE_CURSOR)
                draw_cell_run(1, 0, cells_edge, 2, top + 2, 3, 0x31);
            else
                draw_cell_run(1, 0, cells_edge, 2, top + 2, 3, 0x33);
        } else {
            if (style == TAB_STYLE_CURSOR)
                draw_cell_run(1, 1, cells_icon, 2, top + 2, 3, 0x6d);
            else
                draw_cell_run(1, 1, cells_icon, 2, top + 2, 3, 0x8e);
        }
    }

    /* Phase 5: border. Style 1 draws the top and bottom runs (11 cells from column 5) with the border glyphs
       0x9B / 0xA1, the other style with glyphs 0x32 / 0x33 and the edge cell value. */
    draw_cell_run(1, 0, cells_border, 1, top, 1, 0x9a);
    if (style == TAB_STYLE_CURSOR)
        draw_cell_run(1, 0, cells_border, 5, top, 11, 0x9b);
    else
        draw_cell_run(1, 0, cells_edge, 5, top, 11, 0x32);
    draw_cell_run(1, 0, cells_border, 0x10, top, 1, 0x9c);
    draw_cell_run(1, 0, cells_border, 0x11, top, 1, 0x9d);
    draw_cell_run(1, 0, cells_border, 1, top + 1, 1, 0x9e);
    draw_cell_run(1, 0, cells_border, 0x11, top + 1, 1, 0x9f);
    draw_cell_run(1, 0, cells_border, 1, top + 2, 1, 0xa0);
    if (style == TAB_STYLE_CURSOR)
        draw_cell_run(1, 0, cells_border, 5, top + 2, 11, 0xa1);
    else
        draw_cell_run(1, 0, cells_edge, 5, top + 2, 11, 0x33);
    draw_cell_run(1, 0, cells_border, 0x10, top + 2, 1, 0xa2);
    draw_cell_run(1, 0, cells_border, 0x11, top + 2, 1, 0xa3);
}
