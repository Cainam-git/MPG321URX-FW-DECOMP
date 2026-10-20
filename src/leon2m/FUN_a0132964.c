/* leon2m FUN_a0132964 @ 0xa0132964-0xa0132a14 (44 words), flags -mcpu=v8 -O3 -g.
 * What it does: the "keep going" test of the channel state machine FUN_a013dc6c (state 9 -> 10
 * and state 12 -> 5 only when this returns 1; otherwise the channel waits / restarts).
 * Code facts: m = FUN_a00fd820(port), the port's signal-class code (0xe8, 0xc1, 0x31/0x41/0x51/0x61,
 * ...). Code 0xb1 is replaced by FUN_a012fc20() (the class byte of the active df30 channel record).
 * Only the 4 codes 0x31, 0x41, 0x51, 0x61 give a non-zero chance: the result is then
 * FUN_a01420e4(idx) = bit 6 of the u16 at DAT_a802e116 + idx * 18 + 2, with idx 0 for 0x51,
 * idx 1 for 0x61 and idx 0xff for 0x31/0x41 (the fw really passes 0xff). Every other code returns 0.
 * The channel moves past state 9 only if fd820 reports class 0x51 or
 * 0x61 (or 0xb1 mapped to them) AND bit 6 of that e116 record is set; else it returns 0.
 * The 2nd param is passed by dc6c but never read by the fw (no %i1 use).
 * Fix vs the autoc draft: the idx choice is a switch with 2 cases (an if/else-if chain
 * lets sched1 move the 0x51/0x61 xor pair speculatively into the 0x31/0x41 test block).
 * Aids: none.
 */
extern unsigned char FUN_a00fd820(unsigned char);
extern unsigned char FUN_a012fc20(void);
extern unsigned char FUN_a01420e4(unsigned char);

unsigned char FUN_a0132964(unsigned char port, unsigned int unused)
{
    unsigned char r, idx, m;

    m = FUN_a00fd820(port);
    r = 0;
    idx = 0xff;
    if (m == 0xb1)
        m = FUN_a012fc20();
    if (m == 0x31 || m == 0x41 || m == 0x51 || m == 0x61) {
        switch (m) {
        case 0x51: idx = 0; break;
        case 0x61: idx = 1; break;
        }
        r = FUN_a01420e4(idx);
    }
    return r;
}
