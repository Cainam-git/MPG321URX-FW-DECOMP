/* gpio_set_port7_bit2_high  (FUN_a0125950)
 *
 * Drive pin 2 of GPIO port 7 high.
 * Name basis: descriptive - gpio_write_pin(0x7, 0x4, 1)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125950 @ 0xa0125950, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Write level 1 (high) to mask 4 (pin 2) of GPIO port 7.
 * Called by App_Initialize, sys_run_app_timer_task and power_enter_app_state.
 */
void gpio_set_port7_bit2_high(void)
{
    gpio_write_pin(7, 4, 1);
}
