/* osd_factory_open_menu  (FUN_a009ea24)
 *
 * Open the factory service menu.
 * Note: Menu state 0x111, then osd_draw_factory_menu.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 1 and every key on state 0x115
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009ea24, flags -mcpu=v8 -O2 -g. No direct callers (reached through the key handler table).
 * Source form: a void wrapper with a constant store before a tail call; the nop after the call is the one the
 * compiler places behind such a call sequence.
 */
extern unsigned int osd_menu_state;
extern void osd_draw_factory_menu(void);

#define MENU_STATE_FACTORY_MENU 0x111

/*
 * Open the factory menu: OK or right on menu state 1, or any key on state 0x115. Sets menu state 0x111 and draws
 * the menu (osd_draw_factory_menu).
 */
void osd_factory_open_menu(void)
{
    osd_menu_state = MENU_STATE_FACTORY_MENU;
    osd_draw_factory_menu();
}
