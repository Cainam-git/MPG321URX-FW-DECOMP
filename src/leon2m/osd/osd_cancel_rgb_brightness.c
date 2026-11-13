/* osd_cancel_rgb_brightness  (FUN_a0099bb4)
 *
 * Restore the RGB Brightness saved on entry, send it to the light bar and go back.
 * Note: Applies with UserSetAuroraLEDBarBrightness (UserSetAuroraLEDBarBrightness).
 * Name basis: derived - handler table 0xA802422C: left on state 0xF0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099bb4 @ 0xa0099bb4, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a byte array; the RGB Brightness level is user_settings[0xac].
 */
extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern int osd_clear_choice_highlight();
extern void osd_draw_item_choices(unsigned int, unsigned int);
extern void osd_highlight_choice_row(unsigned int, unsigned int);
extern void UserSetAuroraLEDBarBrightness(unsigned char);

#define USER_SETTINGS_RGB_BRIGHTNESS 0xac /* first byte of settings word +0xAC: the RGB Brightness level */
#define PAGE_SETTINGS_ITEMS      0x2a   /* first item state of the Settings page */
#define SETTINGS_ITEM_RGB_LED    3      /* item row of the RGB LED item in that page */
#define MENU_STATE_RGB_BRIGHTNESS_CHOICE 0xb3 /* the RGB Brightness row of the RGB LED list */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * Left key on the RGB Brightness levels (menu state 0xF0): put back the level saved on entry and go back to the
 * RGB LED list.
 *
 * The highlight of the row of the level now stored is removed, the saved level (osd_edit_value) is written back
 * and the choice column of the RGB LED item is drawn again. The menu state returns to 0xB3 with its row (row 2)
 * highlighted, the restored level is sent to the LED light bar (UserSetAuroraLEDBarBrightness) and osd_edit_value
 * is cleared.
 */
void osd_cancel_rgb_brightness(void)
{
    osd_clear_choice_highlight(user_settings[USER_SETTINGS_RGB_BRIGHTNESS]);
    user_settings[USER_SETTINGS_RGB_BRIGHTNESS] = osd_edit_value;
    osd_draw_item_choices(PAGE_SETTINGS_ITEMS, SETTINGS_ITEM_RGB_LED);
    osd_menu_state = MENU_STATE_RGB_BRIGHTNESS_CHOICE;
    osd_highlight_choice_row(2, CHOICE_ROW_EDGED);
    UserSetAuroraLEDBarBrightness(user_settings[USER_SETTINGS_RGB_BRIGHTNESS]);
    osd_edit_value = 0;
}
