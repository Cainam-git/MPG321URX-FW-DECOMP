/* input_set_shared_route  (FUN_a00fdf44)
 *
 * Point the shared route at an input block 0..7, or clear it.
 * Name basis: descriptive - block * 0x11 to register 0xCF02010C; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fdf44 @ 0xa00fdf44, 48 bytes, leaf, flags -mcpu=v8 -O3 -g.
 * Source form: an unsigned int parameter; only the comparison uses its low byte.
 */
#define SHARED_ROUTE_REG (*(volatile unsigned int *)0xcf02010c)
/* Write (block << 4) | block to the shared route register (0xCF02010C) for a block from 0 to 7, and 0 for any
 * other value. Nothing calls this routine; input_reroute_shared_block writes the same form. */
void input_set_shared_route(unsigned int block)
{
    unsigned char route = 0;
    if ((unsigned char)block <= 7)
        route = (block << 4) | block;
    SHARED_ROUTE_REG = route;
}
