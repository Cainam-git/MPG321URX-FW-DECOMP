/* leon2m FUN_a0142218 @ 0xa0142218-0xa014226c (21 words).
 * Returns the index (0..6) of the first of the seven 18-byte records at 0xa802e116 whose byte +0x10 equals v, or
 * 0xff when none does. Called from FUN_a0136054, FUN_a0143bc4, FUN_a0144574, FUN_a014464c, FUN_a0149588 and others.
 */
struct Rec12 { unsigned short h0, h2; unsigned char pad[0xc]; unsigned char b10, b11; };
extern struct Rec12 DAT_a802e116[7];

unsigned char FUN_a0142218(unsigned char v)
{
    unsigned char r = 0xff;
    unsigned char i;

    for (i = 0; i <= 6; i++) {
        if (DAT_a802e116[i].b10 == v) {
            r = i;
            break;
        }
    }
    return r;
}
