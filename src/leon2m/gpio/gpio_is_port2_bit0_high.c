/* gpio_is_port2_bit0_high  (FUN_a0125b94)
 *
 * Return whether pin 0 of GPIO port 2 reads high.
 * Returns: 0 or 1
 * Name basis: descriptive - gpio_read_pin(0x2, 0x1)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125b94 @ 0xa0125b94, flags -mcpu=v8 -O3 -g.
 * Source form: the result is built in two steps (`level`, `differs`); `differs == 0` compiles to `cmp %g0, %o0` /
 * `subx %g0, -1, %i0`. Frame: `save %sp, -104, %sp`.
 */
extern int gpio_read_pin(int, int);

/*
 * Read mask 1 (pin 0) of GPIO port 2 and return 1 when the low byte of the answer is 1, else 0.
 * No routine of the main program calls it.
 */
int gpio_is_port2_bit0_high(void)
{
    int level = gpio_read_pin(2, 1);
    int differs = (level & 0xff) ^ 1;
    return differs == 0;
}
