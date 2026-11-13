/* osd_open_detection_level_slider  (FUN_a00a231c)
 *
 * Open the level slider when the level row is highlighted (right key)
 * Note: Copies the stored level into the slider value first.
 * Name basis: derived - handler table 0xA802422C: right on states 0xC0..0xC2
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a231c, flags -mcpu=v8 -O3 -g.
 * Source form: the three menu states are tested in an if / else if chain after the choice row test; the slider
 * is shown after the chain whatever the state.
 */
extern unsigned char osd_choice_row, osd_edit_value;
extern unsigned int osd_menu_state;
extern unsigned char user_settings_multi_logo_level, user_settings_taskbar_level, user_settings_boundary_level;
extern void osd_show_detection_level_slider(void);

#define MENU_STATE_MULTI_LOGO_CHOICES   0xc0
#define MENU_STATE_TASKBAR_CHOICES      0xc1
#define MENU_STATE_BOUNDARY_CHOICES     0xc2
#define CHOICE_ROW_LEVEL                2       /* the level row of the OFF / ON / level choices */

/*
 * Right key in the choices of Multi Logo, Taskbar or Boundary Detection (menu states 0xC0 to 0xC2): when the
 * level row (row 2) is highlighted, copy the stored level of that detection into osd_edit_value and show the
 * level slider (osd_show_detection_level_slider). On another row nothing happens.
 */
void osd_open_detection_level_slider(void)
{
    if (osd_choice_row == CHOICE_ROW_LEVEL) {
        if (osd_menu_state == MENU_STATE_MULTI_LOGO_CHOICES)
            osd_edit_value = user_settings_multi_logo_level;
        else if (osd_menu_state == MENU_STATE_TASKBAR_CHOICES)
            osd_edit_value = user_settings_taskbar_level;
        else if (osd_menu_state == MENU_STATE_BOUNDARY_CHOICES)
            osd_edit_value = user_settings_boundary_level;
        osd_show_detection_level_slider();
    }
}
