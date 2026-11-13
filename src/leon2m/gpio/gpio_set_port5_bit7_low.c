/* gpio_set_port5_bit7_low  (FUN_a01259a4)
 *
 * Drive pin 7 of GPIO port 5 low.
 * Name basis: descriptive - gpio_write_pin(0x5, 0x80, 0xFE)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01259a4 @ 0xa01259a4, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Write level 0xfe (bit 0 clear: low) to mask 0x80 (pin 7) of GPIO port 5.
 * Called by APPSetPowerOff and power_enter_app_state.
 */
void gpio_set_port5_bit7_low(void)
{
    gpio_write_pin(5, 0x80, 0xfe);
}
