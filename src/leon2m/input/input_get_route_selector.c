/* input_get_route_selector  (FUN_a00fe7d8)
 *
 * Return the 2-bit route selector, or 3 when the route is off.
 * Returns: 0..3
 * Name basis: descriptive - 0xCF0116DC and bit 5 of 0xCF02DC04; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fe7d8 @ 0xa00fe7d8, 72 bytes, leaf, flags -mcpu=v8 -O3 -g.
 * Source form: 3 as the default, an if/else chain on the masked value, and "return result & 3".
 */
#define ROUTE_ENABLE_REG (*(volatile unsigned int *)0xcf02dc04)
#define ROUTE_SELECT_REG (*(volatile unsigned int *)0xcf0116dc)
/* Return the route that input_set_route_selector stored: 3 when bit 5 of 0xCF02DC04 is clear; otherwise from
 * bits 6-7 of 0xCF0116DC: 0 when both are clear, 1 for 0x80, and 2 for any other value. Nothing calls this
 * routine. */
unsigned char input_get_route_selector(void)
{
    unsigned char result = 3;
    unsigned int bits;
    if (ROUTE_ENABLE_REG & 0x20) {
        bits = ROUTE_SELECT_REG & 0xc0;
        if (bits == 0)
            result = 0;
        else if (bits == 0x80)
            result = 1;
        else
            result = 2;
    }
    return result & 3;
}
