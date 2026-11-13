/* gpio_set_aux_bit2_high  (FUN_a0125d58)
 *
 * Ask for pin 2 of GPIO port number 0xFF to go high; no pin changes (gpio_write_pin: ports 1..17).
 * Note: gpio_write_pin has no arm for port 0xFF, so the call writes nothing; no routine in the source calls
 *   it.
 * Name basis: descriptive - gpio_write_pin(0xFF, 0x4, 0x1); port number 0xFF is not among the ports 1..17 the
 *   pin routines serve
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125d58 @ 0xa0125d58-0xa0125d74 (7 words), flags -mcpu=v8 -O2 -g.
 * The call is a tail call: the callee returns straight to this routine's caller, and the last word is the nop
 * that follows such a call sequence.
 */
extern void gpio_write_pin(unsigned char port, unsigned char pin_mask, unsigned char level);

#define GPIO_PORT_AUX 0xff                      /* not one of the ports 1..17 that gpio_write_pin handles */
#define GPIO_LEVEL_HIGH 1                       /* only bit 0 of the level counts */
#define GPIO_LEVEL_LOW 0xfe

/*
 * Write the high level to pin mask 0x04 of port 0xff. Port 0xff is not one of the ports 1..17 that
 * gpio_write_pin handles, so the call changes nothing. Nothing calls this routine.
 */
void gpio_set_aux_bit2_high(void)
{
    gpio_write_pin(GPIO_PORT_AUX, 0x04, GPIO_LEVEL_HIGH);
}
