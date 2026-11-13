/* OSDCloseWhenSyncDet  (FUN_a0091034)
 *
 * Close the no-signal message (state 0x10D) once an input signal is found.
 * Note: Only when the PIP/PBP mode (settings byte +0x1F) is 0; also hides the menu layer and switches the
 *   panel off (SYSAPI_PanelOnOffControl(0, 1)).
 * Name basis: proven - prints 'OSDCloseWhenSyncDet' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0091034 @ 0xa0091034 (-mcpu=v8 -O3 -g).
 * Source forms the exact build depends on: the routine is declared void and takes six words it does not use
 * itself; its last four are handed on unchanged to SYSAPI_PanelOnOffControl, which is declared without a
 * parameter list and is called as the last statement (a tail call).
 */

#define MENU_STATE_CLOSED      0
#define MENU_STATE_NO_SIGNAL   0x10d    /* the no-signal message */

#define PIP_PBP_OFF            0        /* user_settings pip_pbp_mode: neither PiP nor PBP */

#define PANEL_OFF              0        /* SYSAPI_PanelOnOffControl: first argument */
#define WAIT_DONE              1        /* SYSAPI_PanelOnOffControl: second argument */

extern unsigned char user_settings_pip_pbp_mode;
extern unsigned int osd_menu_state;
extern int osd_hide_menu();
extern int dbg_printf();
extern int SYSAPI_PanelOnOffControl();

/* Close the no-signal message when an input signal has been found. It does nothing unless the menu state
 * is MENU_STATE_NO_SIGNAL and PiP/PBP is off. Then it prints "OSDCloseWhenSyncDet", sets the menu state to
 * closed, hides the menu layer and asks the panel power sequencer to switch the panel off and wait until that
 * is done.
 *   arg1, arg2    not used
 *   arg3 .. arg6  passed on unchanged as the remaining arguments of SYSAPI_PanelOnOffControl
 */
void OSDCloseWhenSyncDet(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
            unsigned int arg5, unsigned int arg6)

{
  if (osd_menu_state == MENU_STATE_NO_SIGNAL) {
    if (user_settings_pip_pbp_mode == PIP_PBP_OFF) {
      dbg_printf("OSDCloseWhenSyncDet\n");
      osd_menu_state = MENU_STATE_CLOSED;
      osd_hide_menu();
      SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE, arg3, arg4, arg5, arg6);
    }
  }
}
