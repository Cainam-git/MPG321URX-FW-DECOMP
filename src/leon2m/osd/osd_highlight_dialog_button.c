/* osd_highlight_dialog_button  (FUN_a00b0710)
 *
 * Highlight the selected button of a dialog and unmark the others.
 *   sel: dialog layout 0..3 (button columns and row)
 *   st: selected button
 * Note: Layouts 0 and 1: two buttons (st non-zero = first); layout 2: three (st 1, 0, other); layout 3: three
 *   or four (st 0..3).
 * Name basis: derived - called by the dialog windows of the change notice (0x116) and the panel protect prompt
 *   (0x10A)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b0710 @ 0xa00b0710-0xa00b0a90 (896 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: every state arm written out with constant flags (GCC cross-jumps the shared calls); in sel 3 the
 * row is set after the dialog_button_index if/else.
 */
#define FRAME_KIND_DIALOG_BUTTON 3

/* osd_dialog_button_index is app_state_record dialog_button_index (+0x3F); user_settings_byte_0x1e2 is
 * settings byte +0x1E2. */
extern unsigned char osd_dialog_button_index;
extern unsigned char user_settings_byte_0x1e2;
extern unsigned short osd_get_menu_state(void);
extern void osd_draw_frame_highlight(unsigned char, unsigned char, unsigned char, unsigned char);

/* Redraw the buttons of a dialog: the selected one with the selected frame, the others plain.
 *   sel: dialog layout, which gives the button columns and the row (all in cells):
 *        0: two buttons at columns 9 and 0x15, row 7;
 *        1: two buttons at columns 0x10 and 0x1c, row 0x16 (a third column 0x25 is set but not used);
 *        2: three buttons at 10, 0x16 and 0x23, row 0x16;
 *        3: row 7 and, when osd_dialog_button_index is 2, three buttons at 10, 0x17 and 0x24,
 *           otherwise four columns 4, 0x10, 0x1c and 0x28 (the fourth is only drawn when
 *           osd_dialog_button_index is 1).
 *   st:  the selected button. Layouts 0 and 1: non-zero selects the first button, 0 the second.
 *        Layout 2: 1 selects the first, 0 the second, any other value the third.
 *        Layout 3: 0, 1, 2, 3 select the first to the fourth.
 * In layout 3 the second button is left alone when settings byte +0x1E2 is 3 or more and the menu
 * state is 0x10a (the panel protect prompt). The change notice (state 0x116) and the panel protect
 * prompt are the dialogs that call this. */
void osd_highlight_dialog_button(unsigned char sel, unsigned char st)
{
    unsigned char a = 0, b = 0, c = 0, d = 0, row = 0;

    switch (sel) {
    case 0:
        a = 9; b = 0x15; row = 7;
        break;
    case 1:
        a = 0x10; b = 0x1c; c = 0x25; row = 0x16;
        break;
    case 2:
        a = 10; b = 0x16; c = 0x23; row = 0x16;
        break;
    case 3:
        if (osd_dialog_button_index == 2) {
            a = 10; b = 0x17; c = 0x24;
        } else {
            a = 4; b = 0x10; c = 0x1c; d = 0x28;
        }
        row = 7;
        break;
    }
    if (sel != 2 && sel != 3) {
        if (st) {
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, a, row, 1);
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, b, row, 0);
        } else {
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, a, row, 0);
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, b, row, 1);
        }
    } else if (sel != 3) {
        if (st == 1) {
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, a, row, 1);
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, b, row, 0);
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, c, row, 0);
        } else if (st == 0) {
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, a, row, 0);
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, b, row, 1);
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, c, row, 0);
        } else {
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, a, row, 0);
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, b, row, 0);
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, c, row, 1);
        }
    } else {
        if (st == 0) {
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, a, row, 1);
            if (user_settings_byte_0x1e2 < 3 || osd_get_menu_state() != 0x10a)
                osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, b, row, 0);
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, c, row, 0);
        } else if (st == 1) {
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, a, row, 0);
            if (user_settings_byte_0x1e2 < 3 || osd_get_menu_state() != 0x10a)
                osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, b, row, 1);
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, c, row, 0);
        } else if (st == 2) {
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, a, row, 0);
            if (user_settings_byte_0x1e2 < 3 || osd_get_menu_state() != 0x10a)
                osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, b, row, 0);
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, c, row, 1);
        } else {
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, a, row, 0);
            if (user_settings_byte_0x1e2 < 3 || osd_get_menu_state() != 0x10a)
                osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, b, row, 0);
            osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, c, row, 0);
        }
        if (osd_dialog_button_index == 1) {
            if (st == 3)
                osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, d, row, 1);
            else
                osd_draw_frame_highlight(FRAME_KIND_DIALOG_BUTTON, d, row, 0);
        }
    }
}
