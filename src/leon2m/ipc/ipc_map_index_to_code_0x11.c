/* ipc_map_index_to_code_0x11  (FUN_a0132d44)
 *
 * Convert an index 1..13 to a code 0x11..0x1D.
 * Returns: code or 0
 * Name basis: descriptive - 18 also gives 0x11; unused
 *
 * Matching notes
 * --------------
 * FUN_a0132d44 (leon2m 0xa0132d44-0xa0132dd8, 148 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: code = 0 before a switch with cases 1..13 ascending and a separate case 18 (jump table at run-time
 * 0xd2a74, image 0xa0132a74); return code & 0x1f.
 */

/*
 * Map index 1..13 to 0x11..0x1D and index 18 to 0x11; every other index gives 0. The result is cut to five bits
 * (all values above fit).
 *
 * Nothing in the image refers to this routine: no call, branch, address constant or address word. Its static
 * copies in ipc_8051_build_wake_table and ipc_8051_build_fixed_wake_table get a GPIO port number (the port that
 * gpio_read_pin reads there) and give the code byte of a wake table pair, 0x10 + port.
 */
unsigned char ipc_map_index_to_code_0x11(unsigned char index)
{
    unsigned char code = 0;

    switch (index) {
    case 1:
        code = 0x11;
        break;
    case 2:
        code = 0x12;
        break;
    case 3:
        code = 0x13;
        break;
    case 4:
        code = 0x14;
        break;
    case 5:
        code = 0x15;
        break;
    case 6:
        code = 0x16;
        break;
    case 7:
        code = 0x17;
        break;
    case 8:
        code = 0x18;
        break;
    case 9:
        code = 0x19;
        break;
    case 10:
        code = 0x1a;
        break;
    case 11:
        code = 0x1b;
        break;
    case 12:
        code = 0x1c;
        break;
    case 13:
        code = 0x1d;
        break;
    case 18:
        code = 0x11;
        break;
    }
    return code & 0x1f;
}
