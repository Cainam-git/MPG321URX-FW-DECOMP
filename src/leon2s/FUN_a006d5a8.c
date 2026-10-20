/* FUN_a006d5a8 (leon2s 0xa006d5a8-0xa006d61c, 116 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Maps the codes 0x31, 0x41, 0x51, 0x61, 0x71, 0x81 to 0..5 and every other value to 0; the result is
 * returned as r & 7.
 */
unsigned char FUN_a006d5a8(unsigned char code)
{
    unsigned char r = 0;

    switch (code) {
    case 0x31: r = 0; break;
    case 0x41: r = 1; break;
    case 0x51: r = 2; break;
    case 0x61: r = 3; break;
    case 0x71: r = 4; break;
    case 0x81: r = 5; break;
    }
    return r & 7;
}
