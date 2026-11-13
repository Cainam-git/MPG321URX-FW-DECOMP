/* osd_select_prev_night_vision  (FUN_a0095bcc)
 *
 * Highlight and apply the previous allowed Night Vision level (up key)
 * Note: Applies the level at once (sys_user_apply_dimming_mode) so the picture previews it.
 * Name basis: derived - handler table 0xA802422C: up on states 0x4E..0x52
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095bcc @ 0xa0095bcc-0xa0095c94 (50 words), flags -mcpu=v8 -O3 -g.
 * Source form: the new level is computed from the low halfword of osd_menu_state, so the remainder by 5 is
 * a signed one. The argument of osd_is_choice_enabled is level - 5, as in the firmware. The settings record is
 * a byte array. Twin of osd_select_next_night_vision, which differs only in the constant 0x4a / 0x4d.
 */
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern void sys_user_apply_dimming_mode(void);

#define MENU_STATE_NIGHT_VISION_LIST 0x4e       /* + level: the Night Vision list, one state per level */
#define NIGHT_VISION_LEVEL_COUNT     5          /* levels 0..4 */
#define USER_SETTINGS_NIGHT_VISION   0x15b      /* offset of the Night Vision byte in the settings record */
#define CHOICE_MARK_LIST             1          /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON               1
#define CHOICE_MARK_OFF              0
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row in the open list */

/*
 * Up key in the Night Vision list: step to the previous level, skipping levels that osd_is_choice_enabled does not
 * accept, wrapping from the first level to the last.
 *
 * The new level is stored in the menu state (0x4E + level) and in the settings, and applied at once through
 * sys_user_apply_dimming_mode. The new row is highlighted. The mark of the level saved on entry (osd_choice_row) is
 * cleared when the new level is that one and drawn otherwise.
 */
void osd_select_prev_night_vision(void)
{
  int level;

  osd_clear_choice_highlight(osd_menu_state - MENU_STATE_NIGHT_VISION_LIST);
  do {
    level = (unsigned short)osd_menu_state - (MENU_STATE_NIGHT_VISION_LIST - 4);   /* current level + 4 */
    level = level % NIGHT_VISION_LEVEL_COUNT;
    osd_menu_state = level + MENU_STATE_NIGHT_VISION_LIST;
  } while (osd_is_choice_enabled(level - NIGHT_VISION_LEVEL_COUNT) != 1);
  user_settings[USER_SETTINGS_NIGHT_VISION] = osd_menu_state - MENU_STATE_NIGHT_VISION_LIST;
  sys_user_apply_dimming_mode();
  osd_highlight_choice_row(osd_menu_state - MENU_STATE_NIGHT_VISION_LIST, CHOICE_ROW_EDGED);
  {
    unsigned char saved_level = osd_choice_row;
    if (osd_menu_state - MENU_STATE_NIGHT_VISION_LIST == saved_level)
      osd_draw_choice_mark(CHOICE_MARK_LIST, saved_level, CHOICE_MARK_OFF);
    else
      osd_draw_choice_mark(CHOICE_MARK_LIST, saved_level, CHOICE_MARK_ON);
  }
}
