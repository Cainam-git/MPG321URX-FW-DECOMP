/* osd_decrease_rgb_brightness  (FUN_a009e348)
 *
 * Lower the RGB LED brightness one step (0..4) and send it to the LED bar.
 * Note: Byte 0xA802D33C; sends it with UserSetAuroraLEDBarBrightness (UserSetAuroraLEDBarBrightness).
 * Name basis: proven - handler table 0xA802422C: up on state 0xF0 (RGB Brightness slider)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009e348, flags -mcpu=v8 -O3 -g.
 * Source form: the level is reached as a byte of the settings array on every use (rgb_brightness is a macro),
 * and the saved level is held in a local that is read once.
 */
extern unsigned char user_settings[];
extern unsigned char osd_edit_value;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void UserSetAuroraLEDBarBrightness(unsigned char);

/* The RGB Brightness level: the first byte of settings word +0xAC. Levels 0 to 4. */
#define rgb_brightness      user_settings[0xac]
#define RGB_BRIGHTNESS_MAX  4

#define CHOICE_ROW_EDGED    1                   /* osd_highlight_choice_row style: with edge glyphs */
#define CHOICE_MARK_LIST    1                   /* osd_draw_choice_mark: mark in a choice list */
#define CHOICE_MARK_OFF     0
#define CHOICE_MARK_ON      1

/*
 * Up key on the RGB Brightness levels (menu state 0xF0):
 * lower the level by one step (from 0 it wraps to the highest level),
 * send it to the LED bar (UserSetAuroraLEDBarBrightness) and move the highlight to the new row.
 *
 * osd_edit_value holds the level that was stored when the list was opened. The mark of that level is cleared
 * while the cursor is on it and drawn again when the cursor is on another level.
 */
void osd_decrease_rgb_brightness(void)
{
    osd_clear_choice_highlight(rgb_brightness);
    if (rgb_brightness != 0)
        rgb_brightness--;
    else
        rgb_brightness = RGB_BRIGHTNESS_MAX;
    UserSetAuroraLEDBarBrightness(rgb_brightness);
    osd_highlight_choice_row(rgb_brightness, CHOICE_ROW_EDGED);
    {
        unsigned char saved_level = osd_edit_value;
        if (rgb_brightness == saved_level)
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved_level, CHOICE_MARK_OFF);
        else
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved_level, CHOICE_MARK_ON);
    }
}
