/* osd_enter_optix_scope_choices  (FUN_a00995f0)
 *
 * Open the Optix Scope list (Scope Size, Scope Ratio, OFF, ON) on the current setting.
 * Note: States 0x44..0x47; on/off = settings byte +0x4A.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x0D = 'Optix Scope' (texts 0x18A360);
 *   texts 0x18D578: Scope Size, Scope Ratio, OFF, ON
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00995f0 @ 0xa00995f0-0xa0099658 (26 words), flags -mcpu=v8 -O3 -g.
 * Same code as the Night Vision list entry routine (osd_enter_alarm_clock_choices) with other constants. Source form: the settings
 * record is addressed as a volatile byte pointer and the Optix Scope byte is read again for each use. The
 * declaration of user_settings_alarm_clock is not used by this routine.
 */
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char user_settings_alarm_clock;
extern void osd_draw_choice_mark();
extern void osd_highlight_item_row();
extern int osd_highlight_choice_row();

#define USER_SETTINGS_BASE       0xA802D290 /* the user settings record */
#define USER_SETTINGS_OPTIX_SCOPE 0x4a  /* the Optix Scope switch: 0 = OFF, 1 = ON */
#define PAGE_GI_ITEMS            0x0b   /* first item state of the G.I. page; Optix Scope is state 0x0D */
#define MENU_STATE_OPTIX_SCOPE_OFF 0x46 /* + switch: the OFF / ON rows of the list (states 0x46, 0x47) */
#define OPTIX_SWITCH_ROW         2      /* list rows 0 and 1 are Scope Size and Scope Ratio; OFF is row 2 */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define ITEM_ROW_LIST_OPEN       2      /* osd_highlight_item_row mode: parent of an open choice list */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * OK or right on the Optix Scope item of the G.I. page: open its list (Scope Size, Scope Ratio, OFF, ON) on the
 * switch now stored (settings byte +0x4A).
 *
 * The mark of the switch's row (switch + 2) is cleared. osd_choice_row saves the switch itself (0 or 1) for the
 * left key. The item row is highlighted in the "list open" style, the menu state becomes 0x46 plus the switch
 * and the switch's row is highlighted.
 */
void osd_enter_optix_scope_choices(void)
{
    volatile unsigned char *settings = (volatile unsigned char *)USER_SETTINGS_BASE;
    unsigned char scope;
    unsigned char saved;

    scope = settings[USER_SETTINGS_OPTIX_SCOPE];
    osd_draw_choice_mark(CHOICE_MARK_LIST, (scope + OPTIX_SWITCH_ROW) & 0xff, MARK_CLEAR);
    saved = settings[USER_SETTINGS_OPTIX_SCOPE];
    osd_choice_row = saved;
    osd_highlight_item_row((osd_menu_state - PAGE_GI_ITEMS) & 0xff, ITEM_ROW_LIST_OPEN);
    saved = settings[USER_SETTINGS_OPTIX_SCOPE];
    osd_menu_state = saved + MENU_STATE_OPTIX_SCOPE_OFF;
    osd_highlight_choice_row((saved + OPTIX_SWITCH_ROW) & 0xff, CHOICE_ROW_EDGED);
}
