/* gpio_set_port7_bit1_low  (FUN_a01258ec)
 *
 * Drive pin 1 of GPIO port 7 low.
 * Name basis: descriptive - gpio_write_pin(0x7, 0x2, 0xFE)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01258ec @ 0xa01258ec, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Write level 0xfe (bit 0 clear: low) to mask 2 (pin 1) of GPIO port 7.
 * Called by APPSetPowerOff, power_enter_app_state, sys_user_factory_reset and gpio_user_set_port7_bit1.
 */
void gpio_set_port7_bit1_low(void)
{
    gpio_write_pin(7, 2, 0xfe);
}
