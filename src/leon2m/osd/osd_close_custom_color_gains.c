/* osd_close_custom_color_gains  (FUN_a009665c)
 *
 * Leave the R/G/B gain editor and return to Customization (OK on the B row)
 * Note: Returns to state 0x6F.
 * Name basis: derived - handler table 0xA802422C: OK on state 0xCC (B row)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009665c @ 0xa009665c-0xa0096704 (42 words), flags -mcpu=v8 -O3 -g.
 * Source form: the blue gain is copied to +0x8E before osd_choice_row is stored (the other order loads the
 * Color Temperature byte first). The settings record is a byte array. The routine has no parameters.
 * osd_clear_choice_column runs before osd_draw_color_temp_choices.
 */
extern unsigned char osd_choice_row;
extern unsigned char user_settings[];
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_draw_color_temp_choices(void);
extern void osd_clear_choice_column(void);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_adjust_key_guide(void);
extern void osd_draw_key_guide_text(unsigned int);
extern void osd_update_key_guide(unsigned int, unsigned int);

#define USER_SETTINGS_COLOR_TEMP      0x11      /* Color Temperature */
#define USER_SETTINGS_BLUE_GAIN       0x14      /* custom blue gain */
#define USER_SETTINGS_GAIN_COPY_BLUE  0x8e      /* copy of the blue gain (red +0x8C, green +0x8D) */
#define MENU_STATE_COLOR_TEMP_LIST    0x6c      /* + choice: the Color Temperature list (states 0x6C..0x6F) */
#define MENU_STATE_CUSTOMIZATION      0x6f      /* list state of the choice Customization */
#define COLOR_TEMP_CUSTOMIZATION      3         /* Color Temperature choice "Customization" */
#define CHOICE_MARK_LIST              1         /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_OFF               0
#define CHOICE_ROW_PLAIN              0         /* highlight style of a choice row while the list is left */
#define CHOICE_ROW_EDGED              1         /* highlight style of a choice row in the open list */

/*
 * OK on the blue row of the gain editor: leave the editor and show the Color Temperature list again with
 * Customization highlighted (menu state 0x6F).
 *
 * The blue gain is copied to +0x8E and the Color Temperature value is saved in osd_choice_row. The choice column
 * is cleared and the list redrawn, the mark of the Color Temperature value is cleared, choice row 3 is
 * highlighted in the plain style and then the row of the new state (also row 3) in the edged style. Last, the key
 * guide is redrawn: the adjust guide, three calls of osd_draw_key_guide, the two texts that changed, and the key
 * guide text 7.
 */
void osd_close_custom_color_gains(void)
{
    user_settings[USER_SETTINGS_GAIN_COPY_BLUE] = user_settings[USER_SETTINGS_BLUE_GAIN];
    osd_choice_row = user_settings[USER_SETTINGS_COLOR_TEMP];
    osd_clear_choice_column();
    osd_draw_color_temp_choices();
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings[USER_SETTINGS_COLOR_TEMP], CHOICE_MARK_OFF);
    osd_menu_state = MENU_STATE_CUSTOMIZATION;
    osd_highlight_choice_row(COLOR_TEMP_CUSTOMIZATION, CHOICE_ROW_PLAIN);
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_COLOR_TEMP_LIST, CHOICE_ROW_EDGED);
    osd_draw_adjust_key_guide();
    osd_draw_key_guide(2, 5);
    osd_draw_key_guide(0, 0);
    osd_draw_key_guide(1, 2);
    osd_update_key_guide(0, 1);
    osd_draw_key_guide_text(7);
}
