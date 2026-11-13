/* gpio_set_aux_bit1_mode_ff  (FUN_a0125b28)
 *
 * Pass level 0xFF for pin 1 of GPIO port number 0xFF; no pin changes (gpio_write_pin: ports 1..17).
 * Note: gpio_write_pin has no arm for port 0xFF, so the call writes nothing; no routine in the source calls
 *   it.
 * Name basis: descriptive - gpio_write_pin(0xFF, 0x2, 0xFF); port number 0xFF is not among the ports 1..17 the
 *   pin routines serve
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125b28 @ 0xa0125b28, flags -mcpu=v8 -O2 -g.
 * Source form: the single call is a tail call (the callee returns to this routine's caller; the nop after it is the
 * delay slot).
 */
extern void gpio_write_pin(unsigned char, unsigned char, unsigned char);

/*
 * Write level 0xff to mask 2 (pin 1) of port 0xff. Port 0xff is not one of the ports 1..17 that gpio_write_pin
 * handles, so the call changes nothing. No routine of the main program calls it.
 */
void gpio_set_aux_bit1_mode_ff(void)
{
    gpio_write_pin(0xff, 2, 0xff);
}
