/* gpio_map_index_to_8051_address  (FUN_a00ddbe0)
 *
 * Convert an index 1..8 to an 8051 register address.
 * Returns: address or 0
 * Name basis: descriptive - 0xF00C..0xF00F and 0xF081..0xF084; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ddbe0 @ 0xa00ddbe0-0xa00ddc50, 112 bytes, leaf, flags -mcpu=v8 -O3 -g.
 * Source form: the result is set to 0 before a switch with cases 1..8 in ascending order (jump table at
 * run-time 0x7d8e0, image 0xa00dd8e0).
 */
/*
 * Return the 8051 address that belongs to an index: 1..4 give 0xF00C..0xF00F, 5..8 give 0xF081..0xF084; any
 * other index gives 0. Nothing in the image calls this routine or stores its address.
 */
unsigned short gpio_map_index_to_8051_address(unsigned char index)
{
    unsigned short address = 0;

    switch (index) {
    case 1:
        address = 0xf00c;
        break;
    case 2:
        address = 0xf00d;
        break;
    case 3:
        address = 0xf00e;
        break;
    case 4:
        address = 0xf00f;
        break;
    case 5:
        address = 0xf081;
        break;
    case 6:
        address = 0xf082;
        break;
    case 7:
        address = 0xf083;
        break;
    case 8:
        address = 0xf084;
        break;
    }
    return address;
}
