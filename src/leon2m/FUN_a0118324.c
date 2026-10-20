/* FUN_a0118324: stores the byte v into byte i (0..3) of the 4-byte state record at 0xa8027a90;
 * any other index stores nothing. Called from FUN_a014d5f4. Counterpart of the getter FUN_a01182cc.
 * Both parameters are u8; the selection is a switch.
 */
struct Rec4 { unsigned char b0, b1, b2, b3; };
extern struct Rec4 DAT_a8027a90;

void FUN_a0118324(unsigned char i, unsigned char v)
{
    switch (i) {
    case 0:
        DAT_a8027a90.b0 = v;
        break;
    case 1:
        DAT_a8027a90.b1 = v;
        break;
    case 2:
        DAT_a8027a90.b2 = v;
        break;
    case 3:
        DAT_a8027a90.b3 = v;
        break;
    }
}
