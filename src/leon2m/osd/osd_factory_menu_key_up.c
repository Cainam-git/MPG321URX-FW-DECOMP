/* osd_factory_menu_key_up  (FUN_a009ea40)
 *
 * Move the factory menu highlight to the previous item (up key)
 * Note: Thin forwarder to osd_factory_cursor_up; menu state 0x111.
 * Name basis: proven - handler table 0xA802422C: up on state 0x111
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009ea40, flags -mcpu=v8 -O2 -g. No direct callers (reached through the key handler table).
 * Source form: a void wrapper with a constant store before a tail call; the nop after the call is the one the
 * compiler places behind such a call sequence.
 */
extern unsigned int osd_menu_state;
extern void osd_factory_cursor_up(void);

#define MENU_STATE_FACTORY_MENU 0x111

/*
 * Up key in the factory menu (menu state 0x111): sets the state again and moves the highlight to the previous
 * item (osd_factory_cursor_up).
 */
void osd_factory_menu_key_up(void)
{
    osd_menu_state = MENU_STATE_FACTORY_MENU;
    osd_factory_cursor_up();
}
