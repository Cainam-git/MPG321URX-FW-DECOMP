/* leon2m FUN_a0150b08
 * Fills a local table for FUN_a00f6508 with three entries chosen by sel: entry k gets the low byte of v, entries k + 1 and
 * k - 1 (mod 24) get ((v >> 1) & 0x7F) + 0x40; sel 0: k = 0 (mask 0x800003), sel 1: k = 8 (mask 0x380), sel 2: k = 16
 * (mask 0x38000). For any other sel the table is passed to FUN_a00f6508 without being filled, as in the
 * firmware. Called three times by FUN_a01471a0. Same table form as FUN_a0150a98 (which calls FUN_a00f643c).
 */
struct tab {
    unsigned int mask;
    unsigned char v[24];
};

extern void FUN_a00f6508(struct tab *p);

void FUN_a0150b08(unsigned int sel, unsigned int v)
{
    struct tab t;
    unsigned char h = ((v >> 1) & 0x7f) + 0x40;

    switch (sel) {
    case 0:
        t.mask = 0x800003;
        t.v[0] = v;
        t.v[23] = h;
        t.v[1] = h;
        break;
    case 1:
        t.mask = 0x380;
        t.v[8] = v;
        t.v[7] = h;
        t.v[9] = h;
        break;
    case 2:
        t.mask = 0x38000;
        t.v[16] = v;
        t.v[15] = h;
        t.v[17] = h;
        break;
    }
    FUN_a00f6508(&t);
}
