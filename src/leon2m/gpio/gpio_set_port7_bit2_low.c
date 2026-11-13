/* gpio_set_port7_bit2_low  (FUN_a012596c)
 *
 * Drive pin 2 of GPIO port 7 low.
 * Name basis: descriptive - gpio_write_pin(0x7, 0x4, 0xFE)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012596c @ 0xa012596c, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Write level 0xfe (bit 0 clear: low) to mask 4 (pin 2) of GPIO port 7.
 * Called by APPSetPowerOff and power_enter_app_state.
 */
void gpio_set_port7_bit2_low(void)
{
    gpio_write_pin(7, 4, 0xfe);
}
