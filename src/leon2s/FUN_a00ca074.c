/* leon2s FUN_a00ca074 @ 0xa00ca074-0xa00ca130 (47 words), flags -mcpu=v8 -Os -g.
 * Leaf, hw registers only (0xcf018e04/0c/10/14, all volatile). If reg 0xcf018e0c == 0: reg e04 = v;
 * p == 0xaa: e14 |= 1 and waits until bit 0 clears, else e14 |= 4 and waits for bit 2; e10 = 0x1f;
 * e14 |= 0x80 and waits for bit 7; e0c = 0x3f. Else: e04 = v; e0c = e0c - 1. void.
 * The e04 = v store happens on both paths; on the nonzero path e04 is written before the decrement; e0c is
 * a 32-bit hw register. Source form: the '== 0' arm first.
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
