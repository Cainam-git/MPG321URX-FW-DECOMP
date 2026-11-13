/* gpio_set_aux_bit6_low  (FUN_a0125934)
 *
 * Ask for pin 6 of GPIO port number 0xFF to go low; no pin changes (gpio_write_pin: ports 1..17).
 * Note: gpio_write_pin has no arm for port 0xFF, so the call writes nothing; called by App_Initialize,
 *   APPSetPowerOff.
 * Name basis: descriptive - gpio_write_pin(0xFF, 0x40, 0xFE); port number 0xFF is not among the ports 1..17
 *   the pin routines serve
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125934 @ 0xa0125934, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Write level 0xfe (bit 0 clear: low) to mask 0x40 (pin 6) of port 0xff.
 * Port 0xff is not one of the ports 1..17 that gpio_write_pin handles, so the call changes nothing.
 * Called by APPSetPowerOff and App_Initialize.
 */
void gpio_set_aux_bit6_low(void)
{
    gpio_write_pin(0xff, 0x40, 0xfe);
}
