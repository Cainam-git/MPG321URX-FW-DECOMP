/* leon2m FUN_a012e8c0 @ 0xa012e8c0
 * Maps the byte argument to a single-bit byte: 0x10 -> 0x02, 0x11 -> 0x04, 0x12 -> 0x01, 0x13 -> 0x10,
 * 0x14 -> 0x20, 0x15 -> 0x40, 0x16 -> 0x80, any other value -> 0x01. Called by FUN_a014c118.
 * Source form: a switch (jump table at ROM 0xccea0) with case 0x12 written last, setting an unsigned char r that
 * is returned as int; the final and 0xf7 is the zero extension reduced to the bits any result can have.
 */
int FUN_a012e8c0(unsigned char v)
{
    unsigned char r;

    switch (v) {
    case 0x10:
        r = 0x2;
        break;
    case 0x11:
        r = 0x4;
        break;
    case 0x13:
        r = 0x10;
        break;
    case 0x14:
        r = 0x20;
        break;
    case 0x15:
        r = 0x40;
        break;
    case 0x16:
        r = 0x80;
        break;
    case 0x12:
        r = 0x1;
        break;
    default:
        r = 1;
        break;
    }
    return r;
}
