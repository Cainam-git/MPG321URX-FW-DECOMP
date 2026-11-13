/* fwupd_set_progress_hook  (FUN_a0123648)
 *
 * Store the routine that the update progress loop calls on every percent change.
 * Name basis: derived - stores its argument in the word at 0xA802C9F4, which fwupd_run_progress_loop calls as
 *   a routine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0123648 @ 0xa0123648, flags -mcpu=v8 -O2 -g (the section default).
 */
extern unsigned int fwupd_progress_hook;

/*
 * Store the routine that fwupd_run_progress_loop calls whenever the update progress in percent changes
 * (data name fwupd_progress_hook). Caller: fwupd_api_start_update, with a slot of the system callback table.
 *   hook: address of the routine to call; 0 means none.
 */
void fwupd_set_progress_hook(unsigned int hook)
{
  fwupd_progress_hook = hook;
}
