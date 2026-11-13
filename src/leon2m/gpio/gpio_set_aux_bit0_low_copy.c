/* gpio_set_aux_bit0_low_copy  (FUN_a0124a24)
 *
 * Ask for pin 0 of GPIO port number 0xFF to go low; no pin changes (gpio_write_pin: ports 1..17).
 * Note: gpio_write_pin has no arm for port 0xFF, so the call writes nothing; no routine in the source calls
 *   it.
 * Name basis: descriptive - gpio_write_pin(0xFF, 0x1, 0xFE); port number 0xFF is not among the ports 1..17 the
 *   pin routines serve
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124a24 @ 0xa0124a24, flags -mcpu=v8 -O2 -g.
 * Source form: the single call is a tail call (the callee returns to this routine's caller; the nop after it is the
 * delay slot).
 */
extern void gpio_write_pin(unsigned char, unsigned char, unsigned char);

/*
 * Write level 0xfe (bit 0 clear) to mask 1 of port 0xff. Port 0xff is not one of the ports 1..17 that
 * gpio_write_pin handles, so the call changes nothing. Nothing calls this routine.
 */
void gpio_set_aux_bit0_low_copy(void)
{
    gpio_write_pin(0xff, 1, 0xfe);
}
