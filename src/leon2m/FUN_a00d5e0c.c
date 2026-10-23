/* leon2m FUN_a00d5e0c @ 0xa00d5e0c-0xa00d5e84 (30 words).
 * FUN_a0148fc0(m) (tail call) with m = 1, 2 or 3 when bits 12..15 of word DAT_a802d2c4 are 1, 2 or 3, else 0.
 * Source form: the 4-bit value is a bit-field (it promotes to int: signed compares in the switch).
 */
extern void FUN_a0148fc0(unsigned char);
struct W2c4 {
    unsigned int hi : 16;
    unsigned int f12 : 4;
    unsigned int lo : 12;
};
extern struct W2c4 DAT_a802d2c4;

void FUN_a00d5e0c(void)
{
    unsigned char m;

    switch (DAT_a802d2c4.f12) {
    case 1: m = 1; break;
    case 2: m = 2; break;
    case 3: m = 3; break;
    default: m = 0; break;
    }
    FUN_a0148fc0(m & 3);
}
