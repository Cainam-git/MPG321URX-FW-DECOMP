/* leon2m FUN_a014a060 @ 0xa014a060-0xa014a0d8 (30 words), flags -mcpu=v8 -O3 -g.
 * Code facts: p (u8) maps 0->0, 1->1, 2->2, 3->3, anything else -> 0xff (switch, emitted as a
 * compare chain). If v <= 3: tail call FUN_a012f1ec(v, 3). Else: log FUN_a00df170(string
 * 0x1a6dd8), then tail call FUN_a012f1ec(0, 3). Both tail calls are separate in the fw.
 * FUN_a012f1ec re-extends its 2nd arg (and %i1,0xff), so (u8, u8). void.
 * Fix vs the autoc draft (83.33): the 'v <= 3' arm is FIRST in the source (fw falls through into
 * the v tail call; the draft's '> 3' first arm made gcc share one tail call). String named by
 * address s_001a6dd8. Aids: none.
 */
extern void FUN_a00df170(const char *);
extern void FUN_a012f1ec(unsigned char, unsigned char);
extern const char s_001a6dd8[];

void FUN_a014a060(unsigned char p)
{
    unsigned char v;

    switch (p) {
    case 1: v = 1; break;
    case 0: v = 0; break;
    case 2: v = 2; break;
    case 3: v = 3; break;
    default: v = 0xff; break;
    }
    if (v <= 3) {
        FUN_a012f1ec(v, 3);
    } else {
        FUN_a00df170(s_001a6dd8);
        FUN_a012f1ec(0, 3);
    }
}
