/* osd_confirm_settings_reset  (FUN_a0099ac0)
 *
 * Reset all user settings to their defaults (Yes in the Reset question)
 * Note: Forwards to osd_run_settings_reset, which closes the menu and reloads the default record.
 * Name basis: proven - handler table 0xA802422C: OK on state 0xB6 = 'Yes'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099ac0 @ 0xa0099ac0, flags -mcpu=v8 -O2 -g (the default of the section).
 * Source form: osd_run_settings_reset is declared without a parameter list, so the two incoming argument
 * registers are passed on to it.
 */
extern int osd_run_settings_reset();

/*
 * OK on Yes in the Reset question (menu state 0xB6): hand over to osd_run_settings_reset, which closes the menu
 * and resets all user settings to their defaults. The two argument registers of the caller are passed on
 * unchanged.
 */
void osd_confirm_settings_reset(unsigned int arg1, unsigned int arg2)

{
  osd_run_settings_reset(arg1, arg2);
  return;
}
