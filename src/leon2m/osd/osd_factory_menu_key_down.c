/* osd_factory_menu_key_down  (FUN_a009ea5c)
 *
 * Move the factory menu highlight to the next item (down key)
 * Note: Thin forwarder to osd_factory_cursor_down; menu state 0x111.
 * Name basis: proven - handler table 0xA802422C: down on state 0x111
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009ea5c, flags -mcpu=v8 -O2 -g. No direct callers (reached through the key handler table).
 * Source form: a void wrapper with a constant store before a tail call; the nop after the call is the one the
 * compiler places behind such a call sequence.
 */
extern unsigned int osd_menu_state;
extern void osd_factory_cursor_down(void);

#define MENU_STATE_FACTORY_MENU 0x111

/*
 * Down key in the factory menu (menu state 0x111): sets the state again and moves the highlight to the next item
 * (osd_factory_cursor_down).
 */
void osd_factory_menu_key_down(void)
{
    osd_menu_state = MENU_STATE_FACTORY_MENU;
    osd_factory_cursor_down();
}
