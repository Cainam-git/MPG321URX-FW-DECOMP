/* osd_open_panel_protect_dialog  (FUN_a0099c64)
 *
 * Open the Panel Protect question (Execute, Cancel, Later, More Info)
 * Note: Closes the menu and shows the dialog in state 0x10A.
 * Name basis: derived - handler table 0xA802422C: OK on state 0x35 = 'Panel Protect' (MSI OLED Care texts
 *   0x185E78); texts 0x190184
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099c64 @ 0xa0099c64-0xa0099cfc (38 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Source form: the single bits are 1-bit bit-fields. The body of osd_close_menu (osd_close_menu) is written out
 * as a static routine of this file.
 */
union app_state_half { unsigned short h; struct { unsigned short b15 : 1, rest : 15; } f; };
/* The fields of the application state record used here. */
struct app_state_record_layout {
    unsigned char pad[4];
    union app_state_half half_0x4;              /* +0x04: bit 15 and bit 10 are used by the menu close */
    unsigned char pad6[8];
    union app_state_half half_0xe;              /* +0x0E: bit 15 is cleared when the dialog opens */
    unsigned char pad10[0x2f];
    unsigned char dialog_button_index;          /* +0x3F: the selected button of a dialog */
};
/* The fields of the settings record used here. */
struct user_settings_record {
    unsigned char pad[0x1dc];
    unsigned int panel_protect_run : 1, rest : 31; /* +0x1DC: bit 31 = Panel Protect run */
    unsigned char pad1e0[4];
    unsigned char byte_0x1e4;                   /* +0x1E4 */
};
extern struct app_state_record_layout app_state_record;
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_choice_row;
extern void input_rearm_port_event(int, int);
extern void osd_hide_menu(void);
extern void osd_draw_panel_protect_dialog(unsigned char, int);

#define APP_STATE_HALF4_BIT10    0x400  /* bit 10 of the halfword at app_state_record + 4 */
#define ALL_PORTS                4      /* input_rearm_port_event: port 4 stands for all ports */
#define MENU_STATE_CLOSED        0
#define MENU_STATE_PANEL_PROTECT 0x10a  /* the Panel Protect question */

/* The body of osd_close_menu: close the menu and hide the menu layer. */
static void osd_close_menu(void)
{
    if (app_state_record.half_0x4.f.b15) {
        app_state_record.half_0x4.h |= APP_STATE_HALF4_BIT10;
        input_rearm_port_event(ALL_PORTS, 0);
    }
    osd_menu_state = MENU_STATE_CLOSED;
    osd_hide_menu();
}

/*
 * OK on the Panel Protect item of the MSI OLED Care page: close the menu and show the Panel Protect question
 * (Execute, Cancel, Later, More Info) in menu state 0x10A.
 *
 * Cleared first: bit 31 of settings word +0x1DC (Panel Protect run), bit 15 of the halfword at
 * app_state_record + 0xE and osd_choice_row. Then the menu is closed, the dialog button index and settings byte
 * +0x1E4 are cleared and the dialog page is drawn (osd_draw_panel_protect_dialog with the cleared osd_choice_row
 * and 4).
 */
void osd_open_panel_protect_dialog(void)
{
    user_settings.panel_protect_run = 0;
    app_state_record.half_0xe.f.b15 = 0;
    osd_choice_row = 0;
    osd_close_menu();
    app_state_record.dialog_button_index = 0;
    user_settings.byte_0x1e4 = 0;
    osd_draw_panel_protect_dialog(osd_choice_row, 4);
    osd_menu_state = MENU_STATE_PANEL_PROTECT;
}
