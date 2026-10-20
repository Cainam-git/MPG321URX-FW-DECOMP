/* FUN_a00d6624 (leon2s 0xa00d6624-0xa00d6694, 112 bytes), flags -mcpu=v8 -Os -g.
 * v = bits 6-7 of the byte returned by the ROM routine func_0xa0fb6bb8(port, 0x9f). Returns 0 for port 1;
 * otherwise returns v (0..3) through a switch that names all four values (an explicit case 0 makes GCC's
 * decision tree test 1 first, as the firmware does).
 */
extern unsigned char func_0xa0fb6bb8(unsigned char, unsigned int);

unsigned char FUN_a00d6624(unsigned char port)
{
    unsigned char v = func_0xa0fb6bb8(port, 0x9f) >> 6;
    unsigned char r = 0;

    if (port == 1)
        return 0;
    switch (v) {
    case 0: r = 0; break;
    case 1: r = 1; break;
    case 2: r = 2; break;
    case 3: r = 3; break;
    }
    return r;
}
