/* leon2s FUN_a00a1e28 @ 0xa00a1e28-0xa00a1f84, -mcpu=v8 -Os -g (leaf).
 * (u8 port), returns a u8 code from the 0x190-byte record DAT_a807d7e0[port]. Byte +0x18 == 0: 1.
 * Word +0x50 == 0: (w74 != 1), plus 0x1a when w70 is 5 or 6. Otherwise the base is 2, or for w60 == 3:
 * 0x14 / 0x1c / 0x22 for w70 == 1 / 5 / 6 (0xe for other values), or 8 for w60 == 2; then +1 when w80 != 0,
 * or (w80 == 0) when w74 is neither 0 nor 1, or w74 == 0 and byte +0x7c == 1; +2 when w50 == 1 and byte
 * +0x185 == 0; +4 when w50 == 3.
 * Source form: the w50 != 0 arm first; in the other arm 'r = w74 != 1; r += 0x1a;' as two statements
 * (one expression folds to mov 0x1b / addx).
 */
struct R190 {
    unsigned char pad0[0x18];
    unsigned char b18;
    unsigned char pad19[0x50 - 0x19];
    unsigned int w50;
    unsigned char pad54[0x60 - 0x54];
    unsigned int w60;
    unsigned char pad64[0x70 - 0x64];
    unsigned int w70;
    unsigned int w74;
    unsigned char pad78[4];
    unsigned char b7c;
    unsigned char pad7d[3];
    unsigned int w80;
    unsigned char pad84[0x185 - 0x84];
    unsigned char b185;
    unsigned char pad186[0x190 - 0x186];
};
extern struct R190 DAT_a807d7e0[];

unsigned char FUN_a00a1e28(unsigned char port)
{
    unsigned char r = 1;

    if (DAT_a807d7e0[port].b18 != 0) {
        if (DAT_a807d7e0[port].w50 != 0) {
            r = 2;
            if (DAT_a807d7e0[port].w60 == 3) {
                r = 0xe;
                if (DAT_a807d7e0[port].w70 == 1)
                    r = 0x14;
                else if (DAT_a807d7e0[port].w70 == 5)
                    r = 0x1c;
                else if (DAT_a807d7e0[port].w70 == 6)
                    r = 0x22;
            } else if (DAT_a807d7e0[port].w60 == 2) {
                r = 8;
            }
            if (DAT_a807d7e0[port].w80 == 0) {
                if (DAT_a807d7e0[port].w74 != 1) {
                    if (DAT_a807d7e0[port].w74 == 0) {
                        if (DAT_a807d7e0[port].b7c == 1)
                            r++;
                    } else {
                        r++;
                    }
                }
            } else {
                r++;
            }
            if (DAT_a807d7e0[port].w50 == 1 && DAT_a807d7e0[port].b185 == 0)
                r += 2;
            if (DAT_a807d7e0[port].w50 == 3)
                r += 4;
        } else {
            if (DAT_a807d7e0[port].w70 - 5 < 2)
            {
                r = DAT_a807d7e0[port].w74 != 1;
                r += 0x1a;
            }
            else
                r = DAT_a807d7e0[port].w74 != 1;
        }
    }
    return r;
}
