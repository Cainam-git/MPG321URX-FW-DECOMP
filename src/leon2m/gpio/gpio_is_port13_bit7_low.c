/* gpio_is_port13_bit7_low  (FUN_a01248f0)
 *
 * Return whether pin 7 of GPIO port 13 reads low.
 * Returns: 0 or 1
 * Name basis: descriptive - gpio_read_pin(0xd, 0x80)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01248f0, flags -mcpu=v8 -O2 -g.
 * Source form: `return (x & 0xff) == 0;` gives and / cmp %g0, %o0 / subx %g0, -1, %i0.
 */
#define GPIO_PORT_13   0xd
#define PIN_7_MASK     0x80

extern int gpio_read_pin(int, int);

/* Return 1 when pin 7 of GPIO port 13 reads low, else 0. Called by sys_run_app_timer_task. */
int gpio_is_port13_bit7_low(void)
{
    int level;
    level = gpio_read_pin(GPIO_PORT_13, PIN_7_MASK);
    return (level & 0xff) == 0;
}
