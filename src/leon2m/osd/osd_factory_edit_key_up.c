/* osd_factory_edit_key_up  (FUN_a009eadc)
 *
 * Lower or toggle the edited factory menu value (up key)
 * Note: Thin forwarder to osd_factory_decrease_value; keeps menu state 0x112.
 * Name basis: proven - handler table 0xA802422C: up on state 0x112
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009eadc, flags -mcpu=v8 -O2 -g. No direct callers (reached through the key handler table).
 * Source form: a void wrapper with a constant store before a tail call; the nop after the call is the one the
 * compiler places behind such a call sequence.
 */
extern unsigned int osd_menu_state;
extern void osd_factory_decrease_value(void);

#define MENU_STATE_FACTORY_ITEM_EDIT 0x112

/*
 * Up key while a factory menu item is edited (menu state 0x112): keeps the state and changes the value with
 * osd_factory_decrease_value.
 */
void osd_factory_edit_key_up(void)
{
    osd_menu_state = MENU_STATE_FACTORY_ITEM_EDIT;
    osd_factory_decrease_value();
}
