/* gpio_is_aux_bit0_high  (FUN_a0124a40)
 *
 * Read pin 0 of GPIO port number 0xFF; gpio_read_pin answers 0 for that port, so the result is 0.
 * Returns: always 0
 * Note: Port number 0xFF has no register (ports 1..17 only); called by uart_cmd_set_auto_level,
 *   sys_run_app_timer_task, GlobalModeHandler, panel_blurfree_apply_user_mode.
 * Name basis: descriptive - gpio_read_pin(0xFF, 1); port number 0xFF is not among the ports 1..17 the pin
 *   routines serve
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124a40 @ 0xa0124a40, flags -mcpu=v8 -O3 -g.
 * Source form: the result is `!((r & 0xff) ^ 1)`.
 */
extern int gpio_read_pin(int, int);

/*
 * Read mask 1 of port 0xff and return 1 when the low byte of the answer is 1. Port 0xff is not one of the ports
 * 1..17 that gpio_read_pin handles, so it always answers 0 and this routine always returns 0.
 * Called from sys_run_app_timer_task, panel_blurfree_apply_user_mode, uart_cmd_set_auto_level and GlobalModeHandler.
 */
int gpio_is_aux_bit0_high(void)
{
    int level = gpio_read_pin(0xff, 1);
    return !((level & 0xff) ^ 1);
}
