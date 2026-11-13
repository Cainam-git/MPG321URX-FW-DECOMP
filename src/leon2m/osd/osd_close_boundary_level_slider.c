/* osd_close_boundary_level_slider  (FUN_a00a27a4)
 *
 * Keep the Boundary Detection level, apply it and close the slider (OK)
 * Note: Stores settings byte +0x1ED; returns to state 0xC2, row 2.
 * Name basis: derived - handler table 0xA802422C: OK on state 0xF9
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a27a4, flags -mcpu=v8 -O3 -g.
 * Source form: the fixed call sequence is written out as in the firmware; the settings array is reached as
 * bytes, and the 0xFF store (settings +0x189) comes before osd_draw_adjust_key_guide (the compiler places it
 * in that call's delay slot). osd_request_bits is written as 'x = x | 2'.
 * Same code as the other two level slider handlers of the OLED Care detections, with other constants.
 */
extern unsigned char osd_edit_value;
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char osd_request_bits;
extern unsigned char user_settings[];

extern void osd_clear_choice_highlight(unsigned int);
extern void osd_clear_choice_column(void);
extern void osd_draw_oled_care_choices(unsigned int);
extern void osd_highlight_choice_row(unsigned int, unsigned int);
extern void osd_draw_adjust_key_guide(void);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_draw_key_guide_text(unsigned int);
extern void osd_update_key_guide(unsigned int, unsigned int);
extern void oled_user_apply_pillar_box(void);

#define MENU_STATE_BOUNDARY_CHOICES    0xc2     /* the OFF / ON / level choices of Boundary Detection */
#define MENU_STATE_BOUNDARY_ITEM    0x3a     /* its item on the OLED Care page */
#define SETTINGS_LEVEL  0x1ed     /* settings byte: the Boundary Detection level */
#define SETTINGS_KEY_GUIDE_SHOWN 0x189  /* settings byte: the key guide texts last shown (two nibbles) */
#define CHOICE_ROW_LEVEL         2      /* the level row of the OFF / ON / level choices */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */
#define KEY_TEXT_MOVE            0      /* key guide texts: Move, Enter, Back */
#define KEY_TEXT_ENTER           1
#define KEY_TEXT_BACK            7
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit 1 of osd_request_bits */

/*
 * OK on the Boundary Detection level slider (menu state 0xF9): keep the level the slider shows (osd_edit_value)
 * in the settings (byte +0x1ed), apply it (oled_user_apply_pillar_box) and go back to the choices of Boundary
 * Detection
 * (menu state 0xc2) with the level row (row 2) highlighted.
 *
 * Going back clears the choice column, redraws the OLED Care choices of the item, highlights the level row,
 * sets the last shown key guide byte (settings +0x189) to 0xFF, redraws the key guide for adjustable values
 * and the texts Move and Enter, and sets the settings-changed request.
 */
void osd_close_boundary_level_slider(void)
{
    user_settings[SETTINGS_LEVEL] = osd_edit_value;
    osd_choice_row = CHOICE_ROW_LEVEL;
    osd_clear_choice_highlight(0);
    osd_clear_choice_column();
    osd_menu_state = MENU_STATE_BOUNDARY_CHOICES;
    osd_draw_oled_care_choices(MENU_STATE_BOUNDARY_ITEM);
    osd_highlight_choice_row(osd_choice_row, CHOICE_ROW_EDGED);
    user_settings[SETTINGS_KEY_GUIDE_SHOWN] = 0xff;
    osd_draw_adjust_key_guide();
    osd_draw_key_guide(1, 2);
    osd_draw_key_guide(2, 5);
    osd_draw_key_guide(0, 0);
    osd_draw_key_guide_text(KEY_TEXT_BACK);
    osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
    oled_user_apply_pillar_box();
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
