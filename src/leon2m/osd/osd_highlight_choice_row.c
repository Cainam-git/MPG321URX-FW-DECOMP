/* osd_highlight_choice_row  (FUN_a00a9650)
 *
 * Highlight a choice row in the choice column and update the key guide.
 *   row: choice row
 *   mode: highlight style
 * Name basis: derived - called by every choice step handler; menu columns: tabs 1..0x12, items 0x14.., choices
 *   0x27.., key guide 0x37..
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a9650 @ 0xa00a9650-0xa00a9abc (283 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - osd_get_state_highlight_kind (osd_get_state_highlight_kind, a switch over osd_get_menu_state, jump tables 0xa00a3e50 and
 *    0xa00a3b64 in its two inlined copies) is defined here as a static copy;
 *  - cell_row is an unsigned int and the call arguments narrow it;
 *  - the test 'mode != 0 && mode != 2' is written out at each use (if-conversion computes it again each time).
 */
extern unsigned short osd_get_menu_state(void);
extern void osd_draw_key_guide(unsigned int row_group, unsigned int icons);
extern void osd_update_key_guide(unsigned int first_text, unsigned int second_text);
extern void osd_api_set_window_enable(int window, int on, int layer);
extern void osd_api_set_window_effect(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                         unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void osd_api_set_window_rect(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void osd_set_highlight_window(unsigned char on, unsigned char column, unsigned int row, unsigned int width);
extern void osd_draw_cell_run(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char,
                         unsigned char);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

/* What osd_get_state_highlight_kind returns for the current menu state. */
enum {
    HIGHLIGHT_KIND_SELECT     = 0,      /* key guide 'Move' / 'Select' */
    HIGHLIGHT_KIND_ENTER      = 1,      /* key guide 'Move' / 'Enter' */
    HIGHLIGHT_KIND_KEEP_GUIDE = 2       /* key guide left as it is */
};

/* The mode argument. 0 and 2 do the same here, and 1 and 3 differ only in the key guide. */
enum {
    CHOICE_ROW_PLAIN          = 0,      /* window 4, edge glyphs removed */
    CHOICE_ROW_EDGED          = 1,      /* window 3, edge glyphs drawn, key guide by highlight kind */
    CHOICE_ROW_PLAIN_2        = 2,
    CHOICE_ROW_EDGED_NO_GUIDE = 3       /* as 1, key guide left as it is */
};

/* Texts of the key guide table (osd_update_key_guide). */
enum {
    KEY_TEXT_MOVE   = 0,
    KEY_TEXT_ENTER  = 1,
    KEY_TEXT_SELECT = 4
};

#define MENU_LAYER_MAIN       0
#define PLANE_0               0         /* byte plane 0 (first argument of osd_api_fill_cell_bytes) */
#define CHOICE_COLUMN         0x27      /* first column of the choice column */
#define CHOICE_RIGHT_COLUMN   0x34      /* last column of a choice row (CHOICE_COLUMN + 13) */
#define CHOICE_WIDTH          0xe       /* cells of a choice row */
#define CHOICE_FIRST_ROW      5         /* cell row of choice row 0; each choice takes two cell rows */
#define WINDOW_EDGED          3         /* menu window used by modes 1 and 3 */
#define WINDOW_PLAIN          4         /* menu window used by modes 0 and 2 */
#define KEY_GUIDE_GROUP_1     1         /* osd_draw_key_guide: rows 0x10..0x12 of the key guide column */
#define ALARM_TIME_STATE_FIRST 0x58     /* menu states 0x58..0x5B: osd_accept_alarm_time sets 0x58 + settings byte
                                           +0x1A3 */
#define ALARM_TIME_STATE_LAST  0x5b

/*
 * The highlight kind of the current menu state (a copy of osd_get_state_highlight_kind; the firmware has the same
 * switch inlined twice in osd_highlight_choice_row).
 *   row  the choice row; it matters only in states 0xC0..0xC2 (the OLED Care detection choices), where only
 *        row 2 is of kind HIGHLIGHT_KIND_ENTER
 */
static unsigned char osd_get_state_highlight_kind(unsigned char row)
{
    unsigned char kind = HIGHLIGHT_KIND_SELECT;

    switch (osd_get_menu_state()) {
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x44:
    case 0x45:
    case 0x53:
    case 0x56:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5b:
    case 0x6f:
    case 0x7a:
    case 0x7b:
    case 0x7c:
    case 0x82:
    case 0x83:
    case 0xb3:
    case 0xba:
    case 0xbd:
    case 0xbe:
    case 0xbf:
    case 0xdc:
    case 0xe1:
    case 0xe6:
        kind = HIGHLIGHT_KIND_ENTER;
        break;
    case 0xc0:
    case 0xc1:
    case 0xc2:
        if (row == 2)
            kind = HIGHLIGHT_KIND_ENTER;
        break;
    case 0x69:
    case 0x6a:
    case 0x6b:
    case 0xaf:
    case 0xb0:
    case 0xca:
    case 0xcb:
    case 0xcc:
    case 0xf5:
    case 0xf7:
    case 0xf8:
    case 0xf9:
        kind = HIGHLIGHT_KIND_KEEP_GUIDE;
        break;
    }
    return kind & 3;
}

/*
 * Mark one row of the choice column (columns 0x27..0x34 of the main menu; choice row n starts at cell row
 * 5 + 2n and is three cell rows high).
 *
 *   row   the choice row
 *   mode  CHOICE_ROW_*: 1 and 3 put window 3 and the edge glyphs on the row, 0 and 2 window 4 without them
 *
 * Called by nearly every routine that enters, steps through, accepts or cancels a choice list, usually right
 * after osd_clear_choice_highlight.
 *
 * Phases:
 *   1. Key guide: modes 0 and 2 show icon set 2 with the texts 'Move' / 'Enter'. Mode 1 does the same for
 *      menu states of kind HIGHLIGHT_KIND_ENTER, shows icon set 3 with 'Move' / 'Select' for kind
 *      HIGHLIGHT_KIND_SELECT and leaves the guide for kind HIGHLIGHT_KIND_KEEP_GUIDE. Mode 3 leaves it.
 *   2. The window (3 or 4) is switched off, given its effect (4 or 0xC) and its rectangle over the row (in
 *      modes 0 / 2 four units higher and lower).
 *   3. Modes 1 / 3: window 3 on, the highlight window over the 14 cells of the row, edge glyphs 0xA6..0xA8 down
 *      the left column and 0xA9..0xAB down the right column, windows 1 and 2 on.
 *      Modes 0 / 2: the edge glyphs are removed. In the Alarm Clock time states 0x58..0x5B the first and the
 *      third cell row and both edge cells of the middle row are redrawn empty (glyph 0, attribute 0x792);
 *      otherwise the two edge columns get glyph 0 on all three cell rows. Then window 4 on.
 */
void osd_highlight_choice_row(unsigned char row, unsigned char mode)
{
    unsigned int cell_row = row * 2 + CHOICE_FIRST_ROW;
    unsigned char window;
    unsigned char k;

    /* 1. Key guide. */
    if (mode == CHOICE_ROW_PLAIN || mode == CHOICE_ROW_PLAIN_2) {
        osd_draw_key_guide(KEY_GUIDE_GROUP_1, 2);
        osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
    } else if (mode == CHOICE_ROW_EDGED) {
        if (osd_get_state_highlight_kind(row) == HIGHLIGHT_KIND_ENTER) {
            osd_draw_key_guide(KEY_GUIDE_GROUP_1, 2);
            osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
        } else if (osd_get_state_highlight_kind(row) == HIGHLIGHT_KIND_SELECT) {
            osd_draw_key_guide(KEY_GUIDE_GROUP_1, 3);
            osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_SELECT);
        }
    }

    /* 2. The row's window: off, effect, rectangle. */
    window = (mode != CHOICE_ROW_PLAIN && mode != CHOICE_ROW_PLAIN_2) ? WINDOW_EDGED : WINDOW_PLAIN;
    osd_api_set_window_enable(window, 0, MENU_LAYER_MAIN);
    if (mode != CHOICE_ROW_PLAIN && mode != CHOICE_ROW_PLAIN_2)
        osd_api_set_window_effect(window, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0);
    else
        osd_api_set_window_effect(window, 0, 0, 0, 0, 0xc, 0, 0, 0, 0, 0);
    if (mode != CHOICE_ROW_PLAIN && mode != CHOICE_ROW_PLAIN_2)
        osd_api_set_window_rect(window, 0x3a8, (unsigned char)cell_row * 36 + 0x1a, 0x4f7, (unsigned char)cell_row * 36 + 0x51, 0);
    else
        osd_api_set_window_rect(window, 0x3a8, (unsigned char)cell_row * 36 + 0x16, 0x4f7, (unsigned char)cell_row * 36 + 0x55, 0);

    /* 3. Edge glyphs and window on. */
    if (mode != CHOICE_ROW_PLAIN && mode != CHOICE_ROW_PLAIN_2) {
        osd_api_set_window_enable(window, 1, MENU_LAYER_MAIN);
        osd_set_highlight_window(1, CHOICE_COLUMN, (unsigned char)cell_row, CHOICE_WIDTH);
        osd_draw_cell_run(0, 1, 0x589a, CHOICE_COLUMN, cell_row, 3, 0xa6);
        osd_draw_cell_run(0, 1, 0x589a, CHOICE_RIGHT_COLUMN, cell_row, 3, 0xa9);
        osd_api_set_window_enable(1, 1, MENU_LAYER_MAIN);
        osd_api_set_window_enable(2, 1, MENU_LAYER_MAIN);
    } else if (osd_get_menu_state() > ALARM_TIME_STATE_FIRST - 1 && osd_get_menu_state() <= ALARM_TIME_STATE_LAST) {
        osd_draw_cell_run(1, 0, 0x792, CHOICE_COLUMN, cell_row, CHOICE_WIDTH, 0);
        osd_draw_cell_run(1, 0, 0x792, CHOICE_COLUMN, cell_row + 2, CHOICE_WIDTH, 0);
        osd_draw_cell_run(1, 0, 0x792, CHOICE_COLUMN, cell_row + 1, 1, 0);
        osd_draw_cell_run(1, 0, 0x792, CHOICE_RIGHT_COLUMN, cell_row + 1, 1, 0);
        osd_api_set_window_enable(window, 1, MENU_LAYER_MAIN);
    } else {
        for (k = 0; k <= 2; k++) {
            osd_api_fill_cell_bytes(PLANE_0, CHOICE_COLUMN, (unsigned char)cell_row + k, 1, 0, MENU_LAYER_MAIN);
            osd_api_fill_cell_bytes(PLANE_0, CHOICE_RIGHT_COLUMN, (unsigned char)cell_row + k, 1, 0, MENU_LAYER_MAIN);
        }
        osd_api_set_window_enable(window, 1, MENU_LAYER_MAIN);
    }
}
