/* osd_draw_tab_page  (FUN_a00b0034)
 *
 * Draw the item list and first choices of a main menu tab.
 *   tab: tab 0..8
 * Note: Tabs 0..8 = G.I., Gaming, Professional, Image, Input Source, PIP/PBP, Navi Key, Settings, MSI OLED
 *   Care.
 * Name basis: proven - item texts 0x18A360, 0x188634, 0x18CA88, 0x19158C; called by osd_open_main_menu and the
 *   tab handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b0034 @ 0xa00b0034-0xa00b05d8 (361 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - clear_column_0x13 is a static helper, inlined twice;
 *  - the G.I. rows (tab 0) use their own block-local counter `item`; with the shared counter the loop
 *    pre-header orders 'clr' before the address 'sethi';
 *  - the Navi Key rows (tab 6) are the static helper draw_item_rows(texts, column, count) with the row count as
 *    its parameter (cmp 4; bcs), as in src/leon2m/osd/osd_draw_navi_key_items.c;
 *  - the text tables are extern array symbols.
 */
/* The three fields of the user settings record read here. */
struct user_settings_record {
    unsigned char p000[8];
    unsigned char language;                     /* +0x08: menu language */
    unsigned char p009[0x1e - 9];
    unsigned char input_source;                 /* +0x1E: selected Input Source */
    unsigned char pip_pbp_mode;                 /* +0x1F: PIP/PBP mode (0 off, 1 PIP, 2 PBP) */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_gi_item_texts[], osd_professional_item_texts[], osd_image_item_texts[], osd_navi_key_item_texts[];
extern void panel_wait_sync_pulse(void);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_set_window_enable(int, int, int);
extern void osd_api_set_glyph_write_address(int, int);
extern void osd_api_set_text_mode(int, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void osd_clear_choice_column(void);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_item_choices(int, unsigned char);
extern void osd_draw_oled_care_items(unsigned char);
extern void osd_draw_settings_items(unsigned char);
extern void osd_draw_gaming_items(unsigned char, int);
extern void osd_draw_pip_pbp_items(void);
extern void osd_draw_input_source_items(void);
extern void osd_draw_low_blue_light_switch(void);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);

/* The tabs of the main menu, in menu order (the menu state of a tab is its number + 2). */
enum {
    TAB_GI           = 0,
    TAB_GAMING       = 1,
    TAB_PROFESSIONAL = 2,
    TAB_IMAGE        = 3,
    TAB_INPUT_SOURCE = 4,
    TAB_PIP_PBP      = 5,
    TAB_NAVI_KEY     = 6,
    TAB_SETTINGS     = 7,
    TAB_OLED_CARE    = 8
};

/* Menu state of the first item of each tab: the page number that osd_draw_item_choices takes. */
enum {
    PAGE_GI_ITEMS           = 0x0b,
    PAGE_GAMING_ITEMS       = 0x0e,
    PAGE_PROFESSIONAL_ITEMS = 0x15,
    PAGE_IMAGE_ITEMS        = 0x18,
    PAGE_PIP_PBP_ITEMS      = 0x23,
    PAGE_NAVI_KEY_ITEMS     = 0x26,
    PAGE_SETTINGS_ITEMS     = 0x2a,
    PAGE_OLED_CARE_ITEMS    = 0x34
};

/* Menu layout in character cells: the tabs fill columns 1..0x12, the items start at column 0x14 and the
   choices at column 0x27. Item n is drawn on row n * 2 + 6. */
#define ITEM_COLUMN       0x14
#define TEXTS_PER_ITEM    29        /* a text table holds one text per menu language for every item */
#define CELL_ITEM_GREYED  0x292     /* cell value laid under the text of an item that cannot be selected */

/* Draw the first `count` item names of a tab from `texts` in column `column`, in the menu language. */
static void draw_item_rows(unsigned int *const texts, int column, unsigned char count)
{
    unsigned char i;

    for (i = 0; i < count; i++)
        osd_draw_text(0, column, i * 2 + 6, 1, osd_get_text(texts, i * TEXTS_PER_ITEM + user_settings.language), 0);
}

/* Clear column 0x13 on rows 5..0x14 (in the byte plane and in the cells), clear two cells of the byte plane at
   column 0x1C row 0x15 and switch window 5 of menu layer 0 off. Column 0x13 lies between the tabs and the items. */
static void clear_column_0x13(void)
{
    unsigned char row;

    panel_wait_sync_pulse();
    for (row = 5; row <= 0x14; row++) {
        osd_api_fill_cell_bytes(0, 0x13, row, 0x13, 0, 0);
        osd_api_fill_cells(0x13, row, 0x13, 0x792, 0);
    }
    osd_api_fill_cell_bytes(0, 0x1c, 0x15, 2, 0, 0);
    osd_api_set_window_enable(5, 0, 0);
}

/*
 * Draw the item column of a main menu tab, highlight its first item (or the current setting) and draw the
 * choices of that item.
 *
 *   tab  TAB_GI .. TAB_OLED_CARE; any other value only clears the columns
 *
 * Called with the menu state - 2 when the main menu opens (osd_open_main_menu), when the highlight moves to
 * another tab (osd_select_prev_tab, osd_select_next_tab) and when an item list is left back to its tab.
 *
 * The G.I., Professional, Image and Navi Key items are drawn here from their text tables; the other tabs have
 * a routine of their own. Items that cannot be selected at present (osd_is_item_enabled) are laid on greyed
 * cells first; the Navi Key items are drawn without that test.
 *
 * clear_column_0x13 first waits for one sync pulse of the panel (panel_wait_sync_pulse).
 */
void osd_draw_tab_page(unsigned char tab)
{
    unsigned char i, first, marker_row;

    clear_column_0x13();
    osd_clear_choice_column();
    switch (tab) {
    case TAB_GI: {
        unsigned char item;

        clear_column_0x13();
        osd_api_set_glyph_write_address(0x92, 0);
        osd_api_set_text_mode(0, 0);
        for (item = 0; item <= 2; item++) {
            if (!osd_is_item_enabled(item))
                osd_api_fill_cells(ITEM_COLUMN, item * 2 + 6, 0xd, CELL_ITEM_GREYED, 0);
            osd_draw_text(0, ITEM_COLUMN, item * 2 + 6, 1, osd_get_text(osd_gi_item_texts, item * TEXTS_PER_ITEM + user_settings.language), 0);
        }
        osd_highlight_item_row(0, 0);
        osd_draw_item_choices(PAGE_GI_ITEMS, 0);
        break;
    }
    case TAB_GAMING:
        osd_draw_gaming_items(0, 0);
        osd_highlight_item_row(0, 0);
        osd_draw_item_choices(PAGE_GAMING_ITEMS, 0);
        break;
    case TAB_PROFESSIONAL:
        osd_api_set_glyph_write_address(0x92, 0);
        osd_api_set_text_mode(0, 0);
        for (i = 0; i <= 2; i++) {
            if (!osd_is_item_enabled(i))
                osd_api_fill_cells(ITEM_COLUMN, i * 2 + 6, 0xf, CELL_ITEM_GREYED, 0);
            osd_draw_text(0, ITEM_COLUMN, i * 2 + 6, 1, osd_get_text(osd_professional_item_texts, i * TEXTS_PER_ITEM + user_settings.language), 0);
        }
        /* Low Blue Light is shown as off while HDR is active. */
        osd_draw_low_blue_light_switch();
        osd_highlight_item_row(0, 0);
        osd_draw_item_choices(PAGE_PROFESSIONAL_ITEMS, 0);
        break;
    case TAB_IMAGE:
        osd_api_set_glyph_write_address(0x92, 0);
        osd_api_set_text_mode(0, 0);
        for (i = 0; i <= 5; i++) {
            if (!osd_is_item_enabled(i))
                osd_api_fill_cells(ITEM_COLUMN, i * 2 + 6, 0xd, CELL_ITEM_GREYED, 0);
            osd_draw_text(0, ITEM_COLUMN, i * 2 + 6, 1, osd_get_text(osd_image_item_texts, i * TEXTS_PER_ITEM + user_settings.language), 0);
        }
        /* Highlight the first of items 0 and 1 that can be selected, else item 2. */
        if (osd_is_item_enabled(0))
            first = 0;
        else if (osd_is_item_enabled(1) == 1)
            first = 1;
        else
            first = 2;
        osd_highlight_item_row(first, 0);
        osd_draw_item_choices(PAGE_IMAGE_ITEMS, first);
        break;
    case TAB_INPUT_SOURCE:
        /* The highlight starts on the selected input. */
        osd_draw_input_source_items();
        osd_highlight_item_row(input_api_source_id_to_menu_index(user_settings.input_source), 0);
        break;
    case TAB_PIP_PBP:
        /* The highlight starts on the current PIP/PBP mode, which also gets the two marker cells 0x3A, 0x3B
           in the item column. From the eighth item on the rows start again at the top. */
        osd_draw_pip_pbp_items();
        osd_highlight_item_row(user_settings.pip_pbp_mode, 0);
        if (user_settings.pip_pbp_mode < 7)
            marker_row = user_settings.pip_pbp_mode * 2 + 6;
        else
            marker_row = user_settings.pip_pbp_mode * 2 - 8;
        osd_api_fill_cell_bytes(0, ITEM_COLUMN, marker_row, 1, 0x3a, 0);
        osd_api_fill_cell_bytes(0, ITEM_COLUMN + 1, marker_row, 1, 0x3b, 0);
        osd_draw_item_choices(PAGE_PIP_PBP_ITEMS, user_settings.pip_pbp_mode);
        break;
    case TAB_NAVI_KEY:
        osd_api_set_glyph_write_address(0x92, 0);
        osd_api_set_text_mode(0, 0);
        draw_item_rows(osd_navi_key_item_texts, ITEM_COLUMN, 4);
        osd_highlight_item_row(0, 0);
        osd_draw_item_choices(PAGE_NAVI_KEY_ITEMS, 0);
        break;
    case TAB_SETTINGS:
        osd_draw_settings_items(0);
        osd_highlight_item_row(0, 0);
        osd_draw_item_choices(PAGE_SETTINGS_ITEMS, 0);
        break;
    case TAB_OLED_CARE:
        osd_draw_oled_care_items(0);
        osd_highlight_item_row(0, 0);
        osd_draw_item_choices(PAGE_OLED_CARE_ITEMS, 0);
        break;
    }
}
