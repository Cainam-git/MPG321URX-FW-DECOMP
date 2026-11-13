/* osd_select_prev_static_screen_start_time  (FUN_a009e5ac)
 *
 * Move to the previous 'Starting in' time (up key) and store it.
 * Note: Settings byte +0x1E0, values 0..1 (0 wraps to 1).
 * Name basis: derived - handler table 0xA802422C: up on state 0xF4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009e5ac, flags -mcpu=v8 -O3 -g.
 * Source form: the stored value is reached as a byte of the settings array on every use (start_time is a macro), and
 * the saved value is held in a local that is read once.
 */
extern unsigned char user_settings[];
extern unsigned char osd_edit_value;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_mark(int, unsigned char, int);

#define start_time user_settings[0x1e0]    /* the Starting in choice, settings byte +0x1E0 */

#define CHOICE_ROW_EDGED    1                   /* osd_highlight_choice_row style: with edge glyphs */
#define CHOICE_MARK_LIST    1                   /* osd_draw_choice_mark: mark in a choice list */
#define CHOICE_MARK_OFF     0
#define CHOICE_MARK_ON      1

/*
 * Up key in the Static Screen Detection 'Starting in' choices (menu state 0xF4): go to the previous choice (before
 * the first comes the last)
 * and store it at once in the settings (byte +0x1e0). There are two choices, 0 and 1.
 *
 * osd_edit_value holds the choice stored when the list was opened. Its mark is cleared while the cursor is on
 * it and drawn again on the other choice.
 */
void osd_select_prev_static_screen_start_time(void)
{
    osd_clear_choice_highlight(start_time);
    if (start_time != 0)
        start_time--;
    else
        start_time = 1;
    osd_highlight_choice_row(start_time, CHOICE_ROW_EDGED);
    {
        unsigned char saved_choice = osd_edit_value;
        if (start_time == saved_choice)
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved_choice, CHOICE_MARK_OFF);
        else
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved_choice, CHOICE_MARK_ON);
    }
}
