/* fwupd_query_progress_percent  (FUN_a002f96c)
 *
 * Return fwupd_get_progress_percent() as an int.
 * Returns: percent
 * Note: No direct caller (reached through a pointer).
 * Name basis: derived - wraps fwupd_get_progress_percent
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002f96c @ 0xa002f96c, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept, because it matches the firmware: two arguments, the byte widened to
 * unsigned int and the return value built with CONCAT44(arg1, ...) and returned as int.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern unsigned char fwupd_get_progress_percent(void);

/*
 * Return the firmware update progress in percent (the result of fwupd_get_progress_percent).
 *   arg0, arg1: not used.
 */
int fwupd_query_progress_percent(unsigned int arg0, unsigned int arg1)
{
  unsigned char percent;

  percent = fwupd_get_progress_percent();
  return CONCAT44(arg1, (unsigned int)percent);
}
