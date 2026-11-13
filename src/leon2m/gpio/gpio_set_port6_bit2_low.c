/* gpio_set_port6_bit2_low  (FUN_a01258b4)
 *
 * Drive pin 2 of GPIO port 6 low.
 * Name basis: descriptive - gpio_write_pin(0x6, 0x4, 0xFE)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01258b4 @ 0xa01258b4, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Write level 0xfe (bit 0 clear: low) to mask 4 (pin 2) of GPIO port 6.
 * Called by APPSetPowerOff.
 */
void gpio_set_port6_bit2_low(void)
{
    gpio_write_pin(6, 4, 0xfe);
}
