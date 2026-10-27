/* FUN_a00cf194 (leon2m 0xa00cf194-0xa00cf1ec, 88 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Maps c to a code: 5 -> 1, 6 -> 4, 8 -> 7, 0xb -> 0x17, anything else -> 0. Nothing in the image refers to it: no
 * call, branch, sethi/or constant or address word. It lies between switchdataD_a00cf178 and FUN_a00cf1ec. Source
 * form: r = 0 before a switch with cases 5, 6, 8, 0xb in ascending order; return r & 0x17.
 */
unsigned char FUN_a00cf194(unsigned char c)
{
    unsigned char r = 0;

    switch (c) {
    case 5:
        r = 1;
        break;
    case 6:
        r = 4;
        break;
    case 8:
        r = 7;
        break;
    case 0xb:
        r = 0x17;
        break;
    }
    return r & 0x17;
}
