/* osd_leave_optix_scope_choices  (FUN_a0099970)
 *
 * Leave the Optix Scope list and return to the G.I. item (left)
 * Note: Returns to state 0x0D.
 * Name basis: derived - handler table 0xA802422C: left on states 0x44..0x47
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099970 @ 0xa0099970-0xa00999ec, flags -mcpu=v8 -O3 -g.
 * Source form: the Optix Scope byte is a member of the settings record structure (its base stays in a register)
 * and is read again for each use.
 */
struct user_settings_record { unsigned char pad[0x4a]; unsigned char optix_scope; /* +0x4A: 0 = OFF, 1 = ON */ };
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);

#define MENU_STATE_SCOPE_SIZE_ITEM 0x44 /* first state of the list; the row of a state is state - 0x44 */
#define MENU_STATE_OPTIX_SCOPE_ITEM 0x0d /* Optix Scope item of the G.I. page (item row 2) */
#define OPTIX_SWITCH_ROW         2      /* list rows 0 and 1 are Scope Size and Scope Ratio; OFF is row 2 */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define MARK_DRAW                1
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */
#define CHOICE_ROW_PLAIN         0      /* osd_highlight_choice_row style: plain */

/*
 * Left key in the Optix Scope list (states 0x44..0x47): go back to the Optix Scope item without changing the
 * switch.
 *
 * The cursor row (state - 0x44) loses its highlight. The row of the switch now stored (+2) gets the plain
 * highlight; its mark is cleared and drawn again. The menu state returns to the Optix Scope item and the item
 * row is highlighted as active.
 */
void osd_leave_optix_scope_choices(void)
{
    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_SCOPE_SIZE_ITEM);
    osd_highlight_choice_row(user_settings.optix_scope + OPTIX_SWITCH_ROW, CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.optix_scope + OPTIX_SWITCH_ROW, MARK_CLEAR);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.optix_scope + OPTIX_SWITCH_ROW, MARK_DRAW);
    osd_menu_state = MENU_STATE_OPTIX_SCOPE_ITEM;
    osd_highlight_item_row(2, ITEM_ROW_ACTIVE);
}
