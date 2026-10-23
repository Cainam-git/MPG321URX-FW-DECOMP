/* leon2m FUN_a0150a98
 * Scales the low byte of the parameter to l = v * 48 / 255 (unsigned short) and passes FUN_a00f643c a local
 * table { mask 0xF; v[0] = l / 2, v[1] = l * 3 / 4, v[2] = l, v[3] = l * 3 / 4 } (entries 0..3 enabled by the mask).
 * Called by FUN_a01471a0. Same table form as FUN_a0150b08 (which calls FUN_a00f6508).
 */
struct tab {
    unsigned int mask;
    unsigned char v[24];
};

extern void FUN_a00f643c(struct tab *p);

void FUN_a0150a98(unsigned char v)
{
    struct tab t;
    unsigned short l = v * 48 / 255;

    t.mask = 0xf;
    t.v[0] = l / 2;
    t.v[2] = l;
    t.v[1] = l * 3 / 4;
    t.v[3] = l * 3 / 4;
    FUN_a00f643c(&t);
}
