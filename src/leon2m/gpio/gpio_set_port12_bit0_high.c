/* gpio_set_port12_bit0_high  (FUN_a0125dc8)
 *
 * Drive pin 0 of GPIO port 12 high.
 * Name basis: descriptive - gpio_write_pin(0xc, 0x1, 1)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125dc8 @ 0xa0125dc8 (-mcpu=v8 -O2 -g)
 * Source form: a single call; the prototype of gpio_write_pin is left open (no parameter list), as the
 * firmware's code needs.
 */
extern int gpio_write_pin();

#define GPIO_PORT_12 12
#define GPIO_LEVEL_HIGH 1                       /* only bit 0 of the level counts */

/* Write the high level to pin mask 0x01 of GPIO port 12. Called by App_Initialize. */
void gpio_set_port12_bit0_high(void)
{
  gpio_write_pin(GPIO_PORT_12, 0x01, GPIO_LEVEL_HIGH);
}
