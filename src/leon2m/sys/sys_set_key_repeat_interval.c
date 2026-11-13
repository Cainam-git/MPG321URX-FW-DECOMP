/* sys_set_key_repeat_interval  (FUN_a008ef30)
 *
 * Set the time between repeats of a held key.
 *   time_ms: time in ms
 * Note: Halfword 0xA8024046.
 * Name basis: derived - used as the repeat wait of key mode 1 in sys_scan_keys_post_event; set by
 *   App_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008ef30 @ 0xa008ef30, flags -mcpu=v8 -O2 -g (section default).
 * Code: sys_key_repeat_interval = time_ms.
 */
extern unsigned short sys_key_repeat_interval;

/*
 * Set the time between the repeats of a held key.
 *
 *   time_ms   time in milliseconds
 *
 * Stored in sys_key_repeat_interval; read by sys_scan_keys_post_event for key mode 1 (repeat). Set by App_Initialize.
 */
void sys_set_key_repeat_interval(unsigned short time_ms)
{
  sys_key_repeat_interval = time_ms;
}
