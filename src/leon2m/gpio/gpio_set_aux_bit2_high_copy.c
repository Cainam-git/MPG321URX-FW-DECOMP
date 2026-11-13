/* gpio_set_aux_bit2_high_copy  (FUN_a0124eec)
 *
 * Ask for pin 2 of GPIO port number 0xFF to go high; no pin changes (gpio_write_pin: ports 1..17).
 * Note: gpio_write_pin has no arm for port 0xFF, so the call writes nothing; called by System_Initialize.
 * Name basis: descriptive - gpio_write_pin(0xFF, 0x4, 0x1); port number 0xFF is not among the ports 1..17 the
 *   pin routines serve
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124eec @ 0xa0124eec, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Write level 1 (high) to mask 4 (pin 2) of port 0xff. Port 0xff is not one of the ports 1..17 that
 * gpio_write_pin handles, so the call changes nothing.
 * Called by System_Initialize.
 */
void gpio_set_aux_bit2_high_copy(void)
{
    gpio_write_pin(0xff, 4, 1);
}
