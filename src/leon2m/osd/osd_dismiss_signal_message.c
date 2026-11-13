/* osd_dismiss_signal_message  (FUN_a009e2ac)
 *
 * Remove the No Signal message and leave the menu closed (left key)
 * Note: Sets state 0x105 while osd_clear_signal_message clears the message, then state 0; returns its first
 *   argument unchanged.
 * Name basis: derived - handler table 0xA802422C: left on states 0x10D/0x10E (No Signal messages)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009e2ac, flags -mcpu=v8 -O2 -g.
 * Source form: the routine returns its first argument unchanged, so it is declared int-returning with two
 * parameters; the second is not used.
 */
extern unsigned int osd_menu_state;
extern int osd_clear_signal_message();

#define MENU_STATE_105 0x105                    /* set only while the signal message is being cleared */

/*
 * Left key while a No Signal message is shown (menu states 0x10D and 0x10E): remove the message and leave the
 * menu closed (menu state 0).
 *
 * The first argument is returned unchanged; the second is not used.
 */
int osd_dismiss_signal_message(unsigned int first_arg, unsigned int unused)

{
  osd_menu_state = MENU_STATE_105;
  osd_clear_signal_message();
  osd_menu_state = 0;
  return first_arg;
}
