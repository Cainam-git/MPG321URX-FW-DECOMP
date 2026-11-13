/* sys_api_set_block_selector  (FUN_a0132850)
 *
 * Forward a selector 0..3 to the block routine.
 * Name basis: descriptive - tail call for values 0..3; unused
 *
 * Matching notes
 * --------------
 * FUN_a0132850 (leon2m 0xa0132850-0xa01328d4, 132 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: a switch with a constant argument per case.
 */
extern void input_set_route_selector(unsigned char);

/* Pass selector 0..3 on to input_set_route_selector as a tail call; other values do nothing. Not called by name anywhere in the source. */
void sys_api_set_block_selector(unsigned char selector)
{
    switch (selector) {
    case 0:
        input_set_route_selector(0);
        break;
    case 1:
        input_set_route_selector(1);
        break;
    case 2:
        input_set_route_selector(2);
        break;
    case 3:
        input_set_route_selector(3);
        break;
    }
}
