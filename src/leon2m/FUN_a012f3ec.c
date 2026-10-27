/* FUN_a012f3ec (leon2m 0xa012f3ec-0xa012f43c, 80 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns a three-bit code from the byte DAT_a802e1a7 (v): 1 for v = 0, 2 for v = 1, 2, 5, 3 for v = 3, 6, 4 for v
 * = 4, 7, and 1 for v above 7. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a012f3b4 and FUN_a012f43c. Source form: a switch with a jump table (8 words at
 * 0xa012f14c, run-time address 0xcf14c); case order default, 0, 4/7, 3/6, 1/2/5 gives the firmware block order;
 * return r & 7.
 */
extern unsigned char DAT_a802e1a7;

unsigned char FUN_a012f3ec(void)
{
    unsigned char r;

    switch (DAT_a802e1a7) {
    default:
        r = 1;
        break;
    case 0:
        r = 1;
        break;
    case 4:
    case 7:
        r = 4;
        break;
    case 3:
    case 6:
        r = 3;
        break;
    case 1:
    case 2:
    case 5:
        r = 2;
        break;
    }
    return r & 7;
}
