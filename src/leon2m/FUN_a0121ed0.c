/* FUN_a0121ed0 (leon2m 0xa0121ed0-0xa0121f20, 80 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Maps c to a three-bit code: 1 -> 1, 2 -> 2, 3 -> 3, 4 -> 5, anything else -> 0. Nothing in the image refers to
 * it: no call, branch, sethi/or constant or address word. It lies between FUN_a0121ec8 and FUN_a0121f20. Source
 * form: a switch with the cases in the order 2, 3, 4, 1, default; return r & 7.
 */
unsigned char FUN_a0121ed0(unsigned char c)
{
    unsigned char r;

    switch (c) {
    case 2:
        r = 2;
        break;
    case 3:
        r = 3;
        break;
    case 4:
        r = 5;
        break;
    case 1:
        r = 1;
        break;
    default:
        r = 0;
        break;
    }
    return r & 7;
}
