/* gpio_get_port_8051_address  (FUN_a00de444)
 *
 * Return the 8051 address 0xF000..0xF303 of GPIO port 1..17.
 * Returns: address or 0
 * Name basis: descriptive - constant per port
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de444 @ 0xa00de444-0xa00de4fc (46 words).
 * Source form: the result is set to 0 before a switch with one case per port.
 */
/*
 * Return the 8051 address of a GPIO port: ports 1..5 give 0xF000..0xF004, 6 gives 0xF010, 7 gives 0xF012,
 * 8..13 give 0xF114..0xF11E in steps of 2, 14..17 give 0xF300..0xF303; any other number gives 0.
 * Called from input_get_key_table_entry.
 */
unsigned short gpio_get_port_8051_address(unsigned char port)
{
    unsigned short address = 0;

    switch (port) {
    case 1: address = 0xf000; break;
    case 2: address = 0xf001; break;
    case 3: address = 0xf002; break;
    case 4: address = 0xf003; break;
    case 5: address = 0xf004; break;
    case 6: address = 0xf010; break;
    case 7: address = 0xf012; break;
    case 8: address = 0xf114; break;
    case 9: address = 0xf116; break;
    case 10: address = 0xf118; break;
    case 11: address = 0xf11a; break;
    case 12: address = 0xf11c; break;
    case 13: address = 0xf11e; break;
    case 14: address = 0xf300; break;
    case 15: address = 0xf301; break;
    case 16: address = 0xf302; break;
    case 17: address = 0xf303; break;
    }
    return address;
}
