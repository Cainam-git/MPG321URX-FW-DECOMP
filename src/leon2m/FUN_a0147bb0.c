/* leon2m FUN_a0147bb0 @ 0xa0147bb0-0xa0147c38 (34 words).
 * Passes bits 12-15 of the first word of record ch (the 0x78-byte records at 0xa802df30) to FUN_a0142e8c and
 * returns its result when it is 1..5, otherwise 6 (jump table; 0 shares the default arm). Called from FUN_a0088724.
 */
struct Chan { unsigned int hi16 : 16; unsigned int f12 : 4; unsigned int lo12 : 12; unsigned char rest[0x74]; };
extern struct Chan DAT_a802df30[4];
extern unsigned char FUN_a0142e8c(unsigned int);

int FUN_a0147bb0(unsigned char ch)
{
    int r;

    switch (FUN_a0142e8c(DAT_a802df30[ch].f12)) {
    case 1: r = 1; break;
    case 2: r = 2; break;
    case 3: r = 3; break;
    case 4: r = 4; break;
    case 5: r = 5; break;
    default: r = 6; break;
    }
    return r;
}
