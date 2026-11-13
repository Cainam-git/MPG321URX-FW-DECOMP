/* sys_restart_key_scan_timer  (FUN_CODE_dd41)
 *
 * Clear the scan flag and restart the key scan timer.
 * Name basis: derived - flag 0xA629 and tick stamp 0xA5EB used by the key scan power_scan_wake_keys; power
 *   saving / power off commands
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dd41 @ 0xdd41  OPTIMIZE(7,SPEED)
 * timer_get_ticks returns unsigned int (R6:R7), stored big-endian at XDATA 0xA5EB/0xA5EC; the address is written as a
 * cast because the build needs that form.
 */
extern xdata unsigned char power_key_release_seen_flag;
extern unsigned int timer_get_ticks(void);

/* Clear power_key_release_seen_flag and store the current tick count in
 * the word at 0xA5EB (power_key_hit_ticks, the tick stamp of the wake key
 * scan). */
void sys_restart_key_scan_timer(void) {
    power_key_release_seen_flag = 0;
    *((unsigned int xdata *)0xa5eb) = timer_get_ticks();
}
