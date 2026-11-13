/* gpio_is_port2_bit3_high  (FUN_a0125b44)
 *
 * Return whether pin 3 of GPIO port 2 reads high.
 * Returns: 0 or 1
 * Name basis: descriptive - gpio_read_pin(0x2, 0x8)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125b44 @ 0xa0125b44, flags -mcpu=v8 -O3 -g.
 * Source form: the result is built in three steps (`level`, `low_byte`, `differs`); the two parameters are
 * declared but not used.
 */
extern int gpio_read_pin(int a, int b);

/*
 * Read mask 8 (pin 3) of GPIO port 2 and return 1 when the low byte of the answer is 1, else 0.
 * The two parameters are not used. No routine of the main program calls it.
 */
int gpio_is_port2_bit3_high(int unused1, int unused2)
{
    int level = gpio_read_pin(2, 8);
    int low_byte = level & 0xff;
    int differs = low_byte ^ 1;
    return differs == 0;
}
