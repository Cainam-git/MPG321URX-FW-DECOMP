/* leon2m FUN_a012f1ec @ 0xa012f1ec-0xa012f2dc (60 words).
 * Maps m to a state value st (0 -> 5, 2 -> 7, 3 -> 8, 4 -> 9, any other m -> 6). For a channel ch 0..3 (0xff and
 * values above 3 return at once) whose channel record DAT_a802df30[ch] (0x78 bytes, layout as in FUN_a01518c8)
 * has a state field (bits 28..31 of word +0) of at least st: when that state is 0xc, bits 14..15 of word +0x70
 * are set to 2; then state = st, the step field (bits 20..23) = 0, bit 22 of word +0x70 is cleared and
 * FUN_a01518c8(ch) is tail-called. Called from many places (FUN_a0080490, FUN_a0148268, FUN_a014c7bc, ...).
 * Source form: switch without a case 1 (it falls to the default, so GCC builds a compare tree); the state test
 * compares (unsigned int)st with the bit-field (unsigned compare).
 */
struct Chan {
    union { unsigned int w; struct { unsigned int state:4, f24:4, step:4, f16:4, port:4, f8:4, f4:4, f1:3, b0:1; } b; } u;
    unsigned char p04[0x70 - 0x04];
    unsigned int w70;
    unsigned char p74[0x78 - 0x74];
};
extern struct Chan DAT_a802df30[4];
extern void FUN_a01518c8(unsigned char ch);

void FUN_a012f1ec(unsigned char ch, unsigned char m)
{
    unsigned char st;

    switch (m) {
    case 0: st = 5; break;
    case 2: st = 7; break;
    case 3: st = 8; break;
    case 4: st = 9; break;
    default: st = 6; break;
    }
    if (ch == 0xff)
        return;
    if (ch > 3)
        return;
    if ((unsigned int)st > DAT_a802df30[ch].u.b.state)
        return;
    if (DAT_a802df30[ch].u.b.state == 0xc)
        DAT_a802df30[ch].w70 = (DAT_a802df30[ch].w70 & ~0xc000) | 0x8000;
    DAT_a802df30[ch].u.b.state = st;
    DAT_a802df30[ch].u.b.step = 0;
    DAT_a802df30[ch].w70 &= ~0x400000;
    FUN_a01518c8(ch);
}
