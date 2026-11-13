/* gpio_set_port6_bit2_high_copy  (FUN_a0125898)
 *
 * Drive pin 2 of GPIO port 6 high (second copy).
 * Name basis: descriptive - same call as gpio_set_port6_bit2_high, as a tail call
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125898 @ 0xa0125898, flags -mcpu=v8 -O2 -g.
 * Source form: the single call is a tail call (the callee returns to this routine's caller; the nop after it is the
 * delay slot).
 */
extern void gpio_write_pin(unsigned char, unsigned char, unsigned char);

/*
 * Write level 1 (high) to mask 4 (pin 2) of GPIO port 6: the same call as gpio_set_port6_bit2_high.
 * Called by power_enter_app_state.
 */
void gpio_set_port6_bit2_high_copy(void)
{
    gpio_write_pin(6, 4, 1);
}
