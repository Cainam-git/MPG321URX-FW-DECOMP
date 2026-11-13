/* gpio_set_aux_bit1_low  (FUN_a0125c18)
 *
 * Ask for pin 1 of GPIO port number 0xFF to go low; no pin changes (gpio_write_pin: ports 1..17).
 * Note: gpio_write_pin has no arm for port 0xFF, so the call writes nothing; called by APPSetPowerOff,
 *   power_enter_app_state.
 * Name basis: descriptive - gpio_write_pin(0xFF, 0x2, 0xFE); port number 0xFF is not among the ports 1..17 the
 *   pin routines serve
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125c18 @ 0xa0125c18 (-mcpu=v8 -O2 -g)
 * Source form: a single call; the prototype of gpio_write_pin is left open (no parameter list), as the
 * firmware's code needs.
 */
extern int gpio_write_pin();

#define GPIO_PORT_AUX 0xff                      /* not one of the ports 1..17 that gpio_write_pin handles */
#define GPIO_LEVEL_LOW 0xfe                     /* only bit 0 of the level counts: bit 0 clear = low */

/*
 * Write level 0xfe (low) to pin mask 0x02 of port 0xff. Port 0xff is not one of the ports 1..17 that
 * gpio_write_pin handles, so the call changes nothing. Called by APPSetPowerOff and power_enter_app_state.
 */
void gpio_set_aux_bit1_low(void)
{
  gpio_write_pin(GPIO_PORT_AUX, 0x02, GPIO_LEVEL_LOW);
}
