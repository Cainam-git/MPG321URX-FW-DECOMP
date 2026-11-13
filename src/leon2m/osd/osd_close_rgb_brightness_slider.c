/* osd_close_rgb_brightness_slider  (FUN_a0099b60)
 *
 * Close the RGB Brightness slider keeping the value (OK)
 * Note: Returns to state 0xB3.
 * Name basis: derived - handler table 0xA802422C: OK on state 0xF0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099b60 @ 0xa0099b60, flags -mcpu=v8 -O3 -g.
 * Source form: both parameters are declared; the second is not used. The routine returns its first parameter
 * unchanged. The RGB Brightness level is the byte at 0xA802D33C, declared as a byte of its own.
 */
extern unsigned char osd_edit_value;
extern unsigned char osd_request_bits;
extern unsigned char user_settings_settings_page_flags;
extern unsigned int osd_menu_state;

extern int osd_clear_choice_highlight();
extern int osd_highlight_choice_row();
extern void osd_draw_item_choices();

#define PAGE_SETTINGS_ITEMS      0x2a   /* first item state of the Settings page */
#define SETTINGS_ITEM_RGB_LED    3      /* item row of the RGB LED item in that page */
#define MENU_STATE_RGB_BRIGHTNESS_CHOICE 0xb3 /* the RGB Brightness row of the RGB LED list */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK on the RGB Brightness levels (menu state 0xF0): keep the level and go back to the RGB LED list.
 *
 * The highlight of the level's row is removed, the choice column of the RGB LED item is drawn again
 * (osd_draw_item_choices), the menu state returns to 0xB3 and its row (row 2) is highlighted. osd_edit_value is
 * cleared. The routine returns its first parameter unchanged.
 */
unsigned int osd_close_rgb_brightness_slider(unsigned int first_arg, char unused_arg)
{
    osd_clear_choice_highlight(user_settings_settings_page_flags);
    osd_draw_item_choices(PAGE_SETTINGS_ITEMS, SETTINGS_ITEM_RGB_LED);
    osd_menu_state = MENU_STATE_RGB_BRIGHTNESS_CHOICE;
    osd_highlight_choice_row(2, CHOICE_ROW_EDGED);
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
    osd_edit_value = 0;
    return first_arg;
}
