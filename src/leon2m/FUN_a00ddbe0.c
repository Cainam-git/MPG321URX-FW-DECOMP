/* FUN_a00ddbe0 (leon2m 0xa00ddbe0-0xa00ddc50, 112 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Maps c = 1..8 to the halfwords 0xf00c, 0xf00d, 0xf00e, 0xf00f, 0xf081, 0xf082, 0xf083, 0xf084; any other value
 * gives 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a00ddae4 and switchdataD_a00ddc50. Source form: r = 0 before a switch with cases 1..8 in ascending order
 * (jump table at run-time 0x7d8e0, image 0xa00dd8e0).
 */
unsigned short FUN_a00ddbe0(unsigned char c)
{
    unsigned short r = 0;

    switch (c) {
    case 1:
        r = 0xf00c;
        break;
    case 2:
        r = 0xf00d;
        break;
    case 3:
        r = 0xf00e;
        break;
    case 4:
        r = 0xf00f;
        break;
    case 5:
        r = 0xf081;
        break;
    case 6:
        r = 0xf082;
        break;
    case 7:
        r = 0xf083;
        break;
    case 8:
        r = 0xf084;
        break;
    }
    return r;
}
