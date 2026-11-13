/* gpio_set_port6_bit2_high  (FUN_a012587c)
 *
 * Drive pin 2 of GPIO port 6 high.
 * Name basis: descriptive - gpio_write_pin(6, 4, 1)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012587c @ 0xa012587c, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Write level 1 (high) to mask 4 (pin 2) of GPIO port 6.
 * Called by App_Initialize and power_enter_app_state.
 */
void gpio_set_port6_bit2_high(void)
{
    gpio_write_pin(6, 4, 1);
}
