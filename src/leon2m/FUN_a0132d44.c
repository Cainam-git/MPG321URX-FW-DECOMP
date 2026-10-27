/* FUN_a0132d44 (leon2m 0xa0132d44-0xa0132dd8, 148 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Maps c = 1..13 to 0x11..0x1d and c = 18 to 0x11; any other value gives 0 (five-bit result). Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a0132cd4 and FUN_a0132dd8.
 * Source form: r = 0 before a switch with cases 1..13 ascending and a separate case 18 (jump table at run-time
 * 0xd2a74, image 0xa0132a74); return r & 0x1f.
 */
unsigned char FUN_a0132d44(unsigned char c)
{
    unsigned char r = 0;

    switch (c) {
    case 1:
        r = 0x11;
        break;
    case 2:
        r = 0x12;
        break;
    case 3:
        r = 0x13;
        break;
    case 4:
        r = 0x14;
        break;
    case 5:
        r = 0x15;
        break;
    case 6:
        r = 0x16;
        break;
    case 7:
        r = 0x17;
        break;
    case 8:
        r = 0x18;
        break;
    case 9:
        r = 0x19;
        break;
    case 10:
        r = 0x1a;
        break;
    case 11:
        r = 0x1b;
        break;
    case 12:
        r = 0x1c;
        break;
    case 13:
        r = 0x1d;
        break;
    case 18:
        r = 0x11;
        break;
    }
    return r & 0x1f;
}
