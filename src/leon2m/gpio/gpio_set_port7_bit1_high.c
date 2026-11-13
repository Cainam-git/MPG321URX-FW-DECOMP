/* gpio_set_port7_bit1_high  (FUN_a01258d0)
 *
 * Drive pin 1 of GPIO port 7 high.
 * Name basis: descriptive - gpio_write_pin(0x7, 0x2, 1)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01258d0 @ 0xa01258d0, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Write level 1 (high) to mask 2 (pin 1) of GPIO port 7.
 * Called by sys_user_factory_reset and gpio_user_set_port7_bit1.
 */
void gpio_set_port7_bit1_high(void)
{
    gpio_write_pin(7, 2, 1);
}
