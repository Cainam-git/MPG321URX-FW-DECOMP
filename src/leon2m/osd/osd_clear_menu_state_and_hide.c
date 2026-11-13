/* osd_clear_menu_state_and_hide  (FUN_a0091294)
 *
 * Clear the menu state and hide the menu window.
 * Note: Unlike osd_close_menu it does not re-arm the port events.
 * Name basis: proven - clears 0xA802AFEC, tail-calls the menu hide routine; key role from the menu state
 *   handler table 0xA802422C, tab texts 0x196DC0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0091294, flags -mcpu=v8 -O2 -g.
 * Tail call: the callee returns straight to this routine's caller; the last word is the nop the compiler places
 * behind such a call sequence.
 */

extern unsigned int osd_menu_state;
extern void osd_call_hide_menu(void);

/* Set the menu state to 0 (closed) and hide the menu layer. Its address is stored in the menu key table. */
void osd_clear_menu_state_and_hide(void)
{
  osd_menu_state = 0;
  osd_call_hide_menu();
}
