/* gpio_is_port10_bit2_high  (FUN_a0124964)
 *
 * Return whether pin 2 of GPIO port 10 reads high.
 * Returns: 0 or 1
 * Name basis: descriptive - gpio_read_pin(0xa, 0x4)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124964, flags -mcpu=v8 -O3 -g.
 * Source form: '((r & 0xff) ^ 1) == 0': the and result goes to %g1, the xor follows, and the `== 0` compiles to
 * cmp %g0, x / subx %g0, -1, %i0 (1 minus the carry).
 */
#define GPIO_PORT_10   10
#define PIN_2_MASK     4

extern int gpio_read_pin(int, int);

/* Return 1 when pin 2 of GPIO port 10 reads high, else 0. Called by sys_run_app_timer_task. */
int gpio_is_port10_bit2_high(void)
{
    int level = gpio_read_pin(GPIO_PORT_10, PIN_2_MASK);
    return ((level & 0xff) ^ 1) == 0;
}
