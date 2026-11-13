/* fwupd_get_progress_percent  (FUN_a002f10c)
 *
 * Return the transfer progress in percent (0..100)
 * Returns: percent
 * Note: Byte 0xA802C9F0, written by fwupd_run_progress_loop.
 * Name basis: derived - the progress loop fwupd_run_progress_loop stores size * 100 / total here
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002f10c @ 0xa002f10c, flags -mcpu=v8 -O2 -g (the section default). A leaf routine without a register window.
 */
extern unsigned char fwupd_progress_percent;

/* Return the firmware update progress in percent (0..100), as kept by fwupd_run_progress_loop. */
unsigned char fwupd_get_progress_percent(void)
{
  return fwupd_progress_percent;
}
