/* osd_switch_power_button_choice  (FUN_a009d8f4)
 *
 * Move the highlight to the other Power Button choice and store it.
 * Note: Copies the row into bit 15 of settings word +0xA8 at once; the byte-identical copy
 *   osd_switch_power_button_choice_copy serves the down key.
 * Name basis: derived - handler table 0xA802422C: up on states 0xB4/0xB5 (2 rows)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009d8f4 @ 0xa009d8f4, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - (BASE - 1), taken modulo 2 in a second statement (both directions are the same step);
 *  - the switch is a one-bit field of the word at +0xA8, assigned from (unsigned char)(state + (256 - BASE)), so
 *    only the lowest bit of the row is kept; osd_choice_row is copied into a block-scope local.
 */

#define MENU_STATE_POWER_BUTTON_LIST    0xb4    /* + row: the two Power Button choices */
#define POWER_BUTTON_COUNT              2
#define CHOICE_MARK_LIST            1           /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON              1
#define CHOICE_MARK_OFF             0
#define CHOICE_ROW_EDGED            1           /* highlight style of a choice row */

/* Fields of the user settings record (docs/RECORDS.md) up to the word at +0xA8. */
struct user_settings_record {
    unsigned char p000[0xa8];
    unsigned int p_0xa8_hi : 16;
    unsigned int power_button_standby : 1;      /* +0xA8 bit 15 (SETTINGS_POWER_BUTTON_STANDBY, 0x8000) */
    unsigned int p_0xa8_lo : 15;
};
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern struct user_settings_record user_settings;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);

/*
 * Up or down key on the two Power Button choices: move the highlight to the other row (with two rows both keys
 * do the same). Serves the up key; osd_switch_power_button_choice_copy is a byte-identical copy for the down key.
 * Rows that osd_is_choice_enabled rejects are skipped.
 *
 * The lowest bit of the new row is stored at once in bit 15 of the settings word at +0xA8. The mark is drawn at
 * the row of osd_choice_row (the value saved on entry); it is switched off while the highlight is on that row
 * and on otherwise.
 */
void osd_switch_power_button_choice(void)
{
  int row;

  osd_clear_choice_highlight(osd_menu_state + (256 - MENU_STATE_POWER_BUTTON_LIST));
  do {
    row = (unsigned short)osd_menu_state - (MENU_STATE_POWER_BUTTON_LIST - 1);
    row = row % POWER_BUTTON_COUNT;
    osd_menu_state = row + MENU_STATE_POWER_BUTTON_LIST;
  } while (osd_is_choice_enabled(row) != 1);
  user_settings.power_button_standby = (unsigned char)(osd_menu_state + (256 - MENU_STATE_POWER_BUTTON_LIST));
  osd_highlight_choice_row(osd_menu_state + (256 - MENU_STATE_POWER_BUTTON_LIST), CHOICE_ROW_EDGED);
  {
    unsigned char saved = osd_choice_row;
    if (osd_menu_state - MENU_STATE_POWER_BUTTON_LIST == saved)
      osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_OFF);
    else
      osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_ON);
  }
}
