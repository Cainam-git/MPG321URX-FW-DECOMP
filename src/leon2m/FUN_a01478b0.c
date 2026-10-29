/* leon2m FUN_a01478b0 @ 0xa01478b0-0xa01479ec (280 bytes), flags -mcpu=v8 -O3 -g.
 * Looks p up in the ROM table of 5 three-byte entries at 0x1a6da3 {a, val, key}: the first entry with
 * val == p gives r = its a (0 when none matches); when FUN_a012ad6c() returns 1, r values 4 and 6 are swapped.
 * m selects x: 0 -> 0, 1 -> 6, 2 -> 7, 3 -> 8, anything else -> 9. x == 9 calls FUN_a014f3d8(r, k) for
 * k = 0, 6, 7, 4, 5, 8 in that order; any other x calls FUN_a014f3d8(r, x) once.
 * Source form: the lookup is a static helper inlined here. Cases 4..7 and the default all set x = 9 and give
 * one jump-table target; the case blocks are laid out 3, 2, 1, 0 when case 7 has its own body and cases
 * 4, 5, 6 share theirs with the default.
 */
struct E3 { unsigned char a, val, key; };
extern const struct E3 DAT_001a6da3[];
extern unsigned char FUN_a012ad6c(void);
extern void FUN_a014f3d8(unsigned char, unsigned char);

static unsigned char lookup(unsigned char p)
{
    unsigned char k, r;

    for (k = 0; k < 5; k++) {
        if (DAT_001a6da3[k].val == p) {
            r = DAT_001a6da3[k].a;
            if (FUN_a012ad6c() == 1) {
                if (r == 4)
                    r = 6;
                else if (r == 6)
                    r = 4;
            }
            return r;
        }
    }
    return 0;
}

void FUN_a01478b0(unsigned char p, unsigned char m)
{
    unsigned char r, x;

    r = lookup(p);
    switch (m) {
    case 0: x = 0; break;
    case 1: x = 6; break;
    case 2: x = 7; break;
    case 3: x = 8; break;
    case 7: x = 9; break;
    case 4: case 5: case 6: default: x = 9; break;
    }
    if (x == 9) {
        FUN_a014f3d8(r, 0);
        FUN_a014f3d8(r, 6);
        FUN_a014f3d8(r, 7);
        FUN_a014f3d8(r, 4);
        FUN_a014f3d8(r, 5);
        FUN_a014f3d8(r, 8);
    } else
        FUN_a014f3d8(r, x);
}
