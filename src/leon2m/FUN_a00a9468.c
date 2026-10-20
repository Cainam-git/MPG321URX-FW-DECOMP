/* leon2m FUN_a00a9468 @ 0xa00a9468  (-mcpu=v8 -O3 -g)
 * Calls FUN_a0146a80 and FUN_a0146b20 with the second argument (q) starting at base: 6 for sel 2, 0xB for sel 0, else
 * 0x10. mode 6: for q = base..base+3, FUN_a0146a80(0x37, q, 4, 0x792, 0) and FUN_a0146b20(0, 0x37, q, 4, 0, 0). Other
 * modes pick three values c1, c2, c3 (mode 5: 0x399E/0x792/0x992, 0: 0x3E9E/0x992/0x992, 1: 0x439E/0x792/0x792, 2:
 * 0x489E/0x992/0x792, 3: 0x4D9E/0x992/0x992, 4 and anything else: all 0) and call, for q = base..base+2,
 * FUN_a0146a80(0x37, q, 1, c2, 0) and FUN_a0146a80(0x3A, q, 1, c3, 0), then FUN_a0146a80(0x38, q, 2, c1, 0) for the
 * same q.
 * Callers: FUN_a0091710, FUN_a00919b4, FUN_a0091d74, FUN_a009221c, FUN_a00922f0, FUN_a00b7474 and others.
 * Source form: an if/else-if chain in the order 6, 5, 4, 0, 1, 2, 3 (mode 6 runs its clear loop in the first arm),
 * followed by a separate 'if (mode != 6)' around the loops of the other modes; the compiler threads the known modes past
 * the second test.
 */
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

void FUN_a00a9468(unsigned char sel, unsigned char mode)
{
    unsigned char base;
    unsigned char k;
    unsigned short c1 = 0;
    unsigned short c2 = 0;
    unsigned short c3 = 0;

    if (sel == 2)
        base = 6;
    else
        base = sel == 0 ? 0xb : 0x10;
    if (mode == 6) {
        for (k = 0; k <= 3; k++) {
            FUN_a0146a80(0x37, base + k, 4, 0x792, 0);
            FUN_a0146b20(0, 0x37, base + k, 4, 0, 0);
        }
    } else if (mode == 5) {
        c1 = 0x399e; c2 = 0x792; c3 = 0x992;
    } else if (mode == 4) {
    } else if (mode == 0) {
        c1 = 0x3e9e; c2 = 0x992; c3 = 0x992;
    } else if (mode == 1) {
        c1 = 0x439e; c2 = 0x792; c3 = 0x792;
    } else if (mode == 2) {
        c1 = 0x489e; c2 = 0x992; c3 = 0x792;
    } else if (mode == 3) {
        c1 = 0x4d9e; c2 = 0x992; c3 = 0x992;
    }
    if (mode != 6) {
        for (k = 0; k <= 2; k++) {
            FUN_a0146a80(0x37, base + k, 1, c2, 0);
            FUN_a0146a80(0x3a, base + k, 1, c3, 0);
        }
        for (k = 0; k <= 2; k++)
            FUN_a0146a80(0x38, base + k, 2, c1, 0);
    }
}
