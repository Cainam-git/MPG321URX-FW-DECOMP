/* gpio_set_aux_bit5_low  (FUN_a0125be0)
 *
 * Ask for pin 5 of GPIO port number 0xFF to go low; no pin changes (gpio_write_pin: ports 1..17).
 * Note: gpio_write_pin has no arm for port 0xFF, so the call writes nothing; called by APPSetPowerOff,
 *   power_enter_app_state.
 * Name basis: descriptive - gpio_write_pin(0xFF, 0x20, 0xFE); port number 0xFF is not among the ports 1..17
 *   the pin routines serve
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125be0 @ 0xa0125be0, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Write level 0xfe (bit 0 clear: low) to mask 0x20 (pin 5) of port 0xff.
 * Port 0xff is not one of the ports 1..17 that gpio_write_pin handles, so the call changes nothing.
 * Called by APPSetPowerOff and power_enter_app_state.
 */
void gpio_set_aux_bit5_low(void)
{
    gpio_write_pin(0xff, 0x20, 0xfe);
}
