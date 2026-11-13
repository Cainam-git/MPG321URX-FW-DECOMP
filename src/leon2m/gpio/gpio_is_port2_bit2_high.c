/* gpio_is_port2_bit2_high  (FUN_a0125ae4)
 *
 * Return whether pin 2 of GPIO port 2 reads high.
 * Returns: 0 or 1
 * Name basis: descriptive - gpio_read_pin(0x2, 0x4); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125ae4 @ 0xa0125ae4, flags -mcpu=v8 -O3 -g.
 * Source form: the result is `((level & 0xff) ^ 1) == 0`; the compiler computes it without a branch (cmp
 * followed by subx %g0, -1).
 */
extern int gpio_read_pin(int, int);

/*
 * Read mask 4 (pin 2) of GPIO port 2 and return 1 when the low byte of the answer is 1, else 0.
 * No routine of the main program calls it.
 */
int gpio_is_port2_bit2_high(void)
{
    int level = gpio_read_pin(2, 4);
    return ((level & 0xff) ^ 1) == 0;
}
