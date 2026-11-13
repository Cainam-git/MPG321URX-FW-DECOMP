/* osd_factory_leave_item_edit  (FUN_a009eaa4)
 *
 * Finish editing a factory menu value and return to the item list.
 * Note: Menu state 0x111, then osd_factory_select_item.
 * Name basis: derived - handler table 0xA802422C: OK/left/right on state 0x112
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009eaa4, flags -mcpu=v8 -O2 -g. No direct callers (reached through the key handler table).
 * Source form: a void wrapper with a constant store before a tail call; the nop after the call is the one the
 * compiler places behind such a call sequence.
 */
extern unsigned int osd_menu_state;
extern void osd_factory_select_item(void);

#define MENU_STATE_FACTORY_MENU 0x111

/*
 * OK, left or right while a factory menu item is edited (menu state 0x112): the menu state returns to 0x111 and
 * osd_factory_select_item runs.
 */
void osd_factory_leave_item_edit(void)
{
    osd_menu_state = MENU_STATE_FACTORY_MENU;
    osd_factory_select_item();
}
