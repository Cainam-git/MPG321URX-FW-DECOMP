/* leon2s FUN_a00ca074 @ 0xa00ca074-0xa00ca130 (47 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp 0/47 mismatches.
 * Code facts: leaf, hw registers only (0xcf018e04/0c/10/14, all volatile = real registers).
 * If reg 0xcf018e0c == 0: reg e04 = v; p == 0xaa: e14 |= 1 and wait until bit 0 clears, else
 * e14 |= 4 and wait for bit 2; e10 = 0x1f; e14 |= 0x80 and wait for bit 7; e0c = 0x3f.
 * Else: e04 = v; e0c = e0c - 1. void.
 * Fix vs the autoc draft (82.98): BEHAVIOUR: the e04 = v store happens on BOTH paths (the draft
 * skipped it on the e0c == 0 path); on the nonzero path e04 is written BEFORE the decrement; e0c
 * is a 32-bit hw register (the draft used an undeclared name); the '== 0' arm first. Aids: none.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00ca074(unsigned char p, unsigned char v)
{
    if (R(0xcf018e0c) == 0) {
        R(0xcf018e04) = v;
        if (p == 0xaa) {
            R(0xcf018e14) |= 1;
            while (R(0xcf018e14) & 1)
                ;
        } else {
            R(0xcf018e14) |= 4;
            while (R(0xcf018e14) & 4)
                ;
        }
        R(0xcf018e10) = 0x1f;
        R(0xcf018e14) |= 0x80;
        while (R(0xcf018e14) & 0x80)
            ;
        R(0xcf018e0c) = 0x3f;
    } else {
        R(0xcf018e04) = v;
        R(0xcf018e0c) = R(0xcf018e0c) - 1;
    }
}
