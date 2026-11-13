/* gpio_is_port13_bit4_high  (FUN_a0125e38)
 *
 * Return whether pin 4 of GPIO port 13 reads high.
 * Returns: 0 or 1
 * Name basis: descriptive - gpio_read_pin(0xd, 0x10)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125e38 @ 0xa0125e38 (-mcpu=v8 -O3 -g)
 * Required form: (x & 0xff) ^ 1 in a named intermediate, so the and result stays in %g1 instead of overwriting
 * %o0, and the comparison returned directly, which gives cmp %g0, t / subx %g0, -1, %i0 instead of a clr/or
 * sequence.
 */
extern int gpio_read_pin(int port, int pin_mask); /* at 0x4008cd38 */

#define GPIO_PORT_13 13
#define PIN_MASK_BIT4 0x10

/*
 * Read pin mask 0x10 of GPIO port 13 and return 1 when gpio_read_pin answers 1 (low byte), else 0. Called by
 * sys_ddr_init and sys_ddr_init_select_script, where this pin (low = old script, high = new) selects the
 * memory set-up script.
 */
int gpio_is_port13_bit4_high(void)
{
    int level = gpio_read_pin(GPIO_PORT_13, PIN_MASK_BIT4);
    int differs_from_one = (level & 0xff) ^ 1;
    return differs_from_one == 0;
}
