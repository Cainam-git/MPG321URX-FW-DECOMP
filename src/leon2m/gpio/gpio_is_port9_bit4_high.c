/* gpio_is_port9_bit4_high  (FUN_a012493c)
 *
 * Return whether pin 4 of GPIO port 9 reads high.
 * Returns: 0 or 1
 * Name basis: descriptive - gpio_read_pin(0x9, 0x10); read by the OLED power state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012493c, flags -mcpu=v8 -O3 -g.
 * Source form: '((x & 0xff) ^ 1) == 0' compiles branch-free: 'cmp %g0, x' sets the carry for a nonzero x and
 * 'subx %g0, -1, %i0' yields 1 - carry.
 */
#define GPIO_PORT_9    9
#define PIN_4_MASK     0x10

extern int gpio_read_pin(int, int);

/* Return 1 when pin 4 of GPIO port 9 reads high, else 0. Called by oled_power_task. */
int gpio_is_port9_bit4_high(void)
{
    int level = gpio_read_pin(GPIO_PORT_9, PIN_4_MASK);
    return ((level & 0xff) ^ 1) == 0;
}
