/* sys_set_key_repeat_delay  (FUN_a008ef24)
 *
 * Set the hold time before a repeating key repeats for the first time.
 *   time_ms: time in ms
 * Note: Halfword 0xA8024048.
 * Name basis: derived - used as the first wait of key mode 1 in sys_scan_keys_post_event; set by
 *   App_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008ef24 @ 0xa008ef24, flags -mcpu=v8 -O2 -g (section default).
 * Code: sys_key_repeat_delay = time_ms.
 */
extern unsigned short sys_key_repeat_delay;

/*
 * Set the time a repeating key must be held before it repeats for the first time.
 *
 *   time_ms   time in milliseconds
 *
 * Stored in sys_key_repeat_delay; read by sys_scan_keys_post_event for key mode 1 (repeat). Set by App_Initialize.
 */
void sys_set_key_repeat_delay(unsigned short time_ms)
{
  sys_key_repeat_delay = time_ms;
}
