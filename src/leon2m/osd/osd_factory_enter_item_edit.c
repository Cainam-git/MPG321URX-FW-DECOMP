/* osd_factory_enter_item_edit  (FUN_a009ea88)
 *
 * Run or start editing the highlighted factory menu item (OK/right)
 * Note: Menu state 0x112, then osd_factory_activate_item (Reset and Exit run at once).
 * Name basis: proven - handler table 0xA802422C: OK/right on state 0x111
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009ea88, flags -mcpu=v8 -O2 -g. No direct callers (reached through the key handler table).
 * Source form: a void wrapper with a constant store before a tail call; the nop after the call is the one the
 * compiler places behind such a call sequence.
 */
extern unsigned int osd_menu_state;
extern void osd_factory_activate_item(void);

#define MENU_STATE_FACTORY_ITEM_EDIT 0x112

/*
 * OK or right in the factory menu (menu state 0x111): the menu state becomes 0x112 (editing an item) and the
 * highlighted item is activated (osd_factory_activate_item).
 */
void osd_factory_enter_item_edit(void)
{
    osd_menu_state = MENU_STATE_FACTORY_ITEM_EDIT;
    osd_factory_activate_item();
}
