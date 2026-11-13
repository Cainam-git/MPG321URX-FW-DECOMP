/* osd_redraw_page_after_notice  (FUN_a00b1004)
 *
 * Redraw the main menu on the Game Mode, Pro Mode or Panel Protect page after a notice or prompt.
 *   page: 0, 2 or 7
 *   in_list: keep cursor in the list
 * Note: Page 0 = Gaming (game modes), 2 = Professional (Pro modes), 7 = MSI OLED Care with the Panel Protect
 *   item.
 * Name basis: derived - called by osd_close_change_notice and by osd_run_periodic_task when the Panel Protect
 *   prompt got no answer for 60 s
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b1004 @ 0xa00b1004-0xa00b1654 (1568 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - clear_column_0x13, draw_tab_icons and mark_choice_row are static helpers that GCC inlines;
 *  - draw_tab_icons is the body of osd_draw_tab_icons, but its two bounds are set in an if/else (the
 *    default-then-override form of osd_draw_tab_icons gives other registers here);
 *  - the Pro mode list position is fetched again from osd_step_pro_mode_index for every use.
 */
/* The user settings fields read here (offsets in the record user_settings). */
struct user_settings_record {
    unsigned char p000[8];
    unsigned char language;                     /* +0x08: menu language */
    unsigned char p009[0x181 - 0x09];
    unsigned char pro_mode;                     /* +0x181: Professional mode */
    unsigned char game_mode;                    /* +0x182: Game Mode */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_professional_item_texts[];

extern void osd_hide_menu(void);
extern void osd_draw_main_menu_frame(void);
extern void panel_wait_sync_pulse(void);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_set_window_enable(int, int, int);
extern void osd_api_set_glyph_write_address(int, int);
extern void osd_api_set_text_mode(int, int);
extern void osd_clear_choice_column(void);
extern void osd_highlight_tab(unsigned char, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void osd_draw_low_blue_light_switch(void);
extern unsigned char osd_step_pro_mode_index(unsigned char, unsigned char);
extern void osd_draw_pro_mode_choices(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_gaming_items(unsigned char, int);
extern void osd_draw_game_mode_choices(void);
extern void osd_draw_cell_run(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char,
                         unsigned char);
extern void osd_draw_tab_names(unsigned char);
extern void osd_draw_oled_care_items(unsigned char);
extern void osd_draw_oled_care_choices(unsigned int);
extern void osd_user_apply_transparency(void);
extern void osd_api_enable(int, int);

/* Which page is drawn again: the first argument. The callers use the notice origin numbers. */
#define NOTICE_FROM_GAME_MODE   0       /* Gaming tab, Game Mode list (after the Confirm Change notice) */
#define NOTICE_FROM_PRO_MODE    2       /* Professional tab, Pro Mode list (after the Confirm Change notice) */
#define NOTICE_PAGE_7           7       /* MSI OLED Care tab, Panel Protect item (after the Panel Protect prompt) */

/* Tabs of the main menu, in menu order. */
#define TAB_GAMING              1
#define TAB_PROFESSIONAL        2
#define TAB_OLED_CARE           8

/* Styles of osd_highlight_tab: 1 = cursor on the tabs (also stores the tab in osd_list_id), 2 = tab of the
   open item list. */
#define TAB_STYLE_CURSOR        1
#define TAB_STYLE_PARENT        2

#define MENU_STATE_PANEL_PROTECT_ITEM 0x35  /* MSI OLED Care page, item Panel Protect */
#define MENU_LAYER_MAIN         0       /* the layer osd_show_menu_layer switches on */

/* Menu layout in character cells. Item and choice n are drawn on row n * 2 + 6. */
#define TAB_COLUMN              1       /* the tabs fill columns 1..0x11 */
#define ITEM_COLUMN             0x14
#define CHOICE_MARK_COLUMN      0x28    /* the two cells of the choice mark: columns 0x28 and 0x29 */
#define CHOICE_MARK_CODE        0x0f    /* byte plane values of the mark: 0x0F, then 0x10 */
#define TEXTS_PER_ITEM          29      /* a text table holds one text per menu language for every item */
#define CELL_ITEM_GREYED        0x292   /* cell value laid under the text of an item that cannot be selected */
#define CELL_BLANK              0x792   /* cell value of an empty menu cell */
#define CHOICES_PER_PAGE        7       /* longer lists are drawn in pages of seven */

/* Clear column 0x13 on rows 5..0x14 (in the byte plane and in the cells), clear two cells of the byte plane at
   column 0x1C row 0x15 and switch window 5 of menu layer 0 off. Column 0x13 lies between the tabs and the items. */
static void clear_column_0x13(void)
{
    unsigned char row;

    panel_wait_sync_pulse();
    for (row = 5; row <= 0x14; row++) {
        osd_api_fill_cell_bytes(0, 0x13, row, 0x13, 0, 0);
        osd_api_fill_cells(0x13, row, 0x13, CELL_BLANK, 0);
    }
    osd_api_fill_cell_bytes(0, 0x1c, 0x15, 2, 0, 0);
    osd_api_set_window_enable(5, 0, 0);
}

/* Draw the tab icons of the left column: tabs 0..6 (second_page 0) or tabs 7..8 (the second page), as
   osd_draw_tab_icons does. Each icon is a run of three glyph cells from column 2; the icons of tabs 0, 6 and 7
   are three rows high. */
static void draw_tab_icons(unsigned char second_page)
{
    unsigned char tab, start, end, row;
    unsigned char glyph = 0;

    if (second_page == 0) {
        end = 7;
        start = 0;
    } else {
        end = 9;
        start = 7;
    }
    for (tab = start; tab < end; tab++) {
        /* First glyph of the icon of this tab. */
        switch (tab) {
        case 0:
            glyph = 0x49;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            glyph = tab * 3 + 0x52;
            break;
        case 6:
            glyph = 0x64;
            break;
        case 7:
            glyph = 0x70;
            break;
        case 8:
            glyph = 0x7c;
            break;
        }
        row = (tab % 7) * 2 + 6;
        if (tab == 6 || tab == 7 || tab == 0) {
            osd_draw_cell_run(1, 1, 0x629a, 2, row - 1, 3, glyph);
            osd_draw_cell_run(1, 1, 0x629a, 2, row, 3, glyph + 3);
            osd_draw_cell_run(1, 1, 0x629a, 2, row + 1, 3, glyph + 6);
        } else {
            osd_draw_cell_run(1, 1, 0x659a, 2, row, 3, glyph);
        }
    }
}

/* Write the two mark cells of choice row `choice` with the byte plane values `first` and `second` (0, 0 clears
   them). From the eighth choice on the rows start again at the top. */
static void mark_choice_row(unsigned char choice, unsigned char first, unsigned char second)
{
    unsigned char row;

    if (choice < 7)
        row = choice * 2 + 6;
    else
        row = choice * 2 - 8;
    osd_api_fill_cell_bytes(0, CHOICE_MARK_COLUMN, row, 1, first, 0);
    osd_api_fill_cell_bytes(0, CHOICE_MARK_COLUMN + 1, row, 1, second, 0);
}

/*
 * Draw the main menu again on the page that was open before a notice or prompt covered it.
 *
 *   page       NOTICE_FROM_GAME_MODE, NOTICE_FROM_PRO_MODE or NOTICE_PAGE_7; any other value draws only the
 *              frame
 *   in_list    Game Mode and Pro Mode pages: non-zero when the cursor stays in the choice list, 0 when it goes
 *              back to the item. Not read for NOTICE_PAGE_7.
 *
 * Callers: osd_close_change_notice, when the Confirm Change notice is answered (in_list 1 after Yes, 0 after
 * No or a time-out), and osd_run_periodic_task, when the Panel Protect prompt has had no answer for 60 s.
 *
 * Phases:
 *   1. Hide the menu, draw the frame of the main menu, clear column 0x13 and the choice column.
 *   2. By page:
 *        Game Mode:  highlight the Gaming tab, draw the Gaming items and the game mode list;
 *        Pro Mode:   highlight the Professional tab, draw its three items (greyed where they cannot be
 *                    selected), the Low Blue Light switch and the page of the Pro Mode list that holds the
 *                    stored mode;
 *        NOTICE_PAGE_7: clear the tab column, draw the second page of tab icons and tab names, the MSI OLED
 *                    Care items and the Panel Protect choices, highlight the MSI OLED Care tab and item 1.
 *   3. Game Mode and Pro Mode: highlight the item and the stored choice. With in_list set the choice row gets
 *      highlight styles 0 and 1 and no mark (the game mode mark cells are cleared); else it gets style 2 and the
 *      choice mark.
 *   4. Apply the menu transparency and switch the main menu layer on.
 */
void osd_redraw_page_after_notice(unsigned char page, unsigned char in_list)
{
    unsigned char i;

    /* Phase 1: empty main menu frame. */
    osd_hide_menu();
    osd_draw_main_menu_frame();
    clear_column_0x13();
    osd_clear_choice_column();

    /* Phases 2 and 3. */
    switch (page) {
    case NOTICE_FROM_GAME_MODE:
        osd_highlight_tab(TAB_GAMING, TAB_STYLE_CURSOR);
        osd_highlight_tab(TAB_GAMING, TAB_STYLE_PARENT);
        osd_draw_gaming_items(0, 0);
        osd_draw_game_mode_choices();
        if (in_list) {
            osd_highlight_item_row(0, 2);
            osd_highlight_choice_row(user_settings.game_mode, 0);
            osd_highlight_choice_row(user_settings.game_mode, 1);
            mark_choice_row(user_settings.game_mode, 0, 0);
        } else {
            osd_highlight_item_row(0, 1);
            osd_highlight_choice_row(user_settings.game_mode, 2);
            mark_choice_row(user_settings.game_mode, CHOICE_MARK_CODE, CHOICE_MARK_CODE + 1);
        }
        break;
    case NOTICE_FROM_PRO_MODE:
        osd_highlight_tab(TAB_PROFESSIONAL, TAB_STYLE_CURSOR);
        osd_highlight_tab(TAB_PROFESSIONAL, TAB_STYLE_PARENT);
        /* The items Pro Mode, Low Blue Light, Image Enhancement. */
        osd_api_set_glyph_write_address(0x92, 0);
        osd_api_set_text_mode(0, 0);
        for (i = 0; i <= 2; i++) {
            if (!osd_is_item_enabled(i))
                osd_api_fill_cells(ITEM_COLUMN, i * 2 + 6, 0xf, CELL_ITEM_GREYED, 0);
            osd_draw_text(0, ITEM_COLUMN, i * 2 + 6, 1, osd_get_text(osd_professional_item_texts, i * TEXTS_PER_ITEM + user_settings.language), 0);
        }
        osd_draw_low_blue_light_switch();
        /* The list position of the stored mode is osd_step_pro_mode_index(pro_mode, 0): the stored value plus
           one, with 7 wrapping to 0. */
        osd_draw_pro_mode_choices(osd_step_pro_mode_index(user_settings.pro_mode, 0) / CHOICES_PER_PAGE);
        if (in_list) {
            osd_highlight_item_row(0, 2);
            osd_highlight_choice_row(osd_step_pro_mode_index(user_settings.pro_mode, 0) % CHOICES_PER_PAGE, 0);
            osd_highlight_choice_row(osd_step_pro_mode_index(user_settings.pro_mode, 0) % CHOICES_PER_PAGE, 1);
        } else {
            osd_highlight_item_row(0, 1);
            osd_highlight_choice_row(osd_step_pro_mode_index(user_settings.pro_mode, 0) % CHOICES_PER_PAGE, 2);
            mark_choice_row(osd_step_pro_mode_index(user_settings.pro_mode, 0) % CHOICES_PER_PAGE, CHOICE_MARK_CODE, CHOICE_MARK_CODE + 1);
        }
        break;
    case NOTICE_PAGE_7:
        /* MSI OLED Care is tab 8, on the second page of the tab column: clear the tab column (rows 5..0x15)
           and draw that page. */
        panel_wait_sync_pulse();
        for (i = 5; i <= 0x15; i++) {
            osd_api_fill_cells(TAB_COLUMN, i, 0x11, CELL_BLANK, 0);
            osd_api_fill_cell_bytes(0, TAB_COLUMN, i, 0x11, 0, 0);
        }
        draw_tab_icons(1);
        osd_draw_tab_names(1);
        osd_draw_oled_care_items(0);
        osd_draw_oled_care_choices(MENU_STATE_PANEL_PROTECT_ITEM);
        osd_highlight_tab(TAB_OLED_CARE, TAB_STYLE_CURSOR);
        osd_highlight_tab(TAB_OLED_CARE, TAB_STYLE_PARENT);
        /* Item 1 is Panel Protect. */
        osd_highlight_item_row(1, 1);
        break;
    }

    /* Phase 4: show the menu. */
    osd_user_apply_transparency();
    osd_api_enable(1, MENU_LAYER_MAIN);
}
