/* osd_open_custom_color_gains  (FUN_a0096610)
 *
 * Open the R/G/B gain editor of the Customization colour temperature.
 * Note: Selects Customization in settings byte +0x11 and copies the gains to edit bytes +0x8C..+0x8E; state
 *   0xCA.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x6F = 'Customization'; row texts 0x197D08
 *   R, G, B
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0096610 @ 0xa0096610-0xa009665c (19 words), flags -mcpu=v8 -O3 -g.
 * Sibling of osd_close_custom_color_gains (osd_close_custom_color_gains).
 * Source form: the settings record is a byte array addressed from its base, no parameters are forwarded, and the
 * stores are written in ascending record-offset order with the osd_menu_state store last (the scheduler then
 * emits them in the firmware's order).
 */
extern unsigned char user_settings[];
extern unsigned int osd_menu_state;
extern void osd_draw_custom_color_page(void);
extern void osd_highlight_choice_row(unsigned char, int);

#define USER_SETTINGS_COLOR_TEMP      0x11      /* Color Temperature */
#define USER_SETTINGS_RED_GAIN        0x12      /* custom red gain; green gain +0x13, blue gain +0x14 */
#define USER_SETTINGS_GREEN_GAIN      0x13
#define USER_SETTINGS_BLUE_GAIN       0x14
#define USER_SETTINGS_GAIN_COPY_RED   0x8c      /* copies of the three gains; green +0x8D, blue +0x8E */
#define USER_SETTINGS_GAIN_COPY_GREEN 0x8d
#define USER_SETTINGS_GAIN_COPY_BLUE  0x8e
#define COLOR_TEMP_CUSTOMIZATION      3         /* Color Temperature choice "Customization" */
#define MENU_STATE_GAIN_EDITOR_RED    0xca      /* gain editor, red row (green 0xCB, blue 0xCC) */
#define CHOICE_ROW_EDGED              1         /* highlight style of a choice row in the open list */

/*
 * OK on Customization in the Color Temperature list: open the editor of the red, green and blue gains.
 *
 * Color Temperature is set to Customization. The three custom gains are copied to the bytes +0x8C..+0x8E, the
 * menu state becomes 0xCA (the red row of the editor), the custom colour page is drawn and choice row 0 is
 * highlighted.
 */
void osd_open_custom_color_gains(void)
{
    user_settings[USER_SETTINGS_COLOR_TEMP] = COLOR_TEMP_CUSTOMIZATION;
    user_settings[USER_SETTINGS_GAIN_COPY_RED] = user_settings[USER_SETTINGS_RED_GAIN];
    user_settings[USER_SETTINGS_GAIN_COPY_GREEN] = user_settings[USER_SETTINGS_GREEN_GAIN];
    user_settings[USER_SETTINGS_GAIN_COPY_BLUE] = user_settings[USER_SETTINGS_BLUE_GAIN];
    osd_menu_state = MENU_STATE_GAIN_EDITOR_RED;
    osd_draw_custom_color_page();
    osd_highlight_choice_row(0, CHOICE_ROW_EDGED);
}
