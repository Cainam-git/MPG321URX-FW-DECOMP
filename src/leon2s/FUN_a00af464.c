/* leon2s FUN_a00af464 @ 0xa00af464-0xa00af524 (48 words incl. the merged ret/restore tail), -mcpu=v8 -Os -g.
 * Code facts: (u8 port, u8 on). r = FUN_a00a6bb8(port, 0x461) & 1. on == 1 and r == 0, or on != 1 and
 * r == 1: FUN_a00a6c98(port, 0x30, 0x80, 1); FUN_a00a6c98(port, 0x461, 1, on == 1); then the sibcall
 * FUN_a00a6c98(port, 0x30, 0x80, 0). Otherwise nothing. void (the draft returned 0).
 * Fix vs the autoc draft (75.00, which did not compile cleanly): each arm holds its OWN three calls inside
 * the r test. -Os code hoisting then moves the shared sibcall arguments (%i1..%i3 = 0x30, 0x80, 0) above
 * the r test in both arms, and crossjumping merges the two final calls into one: the fw shape. Early
 * returns with one shared final call give a different layout (60.42). Aids: none.
 */
extern unsigned char FUN_a00a6bb8(unsigned char, unsigned short);
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned char, unsigned char);

void FUN_a00af464(unsigned char port, unsigned char on)
{
    if (on == 1) {
        if ((FUN_a00a6bb8(port, 0x461) & 1) == 0) {
            FUN_a00a6c98(port, 0x30, 0x80, 1);
            FUN_a00a6c98(port, 0x461, 1, 1);
            FUN_a00a6c98(port, 0x30, 0x80, 0);
        }
    } else {
        if (FUN_a00a6bb8(port, 0x461) & 1) {
            FUN_a00a6c98(port, 0x30, 0x80, 1);
            FUN_a00a6c98(port, 0x461, 1, 0);
            FUN_a00a6c98(port, 0x30, 0x80, 0);
        }
    }
}
