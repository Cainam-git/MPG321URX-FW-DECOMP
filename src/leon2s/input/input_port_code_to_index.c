/* input_port_code_to_index  (FUN_a00c5fb0)
 *
 * Convert a port code 0x31..0x81 to the input number 0..5.
 * Returns: index or 0xFF
 * Name basis: derived - codes in steps of 0x10
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c5fb0 @ 0xa00c5fb0, flags -mcpu=v8 -Os -g. A leaf routine; the switch has no jump table.
 */

/* Convert the port code 0x31 + 0x10 * n (0x31, 0x41, 0x51, 0x61, 0x71, 0x81) to the input number n (0..5). Any other code gives 0xff. */
unsigned char input_port_code_to_index(unsigned char code)
{
    unsigned char index;

    switch (code) {
    case 0x31: index = 0; break;
    case 0x41: index = 1; break;
    case 0x51: index = 2; break;
    case 0x61: index = 3; break;
    case 0x71: index = 4; break;
    case 0x81: index = 5; break;
    default: index = 0xff; break;
    }
    return index;
}
