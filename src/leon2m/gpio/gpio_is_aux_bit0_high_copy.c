/* gpio_is_aux_bit0_high_copy  (FUN_a0125b6c)
 *
 * Read pin 0 of GPIO port number 0xFF; gpio_read_pin answers 0 for that port, so the result is 0.
 * Returns: always 0
 * Note: Port number 0xFF has no register (ports 1..17 only); no routine in the source calls it.
 * Name basis: descriptive - gpio_read_pin(0xFF, 1); port number 0xFF is not among the ports 1..17 the pin
 *   routines serve
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125b6c @ 0xa0125b6c, flags -mcpu=v8 -O3 -g.
 * Source form: the result is `((gpio_read_pin(0xff, 1) & 0xff) ^ 1) == 0` in one expression; the `== 0` compiles
 * to `cmp %g0, x` / `subx %g0, -1, %i0` (1 minus the carry set by the cmp).
 */
extern int gpio_read_pin(int, int);

/*
 * Read mask 1 of port 0xff and return 1 when the low byte of the answer is 1. Port 0xff is not one of the ports
 * 1..17 that gpio_read_pin handles, so it always answers 0 and this routine always returns 0.
 * No routine of the main program calls it.
 */
int gpio_is_aux_bit0_high_copy(void)
{
    return ((gpio_read_pin(0xff, 1) & 0xff) ^ 1) == 0;
}
