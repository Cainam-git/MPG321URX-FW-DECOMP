/* gpio_set_aux_bit1_mode0  (FUN_a0125b0c)
 *
 * Pass level 0x00 for pin 1 of GPIO port number 0xFF; no pin changes (gpio_write_pin: ports 1..17).
 * Note: gpio_write_pin has no arm for port 0xFF, so the call writes nothing; no routine in the source calls
 *   it.
 * Name basis: descriptive - gpio_write_pin(0xFF, 0x2, 0x0); port number 0xFF is not among the ports 1..17 the
 *   pin routines serve
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125b0c @ 0xa0125b0c, flags -mcpu=v8 -O2 -g.
 * Source form: the single call is a tail call (the callee returns to this routine's caller; the nop after it is the
 * delay slot).
 */
extern void gpio_write_pin(unsigned char, unsigned char, unsigned char);

/*
 * Write level 0 to mask 2 (pin 1) of port 0xff. Port 0xff is not one of the ports 1..17 that gpio_write_pin
 * handles, so the call changes nothing. No routine of the main program calls it.
 */
void gpio_set_aux_bit1_mode0(void)
{
    gpio_write_pin(0xff, 2, 0);
}
