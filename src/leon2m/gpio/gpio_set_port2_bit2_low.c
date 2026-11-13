/* gpio_set_port2_bit2_low  (FUN_a0125ac8)
 *
 * Drive pin 2 of GPIO port 2 low.
 * Name basis: descriptive - gpio_write_pin(0x2, 0x4, 0xFE)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125ac8 @ 0xa0125ac8, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Write level 0xfe (bit 0 clear: low) to mask 4 (pin 2) of GPIO port 2.
 * Called by, among others, APPSetPowerOff, power_enter_app_state, sys_run_app_timer_task, ddc_tool_set_rgb_led, sys_user_factory_reset and oled_power_task.
 */
void gpio_set_port2_bit2_low(void)
{
    gpio_write_pin(2, 4, 0xfe);
}
