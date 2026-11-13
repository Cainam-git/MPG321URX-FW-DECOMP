/* osd_show_change_notice  (FUN_a00b0f48)
 *
 * Draw the whole change notice dialog and show it.
 * Name basis: derived - callers osd_open_change_notice, osd_enter_game|pro_mode_choices, osd_run_navi_key_*;
 *   draws osd_draw_change_notice_text
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b0f48 @ 0xa00b0f48, flags -mcpu=v8 -O2 -g (section default).
 * The function ends where osd_switch_change_notice_choice begins; the last call is a tail call.
 */
extern void osd_close_menu(void);
extern void panel_wait_sync_pulse(void);
extern void osd_set_layout(unsigned int mode);
extern void osd_setup_layer_window(int columns, int rows, int attribute);
extern void osd_draw_dialog_frame(void);
extern void osd_api_set_position(unsigned short x, unsigned short y, unsigned char layer);
extern void osd_draw_change_notice_text(void);
extern void osd_user_apply_transparency(void);
extern void osd_api_enable(int on, int layer);

#define DIALOG_LAYOUT        3       /* osd_set_layout mode used for dialogs and messages */
#define DIALOG_COLUMNS       0x28    /* 40 cells wide */
#define DIALOG_ROWS          0xb     /* 11 cells high */
#define CELL_BLANK           0x792   /* background attribute of the layer */
#define DIALOG_POSITION      0x32    /* both position numbers: 50 (the menu position settings are percentages) */
#define MENU_LAYER_MAIN      0

/* Build the 'Confirm Change !' notice and show it. The menu is closed, the layer is reset to a 40 x 11
 * dialog (layout 3, blank background, position 50, 50), the dialog frame and the notice texts are drawn,
 * the menu transparency is applied and the layer is switched on. Called by the openers of the notice
 * (osd_open_change_notice, the Game and Pro Mode choice entries, the Navi key handlers). */
void osd_show_change_notice(void)
{
    osd_close_menu();
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    osd_set_layout(DIALOG_LAYOUT);
    osd_setup_layer_window(DIALOG_COLUMNS, DIALOG_ROWS, CELL_BLANK);
    osd_draw_dialog_frame();
    osd_api_set_position(DIALOG_POSITION, DIALOG_POSITION, 0);
    osd_draw_change_notice_text();
    osd_user_apply_transparency();
    osd_api_enable(1, MENU_LAYER_MAIN);
}
