/* gpio_is_port7_bit3_high  (FUN_a0125a60)
 *
 * Return whether pin 3 of GPIO port 7 reads high.
 * Returns: 0 or 1
 * Name basis: descriptive - gpio_read_pin(0x7, 0x8)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125a60 @ 0xa0125a60, flags -mcpu=v8 -O3 -g.
 * Source form: the result is `((level & 0xff) ^ 1) == 0`; the `== 0` compiles to `cmp %g0, x` / `subx %g0, -1, %i0`
 * (1 minus the carry set by the cmp).
 */
extern int gpio_read_pin(int, int);

/*
 * Read mask 8 (pin 3) of GPIO port 7 and return 1 when the low byte of the answer is 1, else 0.
 * Called by UsbModeSelectRoutine.
 */
int gpio_is_port7_bit3_high(void)
{
    int level;
    level = gpio_read_pin(7, 8);
    return ((level & 0xff) ^ 1) == 0;
}
