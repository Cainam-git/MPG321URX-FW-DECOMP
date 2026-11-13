/* osd_accept_optix_scope  (FUN_a0099864)
 *
 * Apply the highlighted Optix Scope OFF or ON and go back (OK)
 * Note: Returns to state 0x0D.
 * Name basis: derived - handler table 0xA802422C: OK on states 0x46/0x47; texts 0x18D578: Scope Size, Scope
 *   Ratio, OFF, ON
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099864 @ 0xa0099864-0xa0099970 (67 words), flags -mcpu=v8 -O3 -g.
 */
struct user_settings_record { unsigned char pad[0x4a]; unsigned char optix_scope; /* +0x4A: 0 = OFF, 1 = ON */ };
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern unsigned int osd_menu_state;
extern void osd_apply_optix_scope(void);
extern int sys_user_get_picture_state(void);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);

#define MENU_STATE_SCOPE_RATIO_ITEM 0x45 /* the state just below the OFF / ON rows of the list */
#define MENU_STATE_SCOPE_SIZE_ITEM 0x44 /* first state of the list; the row of a state is state - 0x44 */
#define MENU_STATE_OPTIX_SCOPE_ITEM 0x0d /* Optix Scope item of the G.I. page (item row 2) */
#define OPTIX_SWITCH_ROW         2      /* list rows 0 and 1 are Scope Size and Scope Ratio; OFF is row 2 */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define MARK_DRAW                1
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */
#define CHOICE_ROW_PLAIN         0      /* osd_highlight_choice_row style: plain */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK on OFF or ON in the Optix Scope list (states 0x46, 0x47): switch the scope as chosen and go back to the
 * Optix Scope item.
 *
 * osd_apply_optix_scope switches the scope on or off from the menu state and writes settings byte +0x4A. When the
 * menu state is still above 0x45 afterwards, 12 cells from column 9, row 0x13 are filled with 0x292 if
 * sys_user_get_picture_state is not 0 and with 0x792 otherwise. The row saved on entry (osd_choice_row + 2) loses
 * its highlight and mark; the cursor row (state - 0x44) gets the plain highlight; the mark of the row of the
 * switch now stored (+2) is cleared and drawn again. The menu state returns to the Optix Scope item and the
 * item row is highlighted as active.
 */
void osd_accept_optix_scope(void)
{
    osd_apply_optix_scope();
    if (osd_menu_state > MENU_STATE_SCOPE_RATIO_ITEM) {
        if (sys_user_get_picture_state() != 0)
            osd_api_fill_cells(9, 0x13, 0xc, 0x292, 0);
        else
            osd_api_fill_cells(9, 0x13, 0xc, 0x792, 0);
    }
    osd_clear_choice_highlight(osd_choice_row + OPTIX_SWITCH_ROW);
    osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row + OPTIX_SWITCH_ROW, MARK_CLEAR);
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_SCOPE_SIZE_ITEM, CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.optix_scope + OPTIX_SWITCH_ROW, MARK_CLEAR);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.optix_scope + OPTIX_SWITCH_ROW, MARK_DRAW);
    osd_menu_state = MENU_STATE_OPTIX_SCOPE_ITEM;
    osd_highlight_item_row(2, ITEM_ROW_ACTIVE);
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
