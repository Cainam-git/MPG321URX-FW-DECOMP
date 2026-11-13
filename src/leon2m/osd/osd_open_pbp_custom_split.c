/* osd_open_pbp_custom_split  (FUN_a009811c)
 *
 * Switch PBP to the custom split and open its editor.
 * Note: Prints 'PBP New Mode'; menu state 0x109.
 * Name basis: proven - handler table 0xA802422C: OK on state 0x81 = 'Customize'; prints 'PBP New Mode'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009811c @ 0xa009811c, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the constant 2 reaches pbp_layout through the local "layout" while split_editor gets the literal
 *    (SPLIT_EDITOR_OPEN), so the compiler loads it into two registers;
 *  - the sleep word (+4) is a bit-field view (bit 15, a 4-bit field, bit 10) as in osd_close_menu;
 *  - the right edge of the window is cast to unsigned short: (unsigned short)(split_x + 4).
 */

#define MENU_STATE_CLOSED           0
#define MENU_STATE_PBP_CUSTOM_SPLIT 0x109       /* the PBP custom split editor */
#define ALL_PORTS                   4           /* input_rearm_port_event: every port */
#define PBP_LAYOUT_CUSTOM           2           /* pbp_layout: the custom split (PBP_LAYOUT_*) */
#define SPLIT_EDITOR_OPEN           2           /* app_state_record +0x34 while the custom split editor is open */
#define SETTINGS_1EC_SPLIT_STORED   0x40        /* word +0x1EC bit 6: a custom split is stored in +0x1F0 / +0x1F2 */
#define SPLIT_WINDOW                6           /* menu window that shows the split line */
#define ACTIVE_SIZE_FIRST           0           /* panel_api_get_active_size selectors: first and second size field */
#define ACTIVE_SIZE_SECOND          1
#define SPLIT_LINE_WIDTH            4           /* the window is drawn from split_x to split_x + 4 */

/* The fields of the application state record used here. */
struct app_state_record {
    unsigned char pad[4];
    unsigned short bit15 : 1,                   /* sleep word (+4) bit 15: closing the menu re-arms the port events */
                   bits_11_14 : 4,
                   bit10 : 1,                   /* set together with that re-arm */
                   rest : 10;
    unsigned char pad6[0x34 - 6];
    unsigned char split_editor;                 /* +0x34: SPLIT_EDITOR_OPEN while the editor is open */
    unsigned char pad35;
    unsigned short split_x, split_lines;        /* +0x36 / +0x38: the split line of the editor (x, height) */
};

/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x2f];
    unsigned char pbp_layout;                   /* +0x2F: the PBP layout (PBP_LAYOUT_*) */
    unsigned char pad30[0x1ec - 0x30];
    unsigned int word_0x1ec;                    /* +0x1EC: SETTINGS_1EC_* */
    unsigned short custom_split_x, custom_split_lines;  /* +0x1F0 / +0x1F2: the stored custom split */
};
extern struct app_state_record app_state_record;
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern int dbg_printf();
extern unsigned short panel_api_get_active_size(int);
extern void input_rearm_port_event(unsigned char, unsigned char);
extern void osd_hide_menu(void);
extern void panel_wait_sync_pulse(void);
extern void osd_show_screen_overlays(unsigned char on);
extern void osd_api_set_window_enable(int, int, int);
extern void osd_api_set_window_effect(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                         unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void osd_api_set_window_rect(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

/*
 * OK on the 'Customize' item (menu state 0x81) of the PBP settings list: switch the PBP layout to the custom
 * split and open the split editor (menu state 0x109).
 *
 * Called through osd_menu_key_table (OK on state 0x81), by osd_run_periodic_task when its countdown ends on
 * state 0x81, and by uart_cmd_adjust_pbp_split (PC tool command digit 1, "open").
 *
 * In order:
 *   1. Print "PBP New Mode"; read the first and second size field of the active panel timing row.
 *   2. Close the menu (the steps of osd_close_menu), wait two sync pulses, redraw the screen overlays (the
 *      menu layer is gone) and set the menu state to 0x109.
 *   3. Window 6 is switched off, given its effect record, and the layout is set to the custom split with the
 *      editor marked open.
 *   4. The split line starts at the stored custom split (+0x1F0 / +0x1F2) when the settings mark one stored,
 *      else at half of the first size field and the second size field as its height.
 *   5. Window 6 gets the rectangle from the split x to x + 4 with that height, "(x y)" is printed with the
 *      split values, and the window is switched on.
 */
void osd_open_pbp_custom_split(void)
{
    unsigned short width, height;
    int layout;

    dbg_printf("PBP New Mode\r\n");
    width = panel_api_get_active_size(ACTIVE_SIZE_FIRST);
    height = panel_api_get_active_size(ACTIVE_SIZE_SECOND);
    if (app_state_record.bit15) {
        app_state_record.bit10 = 1;
        input_rearm_port_event(ALL_PORTS, 0);
    }
    osd_menu_state = MENU_STATE_CLOSED;
    osd_hide_menu();
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    osd_show_screen_overlays(1);
    osd_menu_state = MENU_STATE_PBP_CUSTOM_SPLIT;
    osd_api_set_window_enable(SPLIT_WINDOW, 0, 0);
    osd_api_set_window_effect(SPLIT_WINDOW, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    layout = PBP_LAYOUT_CUSTOM;
    user_settings.pbp_layout = layout;
    app_state_record.split_editor = SPLIT_EDITOR_OPEN;
    if (user_settings.word_0x1ec & SETTINGS_1EC_SPLIT_STORED) {
        app_state_record.split_x = user_settings.custom_split_x;
        app_state_record.split_lines = user_settings.custom_split_lines;
    } else {
        app_state_record.split_x = width / 2;
        app_state_record.split_lines = height;
    }
    osd_api_set_window_rect(SPLIT_WINDOW, app_state_record.split_x, 0, (unsigned short)(app_state_record.split_x + SPLIT_LINE_WIDTH), app_state_record.split_lines, 0);
    dbg_printf("(x y) %d, %d\n", app_state_record.split_x, app_state_record.split_lines);
    osd_api_set_window_enable(SPLIT_WINDOW, 1, 0);
}
