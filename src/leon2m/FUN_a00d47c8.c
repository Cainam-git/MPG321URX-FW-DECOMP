/* leon2m FUN_a00d47c8 @ 0xa00d47c8-0xa00d4888 (48 words), -mcpu=v8 -O3 -g. No direct callers found.
 * Reads byte 6 of the record DAT_a802d290, limits it to at most 4 and stores it back. The value selects m:
 * 1 -> 1, 2 -> 2, 3 -> 3, any other value -> 0. Then it calls FUN_a0146dc0(0, 0), FUN_a01492f0(m & 3) and
 * FUN_a0146dc0(1, 0).
 * Source form: a switch with the default arm written first; m starts at 2 and case 2 leaves it unchanged.
 */
struct R290 {
    unsigned char pad0[6];
    unsigned char b06;
};
extern struct R290 DAT_a802d290;
extern void FUN_a0146dc0(int, int);
extern void FUN_a01492f0(unsigned char);

void FUN_a00d47c8(void)
{
    unsigned char v = DAT_a802d290.b06;
    unsigned char m = 2;

    if (v > 4)
        v = 4;
    DAT_a802d290.b06 = v;
    switch (v) {
    default:
        m = 0;
        break;
    case 1:
        m = 1;
        break;
    case 2:
        break;
    case 3:
        m = 3;
        break;
    }
    FUN_a0146dc0(0, 0);
    FUN_a01492f0(m & 3);
    FUN_a0146dc0(1, 0);
}
