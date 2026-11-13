/* osd_open_main_menu  (FUN_a00911a0)
 *
 * Open the main menu with the first entry highlighted.
 * Note: Does nothing while bit 10 of 0xA802CFF4 is set or port 0 is not in raw state 0xC.
 * Name basis: proven - sets menu state 1 or 2, draws the menu frame and tab column; reached through the action
 *   table; key role from the menu state handler table 0xA802422C, tab texts 0x196DC0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00911a0, flags -mcpu=v8 -O3 -g.
 * Reached through the menu key table, no direct caller.
 */

#define APP_STATE_FLAGS_BIT10    0x400          /* bit 10 of the halfword at app_state_record + 0 */
#define SETTINGS_FACTORY_MODE    0x4000         /* bit 14 of the first settings word */
#define CHANNEL_STATE_0C         0x0c           /* the state of channel 0 in which the menu opens */
#define MENU_STATE_FACTORY_ENTRY 1              /* the extra top entry shown in factory mode */
#define MENU_STATE_TAB_FIRST     2              /* the first main tab row (tab 0); tab n is state 2 + n */
#define OSD_SYMBOL_TEXT_F        8              /* entry 8 of osd_symbol_texts */

extern unsigned short app_state_record;
extern unsigned int user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_list_id;
extern unsigned int osd_symbol_texts[];
extern unsigned char sys_get_channel_state(unsigned char);
extern void osd_draw_main_menu_frame(void);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, int, unsigned int, int, unsigned int, int);
extern void osd_highlight_tab(unsigned char, int);
extern void osd_draw_tab_page(unsigned char);
extern void osd_show_menu_layer(void);

/*
 * Open the main menu. Nothing happens when bit 10 of the application state flags is set or channel 0 is not in
 * state 0x0C. Otherwise the frame is drawn and one of two entries is shown: in factory mode (bit 14 of the
 * first settings word) the menu state becomes 1 and the text F (osd_symbol_texts entry 8) is drawn at cell
 * (1, 4); else the menu state becomes 2 and tab 0 is highlighted. Then the page of tab 0 is drawn and the menu
 * layer is switched on.
 */
void osd_open_main_menu(void)
{
    if (app_state_record & APP_STATE_FLAGS_BIT10)
        return;
    if (sys_get_channel_state(0) != CHANNEL_STATE_0C)
        return;
    osd_draw_main_menu_frame();
    if (user_settings & SETTINGS_FACTORY_MODE) {
        osd_menu_state = MENU_STATE_FACTORY_ENTRY;
        osd_list_id = 0;
        osd_api_set_glyph_write_address(0xfe, 0);
        osd_api_set_text_mode(0, 0);
        osd_api_fill_cells(1, 4, 1, 0x592, 0);
        osd_draw_text(0, 1, 4, 1, osd_get_text(osd_symbol_texts, OSD_SYMBOL_TEXT_F), 0);
    } else {
        osd_menu_state = MENU_STATE_TAB_FIRST;
        osd_highlight_tab(0, 1);
    }
    osd_draw_tab_page(0);
    osd_show_menu_layer();
}
