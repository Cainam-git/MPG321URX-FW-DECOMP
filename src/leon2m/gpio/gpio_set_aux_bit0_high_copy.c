/* gpio_set_aux_bit0_high_copy  (FUN_a0125e00)
 *
 * Ask for pin 0 of GPIO port number 0xFF to go high; no pin changes (gpio_write_pin: ports 1..17).
 * Note: gpio_write_pin has no arm for port 0xFF, so the call writes nothing; called by
 *   panel_blurfree_apply_user_mode.
 * Name basis: descriptive - gpio_write_pin(0xFF, 0x1, 0x1); port number 0xFF is not among the ports 1..17 the
 *   pin routines serve
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125e00 @ 0xa0125e00 (-mcpu=v8 -O2 -g)
 * Source form: a single call; the prototype of gpio_write_pin is left open (no parameter list), as the
 * firmware's code needs.
 */
extern int gpio_write_pin();

#define GPIO_PORT_AUX 0xff                      /* not one of the ports 1..17 that gpio_write_pin handles */
#define GPIO_LEVEL_HIGH 1                       /* only bit 0 of the level counts */

/*
 * Write the high level to pin mask 0x01 of port 0xff. Port 0xff is not one of the ports 1..17 that
 * gpio_write_pin handles, so the call changes nothing. Called by panel_blurfree_apply_user_mode.
 */
void gpio_set_aux_bit0_high_copy(void)
{
  gpio_write_pin(GPIO_PORT_AUX, 0x01, GPIO_LEVEL_HIGH);
}
