/* osd_select_next_refresh_rate_choice  (FUN_a009a8dc)
 *
 * Move to the next allowed Refresh Rate choice (down key) and apply on/off.
 * Note: Wraps inside the states 0x53..0x55; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: down on states 0x53..0x55; writes bit 12 of settings word
 *   +0xA8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009a8dc @ 0xa009a8dc, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk forward is written (u16)state - BASE + 1, taken modulo the choice count in a second statement;
 *  - the Refresh Rate bit is a one-bit field of the word at +0xA8, assigned from an unsigned int (only its lowest
 *    bit is kept);
 *  - osd_menu_state and osd_choice_row are read again for each use.
 */

#define MENU_STATE_REFRESH_RATE_CHOICES 0x53    /* + choice row: 0 Location, 1 OFF, 2 ON */
#define REFRESH_RATE_CHOICE_COUNT       3
#define CHOICE_MARK_LIST                1       /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON                  1
#define CHOICE_MARK_OFF                 0
#define CHOICE_ROW_EDGED                1       /* highlight style of a choice row */

/* Fields of the user settings record (docs/RECORDS.md) up to the word at +0xA8. */
struct user_settings_record {
    unsigned char p000[0xa8];
    unsigned int p_0xa8_hi : 19;
    unsigned int refresh_rate_display : 1;      /* +0xA8 bit 12: the Refresh Rate overlay is on */
    unsigned int p_0xa8_lo : 12;
};
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);

/*
 * Down key in the Refresh Rate choice list (rows Location, OFF, ON): move the highlight to the next row,
 * wrapping from the last row to the first. Rows that osd_is_choice_enabled rejects are skipped.
 *
 * Same as osd_select_prev_refresh_rate_choice except for the direction. The Refresh Rate switch (bit 12 of the
 * settings word at +0xA8) takes the lowest bit of the menu state (OFF row 0x54 gives 0, ON row 0x55 gives 1); on
 * the Location row the saved choice in osd_choice_row is written back. The mark of the saved choice (row
 * osd_choice_row + 1) is switched off while the highlight is on that row and on otherwise.
 */
void osd_select_next_refresh_rate_choice(void)
{
    int row;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_REFRESH_RATE_CHOICES);
    do {
        row = (unsigned short)osd_menu_state - MENU_STATE_REFRESH_RATE_CHOICES + 1;
        row = row % REFRESH_RATE_CHOICE_COUNT;
        osd_menu_state = row + MENU_STATE_REFRESH_RATE_CHOICES;
    } while (osd_is_choice_enabled(row) != 1);
    if (osd_menu_state > MENU_STATE_REFRESH_RATE_CHOICES)
        user_settings.refresh_rate_display = osd_menu_state;
    else
        user_settings.refresh_rate_display = osd_choice_row;
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_REFRESH_RATE_CHOICES, CHOICE_ROW_EDGED);
    if (osd_menu_state - MENU_STATE_REFRESH_RATE_CHOICES == osd_choice_row + 1)
        osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row + 1, CHOICE_MARK_OFF);
    else
        osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row + 1, CHOICE_MARK_ON);
}
