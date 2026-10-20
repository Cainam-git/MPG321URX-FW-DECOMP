/* FUN_a01182cc: returns one byte of the 4-byte state record at 0xa8027a90: byte 1, 2 or 3 for
 * an index of 1, 2 or 3, byte 0 for any other index. Called repeatedly from FUN_a014d5f4.
 * The index is a u8 parameter; the selection is a switch (signed compare chain after promotion).
 */
struct Rec4 { unsigned char b0, b1, b2, b3; };
extern struct Rec4 DAT_a8027a90;

unsigned char FUN_a01182cc(unsigned char i)
{
    unsigned char r;

    switch (i) {
    case 1:
        r = DAT_a8027a90.b1;
        break;
    case 2:
        r = DAT_a8027a90.b2;
        break;
    case 3:
        r = DAT_a8027a90.b3;
        break;
    default:
        r = DAT_a8027a90.b0;
        break;
    }
    return r;
}
