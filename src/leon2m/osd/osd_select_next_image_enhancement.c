/* osd_select_next_image_enhancement  (FUN_a009c590)
 *
 * Move to the next allowed Image Enhancement level (down key) and preview it.
 * Note: Wraps inside the states 0x64..0x68; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: down on states 0x64..0x68; writes settings halfword +0x34,
 *   applies with sys_user_apply_channel0_scaling_mode/FUN_a00d58d8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009c590 @ 0xa009c590, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - (BASE - 1), taken modulo the count in a second statement;
 *  - the level is a 4-bit field of the settings record (bits 16..19 of the word at +0x34, big-endian), assigned from
 *    an unsigned int; the channel 0 scaling call comes before the channel 1 call;
 *  - osd_choice_row is copied into a block-scope local for the compare and the mark row.
 */

#define MENU_STATE_IMAGE_ENHANCEMENT_LIST 100   /* + row: the five Image Enhancement levels */
#define IMAGE_ENHANCEMENT_COUNT     5
#define CHOICE_MARK_LIST            1           /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON              1
#define CHOICE_MARK_OFF             0
#define CHOICE_ROW_EDGED            1           /* highlight style of a choice row */

/* Fields of the user settings record (docs/RECORDS.md) up to the halfword at +0x34. */
struct user_settings_record {
    unsigned char p000[0x34];
    unsigned int p_0x34_hi : 12;
    unsigned int image_enhancement : 4;         /* +0x34 bits 0..3 of the halfword: the Image Enhancement level */
    unsigned int p_0x36 : 16;
};
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern struct user_settings_record user_settings;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern void sys_user_save_mode_slot(void);
extern void sys_user_apply_channel1_scaling_mode(void);
extern void sys_user_apply_channel0_scaling_mode(void);

/*
 * Down key in the Image Enhancement list: move the highlight to the next level, wrapping from the last to the first.
 * Levels that osd_is_choice_enabled rejects are skipped.
 *
 * The row number is stored as the Image Enhancement level at once and applied: the scaling mode of channel 0 and
 * of channel 1 is applied and the picture mode slot is saved. The mark is drawn at the row of the level saved on
 * entry (osd_choice_row); it is switched off while the highlight is on that row and on otherwise.
 */
void osd_select_next_image_enhancement(void)
{
  int row;

  osd_clear_choice_highlight(osd_menu_state - MENU_STATE_IMAGE_ENHANCEMENT_LIST);
  do {
    row = (unsigned short)osd_menu_state - (MENU_STATE_IMAGE_ENHANCEMENT_LIST - 1);
    row = row % IMAGE_ENHANCEMENT_COUNT;
    osd_menu_state = row + MENU_STATE_IMAGE_ENHANCEMENT_LIST;
  } while (osd_is_choice_enabled(row) != 1);
  user_settings.image_enhancement = osd_menu_state - MENU_STATE_IMAGE_ENHANCEMENT_LIST;
  sys_user_apply_channel0_scaling_mode();
  sys_user_apply_channel1_scaling_mode();
  sys_user_save_mode_slot();
  osd_highlight_choice_row(osd_menu_state - MENU_STATE_IMAGE_ENHANCEMENT_LIST, CHOICE_ROW_EDGED);
  {
    unsigned char saved = osd_choice_row;
    if (osd_menu_state - MENU_STATE_IMAGE_ENHANCEMENT_LIST == saved)
      osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_OFF);
    else
      osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_ON);
  }
}
