/* gpio_is_port11_bit1_low  (FUN_a0125a88)
 *
 * Return whether pin 1 of GPIO port 11 reads low.
 * Returns: 0 or 1
 * Name basis: descriptive - gpio_read_pin(0xb, 0x2)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125a88 @ 0xa0125a88, flags -mcpu=v8 -O2 -g.
 * Source form: the result is `(level & 0xff) == 0` (compiled to `and` / `cmp %g0, %o0` / `subx %g0, -1, %i0`).
 */
extern int gpio_read_pin(int, int);

/*
 * Read mask 2 (pin 1) of GPIO port 11 and return 1 when the low byte of the answer is 0, else 0.
 * Called by UsbModeSelectRoutine.
 */
int gpio_is_port11_bit1_low(void)
{
    int level = gpio_read_pin(0xb, 2);
    return (level & 0xff) == 0;
}
