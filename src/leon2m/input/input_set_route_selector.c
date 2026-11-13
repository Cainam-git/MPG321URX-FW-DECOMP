/* input_set_route_selector  (FUN_a00fe718)
 *
 * Write the 2-bit route selector, or switch the route off.
 * Name basis: descriptive - bits 6-7 of 0xCF0116DC with bit 5 of 0xCF02DC04
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fe718 @ 0xa00fe718, 192 bytes, leaf, flags -mcpu=v8 -O3 -g.
 * Source form: the low six bits of the register are read into an unsigned char before the switch.
 */
#define ROUTE_SELECT_REG (*(volatile unsigned int *)0xcf0116dc)
#define ROUTE_ENABLE_REG (*(volatile unsigned int *)0xcf02dc04)
/* Select the route 0, 1 or 2, or switch the route off (3). For 0 to 2 bit 5 of 0xCF02DC04 is set and 0xCF0116DC
 * is written with its low six bits kept and 0 (route 0), 0x80 (route 1) or 0xC0 (route 2) in bits 6-7. For 3
 * only bit 5 of 0xCF02DC04 is cleared. Other values change nothing. Called by sys_api_set_block_selector, which
 * passes 0 to 3 through. input_get_route_selector reads the value back. */
void input_set_route_selector(unsigned char route)
{
    unsigned char low_bits = ROUTE_SELECT_REG & 0x3f;
    switch (route) {
    case 0:
        ROUTE_ENABLE_REG |= 0x20;
        ROUTE_SELECT_REG = low_bits;
        break;
    case 1:
        ROUTE_ENABLE_REG |= 0x20;
        ROUTE_SELECT_REG = low_bits | 0x80;
        break;
    case 2:
        ROUTE_ENABLE_REG |= 0x20;
        ROUTE_SELECT_REG = low_bits | 0xc0;
        break;
    case 3:
        ROUTE_ENABLE_REG &= ~0x20u;
        break;
    }
}
