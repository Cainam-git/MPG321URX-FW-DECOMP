/* dp_get_reg9f_field  (FUN_a00d6624)
 *
 * Return the 2-bit field at bits 6-7 of register 0x9F of a port.
 * Returns: 0..3
 * Name basis: descriptive - 0 for port 1
 *
 * Matching notes
 * --------------
 * FUN_a00d6624 (leon2s 0xa00d6624-0xa00d6694, 112 bytes), flags -mcpu=v8 -Os -g.
 * The switch names all four values (an explicit case 0 makes GCC's decision tree test 1 first, as the
 * firmware does).
 */
extern unsigned char dp_reg_read8(unsigned char, unsigned int);

/* Return bits 6..7 of register 0x9F of DisplayPort receiver `port` (0..3); 0 for port 1. */
unsigned char dp_get_reg9f_field(unsigned char port)
{
    unsigned char field = dp_reg_read8(port, 0x9f) >> 6;
    unsigned char result = 0;

    if (port == 1)
        return 0;
    switch (field) {
    case 0: result = 0; break;
    case 1: result = 1; break;
    case 2: result = 2; break;
    case 3: result = 3; break;
    }
    return result;
}
