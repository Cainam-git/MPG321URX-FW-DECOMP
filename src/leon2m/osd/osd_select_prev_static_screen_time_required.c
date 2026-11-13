/* osd_select_prev_static_screen_time_required  (FUN_a009e708)
 *
 * Move to the previous 'Time required' choice (up key) and store it.
 * Note: Settings byte +0x1E1, values 0..1 (0 wraps to 1).
 * Name basis: derived - handler table 0xA802422C: up on state 0xF6; choices 0x18A7EC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009e708, flags -mcpu=v8 -O3 -g.
 * Source form: the stored value is reached as a byte of the settings array on every use (time_required is a macro), and
 * the saved value is held in a local that is read once.
 */
extern unsigned char user_settings[];
extern unsigned char osd_edit_value;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_mark(int, unsigned char, int);

#define time_required user_settings[0x1e1]    /* the Time required choice, settings byte +0x1E1 */

#define CHOICE_ROW_EDGED    1                   /* osd_highlight_choice_row style: with edge glyphs */
#define CHOICE_MARK_LIST    1                   /* osd_draw_choice_mark: mark in a choice list */
#define CHOICE_MARK_OFF     0
#define CHOICE_MARK_ON      1

/*
 * Up key in the Static Screen Detection 'Time required' choices (menu state 0xF6): go to the previous choice
 * (before the first comes the last)
 * and store it at once in the settings (byte +0x1e1). There are two choices, 0 and 1.
 *
 * osd_edit_value holds the choice stored when the list was opened. Its mark is cleared while the cursor is on
 * it and drawn again on the other choice.
 */
void osd_select_prev_static_screen_time_required(void)
{
    osd_clear_choice_highlight(time_required);
    if (time_required != 0)
        time_required--;
    else
        time_required = 1;
    osd_highlight_choice_row(time_required, CHOICE_ROW_EDGED);
    {
        unsigned char saved_choice = osd_edit_value;
        if (time_required == saved_choice)
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved_choice, CHOICE_MARK_OFF);
        else
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved_choice, CHOICE_MARK_ON);
    }
}
