/* osd_is_tab_enabled  (FUN_a00aa4e0)
 *
 * Return 1 when a menu tab can be entered (PIP/PBP needs SDR and no lock)
 *   id: tab index
 * Returns: 1 enabled, 0 skipped
 * Note: Only tab 5 (PIP/PBP) can be blocked: while HDR is active or byte 0xA802D484 is negative.
 * Name basis: derived - called by osd_select_prev_tab / osd_select_next_tab
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00aa4e0 @ 0xa00aa4e0, flags -mcpu=v8 -O2 -g.
 * Source form: sys_user_get_picture_state is called with no argument (the firmware does not set %o0 before the
 * call); the word is tested with ">= 0" (load, compare, branch with annulled delay slot).
 */
extern int user_settings_word_0x1f4;
extern int sys_user_get_picture_state(void);

#define TAB_PIP_PBP 5

/* Return 1 when a menu tab can be entered, 0 when it is skipped. Every tab
 * except the PIP/PBP tab (5) is enabled. The PIP/PBP tab is enabled only when
 * sys_user_get_picture_state() returns 0 and bit 31 of settings word +0x1F4
 * (the DSC switch) is clear. Called by osd_select_prev_tab and
 * osd_select_next_tab. */
int osd_is_tab_enabled(unsigned char id)
{
  int ok = 1;
  if (id == TAB_PIP_PBP) {
    ok = 0;
    if (sys_user_get_picture_state() == 0 && user_settings_word_0x1f4 >= 0)
      ok = 1;
  }
  return ok;
}
