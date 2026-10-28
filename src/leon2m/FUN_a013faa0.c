/* leon2m FUN_a013faa0 @ 0xa013faa0-0xa013fbe8 (82 words), -mcpu=v8 -O3 -g.
 * t = FUN_a013cd4c(port). Searches the 36-byte ROM rows DAT_001a5a16 (the list ends at a row whose halfword +2 is
 * 0xffff) for the first row i whose halfword +0x22 equals the halfword +0x3c of t; returns 0xff when there is none.
 * Otherwise it steps on from row i + 1, wrapping to row 0 at the end row, and returns the index of the first row
 * whose halfword +0x22 has the same high byte as t's halfword +0x3c; it returns 0xff when it reaches a row whose
 * halfword +0x22 equals t's halfword +0x3c first. No caller refers to it directly.
 * Source form: the first search sets a found flag and breaks; the second loop is 'for (i++; ; i++)' with the wrap
 * test first; both comparisons are written with t's halfword on the left.
 */
struct Rec {
    unsigned char pad0[0x3c];
    unsigned short w3c;
};
struct Row {
    unsigned char b0, pad1;
    unsigned short w2;
    unsigned char pad4[0x22 - 4];
    unsigned short w22;
};
extern struct Row DAT_001a5a16[];
extern struct Rec *FUN_a013cd4c(unsigned char);

unsigned char FUN_a013faa0(unsigned char port)
{
    struct Rec *t = FUN_a013cd4c(port);
    unsigned char found = 0;
    unsigned char i;

    for (i = 0; DAT_001a5a16[i].w2 != 0xffff; i++)
        if (t->w3c == DAT_001a5a16[i].w22) {
            found = 1;
            break;
        }
    if (found) {
        for (i++; ; i++) {
            if (DAT_001a5a16[i].w2 == 0xffff)
                i = 0;
            if (t->w3c == DAT_001a5a16[i].w22)
                return 0xff;
            if ((t->w3c >> 8) == (DAT_001a5a16[i].w22 >> 8))
                return i;
        }
    }
    return 0xff;
}
