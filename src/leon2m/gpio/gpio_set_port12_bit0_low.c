/* gpio_set_port12_bit0_low  (FUN_a0125de4)
 *
 * Drive pin 0 of GPIO port 12 low.
 * Name basis: descriptive - gpio_write_pin(0xc, 0x1, 0xFE)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125de4 @ 0xa0125de4 (-mcpu=v8 -O2 -g)
 * Source form: a single call; the prototype of gpio_write_pin is left open (no parameter list), as the
 * firmware's code needs.
 */
extern int gpio_write_pin();

#define GPIO_PORT_12 12
#define GPIO_LEVEL_LOW 0xfe                     /* only bit 0 of the level counts: bit 0 clear = low */

/* Write the low level to pin mask 0x01 of GPIO port 12. Called by APPSetPowerOff and power_enter_app_state. */
void gpio_set_port12_bit0_low(void)
{
  gpio_write_pin(GPIO_PORT_12, 0x01, GPIO_LEVEL_LOW);
}
