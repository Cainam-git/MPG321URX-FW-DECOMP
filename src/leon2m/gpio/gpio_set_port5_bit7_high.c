/* gpio_set_port5_bit7_high  (FUN_a0125988)
 *
 * Drive pin 7 of GPIO port 5 high.
 * Name basis: descriptive - gpio_write_pin(0x5, 0x80, 1); used by the OLED power state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125988 @ 0xa0125988, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Write level 1 (high) to mask 0x80 (pin 7) of GPIO port 5.
 * Called by App_Initialize, sys_run_app_timer_task, power_enter_app_state, power_escape_fake_sleep and oled_power_task.
 */
void gpio_set_port5_bit7_high(void)
{
    gpio_write_pin(5, 0x80, 1);
}
