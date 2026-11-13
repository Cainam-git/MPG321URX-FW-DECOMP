/* gpio_set_port2_bit2_high  (FUN_a0125aac)
 *
 * Drive pin 2 of GPIO port 2 high.
 * Name basis: descriptive - gpio_write_pin(0x2, 0x4, 1); used by the OLED power state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125aac @ 0xa0125aac, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Write level 1 (high) to mask 4 (pin 2) of GPIO port 2.
 * Called by, among others, ddc_tool_set_rgb_led, sys_user_factory_reset and oled_power_task.
 */
void gpio_set_port2_bit2_high(void)
{
    gpio_write_pin(2, 4, 1);
}
