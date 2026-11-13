/* osd_highlight_quick_menu_row  (FUN_a00ad86c)
 *
 * Highlight a row of a quick menu list.
 *   item: row
 *   cursor: non-zero for the entry the cursor is on, zero for the stored entry
 * Name basis: derived - called by every quick menu up/down handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ad86c @ 0xa00ad86c, flags -mcpu=v8 -O3 -g.
 * Source form: the two cases of 'cursor' are written as separate if/else blocks (window id and effect value
 * first, then the rectangle).
 */
extern void osd_api_set_window_enable(int window, int on, int unused);
extern void osd_api_set_window_effect(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                         unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void osd_api_set_window_rect(unsigned int window, unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1, unsigned int unused);
extern void osd_draw_frame_highlight(unsigned char kind, unsigned char column, unsigned char row, unsigned char selected);

#define QUICK_MENU_FIRST_ROW     4       /* row of the first quick menu entry; entries are two rows apart */
#define CELL_HEIGHT              36      /* pixel height of a cell row (window rectangles are row * 36) */
#define FRAME_KIND_QUICK_MENU_ROW 2
#define QUICK_MENU_FRAME_COLUMN  3
#define WINDOW_CURSOR            3       /* window of the entry the cursor is on */
#define WINDOW_STORED            4       /* window of the stored (current) entry */
#define EFFECT_CURSOR            4       /* sixth argument of osd_api_set_window_effect for the cursor window */
#define EFFECT_STORED            0xc     /* the same for the stored window */
#define WINDOW_LEFT              0x48    /* left and right edge of the highlight rectangle, in pixels */
#define WINDOW_RIGHT             0x1c7

/* Place the highlight window over one entry of a quick menu list (four entries, row = entry * 2 + 4).
 *   item:   entry number; only its low two bits are used.
 *   cursor: non-zero for the entry the cursor is on (window 3, then the frame of the entry is drawn);
 *           zero for the stored entry (window 4, slightly taller rectangle, no frame).
 * The window is switched off, its effect and rectangle are set, and it is switched on again. */
void osd_highlight_quick_menu_row(unsigned char item, unsigned char cursor)
{
    unsigned char row = (item & 3) * 2 + QUICK_MENU_FIRST_ROW;
    unsigned char window;
    unsigned char effect;

    if (cursor) {
        window = WINDOW_CURSOR;
        effect = EFFECT_CURSOR;
    } else {
        window = WINDOW_STORED;
        effect = EFFECT_STORED;
    }
    osd_api_set_window_enable(window, 0, 0);
    osd_api_set_window_effect(window, 0, 0, 0, 0, effect, 0, 0, 0, 0, 0);
    if (cursor)
        osd_api_set_window_rect(window, WINDOW_LEFT, row * CELL_HEIGHT + 0x1a, WINDOW_RIGHT, row * CELL_HEIGHT + 0x51, 0);
    else
        osd_api_set_window_rect(window, WINDOW_LEFT, row * CELL_HEIGHT + 0x16, WINDOW_RIGHT, row * CELL_HEIGHT + 0x55, 0);
    osd_api_set_window_enable(window, 1, 0);
    if (cursor)
        osd_draw_frame_highlight(FRAME_KIND_QUICK_MENU_ROW, QUICK_MENU_FRAME_COLUMN, row, cursor);
}
