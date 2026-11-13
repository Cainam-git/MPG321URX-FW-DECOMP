/* sys_set_key_long_press_time  (FUN_a008ef3c)
 *
 * Set the hold time that counts as a long key press.
 *   time_ms: time in ms
 * Note: Halfword 0xA8024044.
 * Name basis: derived - used by key modes 2 and 3 in sys_scan_keys_post_event; set by App_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008ef3c @ 0xa008ef3c, flags -mcpu=v8 -O2 -g (section default).
 * Code: sys_key_long_press_time = time_ms.
 */
extern unsigned short sys_key_long_press_time;

/*
 * Set the hold time that counts as a long key press.
 *
 *   time_ms   time in milliseconds
 *
 * Stored in sys_key_long_press_time; read by sys_scan_keys_post_event for the long-press key modes. Set by App_Initialize.
 */
void sys_set_key_long_press_time(unsigned short time_ms)
{
  sys_key_long_press_time = time_ms;
}
