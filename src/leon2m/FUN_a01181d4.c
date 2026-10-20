/* FUN_a01181d4: steps the 4-byte state record at 0xa8027a90 (bytes b0..b3). Called from FUN_a014d5f4.
 * b3 in 1..6: b3 is decremented. b3 == 0: b3 = 8. b3 in 7..13: b3 is incremented.
 * b3 > 13: if b1 < 3, b1 is incremented; otherwise, when b2 == 1 and b0 == 0, b2 is toggled, b0 = 2 and b1
 * cleared; when b2 == 1 and b0 is 2 or 1, FUN_a01181a4 clears b0..b2 and the bytes 0xa802c98c/0xa802c98d and
 * sets b3 = 6; when b2 != 1, b2 is toggled and b1 cleared. In every b3 > 13 case b3 = 6 is stored afterwards.
 * FUN_a01181a4 is defined here because GCC inlines it at -O3 (its own store of 6 to b3 remains in the copy).
 * Exact form: the b2 == 1 arm before the b2 != 1 arm; b0 == 2 and b0 == 1 as separate ifs, each calling the
 * helper (an || folds into a range test); the helper's store order b0, c98d, c98c, b1, b2, b3.
 */
struct Rec4 { unsigned char b0, b1, b2, b3; };
extern struct Rec4 DAT_a8027a90;
extern unsigned char DAT_a802c98c;
extern unsigned char DAT_a802c98d;

void FUN_a01181a4(void)
{
    DAT_a8027a90.b0 = 0;
    DAT_a802c98d = 0;
    DAT_a802c98c = 0;
    DAT_a8027a90.b1 = 0;
    DAT_a8027a90.b2 = 0;
    DAT_a8027a90.b3 = 6;
}

void FUN_a01181d4(void)
{
    unsigned char c = DAT_a8027a90.b3;

    if ((unsigned char)(c - 1) <= 5) {
        DAT_a8027a90.b3 = c - 1;
    } else if (c == 0) {
        DAT_a8027a90.b3 = 8;
    } else if (c <= 13) {
        DAT_a8027a90.b3 = c + 1;
    } else {
        if (DAT_a8027a90.b1 < 3) {
            DAT_a8027a90.b1++;
        } else if (DAT_a8027a90.b2 == 1) {
            if (DAT_a8027a90.b0 == 0) {
                DAT_a8027a90.b2 ^= 1;
                DAT_a8027a90.b0 = 2;
                DAT_a8027a90.b1 = 0;
            } else if (DAT_a8027a90.b0 == 2) {
                FUN_a01181a4();
            } else if (DAT_a8027a90.b0 == 1) {
                FUN_a01181a4();
            }
        } else {
            DAT_a8027a90.b2 ^= 1;
            DAT_a8027a90.b1 = 0;
        }
        DAT_a8027a90.b3 = 6;
    }
}
