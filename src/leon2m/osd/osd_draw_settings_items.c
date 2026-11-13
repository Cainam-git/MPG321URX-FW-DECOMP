/* osd_draw_settings_items  (FUN_a00ad1c0)
 *
 * Draw the Settings items (Language .. Reset) and their states.
 *   mode: draw mode
 * Name basis: proven - texts 0x1874F8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ad1c0 @ 0xa00ad1c0-0xa00ad460 (168 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the page-0 loop limit is a local (n = 7; i < n gives the cmp 7 / bcc exit test); the two final
 * mode tests are separate ifs (the mode 0 calls are then not tail calls).
 */
#define LANGUAGE_COUNT 29        /* languages per text entry */
#define SETTINGS_ITEMS_PER_PAGE 7
#define SETTINGS_ITEM_COLUMN 0x14

/* Settings record (user_settings): the menu language. */
struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;  /* +8 */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_settings_item_texts[];
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void panel_wait_sync_pulse(void);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_api_fill_cells(unsigned int, unsigned int, unsigned char, unsigned int, unsigned char);
extern void osd_api_set_window_enable(int, int, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, int, unsigned short, int, unsigned int, int);
extern void osd_draw_cell_run(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                         unsigned int);
extern void osd_draw_info_on_screen_switch(void);
extern void osd_draw_hdmi_cec_switch(void);
extern void osd_draw_type_c_pd_charge_switch(void);
extern void osd_draw_power_led_switch(void);

/* Redraw the item area of the Settings tab, which has ten items on two pages.
 *   mode: 0 draws page 0 (items 0..6, Language .. HDMI CEC) with the Info On Screen and HDMI CEC
 *         switches; any other value draws page 1 (items 7..9, Type C PD Charge, Power LED, Reset)
 *         with the Type C PD Charge and Power LED switches (the caller passes 1).
 * The item area (rows 5..0x14) is cleared first. Items for which osd_is_item_enabled() returns 0
 * get their cells filled with 0x292 before the name is drawn. Item i is on row
 * (i % 7) * 2 + 6. Called again when the item cursor moves to the other page. */
void osd_draw_settings_items(unsigned char mode)
{
    unsigned char i;
    unsigned char n = SETTINGS_ITEMS_PER_PAGE;

    osd_api_set_glyph_write_address(0x92, 0);
    panel_wait_sync_pulse();
    for (i = 5; i <= 0x14; i++) {
        osd_api_fill_cell_bytes(0, 0x13, i, 0x13, 0, 0);
        osd_api_fill_cells(0x13, i, 0x13, 0x792, 0);
    }
    osd_api_fill_cell_bytes(0, 0x1c, 0x15, 2, 0, 0);
    osd_api_set_window_enable(5, 0, 0);
    osd_api_set_text_mode(0, 0);
    if (mode == 0) {
        for (i = 0; i < n; i++) {
            if (!osd_is_item_enabled(i))
                osd_api_fill_cells(SETTINGS_ITEM_COLUMN, i * 2 + 6, 0xd, 0x292, 0);
            osd_draw_text(0, SETTINGS_ITEM_COLUMN, i * 2 + 6, 1, osd_get_text(osd_settings_item_texts, i * LANGUAGE_COUNT + user_settings.language), 0);
        }
    } else {
        for (i = 7; i <= 9; i++) {
            if (!osd_is_item_enabled(i))
                osd_api_fill_cells(SETTINGS_ITEM_COLUMN, (i % 7) * 2 + 6, 0xd, 0x292, 0);
            osd_draw_text(0, SETTINGS_ITEM_COLUMN, i * 2 - 8, 1, osd_get_text(osd_settings_item_texts, i * LANGUAGE_COUNT + user_settings.language), 0);
        }
    }
    osd_draw_cell_run(1, 1, 0x792, 0x1c, 0x15, 2, 0x28);
    if (mode == 0) {
        osd_draw_info_on_screen_switch();
        osd_draw_hdmi_cec_switch();
    }
    if (mode == 1) {
        osd_draw_type_c_pd_charge_switch();
        osd_draw_power_led_switch();
    }
}
