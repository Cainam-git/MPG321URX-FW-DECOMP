/* osd_call_hide_menu  (FUN_a00a7adc)
 *
 * Hide the menu layer.
 * Note: Thin forwarder to osd_hide_menu.
 * Name basis: derived - tail call osd_hide_menu; called by osd_clear_menu_state_and_hide
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a7adc @ 0xa00a7adc, flags -mcpu=v8 -O2 -g.
 * The call to osd_hide_menu is a tail call: the caller's return address is handed on, so osd_hide_menu returns
 * straight to this routine's caller. The last word is the nop the compiler places behind such a call sequence.
 */
extern void osd_hide_menu(void);

/* Hide the menu layer and all its windows (osd_hide_menu). Called by
 * osd_clear_menu_state_and_hide. */
void osd_call_hide_menu(void)
{
    osd_hide_menu();
}
